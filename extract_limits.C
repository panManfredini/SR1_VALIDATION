void extract_limits(TString filePath, TString out_dir){ //TString discoveryPath){


	TString OUT_DIR = out_dir; 
	//TString OUT_DIR = "LIMITS/aprv1/";
	//TString OUT_DIR = "LIMITS/egg_nx_bugfix/";

	TFile *f = TFile::Open(filePath);
	TTree *limits = (TTree*)f->Get("limit_tree");
	
	//TFile *f_disc = TFile::Open(discoveryPath);
	//TTree *disc = (TTree*)f_disc->Get("post_fit_tree");
	//cout << disc->GetName() << endl;
	
	const int n_masses = 3;
	double mass_list[n_masses] = {6, 10, 50.};
//	double mass_list[n_masses] = {6., 10., 50., 200.};
	
	//TGraphAsymmErrors sensitivity(TTree* tree, TString OutDir, double[] wimpMass, int N_mass)

	TGraphAsymmErrors limit_graph = plotHelpers::sensitivity(limits, OUT_DIR, mass_list, n_masses);
	
/*	                          // -1    0    +1     sigmas
	 double percents[3] = { 0.158655, 0.5, 0.841345 };
    	 double quantiles[3] = { 0. };
		
	TGraphAsymmErrors expected_discovery_pval(n_masses);
 
	for(int m =0; m <n_masses; m++){

		TString mass = TString::Format("%1.0f", mass_list[m] );
		
	        std::cout << "------->  mass " <<  mass_list[m]<< std::endl;
	        TH1F temp = plotHelpers::giveQuantiles(disc, percents, quantiles, 3, "q_mu", "q_mu>=-0.05 && mass ==" + mass);
		cout << "Quantiles -1sig=" << quantiles[0] << "  median= " <<quantiles[1] << "  +1sig=" << quantiles[2] << endl;
		double pval[3] = {0.};

		pval[0] = plotHelpers::givePval(limits, quantiles[0], "testStat_at0", "testStat_at0>=-0.05 && mass =="+mass);
		pval[1] = plotHelpers::givePval(limits, quantiles[1], "testStat_at0", "testStat_at0>=-0.05 && mass =="+mass);
		pval[2] = plotHelpers::givePval(limits, quantiles[2], "testStat_at0", "testStat_at0>=-0.05 && mass =="+mass);
		cout << "Pval -1sig=" << pval[0] << "  median= " <<pval[1] << "  +1sig=" << pval[2] << endl;
		expected_discovery_pval.SetPoint(m, mass_list[m], pval[1]);
		expected_discovery_pval.SetPointError(m, 0., 0.,  pval[1] - pval[2], pval[0] - pval[1]);
	}

//	expected_discovery_pval.Draw("A*");
	TFile f_out(OUT_DIR + "expected_discovery.root","RECREATE");
	expected_discovery_pval.Write("expected_discovery_pval");
	f_out.Close();

	*/
}
