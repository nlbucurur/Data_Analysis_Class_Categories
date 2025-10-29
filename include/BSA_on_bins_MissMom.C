// #include "../BDT.h"
#include "TCanvas.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TLegend.h"
#include "TLatex.h"

void BDT::BSA_on_bins_MissMom()
{
    TString filename = "/home/lorena/Documents/Thesis/Data_Analysis_Class/Analysis/Data_NP_Theta_g_5.root";
    TFile *file = TFile::Open(filename);

    TTree *tree = (TTree *)file->Get("pDVCS");
    

    double Nphi_plus, Nphi_minus, BSA, BSA_err;
    std::vector<double> bsa_values, bsa_errors, bin_centers;

    for (int bin = 0; bin < 448; bin++) {

        TString cut_plus = TString::Format("(%s) && (_Helicity == 1)", Mbins_missMom[bin].GetTitle());
        TString cut_minus = TString::Format("(%s) && (_Helicity == -1)", Mbins_missMom[bin].GetTitle());

        Nphi_plus = tree->GetEntries(cut_plus);
        Nphi_minus = tree->GetEntries(cut_minus);

        if ((Nphi_plus + Nphi_minus) > 0) {
            BSA = (1.0 / Bpol) * (Nphi_plus - Nphi_minus) / (Nphi_plus + Nphi_minus);
            BSA_err = (1.0 / Bpol) * 2.0 * sqrt(Nphi_plus * Nphi_minus * (Nphi_plus + Nphi_minus)) / ((Nphi_plus + Nphi_minus) * (Nphi_plus + Nphi_minus));
        } else {
            BSA = 0.0;
            BSA_err = 0.0;
        }

        double bin_center = (bins_missMom[bin][6] + bins_missMom[bin][7]) / 2.0;

        bsa_values.push_back(BSA);
        bsa_errors.push_back(BSA_err);
        bin_centers.push_back(bin_center);
    }

    TCanvas *c1 = new TCanvas("c1", "BSA in bins of Miss Mom", 800, 600);

    int nBins = bin_centers.size();
    TGraphErrors *gBSA = new TGraphErrors(nBins, &bin_centers[0], &bsa_values[0], 0, &bsa_errors[0]);

    gBSA->SetTitle("BSA vs Missing Momentum");
    gBSA->GetXaxis()->SetTitle("Missing Momentum [GeV]");
    gBSA->GetYaxis()->SetTitle("BSA");
    gBSA->SetMarkerStyle(20);
    gBSA->SetMarkerSize(1.0);
    gBSA->Draw("AP");

    TF1 *fit = new TF1("fit", "[0]*sin(x)", 0, 2 * TMath::Pi());
    fit->SetParameter(0, 0.2);
    gBSA->Fit(fit, "R");

    c1->SaveAs("Analysis/BSA_on_bins_MissMom.pdf");
}
