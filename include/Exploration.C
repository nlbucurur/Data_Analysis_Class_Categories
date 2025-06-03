void BDT::Exploration_k(int k, TString TData, TString TSim, TCut cutSB, TString extension)
{
  gStyle->SetOptStat(0);

  TCanvas *c1 = new TCanvas("c1", "Histograms");
  c1->Divide(2, 2);
  TFile *input2 = new TFile(Folder + TData, "READ");
  TTree *pDVCS_Data = (TTree *)input2->Get("pDVCS");

  std::cout << "Entries in pDVCS_Data: " << pDVCS_Data->GetEntries() << std::endl;

  TFile *input3 = new TFile(Folder + TSim, "READ");
  TTree *pDVCS_Sim = (TTree *)input3->Get("pDVCS");

  double factor = 1;

  // Create an array of 10 division, covering the BDT response range, so the function applies the cut depending on the input value of k
  float BDTCut[20];
  for (int j = 0; j < 20; j++)
  {
    BDTCut[j] = -0.4 + 0.8 * j / 20;
    std::cout << "BDTCut[" << j << "] = " << BDTCut[j] << std::endl;
  }
  // TCut cut = TCut(Form("_strip_Nuc_BDT>%f && _strip_Ph_Theta > 5", BDTCut[k]) + cutSB);
  TCut cut = TCut(Form("_strip_Nuc_BDT>%f", BDTCut[k]) + cutSB);

  TH1F *hist1c_Sim = new TH1F("hist1c_Sim", "Histogram", 100, -0.2, 2.5);
  TH1F *hist2c_Sim = new TH1F("hist2c_Sim", "Histogram", 100, 0, 5.0);
  TH1F *hist3c_Sim = new TH1F("hist3c_Sim", "Histogram", 100, -2, 2);
  TH1F *hist4c_Sim = new TH1F("hist4c_Sim", "Histogram", 100, -2, 2);

  TH1F *hist1c_Data = new TH1F("hist1c_Data", "Histogram", 100, -0.2, 2.5);
  TH1F *hist2c_Data = new TH1F("hist2c_Data", "Histogram", 100, 0, 5.0);
  TH1F *hist3c_Data = new TH1F("hist3c_Data", "Histogram", 100, -2, 2);
  TH1F *hist4c_Data = new TH1F("hist4c_Data", "Histogram", 100, -2, 2);

  // Variables to plot
  const char *p1 = "_mm2_eNg";
  const char *p2 = "_mm2_eg";
  const char *p3 = "_delta_t";
  const char *p4 = "_delta_Phi";

  pDVCS_Sim->Project("hist1c_Sim", p1, cut);
  pDVCS_Sim->Project("hist2c_Sim", p2, cut);
  pDVCS_Sim->Project("hist3c_Sim", p3, cut);
  pDVCS_Sim->Project("hist4c_Sim", p4, cut);

  pDVCS_Data->Project("hist1c_Data", p1, cut);
  pDVCS_Data->Project("hist2c_Data", p2, cut);
  pDVCS_Data->Project("hist3c_Data", p3, cut);
  pDVCS_Data->Project("hist4c_Data", p4, cut);

  c1->cd(1);
  hist1c_Sim->SetTitle(p1);
  hist1c_Data->SetTitle(p1);
  hist1c_Sim->Scale(factor / hist1c_Sim->GetEntries());
  hist1c_Sim->SetLineColor(kBlack);
  hist1c_Sim->SetFillStyle(0);
  hist1c_Data->Scale(factor / hist1c_Data->GetEntries());
  hist1c_Data->SetLineColor(kRed);
  hist1c_Data->SetFillColor(kRed - 9);
  hist1c_Data->SetFillStyle(3004);

  if (hist1c_Sim->GetMaximum() > hist1c_Data->GetMaximum())
  {
    hist1c_Sim->Draw("HIST");
    hist1c_Data->Draw("HIST SAMES");
  }
  else
  {
    hist1c_Data->Draw("HIST");
    hist1c_Sim->Draw("HIST SAMES");
  }

  c1->cd(2);
  hist2c_Sim->SetTitle(p2);
  hist2c_Data->SetTitle(p2);
  hist2c_Sim->Scale(factor / hist2c_Sim->GetEntries());
  hist2c_Sim->SetLineColor(kBlack);
  hist1c_Data->SetFillStyle(0);
  hist2c_Data->Scale(factor / hist2c_Data->GetEntries());
  hist2c_Data->SetLineColor(kRed);
  hist2c_Data->SetFillColor(kRed - 9);
  hist2c_Data->SetFillStyle(3004);

  if (hist2c_Sim->GetMaximum() > hist2c_Data->GetMaximum())
  {
    hist2c_Sim->Draw("HIST");
    hist2c_Data->Draw("HIST SAMES");
  }
  else
  {
    hist2c_Data->Draw("HIST");
    hist2c_Sim->Draw("HIST SAMES");
  }

  c1->cd(3);
  hist3c_Sim->SetTitle(p3);
  hist3c_Data->SetTitle(p3);
  hist3c_Sim->Scale(factor / hist3c_Sim->GetEntries());
  hist3c_Sim->SetLineColor(kBlack);
  hist3c_Sim->SetFillStyle(0);
  hist3c_Data->Scale(factor / hist3c_Data->GetEntries());
  hist3c_Data->SetLineColor(kRed);
  hist3c_Data->SetFillColor(kRed - 9);
  hist3c_Data->SetFillStyle(3004);

  if (hist3c_Sim->GetMaximum() > hist3c_Data->GetMaximum())
  {
    hist3c_Sim->Draw("HIST");
    hist3c_Data->Draw("HIST SAMES");
  }
  else
  {
    hist3c_Data->Draw("HIST");
    hist3c_Sim->Draw("HIST SAMES");
  }

  c1->cd(4);
  hist4c_Sim->SetTitle(p4);
  hist4c_Data->SetTitle(p4);
  hist4c_Sim->Scale(factor / hist4c_Sim->GetEntries());
  hist4c_Sim->SetLineColor(kBlack);
  hist4c_Sim->SetFillStyle(0);
  hist4c_Data->Scale(factor / hist4c_Data->GetEntries());
  hist4c_Data->SetLineColor(kRed);
  hist4c_Data->SetFillColor(kRed - 9);
  hist4c_Data->SetFillStyle(3004);

  if (hist4c_Sim->GetMaximum() > hist4c_Data->GetMaximum())
  {
    hist4c_Sim->Draw("HIST");
    hist4c_Data->Draw("HIST,SAME");
  }
  else
  {
    hist4c_Data->Draw("HIST");
    hist4c_Sim->Draw("HIST,SAME");
  }

  // input->Close();
  TString in = Folder + "Exploration/Data_vs_MC_";

  c1->Print(in + Form("_k=%i_BDT=%f_entries=%f", k, BDTCut[k], hist2c_Data->GetEntries()) + extension);

  delete pDVCS_Data;
  delete pDVCS_Sim;
  delete hist1c_Sim;
  delete hist1c_Data;
  delete hist2c_Sim;
  delete hist2c_Data;
  delete hist3c_Sim;
  delete hist3c_Data;
  delete hist4c_Sim;
  delete hist4c_Data;
  delete c1;

  input2->Close();
  input3->Close();

  delete input2;
  delete input3;
}
