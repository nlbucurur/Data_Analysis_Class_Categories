void BDT::BSA_on_bins_MissMom() {
    TFile *file = new TFile("/home/lorena/Documents/Thesis/Data_Analysis_Class/Analysis/Data_NP_Theta_g_5.root");
    TTree *tree = (TTree*) file->Get("pDVCS");

    gROOT->ProcessLine(".L Single_BSA.C+");

    for (int i = 0; i < 112; ++i) { // Use 112 or as many bins as you want to process
        TString binName = Form("MissMom_bin_%d", i);
        TString saveName = Form("Analysis1/BSA_Fit_MissMom_bin_%d.pdf", i);

        Single_BSA(TString("Data_NP_Theta_g_5.root"), Mbins_missMom[i], saveName);
        cout << "Processed bin: " << i << endl;
    }
}