
TH1 *BDT::Single_BSA(TString Data, int P_bins = 12)
{
  TChain *ch1 = new TChain("pDVCS");
  ch1->Add(Folder + Data);

  const int NPbins = 6;
  double bins[NPbins + 1] = {0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 1.0};

  double meanQ;
  double meant;
  double meanx;

  TF1 *fit;

  TCanvas *c1 = new TCanvas("c1", "Histograms", 1000, 800);

  c1->SetLeftMargin(0.15);
  c1->SetRightMargin(0.05);
  c1->SetTopMargin(0.08);
  c1->SetBottomMargin(0.13);

  gStyle->SetOptStat(0);
  c1->SetGrid();
  c1->SetFillColor(0);

  TCut cut_p = TCut("_bestCandidateFlag==1 && _Helicity>0");
  TCut cut_m = TCut("_bestCandidateFlag==1 && _Helicity<0");

  //--------------------------------------
  // Get Means

  TCut cutM = TCut("_bestCandidateFlag==1");

  TH1F *tmean = new TH1F("tmean", "t_temp", 100, 0, 0);
  ch1->Project("tmean", "_t_Ph", cutM);
  meant = tmean->GetMean();

  TH1F *Qmean = new TH1F("Qmean", "Q_temp", 100, 0, 0);
  ch1->Project("Qmean", "_strip_Q2", cutM);
  meanQ = Qmean->GetMean();

  TH1F *xmean = new TH1F("xmean", "x_temp", 100, 0, 0);
  ch1->Project("xmean", "_strip_Xbj", cutM);
  meanx = xmean->GetMean();

  TH1F *histp = new TH1F("histp", "1dgraph", P_bins, 0, 360);
  TH1F *histm = new TH1F("histm", "1dgraph", P_bins, 0, 360);
  histp->Sumw2();
  histm->Sumw2();

  ch1->Project("histp", "_Phi_Nuc", cut_p);
  ch1->Project("histm", "_Phi_Nuc", cut_m);

  TH1 *BA = histm->GetAsymmetry(histp);
  BA->Scale(1.0 / Bpol);

  // BA->SetTitle(Form("#splitline{%.3f<t<%.3f , %.3f<Q^{2}<%.3f , %.3f<x_{B}<%.3f}{#splitline{BDT_bef %.3f, BDT_aft %.3f}{ #splitline{#frac{1#gamma}{2#gamma}_bef ratio %.3f,  #frac{1#gamma}{2#gamma}_aft ratio %.3f}{Maxime_bef=%.3f, Maxime_aft=%.3f}}}", boundaries.at(0), boundaries.at(1), boundaries.at(2), boundaries.at(3), boundaries.at(4), boundaries.at(5), boundaries.at(6), boundaries.at(7), boundaries.at(8), boundaries.at(9), boundaries.at(10), boundaries.at(11)));

  delete tmean;
  delete Qmean;
  delete xmean;
  //----------------------------------------
  // The fit gets attached to BA, so if BA is deleted, everything is deleted
  // That is why I plot a new "fit" function
  TF1 *fitf = new TF1("fitf", "[0]*sin(x*TMath::Pi()/180)/(1+[1]*cos(x*TMath::Pi()/180))", 0, 360);
  fitf->SetParameter(0, 0.1);    // Initial guess for A
  fitf->SetParameter(1, -0.3);   // Initial guess for α
  fitf->SetParLimits(0, 0, 0.3); // A constrained to [0, 0.3]
  fitf->SetParLimits(1, -1, 1);  // α constrained to [-1, 1]
  fitf->SetLineWidth(3);
  fitf->SetLineColor(kBlue + 1);

  BA->Fit("fitf", "Q");
  BA->SetLineColor(kBlack);
  BA->SetMarkerColor(kBlack);
  BA->SetMarkerStyle(20);
  BA->SetMarkerSize(1.5);
  BA->SetLineWidth(2);
  BA->SetAxisRange(-0.1, 0.1, "Y");
  BA->SetAxisRange(0., 360., "X");
  BA->GetXaxis()->SetTitle("#phi(deg)");
  BA->GetYaxis()->SetTitle("Beam Spin Asymmetry (BSA)");


  // BA->GetXaxis()->SetTitleSize(0.06);
  // BA->GetYaxis()->SetTitleSize(0.06);
  // BA->GetXaxis()->SetLabelSize(0.045);
  // BA->GetYaxis()->SetLabelSize(0.045);
  // BA->GetYaxis()->SetTitleOffset(0.5);
  // BA->GetXaxis()->SetTitleOffset(0.5);

  BA->SetTitle("");
  BA->GetYaxis()->SetNdivisions(4);
  BA->GetXaxis()->SetNdivisions(4);

  BA->DrawClone();

  BA->DrawClone();
  fitf->Draw("same"); // ensure the fit line is visible

  TLegend *leg = new TLegend(0.20, 0.20, 0.50, 0.33);
  leg->AddEntry(BA, "BSA Data", "p");
  leg->AddEntry(fitf, "Fit: #frac{A sin(#phi)}{(1+#alpha cos(#phi))}", "l");
  leg->SetBorderSize(0);
  leg->SetTextSize(0.04);
  leg->Draw();

  BSA_Amplitude = BA->GetBinContent(BA->GetMaximumBin());
  BSA_Amplitude_fit = fitf->GetParameter(0);
  std::cout << "Final amplitudes: value - fit " << BSA_Amplitude << " " << BSA_Amplitude_fit << endl;

  // Display means
  TLatex *box = new TLatex();
  box->SetNDC(kTRUE);
  box->SetTextSize(0.04);
  box->SetTextFont(42); // Use plain font

  // Kinematics means
  box->DrawLatex(0.73, 0.84, Form("#LT t  #GT  =%.3f", meant));
  box->DrawLatex(0.73, 0.78, Form("#LT Q^{2} #GT  = %.3f", meanQ));
  box->DrawLatex(0.73, 0.72, Form("#LT x_{B} #GT   = %.3f", meanx));

  // Amplitudes
  box->DrawLatex(0.73, 0.66, Form("A_{LU}^{Cal}       = %.3f", BSA_Amplitude));
  box->DrawLatex(0.73, 0.60, Form("A_{LU}^{fit}        = %.3f", BSA_Amplitude_fit));

  // auto *g = new TGraph(Form("Triple%i/Triple%i.txt",k+1,NBINS_Q*l + m+1));
  // g->DrawClone("SAME");

  // c1->Print(Folder + "BSA.png");
  c1->Print(Folder + "BSA.png", "png 150");
  delete histp;
  delete histm;
  delete ch1;
  delete c1;

  return BA;
}
