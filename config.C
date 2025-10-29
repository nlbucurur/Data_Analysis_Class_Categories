void BDT::config()
{
	Nbins = 64;
	categories = true;
	// Working directory
	dir = "/home/lorena/Documents/Thesis/Data_Analysis_Class/data/";
	// External BSA from analysis note -> To compare with a previous analysis
	extBSA = "/work/clas12/jsalvg/pass2_RGA-Analysis/Maxime_BSA/";
	// External xsec from analysis note -> To compare with a previous analysis
	extXSEC = "/work/clas12/jsalvg/pass2_RGA-Analysis/inb/P/Theory_xsec/";
	// Folder to store the results
	Folder = "/home/lorena/Documents/Thesis/Data_Analysis_Class/Analysis/";
	gSystem->Exec(TString("mkdir -p ") + Folder);

	// Compute Q2, t and xB on each phi bin ?
	means_most = false;
	means_maxi = false;

	// To generate the contamination files.
	// Only one of these can be set to true.
	// Thus, you need to run the script 3 times before being able to get any physics results
	generate = false;	// Generate pi0 decays
	recast = false;		// Recombine 1-gamma pi0 events into files for each bin
	add_BDT_Max = true; // Add BDT variable to the contamination files.

	// Estimate contamination from method 1 ? It is not needed to be computed everytime
	generate_most = true;

	// Compute cross-section?
	xsection = false;

	// Data samples for training and experimental data
	//  DVCS="/lustre24/expphy/volatile/clas12/jsalvg/simulation/dvcsgen/inb/withRC/Quality_DVCS_Train.root";
	DVCS = "/home/lorena/Documents/Thesis/Data_Analysis_Class/data/1pDVCS_simulation.root";
	// Pi0 ="/lustre24/expphy/volatile/clas12/jsalvg/simulation/aaogen/P/inb/train/Quality_Pi_as_DVCS_Train.root";
	Pi0 = "/home/lorena/Documents/Thesis/Data_Analysis_Class/data/0pDVCS_Pi0dataAsDVCS_10p2.root";
	// Pi0 ="/work/clas12/jsalvg/RGA-Simulation/pass2_inb/Pi0/Quality_Pi_as_DVCS_Train.root";
	//  Data="/work/clas12/jsalvg/Data/DVCS/pass2_RGA/inb/Quality2_Data_P.root"; //Original, keep after testing //gcorrected
	Data = "/home/lorena/Documents/Thesis/Data_Analysis_Class/data/0pDVCS_inbending_FTPhotonsCorrected_test.root"; // Original, keep after testing //gcorrected
	TData = "Tested_Quality_Data.root";
	TDVCS = "Tested_DVCS.root";
	TPi0 = "Tested_Pi0.root";

	// For eta Background estimation
	epeta = "/work/clas12/jsalvg/Data/eta/pass2_RGA/inb/Quality_Data_epeta_P.root";
	sim_eta_as_dvcs = "/lustre24/expphy/volatile/clas12/jsalvg/simulation/eta/inb/P/1gamma/Quality_1gamma_eta.root";
	sim_epeta = "/lustre24/expphy/volatile/clas12/jsalvg/simulation/eta/inb/P/2gamma/Quality_Sim_epeta_P.root";

	// For Pi0 Background subtraction
	eppi0_name = "Quality_Data_eppi0_P.root";
	eppi0 = "/work/clas12/jsalvg/Data/DVMP/pass2_RGA/inb/P/" + eppi0_name;
	maps_path = "../../maps/";
	sim_eppi0 = "/lustre24/expphy/volatile/clas12/jsalvg/simulation/aaogen/P/inb/bkg_sub/2gamma/Quality_Sim_eppi0_P.root";
	sim_eppi0_1 = "/lustre24/expphy/volatile/clas12/jsalvg/simulation/aaogen/P/inb/bkg_sub/2gamma/Quality_Sim_eppi0_P.root";
	sim_pi_as_dvcs = "/lustre24/expphy/volatile/clas12/jsalvg/simulation/aaogen/P/inb/bkg_sub/1gamma/Quality_Pi_as_DVCS_P_1.root";
	sim_pi_as_dvcs_1 = "/lustre24/expphy/volatile/clas12/jsalvg/simulation/aaogen/P/inb/bkg_sub/1gamma/Quality_Pi_as_DVCS_P_1.root";

	// RC effects dvcs sample
	RC_Sim = DVCS;
	// RC_Sim="/volatile/clas12/jsalvg/simulation/dvcsgen/inb/Quality_BM_DVCS.root";
	TRC_Sim = "Tested_BM_Sim.root";
	// The MC version of the RC sample
	//  MC_RC_Sim="/volatile/clas12/jsalvg/simulation/dvcsgen/inb/MCgen/Quality_MC_DVCS.root";
	MC_RC_Sim = "/home/lorena/Documents/Thesis/Data_Analysis_Class/data/1pDVCS_simulation.root";

	// Acc and BM corrections. Need a dvcs sample with RC effects.
	// RC_can be used if it has enough statistics in all bins.
	BM_Sim = DVCS;
	// BM_Sim="/volatile/clas12/jsalvg/simulation/dvcsgen/inb/Quality_BM_DVCS.root";
	TBM_Sim = "Tested_BM_Sim.root";
	// The MC version of the BM sample
	MC_BM_Sim = "/volatile/clas12/jsalvg/simulation/dvcsgen/inb/MCgen/Quality_MC_DVCS.root";

	// Direct output from dvcsgen to compute the RC correction factor
	MC_DVCS_RC = "/work/clas12/jsalvg/RGA-Simulation/dvcsgen_RC_gen.root";

	// Directory to temporaly store the contamination files from method 2
	Maxime_bkg = "/lustre24/expphy/volatile/clas12/jsalvg/DVCS_analysis/inb/P/";

	// Basic selection/exclusivity cuts
	// cut = "_bestCandidateFlag==1 && \
    // _strip_Xbj <1 && _strip_Xbj >0 && _t_Ph <0 && _strip_Q2 > 1.0 && \
    // _strip_W > 2 && _strip_El_P > 1.0 && _strip_Ph_P>2  && _strip_El_vz < 10 && _strip_El_vz > -12 && \
    // _theta_gamma_e > 5 && abs(_delta_t)<2 && abs(_delta_Phi)%180 < 2 && TMath::Sqrt(_Xbal * _Xbal + _Ybal*_Ybal + _Zbal*_Zbal) <1";
	// // _theta_gamma_e > 5 && abs(_delta_t)<2 && abs(_delta_Phi)%180 < 2 && TMath::Sqrt(_Xbal * _Xbal + _Ybal*_Ybal + _Zbal*_Zbal) <1 && abs(mm2_ep)<0.5";

	cut = "_bestCandidateFlag==1"
		  " && _theta_gamma_e > 6"
		  " && _strip_Xbj < 0.6"
		  " && _strip_Xbj > 0"
		  " && _t_Ph < 0"
		  " && _strip_Q2 > 1.0"
		  " && _strip_W > 2"
		  " && _strip_El_P > 1.0"
		  " && _strip_Ph_P > 2"
		  " && _strip_El_vz < 10"
		  " && _strip_El_vz > -12"
		  " && _theta_gamma_e > 5"
		  " && TMath::Sqrt(_Xbal * _Xbal + _Ybal * _Ybal + _Zbal * _Zbal) < 1"
		  " && _strip_El_chi2pid >= -4.56920"
		  " && _strip_El_chi2pid <= 3.61976"
		  " && _strip_Nuc_chi2pid >= -195.04711"
		  " && _strip_Nuc_chi2pid <= 201.30658"
		  " && _delta_t >= -0.46292"
		  " && _delta_t <= 0.47175"
		  " && abs(fmod(_delta_Phi, 180)) <= 1.5"
		  " && _mm2_eNg >= -0.37894"
		  " && _mm2_eNg <= 2.42267"
		  " && _mm2_eNg_N >= -0.19478"
		  " && _mm2_eNg_N <= 0.15635"
		  " && _mm2_eNX_N >= -3.95236"
		  " && _mm2_eNX_N <= 3.74568"
		  " && _mm2_eg >= -0.12854"
		  " && _mm2_eg <= 2.21362";

	// Cut to estimate systematic error due to cuts
	cut_sys = "_bestCandidateFlag==1 &&\
_strip_Xbj <1 && _strip_Xbj >0 && _t_Ph <0 && _strip_Q2 > 1.0 && \
_strip_W > 2 && _strip_El_P > 1.0 && _strip_Ph_P>2  && _strip_El_vz < 10 && _strip_El_vz > -12 && \
_theta_gamma_e > 5 && abs(_delta_t)<1.5 && abs(_delta_Phi)%180 < 1.5 && TMath::Sqrt(_Xbal * _Xbal + _Ybal*_Ybal + _Zbal*_Zbal) <0.8";

	// Cut to estimate systematic error due pid selection
	cut_pid = "_strip_El_vz > -8 && _strip_El_vz<5 && \
    strip_Nuc_vz > -8 && strip_Nuc_vz<5 && \
    strip_Ph_beta>0.9 && strip_Ph_beta<1.1 && \
    (_strip_El_P<4.5 || (_strip_El_P>4.5 && strip_El_ECin_energy/_strip_El_P > 0.2 - strip_El_PCAL_energy/_strip_El_P))";
	//cut_pid="abs(strip_El_chi2pid)<3 && _strip_El_vz > -8 && _strip_El_vz<5 && \
    abs(strip_Nuc_chi2pid)<3 && strip_Nuc_vz > -8 && strip_Nuc_vz<5 && \
    strip_Ph_beta>0.9 && strip_Ph_beta<1.1 && \
    (_strip_El_P<4.5 || (_strip_El_P>4.5 && strip_El_ECin_energy/_strip_El_P > 0.2 - strip_El_PCAL_energy/_strip_El_P))";

	// Refinemnet cuts, if needed after BDT classification.
	// cut_ref="_delta_t<0.1 && miss_mom_eNg<0.4 && theta_gamma_X < 0.6";
	// cut_ref="bestCandidateFlag==1 && theta_gamma_X<1.0";
	cut_ref = "_bestCandidateFlag==1";

	// Training variables
	Vars.push_back(TString("_mm2_eNg"));
	Vars.push_back(TString("_mm2_eg"));
	Vars.push_back(TString("_delta_Phi"));
	Vars.push_back(TString("_delta_t"));
	Vars.push_back(TString("_theta_gamma_X"));
	Vars.push_back(TString("_strip_Ph_P"));
	Vars.push_back(TString("_strip_El_P"));
	Vars.push_back(TString("_strip_Nuc_P"));

	// Beam polarization
	Bpol = 0.86;
	// BDT cut
	BDT_value = 0.0;
	// BDT cut for systematic error
	BDT_value_sys = 0.04;

	beam->SetXYZT(0.0, 0.0, 10.6, 10.6);
	target->SetXYZT(0.0, 0.0, 0.0, 1.8756);

	//|t|>|tmin| cut. It is good to have it coded
	//(_t_Ph<-(_strip_Q2*0.938 + (_strip_Q2/_strip_Xbj)*( (_strip_Q2/(2*0.938*_strip_Xbj)) - sqrt(_strip_Q2 + pow((_strip_Q2/(2*0.938*_strip_Xbj)),2))))/(0.938 + (_strip_Q2/(2*0.938*_strip_Xbj)) - sqrt(_strip_Q2 + pow((_strip_Q2/(2*0.938*_strip_Xbj)),2))))

	Mbins[0] = TCut("_bestCandidateFlag==1 && _t_Ph<0.0    && _t_Ph>-0.2 && _strip_Q2 > 1 && _strip_Q2 < 1.4 && _strip_Xbj > 0    && _strip_Xbj < 0.13");
	Mbins[1] = TCut("_bestCandidateFlag==1 && _t_Ph<0.0    && _t_Ph>-0.2 && _strip_Q2 > 1 && _strip_Q2 < 1.4 && _strip_Xbj > 0.13 && _strip_Xbj < 0.21");
	Mbins[2] = TCut("_bestCandidateFlag==1 && _t_Ph<0.0    && _t_Ph>-0.2 && _strip_Q2 > 1 && _strip_Q2 < 1.4 && _strip_Xbj > 0.21 && _strip_Xbj < 1.0 ");
	Mbins[3] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.2 && _t_Ph>-0.4 && _strip_Q2 > 1 && _strip_Q2 < 1.4 && _strip_Xbj > 0    && _strip_Xbj < 0.13");
	Mbins[4] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.2 && _t_Ph>-0.4 && _strip_Q2 > 1 && _strip_Q2 < 1.4 && _strip_Xbj > 0.13 && _strip_Xbj < 0.21");
	Mbins[5] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.2 && _t_Ph>-0.4 && _strip_Q2 > 1 && _strip_Q2 < 1.4 && _strip_Xbj > 0.21 && _strip_Xbj < 1.0 ");
	Mbins[6] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.4 && _t_Ph>-0.8 && _strip_Q2 > 1 && _strip_Q2 < 1.4 && _strip_Xbj > 0    && _strip_Xbj < 0.13");
	Mbins[7] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.4 && _t_Ph>-0.8 && _strip_Q2 > 1 && _strip_Q2 < 1.4 && _strip_Xbj > 0.13 && _strip_Xbj < 0.21");
	Mbins[8] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.4 && _t_Ph>-0.8 && _strip_Q2 > 1 && _strip_Q2 < 1.4 && _strip_Xbj > 0.21 && _strip_Xbj < 1.0 ");
	Mbins[9] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.8 && _t_Ph>-100 && _strip_Q2 > 1 && _strip_Q2 < 1.4 && _strip_Xbj > 0    && _strip_Xbj < 0.13");
	Mbins[10] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.8 && _t_Ph>-100 && _strip_Q2 > 1 && _strip_Q2 < 1.4 && _strip_Xbj > 0.13 && _strip_Xbj < 0.21");
	Mbins[11] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.8 && _t_Ph>-100 && _strip_Q2 > 1 && _strip_Q2 < 1.4 && _strip_Xbj > 0.21 && _strip_Xbj < 1.0 ");

	Mbins[12] = TCut("_bestCandidateFlag==1 && _t_Ph<0.0    && _t_Ph>-0.2 && _strip_Q2 > 1.4 && _strip_Q2 < 1.8 && _strip_Xbj > 0    && _strip_Xbj < 0.13");
	Mbins[13] = TCut("_bestCandidateFlag==1 && _t_Ph<0.0    && _t_Ph>-0.2 && _strip_Q2 > 1.4 && _strip_Q2 < 1.8 && _strip_Xbj > 0.13 && _strip_Xbj < 0.21");
	Mbins[14] = TCut("_bestCandidateFlag==1 && _t_Ph<0.0    && _t_Ph>-0.2 && _strip_Q2 > 1.4 && _strip_Q2 < 1.8 && _strip_Xbj > 0.21 && _strip_Xbj < 1.0 ");
	Mbins[15] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.2 && _t_Ph>-0.4 && _strip_Q2 > 1.4 && _strip_Q2 < 1.8 && _strip_Xbj > 0    && _strip_Xbj < 0.13");
	Mbins[16] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.2 && _t_Ph>-0.4 && _strip_Q2 > 1.4 && _strip_Q2 < 1.8 && _strip_Xbj > 0.13 && _strip_Xbj < 0.21");
	Mbins[17] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.2 && _t_Ph>-0.4 && _strip_Q2 > 1.4 && _strip_Q2 < 1.8 && _strip_Xbj > 0.21 && _strip_Xbj < 1.0 ");
	Mbins[18] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.4 && _t_Ph>-0.8 && _strip_Q2 > 1.4 && _strip_Q2 < 1.8 && _strip_Xbj > 0    && _strip_Xbj < 0.13");
	Mbins[19] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.4 && _t_Ph>-0.8 && _strip_Q2 > 1.4 && _strip_Q2 < 1.8 && _strip_Xbj > 0.13 && _strip_Xbj < 0.21");
	Mbins[20] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.4 && _t_Ph>-0.8 && _strip_Q2 > 1.4 && _strip_Q2 < 1.8 && _strip_Xbj > 0.21 && _strip_Xbj < 1.0 ");
	Mbins[21] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.8 && _t_Ph>-100 && _strip_Q2 > 1.4 && _strip_Q2 < 1.8 && _strip_Xbj > 0    && _strip_Xbj < 0.13");
	Mbins[22] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.8 && _t_Ph>-100 && _strip_Q2 > 1.4 && _strip_Q2 < 1.8 && _strip_Xbj > 0.13 && _strip_Xbj < 0.21");
	Mbins[23] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.8 && _t_Ph>-100 && _strip_Q2 > 1.4 && _strip_Q2 < 1.8 && _strip_Xbj > 0.21 && _strip_Xbj < 1.0 ");

	Mbins[24] = TCut("_bestCandidateFlag==1 && _t_Ph<0.0    && _t_Ph>-0.2 && _strip_Q2 > 1.8 && _strip_Q2 < 2.4 && _strip_Xbj > 0    && _strip_Xbj < 0.16");
	Mbins[25] = TCut("_bestCandidateFlag==1 && _t_Ph<0.0    && _t_Ph>-0.2 && _strip_Q2 > 1.8 && _strip_Q2 < 2.4 && _strip_Xbj > 0.16 && _strip_Xbj < 0.26");
	Mbins[26] = TCut("_bestCandidateFlag==1 && _t_Ph<0.0    && _t_Ph>-0.2 && _strip_Q2 > 1.8 && _strip_Q2 < 2.4 && _strip_Xbj > 0.26 && _strip_Xbj < 1.0 ");
	Mbins[27] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.2 && _t_Ph>-0.4 && _strip_Q2 > 1.8 && _strip_Q2 < 2.4 && _strip_Xbj > 0    && _strip_Xbj < 0.16");
	Mbins[28] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.2 && _t_Ph>-0.4 && _strip_Q2 > 1.8 && _strip_Q2 < 2.4 && _strip_Xbj > 0.16 && _strip_Xbj < 0.26");
	Mbins[29] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.2 && _t_Ph>-0.4 && _strip_Q2 > 1.8 && _strip_Q2 < 2.4 && _strip_Xbj > 0.26 && _strip_Xbj < 1.0 ");
	Mbins[30] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.4 && _t_Ph>-0.8 && _strip_Q2 > 1.8 && _strip_Q2 < 2.4 && _strip_Xbj > 0    && _strip_Xbj < 0.16");
	Mbins[31] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.4 && _t_Ph>-0.8 && _strip_Q2 > 1.8 && _strip_Q2 < 2.4 && _strip_Xbj > 0.16 && _strip_Xbj < 0.26");
	Mbins[32] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.4 && _t_Ph>-0.8 && _strip_Q2 > 1.8 && _strip_Q2 < 2.4 && _strip_Xbj > 0.26 && _strip_Xbj < 1.0 ");
	Mbins[33] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.8 && _t_Ph>-100 && _strip_Q2 > 1.8 && _strip_Q2 < 2.4 && _strip_Xbj > 0    && _strip_Xbj < 0.16");
	Mbins[34] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.8 && _t_Ph>-100 && _strip_Q2 > 1.8 && _strip_Q2 < 2.4 && _strip_Xbj > 0.16 && _strip_Xbj < 0.26");
	Mbins[35] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.8 && _t_Ph>-100 && _strip_Q2 > 1.8 && _strip_Q2 < 2.4 && _strip_Xbj > 0.26 && _strip_Xbj < 1.0 ");

	Mbins[36] = TCut("_bestCandidateFlag==1 && _t_Ph<0.0    && _t_Ph>-0.2 && _strip_Q2 > 2.4 && _strip_Q2 < 3.25 && _strip_Xbj > 0    && _strip_Xbj < 0.21");
	Mbins[37] = TCut("_bestCandidateFlag==1 && _t_Ph<0.0    && _t_Ph>-0.2 && _strip_Q2 > 2.4 && _strip_Q2 < 3.25 && _strip_Xbj > 0.21 && _strip_Xbj < 0.33");
	Mbins[38] = TCut("_bestCandidateFlag==1 && _t_Ph<0.0    && _t_Ph>-0.2 && _strip_Q2 > 2.4 && _strip_Q2 < 3.25 && _strip_Xbj > 0.33 && _strip_Xbj < 1.0 ");
	Mbins[39] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.2 && _t_Ph>-0.4 && _strip_Q2 > 2.4 && _strip_Q2 < 3.25 && _strip_Xbj > 0    && _strip_Xbj < 0.21");
	Mbins[40] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.2 && _t_Ph>-0.4 && _strip_Q2 > 2.4 && _strip_Q2 < 3.25 && _strip_Xbj > 0.21 && _strip_Xbj < 0.33");
	Mbins[41] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.2 && _t_Ph>-0.4 && _strip_Q2 > 2.4 && _strip_Q2 < 3.25 && _strip_Xbj > 0.33 && _strip_Xbj < 1.0 ");
	Mbins[42] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.4 && _t_Ph>-0.8 && _strip_Q2 > 2.4 && _strip_Q2 < 3.25 && _strip_Xbj > 0    && _strip_Xbj < 0.21");
	Mbins[43] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.4 && _t_Ph>-0.8 && _strip_Q2 > 2.4 && _strip_Q2 < 3.25 && _strip_Xbj > 0.21 && _strip_Xbj < 0.33");
	Mbins[44] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.4 && _t_Ph>-0.8 && _strip_Q2 > 2.4 && _strip_Q2 < 3.25 && _strip_Xbj > 0.33 && _strip_Xbj < 1.0 ");
	Mbins[45] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.8 && _t_Ph>-100 && _strip_Q2 > 2.4 && _strip_Q2 < 3.25 && _strip_Xbj > 0    && _strip_Xbj < 0.21");
	Mbins[46] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.8 && _t_Ph>-100 && _strip_Q2 > 2.4 && _strip_Q2 < 3.25 && _strip_Xbj > 0.21 && _strip_Xbj < 0.33");
	Mbins[47] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.8 && _t_Ph>-100 && _strip_Q2 > 2.4 && _strip_Q2 < 3.25 && _strip_Xbj > 0.33 && _strip_Xbj < 1.0 ");

	Mbins[48] = TCut("_bestCandidateFlag==1 && _t_Ph<0.0    && _t_Ph>-0.2 && _strip_Q2 > 3.25 && _strip_Q2 < 5.0 && _strip_Xbj > 0    && _strip_Xbj < 0.33");
	Mbins[49] = TCut("_bestCandidateFlag==1 && _t_Ph<0.0    && _t_Ph>-0.2 && _strip_Q2 > 3.25 && _strip_Q2 < 5.0 && _strip_Xbj > 0.33 && _strip_Xbj < 1.0 ");
	Mbins[50] = TCut("_bestCandidateFlag==1 && _t_Ph<0.0  && _t_Ph>-0.4 && _strip_Q2 > 3.25 && _strip_Q2 < 5.0 && _strip_Xbj > 0    && _strip_Xbj < 0.33 ");
	Mbins[51] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.2 && _t_Ph>-0.4 && _strip_Q2 > 3.25 && _strip_Q2 < 5.0 && _strip_Xbj > 0.33 && _strip_Xbj < 1.0  ");
	Mbins[52] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.4 && _t_Ph>-0.8 && _strip_Q2 > 3.25 && _strip_Q2 < 5.0 && _strip_Xbj > 0.   && _strip_Xbj < 0.33");
	Mbins[53] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.4 && _t_Ph>-0.8 && _strip_Q2 > 3.25 && _strip_Q2 < 5.0 && _strip_Xbj > 0.33 && _strip_Xbj < 1.0 ");
	Mbins[54] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.8 && _t_Ph>-100 && _strip_Q2 > 3.25 && _strip_Q2 < 5.0 && _strip_Xbj > 0    && _strip_Xbj < 0.33");
	Mbins[55] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.8 && _t_Ph>-100 && _strip_Q2 > 3.25 && _strip_Q2 < 5.0 && _strip_Xbj > 0.33 && _strip_Xbj < 1.0 ");

	Mbins[56] = TCut("_bestCandidateFlag==1 && _t_Ph<0.0 && _t_Ph>-0.2 && _strip_Q2 > 5.0 && _strip_Q2 < 15.0 && _strip_Xbj > 0    && _strip_Xbj < 0.55");
	Mbins[57] = TCut("_bestCandidateFlag==1 && _t_Ph<0.0 && _t_Ph>-0.2 && _strip_Q2 > 5.0 && _strip_Q2 < 15.0 && _strip_Xbj > 0.55 && _strip_Xbj < 1.0 ");
	Mbins[58] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.2 && _t_Ph>-0.4 && _strip_Q2 > 5.0 && _strip_Q2 < 15.0 && _strip_Xbj > 0    && _strip_Xbj < 0.55");
	Mbins[59] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.2 && _t_Ph>-0.4 && _strip_Q2 > 5.0 && _strip_Q2 < 15.0 && _strip_Xbj > 0.55 && _strip_Xbj < 1.0 ");
	Mbins[60] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.4 && _t_Ph>-0.8 && _strip_Q2 > 5.0 && _strip_Q2 < 15.0 && _strip_Xbj > 0    && _strip_Xbj < 0.55");
	Mbins[61] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.4 && _t_Ph>-0.8 && _strip_Q2 > 5.0 && _strip_Q2 < 15.0 && _strip_Xbj > 0.55 && _strip_Xbj < 1.0 ");
	Mbins[62] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.8 && _t_Ph>-100 && _strip_Q2 > 5.0 && _strip_Q2 < 15.0 && _strip_Xbj > 0    && _strip_Xbj < 0.55");
	Mbins[63] = TCut("_bestCandidateFlag==1 && _t_Ph<-0.8 && _t_Ph>-100 && _strip_Q2 > 5.0 && _strip_Q2 < 15.0 && _strip_Xbj > 0.55 && _strip_Xbj < 1.0 ");

	bins = {{{-0.2, 0, 1, 1.4, 0, 0.13},
			 {-0.2, 0, 1, 1.4, 0.13, 0.21},
			 {-0.2, 0, 1, 1.4, 0.21, 1},
			 {-0.4, -0.2, 1, 1.4, 0, 0.13},
			 {-0.4, -0.2, 1, 1.4, 0.13, 0.21},
			 {-0.4, -0.2, 1, 1.4, 0.21, 1},
			 {-0.8, -0.4, 1, 1.4, 0, 0.13},
			 {-0.8, -0.4, 1, 1.4, 0.13, 0.21},
			 {-0.8, -0.4, 1, 1.4, 0.21, 1},
			 {-100, -0.8, 1, 1.4, 0, 0.13},
			 {-100, -0.8, 1, 1.4, 0.13, 0.21},
			 {-100, -0.8, 1, 1.4, 0.21, 1},
			 {-0.2, 0, 1.4, 1.8, 0, 0.13},
			 {-0.2, 0, 1.4, 1.8, 0.13, 0.21},
			 {-0.2, 0, 1.4, 1.8, 0.21, 1},
			 {-0.4, -0.2, 1.4, 1.8, 0, 0.13},
			 {-0.4, -0.2, 1.4, 1.8, 0.13, 0.21},
			 {-0.4, -0.2, 1.4, 1.8, 0.21, 1},
			 {-0.8, -0.4, 1.4, 1.8, 0, 0.13},
			 {-0.8, -0.4, 1.4, 1.8, 0.13, 0.21},
			 {-0.8, -0.4, 1.4, 1.8, 0.21, 1},
			 {-100, -0.8, 1.4, 1.8, 0, 0.13},
			 {-100, -0.8, 1.4, 1.8, 0.13, 0.21},
			 {-100, -0.8, 1.4, 1.8, 0.21, 1},
			 {-0.2, 0, 1.8, 2.4, 0, 0.16},
			 {-0.2, 0, 1.8, 2.4, 0.16, 0.26},
			 {-0.2, 0, 1.8, 2.4, 0.26, 1},
			 {-0.4, -0.2, 1.8, 2.4, 0, 0.16},
			 {-0.4, -0.2, 1.8, 2.4, 0.16, 0.26},
			 {-0.4, -0.2, 1.8, 2.4, 0.26, 1},
			 {-0.8, -0.4, 1.8, 2.4, 0, 0.16},
			 {-0.8, -0.4, 1.8, 2.4, 0.16, 0.26},
			 {-0.8, -0.4, 1.8, 2.4, 0.26, 1},
			 {-100, -0.8, 1.8, 2.4, 0, 0.16},
			 {-100, -0.8, 1.8, 2.4, 0.16, 0.26},
			 {-100, -0.8, 1.8, 2.4, 0.26, 1},
			 {-0.2, 0, 2.4, 3.25, 0, 0.21},
			 {-0.2, 0, 2.4, 3.25, 0.21, 0.33},
			 {-0.2, 0, 2.4, 3.25, 0.33, 1},
			 {-0.4, -0.2, 2.4, 3.25, 0, 0.21},
			 {-0.4, -0.2, 2.4, 3.25, 0.21, 0.33},
			 {-0.4, -0.2, 2.4, 3.25, 0.33, 1},
			 {-0.8, -0.4, 2.4, 3.25, 0, 0.21},
			 {-0.8, -0.4, 2.4, 3.25, 0.21, 0.33},
			 {-0.8, -0.4, 2.4, 3.25, 0.33, 1},
			 {-100, -0.8, 2.4, 3.25, 0, 0.21},
			 {-100, -0.8, 2.4, 3.25, 0.21, 0.33},
			 {-100, -0.8, 2.4, 3.25, 0.33, 1},
			 {-0.2, 0, 3.25, 5, 0, 0.33},
			 {-0.2, 0, 3.25, 5, 0.33, 1},
			 {-0.4, -0.2, 3.25, 5, 0, 0.33},
			 {-0.4, -0.2, 3.25, 5, 0.33, 1},
			 {-0.8, -0.4, 3.25, 5, 0, 0.33},
			 {-0.8, -0.4, 3.25, 5, 0.33, 1},
			 {-100, -0.8, 3.25, 5, 0, 0.33},
			 {-100, -0.8, 3.25, 5, 0.33, 1},
			 {-0.2, 0, 5, 15, 0, 0.55},
			 {-0.2, 0, 5, 15, 0.55, 1},
			 {-0.4, -0.2, 5, 15, 0, 0.55},
			 {-0.4, -0.2, 5, 15, 0.55, 1},
			 {-0.8, -0.4, 5, 15, 0, 0.55},
			 {-0.8, -0.4, 5, 15, 0.55, 1},
			 {-100, -0.8, 5, 15, 0, 0.55},
			 {-100, -0.8, 5, 15, 0.55, 1}}};
	Nphibins = {
		29,
		22,
		18,
		30,
		23,
		13,
		27,
		26,
		9,
		14,
		12,
		12,
		23,
		24,
		21,
		24,
		23,
		15,
		17,
		22,
		11,
		18,
		14,
		23,
		24,
		25,
		23,
		24,
		28,
		15,
		19,
		27,
		12,
		27,
		17,
		10,
		21,
		21,
		18,
		23,
		25,
		15,
		19,
		22,
		12,
		13,
		16,
		10,
		19,
		19,
		23,
		18,
		21,
		17,
		15,
		13,
		12,
		12,
		13,
		12,
		13,
		12,
		13,
		18};

	Mbins_missMom[0] = Mbins[0] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[1] = Mbins[0] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[2] = Mbins[0] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[3] = Mbins[0] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[4] = Mbins[0] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[5] = Mbins[0] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[6] = Mbins[0] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[7] = Mbins[1] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[8] = Mbins[1] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[9] = Mbins[1] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[10] = Mbins[1] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[11] = Mbins[1] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[12] = Mbins[1] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[13] = Mbins[1] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[14] = Mbins[2] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[15] = Mbins[2] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[16] = Mbins[2] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[17] = Mbins[2] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[18] = Mbins[2] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[19] = Mbins[2] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[20] = Mbins[2] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[21] = Mbins[3] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[22] = Mbins[3] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[23] = Mbins[3] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[24] = Mbins[3] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[25] = Mbins[3] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[26] = Mbins[3] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[27] = Mbins[3] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[28] = Mbins[4] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[29] = Mbins[4] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[30] = Mbins[4] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[31] = Mbins[4] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[32] = Mbins[4] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[33] = Mbins[4] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[34] = Mbins[4] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[35] = Mbins[5] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[36] = Mbins[5] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[37] = Mbins[5] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[38] = Mbins[5] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[39] = Mbins[5] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[40] = Mbins[5] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[41] = Mbins[5] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[42] = Mbins[6] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[43] = Mbins[6] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[44] = Mbins[6] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[45] = Mbins[6] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[46] = Mbins[6] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[47] = Mbins[6] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[48] = Mbins[6] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[49] = Mbins[7] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[50] = Mbins[7] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[51] = Mbins[7] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[52] = Mbins[7] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[53] = Mbins[7] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[54] = Mbins[7] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[55] = Mbins[7] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[56] = Mbins[8] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[57] = Mbins[8] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[58] = Mbins[8] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[59] = Mbins[8] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[60] = Mbins[8] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[61] = Mbins[8] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[62] = Mbins[8] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[63] = Mbins[9] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[64] = Mbins[9] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[65] = Mbins[9] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[66] = Mbins[9] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[67] = Mbins[9] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[68] = Mbins[9] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[69] = Mbins[9] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[70] = Mbins[10] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[71] = Mbins[10] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[72] = Mbins[10] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[73] = Mbins[10] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[74] = Mbins[10] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[75] = Mbins[10] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[76] = Mbins[10] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[77] = Mbins[11] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[78] = Mbins[11] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[79] = Mbins[11] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[80] = Mbins[11] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[81] = Mbins[11] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[82] = Mbins[11] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[83] = Mbins[11] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[84] = Mbins[12] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[85] = Mbins[12] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[86] = Mbins[12] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[87] = Mbins[12] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[88] = Mbins[12] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[89] = Mbins[12] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[90] = Mbins[12] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[91] = Mbins[13] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[92] = Mbins[13] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[93] = Mbins[13] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[94] = Mbins[13] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[95] = Mbins[13] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[96] = Mbins[13] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[97] = Mbins[13] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[98] = Mbins[14] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[99] = Mbins[14] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[100] = Mbins[14] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[101] = Mbins[14] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[102] = Mbins[14] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[103] = Mbins[14] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[104] = Mbins[14] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[105] = Mbins[15] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[106] = Mbins[15] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[107] = Mbins[15] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[108] = Mbins[15] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[109] = Mbins[15] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[110] = Mbins[15] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[111] = Mbins[15] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[112] = Mbins[16] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[113] = Mbins[16] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[114] = Mbins[16] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[115] = Mbins[16] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[116] = Mbins[16] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[117] = Mbins[16] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[118] = Mbins[16] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[119] = Mbins[17] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[120] = Mbins[17] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[121] = Mbins[17] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[122] = Mbins[17] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[123] = Mbins[17] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[124] = Mbins[17] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[125] = Mbins[17] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[126] = Mbins[18] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[127] = Mbins[18] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[128] = Mbins[18] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[129] = Mbins[18] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[130] = Mbins[18] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[131] = Mbins[18] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[132] = Mbins[18] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[133] = Mbins[19] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[134] = Mbins[19] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[135] = Mbins[19] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[136] = Mbins[19] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[137] = Mbins[19] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[138] = Mbins[19] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[139] = Mbins[19] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[140] = Mbins[20] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[141] = Mbins[20] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[142] = Mbins[20] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[143] = Mbins[20] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[144] = Mbins[20] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[145] = Mbins[20] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[146] = Mbins[20] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[147] = Mbins[21] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[148] = Mbins[21] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[149] = Mbins[21] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[150] = Mbins[21] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[151] = Mbins[21] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[152] = Mbins[21] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[153] = Mbins[21] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[154] = Mbins[22] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[155] = Mbins[22] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[156] = Mbins[22] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[157] = Mbins[22] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[158] = Mbins[22] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[159] = Mbins[22] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[160] = Mbins[22] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[161] = Mbins[23] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[162] = Mbins[23] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[163] = Mbins[23] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[164] = Mbins[23] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[165] = Mbins[23] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[166] = Mbins[23] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[167] = Mbins[23] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[168] = Mbins[24] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[169] = Mbins[24] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[170] = Mbins[24] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[171] = Mbins[24] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[172] = Mbins[24] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[173] = Mbins[24] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[174] = Mbins[24] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[175] = Mbins[25] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[176] = Mbins[25] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[177] = Mbins[25] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[178] = Mbins[25] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[179] = Mbins[25] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[180] = Mbins[25] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[181] = Mbins[25] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[182] = Mbins[26] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[183] = Mbins[26] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[184] = Mbins[26] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[185] = Mbins[26] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[186] = Mbins[26] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[187] = Mbins[26] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[188] = Mbins[26] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[189] = Mbins[27] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[190] = Mbins[27] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[191] = Mbins[27] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[192] = Mbins[27] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[193] = Mbins[27] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[194] = Mbins[27] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[195] = Mbins[27] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[196] = Mbins[28] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[197] = Mbins[28] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[198] = Mbins[28] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[199] = Mbins[28] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[200] = Mbins[28] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[201] = Mbins[28] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[202] = Mbins[28] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[203] = Mbins[29] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[204] = Mbins[29] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[205] = Mbins[29] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[206] = Mbins[29] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[207] = Mbins[29] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[208] = Mbins[29] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[209] = Mbins[29] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[210] = Mbins[30] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[211] = Mbins[30] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[212] = Mbins[30] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[213] = Mbins[30] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[214] = Mbins[30] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[215] = Mbins[30] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[216] = Mbins[30] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[217] = Mbins[31] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[218] = Mbins[31] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[219] = Mbins[31] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[220] = Mbins[31] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[221] = Mbins[31] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[222] = Mbins[31] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[223] = Mbins[31] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[224] = Mbins[32] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[225] = Mbins[32] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[226] = Mbins[32] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[227] = Mbins[32] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[228] = Mbins[32] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[229] = Mbins[32] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[230] = Mbins[32] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[231] = Mbins[33] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[232] = Mbins[33] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[233] = Mbins[33] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[234] = Mbins[33] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[235] = Mbins[33] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[236] = Mbins[33] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[237] = Mbins[33] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[238] = Mbins[34] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[239] = Mbins[34] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[240] = Mbins[34] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[241] = Mbins[34] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[242] = Mbins[34] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[243] = Mbins[34] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[244] = Mbins[34] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[245] = Mbins[35] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[246] = Mbins[35] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[247] = Mbins[35] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[248] = Mbins[35] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[249] = Mbins[35] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[250] = Mbins[35] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[251] = Mbins[35] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[252] = Mbins[36] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[253] = Mbins[36] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[254] = Mbins[36] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[255] = Mbins[36] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[256] = Mbins[36] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[257] = Mbins[36] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[258] = Mbins[36] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[259] = Mbins[37] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[260] = Mbins[37] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[261] = Mbins[37] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[262] = Mbins[37] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[263] = Mbins[37] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[264] = Mbins[37] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[265] = Mbins[37] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[266] = Mbins[38] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[267] = Mbins[38] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[268] = Mbins[38] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[269] = Mbins[38] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[270] = Mbins[38] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[271] = Mbins[38] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[272] = Mbins[38] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[273] = Mbins[39] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[274] = Mbins[39] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[275] = Mbins[39] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[276] = Mbins[39] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[277] = Mbins[39] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[278] = Mbins[39] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[279] = Mbins[39] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[280] = Mbins[40] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[281] = Mbins[40] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[282] = Mbins[40] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[283] = Mbins[40] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[284] = Mbins[40] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[285] = Mbins[40] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[286] = Mbins[40] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[287] = Mbins[41] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[288] = Mbins[41] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[289] = Mbins[41] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[290] = Mbins[41] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[291] = Mbins[41] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[292] = Mbins[41] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[293] = Mbins[41] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[294] = Mbins[42] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[295] = Mbins[42] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[296] = Mbins[42] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[297] = Mbins[42] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[298] = Mbins[42] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[299] = Mbins[42] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[300] = Mbins[42] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[301] = Mbins[43] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[302] = Mbins[43] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[303] = Mbins[43] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[304] = Mbins[43] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[305] = Mbins[43] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[306] = Mbins[43] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[307] = Mbins[43] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[308] = Mbins[44] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[309] = Mbins[44] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[310] = Mbins[44] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[311] = Mbins[44] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[312] = Mbins[44] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[313] = Mbins[44] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[314] = Mbins[44] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[315] = Mbins[45] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[316] = Mbins[45] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[317] = Mbins[45] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[318] = Mbins[45] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[319] = Mbins[45] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[320] = Mbins[45] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[321] = Mbins[45] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[322] = Mbins[46] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[323] = Mbins[46] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[324] = Mbins[46] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[325] = Mbins[46] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[326] = Mbins[46] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[327] = Mbins[46] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[328] = Mbins[46] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[329] = Mbins[47] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[330] = Mbins[47] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[331] = Mbins[47] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[332] = Mbins[47] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[333] = Mbins[47] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[334] = Mbins[47] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[335] = Mbins[47] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[336] = Mbins[48] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[337] = Mbins[48] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[338] = Mbins[48] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[339] = Mbins[48] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[340] = Mbins[48] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[341] = Mbins[48] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[342] = Mbins[48] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[343] = Mbins[49] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[344] = Mbins[49] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[345] = Mbins[49] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[346] = Mbins[49] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[347] = Mbins[49] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[348] = Mbins[49] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[349] = Mbins[49] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[350] = Mbins[50] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[351] = Mbins[50] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[352] = Mbins[50] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[353] = Mbins[50] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[354] = Mbins[50] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[355] = Mbins[50] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[356] = Mbins[50] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[357] = Mbins[51] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[358] = Mbins[51] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[359] = Mbins[51] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[360] = Mbins[51] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[361] = Mbins[51] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[362] = Mbins[51] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[363] = Mbins[51] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[364] = Mbins[52] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[365] = Mbins[52] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[366] = Mbins[52] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[367] = Mbins[52] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[368] = Mbins[52] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[369] = Mbins[52] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[370] = Mbins[52] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[371] = Mbins[53] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[372] = Mbins[53] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[373] = Mbins[53] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[374] = Mbins[53] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[375] = Mbins[53] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[376] = Mbins[53] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[377] = Mbins[53] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[378] = Mbins[54] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[379] = Mbins[54] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[380] = Mbins[54] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[381] = Mbins[54] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[382] = Mbins[54] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[383] = Mbins[54] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[384] = Mbins[54] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[385] = Mbins[55] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[386] = Mbins[55] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[387] = Mbins[55] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[388] = Mbins[55] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[389] = Mbins[55] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[390] = Mbins[55] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[391] = Mbins[55] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[392] = Mbins[56] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[393] = Mbins[56] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[394] = Mbins[56] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[395] = Mbins[56] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[396] = Mbins[56] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[397] = Mbins[56] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[398] = Mbins[56] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[399] = Mbins[57] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[400] = Mbins[57] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[401] = Mbins[57] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[402] = Mbins[57] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[403] = Mbins[57] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[404] = Mbins[57] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[405] = Mbins[57] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[406] = Mbins[58] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[407] = Mbins[58] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[408] = Mbins[58] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[409] = Mbins[58] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[410] = Mbins[58] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[411] = Mbins[58] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[412] = Mbins[58] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[413] = Mbins[59] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[414] = Mbins[59] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[415] = Mbins[59] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[416] = Mbins[59] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[417] = Mbins[59] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[418] = Mbins[59] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[419] = Mbins[59] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[420] = Mbins[60] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[421] = Mbins[60] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[422] = Mbins[60] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[423] = Mbins[60] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[424] = Mbins[60] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[425] = Mbins[60] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[426] = Mbins[60] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[427] = Mbins[61] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[428] = Mbins[61] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[429] = Mbins[61] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[430] = Mbins[61] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[431] = Mbins[61] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[432] = Mbins[61] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[433] = Mbins[61] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[434] = Mbins[62] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[435] = Mbins[62] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[436] = Mbins[62] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[437] = Mbins[62] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[438] = Mbins[62] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[439] = Mbins[62] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[440] = Mbins[62] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");
	Mbins_missMom[441] = Mbins[63] && TCut("_miss_mom_eNg >= 0.00 && _miss_mom_eNg < 0.05");
	Mbins_missMom[442] = Mbins[63] && TCut("_miss_mom_eNg >= 0.05 && _miss_mom_eNg < 0.10");
	Mbins_missMom[443] = Mbins[63] && TCut("_miss_mom_eNg >= 0.10 && _miss_mom_eNg < 0.17");
	Mbins_missMom[444] = Mbins[63] && TCut("_miss_mom_eNg >= 0.17 && _miss_mom_eNg < 0.30");
	Mbins_missMom[445] = Mbins[63] && TCut("_miss_mom_eNg >= 0.30 && _miss_mom_eNg < 0.60");
	Mbins_missMom[446] = Mbins[63] && TCut("_miss_mom_eNg >= 0.60 && _miss_mom_eNg < 0.85");
	Mbins_missMom[447] = Mbins[63] && TCut("_miss_mom_eNg >= 0.85 && _miss_mom_eNg < 1.00");

	// bins_missMom = {{t_min, t_max, Q2_min, Q2_max, xB_min, xB_max, missMin, missMax}}

	bins_missMom = {{{-0.20, 0.00, 1.00, 1.40, 0.00, 0.13, 0.00, 0.05},
					 {-0.20, 0.00, 1.00, 1.40, 0.00, 0.13, 0.05, 0.10},
					 {-0.20, 0.00, 1.00, 1.40, 0.00, 0.13, 0.10, 0.17},
					 {-0.20, 0.00, 1.00, 1.40, 0.00, 0.13, 0.17, 0.30},
					 {-0.20, 0.00, 1.00, 1.40, 0.00, 0.13, 0.30, 0.60},
					 {-0.20, 0.00, 1.00, 1.40, 0.00, 0.13, 0.60, 0.85},
					 {-0.20, 0.00, 1.00, 1.40, 0.00, 0.13, 0.85, 1.00},
					 {-0.20, 0.00, 1.00, 1.40, 0.13, 0.21, 0.00, 0.05},
					 {-0.20, 0.00, 1.00, 1.40, 0.13, 0.21, 0.05, 0.10},
					 {-0.20, 0.00, 1.00, 1.40, 0.13, 0.21, 0.10, 0.17},
					 {-0.20, 0.00, 1.00, 1.40, 0.13, 0.21, 0.17, 0.30},
					 {-0.20, 0.00, 1.00, 1.40, 0.13, 0.21, 0.30, 0.60},
					 {-0.20, 0.00, 1.00, 1.40, 0.13, 0.21, 0.60, 0.85},
					 {-0.20, 0.00, 1.00, 1.40, 0.13, 0.21, 0.85, 1.00},
					 {-0.20, 0.00, 1.00, 1.40, 0.21, 1.00, 0.00, 0.05},
					 {-0.20, 0.00, 1.00, 1.40, 0.21, 1.00, 0.05, 0.10},
					 {-0.20, 0.00, 1.00, 1.40, 0.21, 1.00, 0.10, 0.17},
					 {-0.20, 0.00, 1.00, 1.40, 0.21, 1.00, 0.17, 0.30},
					 {-0.20, 0.00, 1.00, 1.40, 0.21, 1.00, 0.30, 0.60},
					 {-0.20, 0.00, 1.00, 1.40, 0.21, 1.00, 0.60, 0.85},
					 {-0.20, 0.00, 1.00, 1.40, 0.21, 1.00, 0.85, 1.00},
					 {-0.40, -0.20, 1.00, 1.40, 0.00, 0.13, 0.00, 0.05},
					 {-0.40, -0.20, 1.00, 1.40, 0.00, 0.13, 0.05, 0.10},
					 {-0.40, -0.20, 1.00, 1.40, 0.00, 0.13, 0.10, 0.17},
					 {-0.40, -0.20, 1.00, 1.40, 0.00, 0.13, 0.17, 0.30},
					 {-0.40, -0.20, 1.00, 1.40, 0.00, 0.13, 0.30, 0.60},
					 {-0.40, -0.20, 1.00, 1.40, 0.00, 0.13, 0.60, 0.85},
					 {-0.40, -0.20, 1.00, 1.40, 0.00, 0.13, 0.85, 1.00},
					 {-0.40, -0.20, 1.00, 1.40, 0.13, 0.21, 0.00, 0.05},
					 {-0.40, -0.20, 1.00, 1.40, 0.13, 0.21, 0.05, 0.10},
					 {-0.40, -0.20, 1.00, 1.40, 0.13, 0.21, 0.10, 0.17},
					 {-0.40, -0.20, 1.00, 1.40, 0.13, 0.21, 0.17, 0.30},
					 {-0.40, -0.20, 1.00, 1.40, 0.13, 0.21, 0.30, 0.60},
					 {-0.40, -0.20, 1.00, 1.40, 0.13, 0.21, 0.60, 0.85},
					 {-0.40, -0.20, 1.00, 1.40, 0.13, 0.21, 0.85, 1.00},
					 {-0.40, -0.20, 1.00, 1.40, 0.21, 1.00, 0.00, 0.05},
					 {-0.40, -0.20, 1.00, 1.40, 0.21, 1.00, 0.05, 0.10},
					 {-0.40, -0.20, 1.00, 1.40, 0.21, 1.00, 0.10, 0.17},
					 {-0.40, -0.20, 1.00, 1.40, 0.21, 1.00, 0.17, 0.30},
					 {-0.40, -0.20, 1.00, 1.40, 0.21, 1.00, 0.30, 0.60},
					 {-0.40, -0.20, 1.00, 1.40, 0.21, 1.00, 0.60, 0.85},
					 {-0.40, -0.20, 1.00, 1.40, 0.21, 1.00, 0.85, 1.00},
					 {-0.80, -0.40, 1.00, 1.40, 0.00, 0.13, 0.00, 0.05},
					 {-0.80, -0.40, 1.00, 1.40, 0.00, 0.13, 0.05, 0.10},
					 {-0.80, -0.40, 1.00, 1.40, 0.00, 0.13, 0.10, 0.17},
					 {-0.80, -0.40, 1.00, 1.40, 0.00, 0.13, 0.17, 0.30},
					 {-0.80, -0.40, 1.00, 1.40, 0.00, 0.13, 0.30, 0.60},
					 {-0.80, -0.40, 1.00, 1.40, 0.00, 0.13, 0.60, 0.85},
					 {-0.80, -0.40, 1.00, 1.40, 0.00, 0.13, 0.85, 1.00},
					 {-0.80, -0.40, 1.00, 1.40, 0.13, 0.21, 0.00, 0.05},
					 {-0.80, -0.40, 1.00, 1.40, 0.13, 0.21, 0.05, 0.10},
					 {-0.80, -0.40, 1.00, 1.40, 0.13, 0.21, 0.10, 0.17},
					 {-0.80, -0.40, 1.00, 1.40, 0.13, 0.21, 0.17, 0.30},
					 {-0.80, -0.40, 1.00, 1.40, 0.13, 0.21, 0.30, 0.60},
					 {-0.80, -0.40, 1.00, 1.40, 0.13, 0.21, 0.60, 0.85},
					 {-0.80, -0.40, 1.00, 1.40, 0.13, 0.21, 0.85, 1.00},
					 {-0.80, -0.40, 1.00, 1.40, 0.21, 1.00, 0.00, 0.05},
					 {-0.80, -0.40, 1.00, 1.40, 0.21, 1.00, 0.05, 0.10},
					 {-0.80, -0.40, 1.00, 1.40, 0.21, 1.00, 0.10, 0.17},
					 {-0.80, -0.40, 1.00, 1.40, 0.21, 1.00, 0.17, 0.30},
					 {-0.80, -0.40, 1.00, 1.40, 0.21, 1.00, 0.30, 0.60},
					 {-0.80, -0.40, 1.00, 1.40, 0.21, 1.00, 0.60, 0.85},
					 {-0.80, -0.40, 1.00, 1.40, 0.21, 1.00, 0.85, 1.00},
					 {-100.00, -0.80, 1.00, 1.40, 0.00, 0.13, 0.00, 0.05},
					 {-100.00, -0.80, 1.00, 1.40, 0.00, 0.13, 0.05, 0.10},
					 {-100.00, -0.80, 1.00, 1.40, 0.00, 0.13, 0.10, 0.17},
					 {-100.00, -0.80, 1.00, 1.40, 0.00, 0.13, 0.17, 0.30},
					 {-100.00, -0.80, 1.00, 1.40, 0.00, 0.13, 0.30, 0.60},
					 {-100.00, -0.80, 1.00, 1.40, 0.00, 0.13, 0.60, 0.85},
					 {-100.00, -0.80, 1.00, 1.40, 0.00, 0.13, 0.85, 1.00},
					 {-100.00, -0.80, 1.00, 1.40, 0.13, 0.21, 0.00, 0.05},
					 {-100.00, -0.80, 1.00, 1.40, 0.13, 0.21, 0.05, 0.10},
					 {-100.00, -0.80, 1.00, 1.40, 0.13, 0.21, 0.10, 0.17},
					 {-100.00, -0.80, 1.00, 1.40, 0.13, 0.21, 0.17, 0.30},
					 {-100.00, -0.80, 1.00, 1.40, 0.13, 0.21, 0.30, 0.60},
					 {-100.00, -0.80, 1.00, 1.40, 0.13, 0.21, 0.60, 0.85},
					 {-100.00, -0.80, 1.00, 1.40, 0.13, 0.21, 0.85, 1.00},
					 {-100.00, -0.80, 1.00, 1.40, 0.21, 1.00, 0.00, 0.05},
					 {-100.00, -0.80, 1.00, 1.40, 0.21, 1.00, 0.05, 0.10},
					 {-100.00, -0.80, 1.00, 1.40, 0.21, 1.00, 0.10, 0.17},
					 {-100.00, -0.80, 1.00, 1.40, 0.21, 1.00, 0.17, 0.30},
					 {-100.00, -0.80, 1.00, 1.40, 0.21, 1.00, 0.30, 0.60},
					 {-100.00, -0.80, 1.00, 1.40, 0.21, 1.00, 0.60, 0.85},
					 {-100.00, -0.80, 1.00, 1.40, 0.21, 1.00, 0.85, 1.00},
					 {-0.20, 0.00, 1.40, 1.80, 0.00, 0.13, 0.00, 0.05},
					 {-0.20, 0.00, 1.40, 1.80, 0.00, 0.13, 0.05, 0.10},
					 {-0.20, 0.00, 1.40, 1.80, 0.00, 0.13, 0.10, 0.17},
					 {-0.20, 0.00, 1.40, 1.80, 0.00, 0.13, 0.17, 0.30},
					 {-0.20, 0.00, 1.40, 1.80, 0.00, 0.13, 0.30, 0.60},
					 {-0.20, 0.00, 1.40, 1.80, 0.00, 0.13, 0.60, 0.85},
					 {-0.20, 0.00, 1.40, 1.80, 0.00, 0.13, 0.85, 1.00},
					 {-0.20, 0.00, 1.40, 1.80, 0.13, 0.21, 0.00, 0.05},
					 {-0.20, 0.00, 1.40, 1.80, 0.13, 0.21, 0.05, 0.10},
					 {-0.20, 0.00, 1.40, 1.80, 0.13, 0.21, 0.10, 0.17},
					 {-0.20, 0.00, 1.40, 1.80, 0.13, 0.21, 0.17, 0.30},
					 {-0.20, 0.00, 1.40, 1.80, 0.13, 0.21, 0.30, 0.60},
					 {-0.20, 0.00, 1.40, 1.80, 0.13, 0.21, 0.60, 0.85},
					 {-0.20, 0.00, 1.40, 1.80, 0.13, 0.21, 0.85, 1.00},
					 {-0.20, 0.00, 1.40, 1.80, 0.21, 1.00, 0.00, 0.05},
					 {-0.20, 0.00, 1.40, 1.80, 0.21, 1.00, 0.05, 0.10},
					 {-0.20, 0.00, 1.40, 1.80, 0.21, 1.00, 0.10, 0.17},
					 {-0.20, 0.00, 1.40, 1.80, 0.21, 1.00, 0.17, 0.30},
					 {-0.20, 0.00, 1.40, 1.80, 0.21, 1.00, 0.30, 0.60},
					 {-0.20, 0.00, 1.40, 1.80, 0.21, 1.00, 0.60, 0.85},
					 {-0.20, 0.00, 1.40, 1.80, 0.21, 1.00, 0.85, 1.00},
					 {-0.40, -0.20, 1.40, 1.80, 0.00, 0.13, 0.00, 0.05},
					 {-0.40, -0.20, 1.40, 1.80, 0.00, 0.13, 0.05, 0.10},
					 {-0.40, -0.20, 1.40, 1.80, 0.00, 0.13, 0.10, 0.17},
					 {-0.40, -0.20, 1.40, 1.80, 0.00, 0.13, 0.17, 0.30},
					 {-0.40, -0.20, 1.40, 1.80, 0.00, 0.13, 0.30, 0.60},
					 {-0.40, -0.20, 1.40, 1.80, 0.00, 0.13, 0.60, 0.85},
					 {-0.40, -0.20, 1.40, 1.80, 0.00, 0.13, 0.85, 1.00},
					 {-0.40, -0.20, 1.40, 1.80, 0.13, 0.21, 0.00, 0.05},
					 {-0.40, -0.20, 1.40, 1.80, 0.13, 0.21, 0.05, 0.10},
					 {-0.40, -0.20, 1.40, 1.80, 0.13, 0.21, 0.10, 0.17},
					 {-0.40, -0.20, 1.40, 1.80, 0.13, 0.21, 0.17, 0.30},
					 {-0.40, -0.20, 1.40, 1.80, 0.13, 0.21, 0.30, 0.60},
					 {-0.40, -0.20, 1.40, 1.80, 0.13, 0.21, 0.60, 0.85},
					 {-0.40, -0.20, 1.40, 1.80, 0.13, 0.21, 0.85, 1.00},
					 {-0.40, -0.20, 1.40, 1.80, 0.21, 1.00, 0.00, 0.05},
					 {-0.40, -0.20, 1.40, 1.80, 0.21, 1.00, 0.05, 0.10},
					 {-0.40, -0.20, 1.40, 1.80, 0.21, 1.00, 0.10, 0.17},
					 {-0.40, -0.20, 1.40, 1.80, 0.21, 1.00, 0.17, 0.30},
					 {-0.40, -0.20, 1.40, 1.80, 0.21, 1.00, 0.30, 0.60},
					 {-0.40, -0.20, 1.40, 1.80, 0.21, 1.00, 0.60, 0.85},
					 {-0.40, -0.20, 1.40, 1.80, 0.21, 1.00, 0.85, 1.00},
					 {-0.80, -0.40, 1.40, 1.80, 0.00, 0.13, 0.00, 0.05},
					 {-0.80, -0.40, 1.40, 1.80, 0.00, 0.13, 0.05, 0.10},
					 {-0.80, -0.40, 1.40, 1.80, 0.00, 0.13, 0.10, 0.17},
					 {-0.80, -0.40, 1.40, 1.80, 0.00, 0.13, 0.17, 0.30},
					 {-0.80, -0.40, 1.40, 1.80, 0.00, 0.13, 0.30, 0.60},
					 {-0.80, -0.40, 1.40, 1.80, 0.00, 0.13, 0.60, 0.85},
					 {-0.80, -0.40, 1.40, 1.80, 0.00, 0.13, 0.85, 1.00},
					 {-0.80, -0.40, 1.40, 1.80, 0.13, 0.21, 0.00, 0.05},
					 {-0.80, -0.40, 1.40, 1.80, 0.13, 0.21, 0.05, 0.10},
					 {-0.80, -0.40, 1.40, 1.80, 0.13, 0.21, 0.10, 0.17},
					 {-0.80, -0.40, 1.40, 1.80, 0.13, 0.21, 0.17, 0.30},
					 {-0.80, -0.40, 1.40, 1.80, 0.13, 0.21, 0.30, 0.60},
					 {-0.80, -0.40, 1.40, 1.80, 0.13, 0.21, 0.60, 0.85},
					 {-0.80, -0.40, 1.40, 1.80, 0.13, 0.21, 0.85, 1.00},
					 {-0.80, -0.40, 1.40, 1.80, 0.21, 1.00, 0.00, 0.05},
					 {-0.80, -0.40, 1.40, 1.80, 0.21, 1.00, 0.05, 0.10},
					 {-0.80, -0.40, 1.40, 1.80, 0.21, 1.00, 0.10, 0.17},
					 {-0.80, -0.40, 1.40, 1.80, 0.21, 1.00, 0.17, 0.30},
					 {-0.80, -0.40, 1.40, 1.80, 0.21, 1.00, 0.30, 0.60},
					 {-0.80, -0.40, 1.40, 1.80, 0.21, 1.00, 0.60, 0.85},
					 {-0.80, -0.40, 1.40, 1.80, 0.21, 1.00, 0.85, 1.00},
					 {-100.00, -0.80, 1.40, 1.80, 0.00, 0.13, 0.00, 0.05},
					 {-100.00, -0.80, 1.40, 1.80, 0.00, 0.13, 0.05, 0.10},
					 {-100.00, -0.80, 1.40, 1.80, 0.00, 0.13, 0.10, 0.17},
					 {-100.00, -0.80, 1.40, 1.80, 0.00, 0.13, 0.17, 0.30},
					 {-100.00, -0.80, 1.40, 1.80, 0.00, 0.13, 0.30, 0.60},
					 {-100.00, -0.80, 1.40, 1.80, 0.00, 0.13, 0.60, 0.85},
					 {-100.00, -0.80, 1.40, 1.80, 0.00, 0.13, 0.85, 1.00},
					 {-100.00, -0.80, 1.40, 1.80, 0.13, 0.21, 0.00, 0.05},
					 {-100.00, -0.80, 1.40, 1.80, 0.13, 0.21, 0.05, 0.10},
					 {-100.00, -0.80, 1.40, 1.80, 0.13, 0.21, 0.10, 0.17},
					 {-100.00, -0.80, 1.40, 1.80, 0.13, 0.21, 0.17, 0.30},
					 {-100.00, -0.80, 1.40, 1.80, 0.13, 0.21, 0.30, 0.60},
					 {-100.00, -0.80, 1.40, 1.80, 0.13, 0.21, 0.60, 0.85},
					 {-100.00, -0.80, 1.40, 1.80, 0.13, 0.21, 0.85, 1.00},
					 {-100.00, -0.80, 1.40, 1.80, 0.21, 1.00, 0.00, 0.05},
					 {-100.00, -0.80, 1.40, 1.80, 0.21, 1.00, 0.05, 0.10},
					 {-100.00, -0.80, 1.40, 1.80, 0.21, 1.00, 0.10, 0.17},
					 {-100.00, -0.80, 1.40, 1.80, 0.21, 1.00, 0.17, 0.30},
					 {-100.00, -0.80, 1.40, 1.80, 0.21, 1.00, 0.30, 0.60},
					 {-100.00, -0.80, 1.40, 1.80, 0.21, 1.00, 0.60, 0.85},
					 {-100.00, -0.80, 1.40, 1.80, 0.21, 1.00, 0.85, 1.00},
					 {-0.20, 0.00, 1.80, 2.40, 0.00, 0.16, 0.00, 0.05},
					 {-0.20, 0.00, 1.80, 2.40, 0.00, 0.16, 0.05, 0.10},
					 {-0.20, 0.00, 1.80, 2.40, 0.00, 0.16, 0.10, 0.17},
					 {-0.20, 0.00, 1.80, 2.40, 0.00, 0.16, 0.17, 0.30},
					 {-0.20, 0.00, 1.80, 2.40, 0.00, 0.16, 0.30, 0.60},
					 {-0.20, 0.00, 1.80, 2.40, 0.00, 0.16, 0.60, 0.85},
					 {-0.20, 0.00, 1.80, 2.40, 0.00, 0.16, 0.85, 1.00},
					 {-0.20, 0.00, 1.80, 2.40, 0.16, 0.26, 0.00, 0.05},
					 {-0.20, 0.00, 1.80, 2.40, 0.16, 0.26, 0.05, 0.10},
					 {-0.20, 0.00, 1.80, 2.40, 0.16, 0.26, 0.10, 0.17},
					 {-0.20, 0.00, 1.80, 2.40, 0.16, 0.26, 0.17, 0.30},
					 {-0.20, 0.00, 1.80, 2.40, 0.16, 0.26, 0.30, 0.60},
					 {-0.20, 0.00, 1.80, 2.40, 0.16, 0.26, 0.60, 0.85},
					 {-0.20, 0.00, 1.80, 2.40, 0.16, 0.26, 0.85, 1.00},
					 {-0.20, 0.00, 1.80, 2.40, 0.26, 1.00, 0.00, 0.05},
					 {-0.20, 0.00, 1.80, 2.40, 0.26, 1.00, 0.05, 0.10},
					 {-0.20, 0.00, 1.80, 2.40, 0.26, 1.00, 0.10, 0.17},
					 {-0.20, 0.00, 1.80, 2.40, 0.26, 1.00, 0.17, 0.30},
					 {-0.20, 0.00, 1.80, 2.40, 0.26, 1.00, 0.30, 0.60},
					 {-0.20, 0.00, 1.80, 2.40, 0.26, 1.00, 0.60, 0.85},
					 {-0.20, 0.00, 1.80, 2.40, 0.26, 1.00, 0.85, 1.00},
					 {-0.40, -0.20, 1.80, 2.40, 0.00, 0.16, 0.00, 0.05},
					 {-0.40, -0.20, 1.80, 2.40, 0.00, 0.16, 0.05, 0.10},
					 {-0.40, -0.20, 1.80, 2.40, 0.00, 0.16, 0.10, 0.17},
					 {-0.40, -0.20, 1.80, 2.40, 0.00, 0.16, 0.17, 0.30},
					 {-0.40, -0.20, 1.80, 2.40, 0.00, 0.16, 0.30, 0.60},
					 {-0.40, -0.20, 1.80, 2.40, 0.00, 0.16, 0.60, 0.85},
					 {-0.40, -0.20, 1.80, 2.40, 0.00, 0.16, 0.85, 1.00},
					 {-0.40, -0.20, 1.80, 2.40, 0.16, 0.26, 0.00, 0.05},
					 {-0.40, -0.20, 1.80, 2.40, 0.16, 0.26, 0.05, 0.10},
					 {-0.40, -0.20, 1.80, 2.40, 0.16, 0.26, 0.10, 0.17},
					 {-0.40, -0.20, 1.80, 2.40, 0.16, 0.26, 0.17, 0.30},
					 {-0.40, -0.20, 1.80, 2.40, 0.16, 0.26, 0.30, 0.60},
					 {-0.40, -0.20, 1.80, 2.40, 0.16, 0.26, 0.60, 0.85},
					 {-0.40, -0.20, 1.80, 2.40, 0.16, 0.26, 0.85, 1.00},
					 {-0.40, -0.20, 1.80, 2.40, 0.26, 1.00, 0.00, 0.05},
					 {-0.40, -0.20, 1.80, 2.40, 0.26, 1.00, 0.05, 0.10},
					 {-0.40, -0.20, 1.80, 2.40, 0.26, 1.00, 0.10, 0.17},
					 {-0.40, -0.20, 1.80, 2.40, 0.26, 1.00, 0.17, 0.30},
					 {-0.40, -0.20, 1.80, 2.40, 0.26, 1.00, 0.30, 0.60},
					 {-0.40, -0.20, 1.80, 2.40, 0.26, 1.00, 0.60, 0.85},
					 {-0.40, -0.20, 1.80, 2.40, 0.26, 1.00, 0.85, 1.00},
					 {-0.80, -0.40, 1.80, 2.40, 0.00, 0.16, 0.00, 0.05},
					 {-0.80, -0.40, 1.80, 2.40, 0.00, 0.16, 0.05, 0.10},
					 {-0.80, -0.40, 1.80, 2.40, 0.00, 0.16, 0.10, 0.17},
					 {-0.80, -0.40, 1.80, 2.40, 0.00, 0.16, 0.17, 0.30},
					 {-0.80, -0.40, 1.80, 2.40, 0.00, 0.16, 0.30, 0.60},
					 {-0.80, -0.40, 1.80, 2.40, 0.00, 0.16, 0.60, 0.85},
					 {-0.80, -0.40, 1.80, 2.40, 0.00, 0.16, 0.85, 1.00},
					 {-0.80, -0.40, 1.80, 2.40, 0.16, 0.26, 0.00, 0.05},
					 {-0.80, -0.40, 1.80, 2.40, 0.16, 0.26, 0.05, 0.10},
					 {-0.80, -0.40, 1.80, 2.40, 0.16, 0.26, 0.10, 0.17},
					 {-0.80, -0.40, 1.80, 2.40, 0.16, 0.26, 0.17, 0.30},
					 {-0.80, -0.40, 1.80, 2.40, 0.16, 0.26, 0.30, 0.60},
					 {-0.80, -0.40, 1.80, 2.40, 0.16, 0.26, 0.60, 0.85},
					 {-0.80, -0.40, 1.80, 2.40, 0.16, 0.26, 0.85, 1.00},
					 {-0.80, -0.40, 1.80, 2.40, 0.26, 1.00, 0.00, 0.05},
					 {-0.80, -0.40, 1.80, 2.40, 0.26, 1.00, 0.05, 0.10},
					 {-0.80, -0.40, 1.80, 2.40, 0.26, 1.00, 0.10, 0.17},
					 {-0.80, -0.40, 1.80, 2.40, 0.26, 1.00, 0.17, 0.30},
					 {-0.80, -0.40, 1.80, 2.40, 0.26, 1.00, 0.30, 0.60},
					 {-0.80, -0.40, 1.80, 2.40, 0.26, 1.00, 0.60, 0.85},
					 {-0.80, -0.40, 1.80, 2.40, 0.26, 1.00, 0.85, 1.00},
					 {-100.00, -0.80, 1.80, 2.40, 0.00, 0.16, 0.00, 0.05},
					 {-100.00, -0.80, 1.80, 2.40, 0.00, 0.16, 0.05, 0.10},
					 {-100.00, -0.80, 1.80, 2.40, 0.00, 0.16, 0.10, 0.17},
					 {-100.00, -0.80, 1.80, 2.40, 0.00, 0.16, 0.17, 0.30},
					 {-100.00, -0.80, 1.80, 2.40, 0.00, 0.16, 0.30, 0.60},
					 {-100.00, -0.80, 1.80, 2.40, 0.00, 0.16, 0.60, 0.85},
					 {-100.00, -0.80, 1.80, 2.40, 0.00, 0.16, 0.85, 1.00},
					 {-100.00, -0.80, 1.80, 2.40, 0.16, 0.26, 0.00, 0.05},
					 {-100.00, -0.80, 1.80, 2.40, 0.16, 0.26, 0.05, 0.10},
					 {-100.00, -0.80, 1.80, 2.40, 0.16, 0.26, 0.10, 0.17},
					 {-100.00, -0.80, 1.80, 2.40, 0.16, 0.26, 0.17, 0.30},
					 {-100.00, -0.80, 1.80, 2.40, 0.16, 0.26, 0.30, 0.60},
					 {-100.00, -0.80, 1.80, 2.40, 0.16, 0.26, 0.60, 0.85},
					 {-100.00, -0.80, 1.80, 2.40, 0.16, 0.26, 0.85, 1.00},
					 {-100.00, -0.80, 1.80, 2.40, 0.26, 1.00, 0.00, 0.05},
					 {-100.00, -0.80, 1.80, 2.40, 0.26, 1.00, 0.05, 0.10},
					 {-100.00, -0.80, 1.80, 2.40, 0.26, 1.00, 0.10, 0.17},
					 {-100.00, -0.80, 1.80, 2.40, 0.26, 1.00, 0.17, 0.30},
					 {-100.00, -0.80, 1.80, 2.40, 0.26, 1.00, 0.30, 0.60},
					 {-100.00, -0.80, 1.80, 2.40, 0.26, 1.00, 0.60, 0.85},
					 {-100.00, -0.80, 1.80, 2.40, 0.26, 1.00, 0.85, 1.00},
					 {-0.20, 0.00, 2.40, 3.25, 0.00, 0.21, 0.00, 0.05},
					 {-0.20, 0.00, 2.40, 3.25, 0.00, 0.21, 0.05, 0.10},
					 {-0.20, 0.00, 2.40, 3.25, 0.00, 0.21, 0.10, 0.17},
					 {-0.20, 0.00, 2.40, 3.25, 0.00, 0.21, 0.17, 0.30},
					 {-0.20, 0.00, 2.40, 3.25, 0.00, 0.21, 0.30, 0.60},
					 {-0.20, 0.00, 2.40, 3.25, 0.00, 0.21, 0.60, 0.85},
					 {-0.20, 0.00, 2.40, 3.25, 0.00, 0.21, 0.85, 1.00},
					 {-0.20, 0.00, 2.40, 3.25, 0.21, 0.33, 0.00, 0.05},
					 {-0.20, 0.00, 2.40, 3.25, 0.21, 0.33, 0.05, 0.10},
					 {-0.20, 0.00, 2.40, 3.25, 0.21, 0.33, 0.10, 0.17},
					 {-0.20, 0.00, 2.40, 3.25, 0.21, 0.33, 0.17, 0.30},
					 {-0.20, 0.00, 2.40, 3.25, 0.21, 0.33, 0.30, 0.60},
					 {-0.20, 0.00, 2.40, 3.25, 0.21, 0.33, 0.60, 0.85},
					 {-0.20, 0.00, 2.40, 3.25, 0.21, 0.33, 0.85, 1.00},
					 {-0.20, 0.00, 2.40, 3.25, 0.33, 1.00, 0.00, 0.05},
					 {-0.20, 0.00, 2.40, 3.25, 0.33, 1.00, 0.05, 0.10},
					 {-0.20, 0.00, 2.40, 3.25, 0.33, 1.00, 0.10, 0.17},
					 {-0.20, 0.00, 2.40, 3.25, 0.33, 1.00, 0.17, 0.30},
					 {-0.20, 0.00, 2.40, 3.25, 0.33, 1.00, 0.30, 0.60},
					 {-0.20, 0.00, 2.40, 3.25, 0.33, 1.00, 0.60, 0.85},
					 {-0.20, 0.00, 2.40, 3.25, 0.33, 1.00, 0.85, 1.00},
					 {-0.40, -0.20, 2.40, 3.25, 0.00, 0.21, 0.00, 0.05},
					 {-0.40, -0.20, 2.40, 3.25, 0.00, 0.21, 0.05, 0.10},
					 {-0.40, -0.20, 2.40, 3.25, 0.00, 0.21, 0.10, 0.17},
					 {-0.40, -0.20, 2.40, 3.25, 0.00, 0.21, 0.17, 0.30},
					 {-0.40, -0.20, 2.40, 3.25, 0.00, 0.21, 0.30, 0.60},
					 {-0.40, -0.20, 2.40, 3.25, 0.00, 0.21, 0.60, 0.85},
					 {-0.40, -0.20, 2.40, 3.25, 0.00, 0.21, 0.85, 1.00},
					 {-0.40, -0.20, 2.40, 3.25, 0.21, 0.33, 0.00, 0.05},
					 {-0.40, -0.20, 2.40, 3.25, 0.21, 0.33, 0.05, 0.10},
					 {-0.40, -0.20, 2.40, 3.25, 0.21, 0.33, 0.10, 0.17},
					 {-0.40, -0.20, 2.40, 3.25, 0.21, 0.33, 0.17, 0.30},
					 {-0.40, -0.20, 2.40, 3.25, 0.21, 0.33, 0.30, 0.60},
					 {-0.40, -0.20, 2.40, 3.25, 0.21, 0.33, 0.60, 0.85},
					 {-0.40, -0.20, 2.40, 3.25, 0.21, 0.33, 0.85, 1.00},
					 {-0.40, -0.20, 2.40, 3.25, 0.33, 1.00, 0.00, 0.05},
					 {-0.40, -0.20, 2.40, 3.25, 0.33, 1.00, 0.05, 0.10},
					 {-0.40, -0.20, 2.40, 3.25, 0.33, 1.00, 0.10, 0.17},
					 {-0.40, -0.20, 2.40, 3.25, 0.33, 1.00, 0.17, 0.30},
					 {-0.40, -0.20, 2.40, 3.25, 0.33, 1.00, 0.30, 0.60},
					 {-0.40, -0.20, 2.40, 3.25, 0.33, 1.00, 0.60, 0.85},
					 {-0.40, -0.20, 2.40, 3.25, 0.33, 1.00, 0.85, 1.00},
					 {-0.80, -0.40, 2.40, 3.25, 0.00, 0.21, 0.00, 0.05},
					 {-0.80, -0.40, 2.40, 3.25, 0.00, 0.21, 0.05, 0.10},
					 {-0.80, -0.40, 2.40, 3.25, 0.00, 0.21, 0.10, 0.17},
					 {-0.80, -0.40, 2.40, 3.25, 0.00, 0.21, 0.17, 0.30},
					 {-0.80, -0.40, 2.40, 3.25, 0.00, 0.21, 0.30, 0.60},
					 {-0.80, -0.40, 2.40, 3.25, 0.00, 0.21, 0.60, 0.85},
					 {-0.80, -0.40, 2.40, 3.25, 0.00, 0.21, 0.85, 1.00},
					 {-0.80, -0.40, 2.40, 3.25, 0.21, 0.33, 0.00, 0.05},
					 {-0.80, -0.40, 2.40, 3.25, 0.21, 0.33, 0.05, 0.10},
					 {-0.80, -0.40, 2.40, 3.25, 0.21, 0.33, 0.10, 0.17},
					 {-0.80, -0.40, 2.40, 3.25, 0.21, 0.33, 0.17, 0.30},
					 {-0.80, -0.40, 2.40, 3.25, 0.21, 0.33, 0.30, 0.60},
					 {-0.80, -0.40, 2.40, 3.25, 0.21, 0.33, 0.60, 0.85},
					 {-0.80, -0.40, 2.40, 3.25, 0.21, 0.33, 0.85, 1.00},
					 {-0.80, -0.40, 2.40, 3.25, 0.33, 1.00, 0.00, 0.05},
					 {-0.80, -0.40, 2.40, 3.25, 0.33, 1.00, 0.05, 0.10},
					 {-0.80, -0.40, 2.40, 3.25, 0.33, 1.00, 0.10, 0.17},
					 {-0.80, -0.40, 2.40, 3.25, 0.33, 1.00, 0.17, 0.30},
					 {-0.80, -0.40, 2.40, 3.25, 0.33, 1.00, 0.30, 0.60},
					 {-0.80, -0.40, 2.40, 3.25, 0.33, 1.00, 0.60, 0.85},
					 {-0.80, -0.40, 2.40, 3.25, 0.33, 1.00, 0.85, 1.00},
					 {-100.00, -0.80, 2.40, 3.25, 0.00, 0.21, 0.00, 0.05},
					 {-100.00, -0.80, 2.40, 3.25, 0.00, 0.21, 0.05, 0.10},
					 {-100.00, -0.80, 2.40, 3.25, 0.00, 0.21, 0.10, 0.17},
					 {-100.00, -0.80, 2.40, 3.25, 0.00, 0.21, 0.17, 0.30},
					 {-100.00, -0.80, 2.40, 3.25, 0.00, 0.21, 0.30, 0.60},
					 {-100.00, -0.80, 2.40, 3.25, 0.00, 0.21, 0.60, 0.85},
					 {-100.00, -0.80, 2.40, 3.25, 0.00, 0.21, 0.85, 1.00},
					 {-100.00, -0.80, 2.40, 3.25, 0.21, 0.33, 0.00, 0.05},
					 {-100.00, -0.80, 2.40, 3.25, 0.21, 0.33, 0.05, 0.10},
					 {-100.00, -0.80, 2.40, 3.25, 0.21, 0.33, 0.10, 0.17},
					 {-100.00, -0.80, 2.40, 3.25, 0.21, 0.33, 0.17, 0.30},
					 {-100.00, -0.80, 2.40, 3.25, 0.21, 0.33, 0.30, 0.60},
					 {-100.00, -0.80, 2.40, 3.25, 0.21, 0.33, 0.60, 0.85},
					 {-100.00, -0.80, 2.40, 3.25, 0.21, 0.33, 0.85, 1.00},
					 {-100.00, -0.80, 2.40, 3.25, 0.33, 1.00, 0.00, 0.05},
					 {-100.00, -0.80, 2.40, 3.25, 0.33, 1.00, 0.05, 0.10},
					 {-100.00, -0.80, 2.40, 3.25, 0.33, 1.00, 0.10, 0.17},
					 {-100.00, -0.80, 2.40, 3.25, 0.33, 1.00, 0.17, 0.30},
					 {-100.00, -0.80, 2.40, 3.25, 0.33, 1.00, 0.30, 0.60},
					 {-100.00, -0.80, 2.40, 3.25, 0.33, 1.00, 0.60, 0.85},
					 {-100.00, -0.80, 2.40, 3.25, 0.33, 1.00, 0.85, 1.00},
					 {-0.20, 0.00, 3.25, 5.00, 0.00, 0.33, 0.00, 0.05},
					 {-0.20, 0.00, 3.25, 5.00, 0.00, 0.33, 0.05, 0.10},
					 {-0.20, 0.00, 3.25, 5.00, 0.00, 0.33, 0.10, 0.17},
					 {-0.20, 0.00, 3.25, 5.00, 0.00, 0.33, 0.17, 0.30},
					 {-0.20, 0.00, 3.25, 5.00, 0.00, 0.33, 0.30, 0.60},
					 {-0.20, 0.00, 3.25, 5.00, 0.00, 0.33, 0.60, 0.85},
					 {-0.20, 0.00, 3.25, 5.00, 0.00, 0.33, 0.85, 1.00},
					 {-0.20, 0.00, 3.25, 5.00, 0.33, 1.00, 0.00, 0.05},
					 {-0.20, 0.00, 3.25, 5.00, 0.33, 1.00, 0.05, 0.10},
					 {-0.20, 0.00, 3.25, 5.00, 0.33, 1.00, 0.10, 0.17},
					 {-0.20, 0.00, 3.25, 5.00, 0.33, 1.00, 0.17, 0.30},
					 {-0.20, 0.00, 3.25, 5.00, 0.33, 1.00, 0.30, 0.60},
					 {-0.20, 0.00, 3.25, 5.00, 0.33, 1.00, 0.60, 0.85},
					 {-0.20, 0.00, 3.25, 5.00, 0.33, 1.00, 0.85, 1.00},
					 {-0.40, -0.20, 3.25, 5.00, 0.00, 0.33, 0.00, 0.05},
					 {-0.40, -0.20, 3.25, 5.00, 0.00, 0.33, 0.05, 0.10},
					 {-0.40, -0.20, 3.25, 5.00, 0.00, 0.33, 0.10, 0.17},
					 {-0.40, -0.20, 3.25, 5.00, 0.00, 0.33, 0.17, 0.30},
					 {-0.40, -0.20, 3.25, 5.00, 0.00, 0.33, 0.30, 0.60},
					 {-0.40, -0.20, 3.25, 5.00, 0.00, 0.33, 0.60, 0.85},
					 {-0.40, -0.20, 3.25, 5.00, 0.00, 0.33, 0.85, 1.00},
					 {-0.40, -0.20, 3.25, 5.00, 0.33, 1.00, 0.00, 0.05},
					 {-0.40, -0.20, 3.25, 5.00, 0.33, 1.00, 0.05, 0.10},
					 {-0.40, -0.20, 3.25, 5.00, 0.33, 1.00, 0.10, 0.17},
					 {-0.40, -0.20, 3.25, 5.00, 0.33, 1.00, 0.17, 0.30},
					 {-0.40, -0.20, 3.25, 5.00, 0.33, 1.00, 0.30, 0.60},
					 {-0.40, -0.20, 3.25, 5.00, 0.33, 1.00, 0.60, 0.85},
					 {-0.40, -0.20, 3.25, 5.00, 0.33, 1.00, 0.85, 1.00},
					 {-0.80, -0.40, 3.25, 5.00, 0.00, 0.33, 0.00, 0.05},
					 {-0.80, -0.40, 3.25, 5.00, 0.00, 0.33, 0.05, 0.10},
					 {-0.80, -0.40, 3.25, 5.00, 0.00, 0.33, 0.10, 0.17},
					 {-0.80, -0.40, 3.25, 5.00, 0.00, 0.33, 0.17, 0.30},
					 {-0.80, -0.40, 3.25, 5.00, 0.00, 0.33, 0.30, 0.60},
					 {-0.80, -0.40, 3.25, 5.00, 0.00, 0.33, 0.60, 0.85},
					 {-0.80, -0.40, 3.25, 5.00, 0.00, 0.33, 0.85, 1.00},
					 {-0.80, -0.40, 3.25, 5.00, 0.33, 1.00, 0.00, 0.05},
					 {-0.80, -0.40, 3.25, 5.00, 0.33, 1.00, 0.05, 0.10},
					 {-0.80, -0.40, 3.25, 5.00, 0.33, 1.00, 0.10, 0.17},
					 {-0.80, -0.40, 3.25, 5.00, 0.33, 1.00, 0.17, 0.30},
					 {-0.80, -0.40, 3.25, 5.00, 0.33, 1.00, 0.30, 0.60},
					 {-0.80, -0.40, 3.25, 5.00, 0.33, 1.00, 0.60, 0.85},
					 {-0.80, -0.40, 3.25, 5.00, 0.33, 1.00, 0.85, 1.00},
					 {-100.00, -0.80, 3.25, 5.00, 0.00, 0.33, 0.00, 0.05},
					 {-100.00, -0.80, 3.25, 5.00, 0.00, 0.33, 0.05, 0.10},
					 {-100.00, -0.80, 3.25, 5.00, 0.00, 0.33, 0.10, 0.17},
					 {-100.00, -0.80, 3.25, 5.00, 0.00, 0.33, 0.17, 0.30},
					 {-100.00, -0.80, 3.25, 5.00, 0.00, 0.33, 0.30, 0.60},
					 {-100.00, -0.80, 3.25, 5.00, 0.00, 0.33, 0.60, 0.85},
					 {-100.00, -0.80, 3.25, 5.00, 0.00, 0.33, 0.85, 1.00},
					 {-100.00, -0.80, 3.25, 5.00, 0.33, 1.00, 0.00, 0.05},
					 {-100.00, -0.80, 3.25, 5.00, 0.33, 1.00, 0.05, 0.10},
					 {-100.00, -0.80, 3.25, 5.00, 0.33, 1.00, 0.10, 0.17},
					 {-100.00, -0.80, 3.25, 5.00, 0.33, 1.00, 0.17, 0.30},
					 {-100.00, -0.80, 3.25, 5.00, 0.33, 1.00, 0.30, 0.60},
					 {-100.00, -0.80, 3.25, 5.00, 0.33, 1.00, 0.60, 0.85},
					 {-100.00, -0.80, 3.25, 5.00, 0.33, 1.00, 0.85, 1.00},
					 {-0.20, 0.00, 5.00, 15.00, 0.00, 0.55, 0.00, 0.05},
					 {-0.20, 0.00, 5.00, 15.00, 0.00, 0.55, 0.05, 0.10},
					 {-0.20, 0.00, 5.00, 15.00, 0.00, 0.55, 0.10, 0.17},
					 {-0.20, 0.00, 5.00, 15.00, 0.00, 0.55, 0.17, 0.30},
					 {-0.20, 0.00, 5.00, 15.00, 0.00, 0.55, 0.30, 0.60},
					 {-0.20, 0.00, 5.00, 15.00, 0.00, 0.55, 0.60, 0.85},
					 {-0.20, 0.00, 5.00, 15.00, 0.00, 0.55, 0.85, 1.00},
					 {-0.20, 0.00, 5.00, 15.00, 0.55, 1.00, 0.00, 0.05},
					 {-0.20, 0.00, 5.00, 15.00, 0.55, 1.00, 0.05, 0.10},
					 {-0.20, 0.00, 5.00, 15.00, 0.55, 1.00, 0.10, 0.17},
					 {-0.20, 0.00, 5.00, 15.00, 0.55, 1.00, 0.17, 0.30},
					 {-0.20, 0.00, 5.00, 15.00, 0.55, 1.00, 0.30, 0.60},
					 {-0.20, 0.00, 5.00, 15.00, 0.55, 1.00, 0.60, 0.85},
					 {-0.20, 0.00, 5.00, 15.00, 0.55, 1.00, 0.85, 1.00},
					 {-0.40, -0.20, 5.00, 15.00, 0.00, 0.55, 0.00, 0.05},
					 {-0.40, -0.20, 5.00, 15.00, 0.00, 0.55, 0.05, 0.10},
					 {-0.40, -0.20, 5.00, 15.00, 0.00, 0.55, 0.10, 0.17},
					 {-0.40, -0.20, 5.00, 15.00, 0.00, 0.55, 0.17, 0.30},
					 {-0.40, -0.20, 5.00, 15.00, 0.00, 0.55, 0.30, 0.60},
					 {-0.40, -0.20, 5.00, 15.00, 0.00, 0.55, 0.60, 0.85},
					 {-0.40, -0.20, 5.00, 15.00, 0.00, 0.55, 0.85, 1.00},
					 {-0.40, -0.20, 5.00, 15.00, 0.55, 1.00, 0.00, 0.05},
					 {-0.40, -0.20, 5.00, 15.00, 0.55, 1.00, 0.05, 0.10},
					 {-0.40, -0.20, 5.00, 15.00, 0.55, 1.00, 0.10, 0.17},
					 {-0.40, -0.20, 5.00, 15.00, 0.55, 1.00, 0.17, 0.30},
					 {-0.40, -0.20, 5.00, 15.00, 0.55, 1.00, 0.30, 0.60},
					 {-0.40, -0.20, 5.00, 15.00, 0.55, 1.00, 0.60, 0.85},
					 {-0.40, -0.20, 5.00, 15.00, 0.55, 1.00, 0.85, 1.00},
					 {-0.80, -0.40, 5.00, 15.00, 0.00, 0.55, 0.00, 0.05},
					 {-0.80, -0.40, 5.00, 15.00, 0.00, 0.55, 0.05, 0.10},
					 {-0.80, -0.40, 5.00, 15.00, 0.00, 0.55, 0.10, 0.17},
					 {-0.80, -0.40, 5.00, 15.00, 0.00, 0.55, 0.17, 0.30},
					 {-0.80, -0.40, 5.00, 15.00, 0.00, 0.55, 0.30, 0.60},
					 {-0.80, -0.40, 5.00, 15.00, 0.00, 0.55, 0.60, 0.85},
					 {-0.80, -0.40, 5.00, 15.00, 0.00, 0.55, 0.85, 1.00},
					 {-0.80, -0.40, 5.00, 15.00, 0.55, 1.00, 0.00, 0.05},
					 {-0.80, -0.40, 5.00, 15.00, 0.55, 1.00, 0.05, 0.10},
					 {-0.80, -0.40, 5.00, 15.00, 0.55, 1.00, 0.10, 0.17},
					 {-0.80, -0.40, 5.00, 15.00, 0.55, 1.00, 0.17, 0.30},
					 {-0.80, -0.40, 5.00, 15.00, 0.55, 1.00, 0.30, 0.60},
					 {-0.80, -0.40, 5.00, 15.00, 0.55, 1.00, 0.60, 0.85},
					 {-0.80, -0.40, 5.00, 15.00, 0.55, 1.00, 0.85, 1.00},
					 {-100.00, -0.80, 5.00, 15.00, 0.00, 0.55, 0.00, 0.05},
					 {-100.00, -0.80, 5.00, 15.00, 0.00, 0.55, 0.05, 0.10},
					 {-100.00, -0.80, 5.00, 15.00, 0.00, 0.55, 0.10, 0.17},
					 {-100.00, -0.80, 5.00, 15.00, 0.00, 0.55, 0.17, 0.30},
					 {-100.00, -0.80, 5.00, 15.00, 0.00, 0.55, 0.30, 0.60},
					 {-100.00, -0.80, 5.00, 15.00, 0.00, 0.55, 0.60, 0.85},
					 {-100.00, -0.80, 5.00, 15.00, 0.00, 0.55, 0.85, 1.00},
					 {-100.00, -0.80, 5.00, 15.00, 0.55, 1.00, 0.00, 0.05},
					 {-100.00, -0.80, 5.00, 15.00, 0.55, 1.00, 0.05, 0.10},
					 {-100.00, -0.80, 5.00, 15.00, 0.55, 1.00, 0.10, 0.17},
					 {-100.00, -0.80, 5.00, 15.00, 0.55, 1.00, 0.17, 0.30},
					 {-100.00, -0.80, 5.00, 15.00, 0.55, 1.00, 0.30, 0.60},
					 {-100.00, -0.80, 5.00, 15.00, 0.55, 1.00, 0.60, 0.85},
					 {-100.00, -0.80, 5.00, 15.00, 0.55, 1.00, 0.85, 1.00}}};
	std::cout << "Configuration loaded !" << endl;
}