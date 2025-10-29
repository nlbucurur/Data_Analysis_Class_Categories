#include <vector>

void BDT::Add_BDT_var(TCut cutSB, TString Data, TString output, vector<TString> vars)
{
  // TString Folder = "/home/lorena/Documents/Thesis/Data_Analysis_Class/Analysis/";
  TString Folder = "/home/lorena/Documents/Thesis/Data_Analysis_Class/Analysis1/bin_missMom_1/";

  cout << "-Start TMVA-" << endl;

  cout << " Adding Variables to Reader" << endl;
  // --- Create the Reader object
  TMVA::Reader *reader = new TMVA::Reader("!Color:!Silent");
  // Create a set of variables and declare them to the reader
  // - the variable names MUST corresponds in name and type to those given in the weight file(s) used
  static vector<Float_t> _vars1(vars.size());
  static Float_t Ph_Th;
  static Float_t Nuc_Th;
  static Float_t MP_eNg;
  // static vector<vector<double>*> _vars(vars.size());
  // static vector<int>* flag;
  // static vector<double>* Ph_Th_V;
  // static vector<double>* Nuc_Th_V;

  static vector<Double_t> _vars(vars.size());
  static Int_t flag;
  static Float_t Ph_Th_V;
  static Float_t Nuc_Th_V;
  static Float_t MP_eNg_V;


  TFile *input4 = new TFile(Data, "READ");
  TTree *signal;
  if (input4->GetListOfKeys()->Contains("pDVCS"))
    signal = (TTree *)input4->Get("pDVCS");
  else
    signal = (TTree *)input4->Get("eppi0");

  //==================================

  for (int l = 0; l < vars.size(); l++)
  {
    reader->AddVariable(vars.at(l), &_vars1.at(l));
  }
  reader->AddSpectator("_strip_Ph_Theta", &Ph_Th);
  reader->AddSpectator("_strip_Nuc_Theta", &Nuc_Th);
  reader->AddSpectator("_miss_mom_eNg", &MP_eNg);

  cout << " Booking Method" << endl;

  if (!nodata)
  {
    if (categories)
      reader->BookMVA("BDT method", Folder + TString("dataset/weights/TMVAClassificationCategory_Ph_Topology.weights.xml"));
    else
      reader->BookMVA("BDT method", Folder + TString("dataset/weights/TMVAClassificationCategory_BDT.weights.xml"));
      // reader->BookMVA("BDT method", Folder + TString("dataset/weights/TMVAClassification_BDT.weights.xml"));
  }
  //========================================
  signal->SetBranchStatus("*", 1); // enable all branches
  TFile f(Folder + output, "RECREATE");
  TTree *Tree = signal->CopyTree(cutSB);

  Long64_t nentries = Tree->GetEntries();
  cout << "Reading File with " << nentries << " to Add MVA response" << endl;
  cout << " Reading Variables" << endl;

  for (int l = 0; l < vars.size(); l++)
  {
    Tree->SetBranchAddress(vars.at(l), &_vars.at(l));
  }
  Tree->SetBranchAddress("_bestCandidateFlag", &flag);
  Tree->SetBranchAddress("_strip_Ph_Theta", &Ph_Th_V);
  Tree->SetBranchAddress("_strip_Nuc_Theta", &Nuc_Th_V);
  Tree->SetBranchAddress("_miss_mom_eNg", &MP_eNg_V);

  cout << " Loop on all events " << Tree->GetEntries() << " to compute MVA output" << endl;

  double _strip_Nuc_BDT;

  TBranch *newBranch = Tree->Branch("_strip_Nuc_BDT", &_strip_Nuc_BDT, "_strip_Nuc_BDT/D");

  ////////////////////////////

  for (Long64_t ievt = 0; ievt < Tree->GetEntries(); ievt++)
  {
    Tree->GetEntry(ievt);
    printProgress(ievt * 1.0 / Tree->GetEntries());

    if (flag == 1)
    {

      for (int l = 0; l < vars.size(); l++)
      {
        _vars1.at(l) = _vars.at(l);
      }
      Ph_Th = Ph_Th_V;
      Nuc_Th = Nuc_Th_V;
      MP_eNg = MP_eNg_V;


      // Get TMVA output
      std::cout << "Ph_Th = " << Ph_Th << std::endl;
      if ((categories || (!categories && Ph_Th > 5)) && !nodata)
      {
        _strip_Nuc_BDT = reader->EvaluateMVA("BDT method");
        // std::cout << "BDT value: " << _strip_Nuc_BDT << std::endl;
      }
      else
      {
        _strip_Nuc_BDT = 2;
      }
      newBranch->Fill();
    }
  }
  cout << "Writing file" << endl;
  Tree->Write();
  cout << "closing file" << endl;
  cout << "Added MVA variables to file" << endl;

  delete reader;
  delete signal;
  input4->Close();
  delete input4;

  delete Tree;
  f.Close();
}
