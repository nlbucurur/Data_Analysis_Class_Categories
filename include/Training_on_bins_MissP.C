
void BDT::Training_on_bins_MissP(TString Data, int NBinsPhi = 0, int bin = 0, bool build = true, bool eta = false)
{

  int bin_number = 1;
  TString Folder_old = Folder;

  int k0 = 0, kN = 447;
  if (bin != 0)
  {
    bin_number = bin;
    k0 = bin - 1;
    kN = bin;
  }

  for (int k = k0; k < kN; k++)
  {

    if (NBinsPhi == 0)
    {
      NBinsPhi = Nphibins[k];
    }

    TCut cut_bin = Mbins_missMom[k];

    std::cout << Form("\n\n t_Ph>%f && t_Ph<%f && strip_Q2>%f && strip_Q2<%f && strip_Xbj>%f && strip_Xbj<%f && _miss_mom_eNg>=%f && _miss_mom_eNg<%f", bins_missMom[k][0], bins_missMom[k][1], bins_missMom[k][2], bins_missMom[k][3], bins_missMom[k][4], bins_missMom[k][5], bins_missMom[k][6], bins_missMom[k][7]) << endl;

    boundaries.clear();
    boundaries.push_back(bins_missMom[k][0]);
    boundaries.push_back(bins_missMom[k][1]);
    boundaries.push_back(bins_missMom[k][2]);
    boundaries.push_back(bins_missMom[k][3]);
    boundaries.push_back(bins_missMom[k][4]);
    boundaries.push_back(bins_missMom[k][5]);
    boundaries.push_back(bins_missMom[k][6]);
    boundaries.push_back(bins_missMom[k][7]);

    Folder = Folder_old + TString("bin_missMom_") + Form("%i/", bin_number);
    gSystem->Exec(TString("mkdir -p ") + Folder);

    // Flag for training category or normal
    // Check if there is enough background in the FT. At least 100 events
    TChain *background = new TChain("eppi0");
    background->Add(Pi0);

    TH1F *hist1 = new TH1F("hist1", "", 100, 0, 1);
    TH1F *hist2 = new TH1F("hist2", "", 100, 0, 1);
    background->Project("hist1", "_strip_Xbj", cut + cut_bin + TCut("_strip_Ph_Theta < 5"));
    background->Project("hist2", "_strip_Xbj", cut + cut_bin);
    nft = hist1->GetEntries() / hist2->GetEntries();
    categories = (nft > 0.05 && hist1->GetEntries() > 50) ? true : false;
    int nev_bkg = hist2->GetEntries();
    delete hist1;
    delete hist2;
    delete background;

    TH1 *Orig;

    std::ifstream nodataInp(Folder + TString("nodata.conf"));
    if (nodataInp)
      nodata = true;
    nodataInp.close();
    std::ofstream nodataFile;

    if (build)
    {
      std::cout << "\nBuilding ML training..." << endl;
      try
      {
        if (nev_bkg < 50)
          throw std::runtime_error("Manually triggered exception!");

        TrainingCategory(cut + cut_bin, DVCS, Pi0, Vars);
      }
      catch (std::exception &e)
      {
        std::cerr << "NO DATA \n Impossible to do a BDT classification. \n generating contamination and exiting..." << "\n";
        nodata = true;
        Write_Null(bin_number);

        gSystem->ChangeDirectory(dir);
        gSystem->Exec("pwd");

        nodataFile.open(Folder + TString("nodata.conf"));
        if (!nodataFile.is_open())
          std::cerr << "Error opening nodata.conf :" << Folder + TString("nodata.conf") << std::endl;
        nodataFile << "true" << endl;
        nodataFile.close();
      }

      Add_BDT_var(cut + cut_bin, DVCS, TDVCS, Vars);
      Add_BDT_var(cut + cut_bin, Pi0, TPi0, Vars);
      Add_BDT_var(cut + cut_bin, Data, TData, Vars);
      Filter(Folder + TData, cut + cut_bin, TString("Data_NP_Theta_g_5.root"));
      
      if (!nodata)
      {
        Get_BDT_Score();
      }
      else
      {
        std::cout << "Skipping Get_BDT_Score because no training was performed in this bin." << std::endl;
      }

      Filter(Folder + TData, cut + cut_bin + TCut(Form("_strip_Nuc_BDT > %f", BDT_value)), TString("Classified_Data.root"));
      Training_vars(Folder + TData, Folder + TDVCS, Folder + TPi0, cut + cut_bin);
      Explore(TData, TDVCS, cut + cut_bin);

      Kin_vars(TData, TDVCS, TPi0, cut + cut_bin);
      gSystem->Exec(TString("mv ") + Folder + TString("Kin_Vars.pdf ") + Folder + TString("Kin_Vars_bef_BDT.pdf"));
      Kin_vars(TData, TDVCS, TPi0, cut + cut_bin + TCut("_strip_Nuc_BDT > 0"));
      gSystem->Exec(TString("mv ") + Folder + TString("Kin_Vars.pdf ") + Folder + TString("Kin_Vars_aft_BDT.pdf"));
    }

    /*******************************************************************/

    std::cout << "\n Getting Contamination BDT way..." << endl;
    Get_Contamination(cut + cut_bin + cut_ref, BDT_value);

    Orig = Single_BSA("Data_NP_Theta_g_5.root", NBinsPhi);
    Orig->SetAxisRange(-1., 1., "Y");
    Orig->SetMarkerColor(kBlack);
    Orig->SetLineColor(kBlack);
    Orig->SetTitle("Before bkg subtraction");

    TCanvas *c3 = new TCanvas("c3", "Histograms");
    gStyle->SetOptFit(0);
    gStyle->SetOptTitle(0);
    Orig->Draw();
    c3->Print(Folder + TString("Raw_BSA.pdf"));
    delete c3;
    delete Orig;
  }

  Folder = Folder_old;

  return;
}
