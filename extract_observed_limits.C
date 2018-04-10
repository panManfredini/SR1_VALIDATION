void extract_limits(TString LimitFilePath, TString ObservedLimitFilePath){

	TFile *f_limit = TFile::Open(LimitFilePath);
	TTree *limits = (TTree*)f_limit->Get("limit_tree");
	
	TFile *f_obs = TFile::Open(ObservedLimitFilePath);
	TTree *obs_limits = (TTree*)f_obs->Get("limit_tree");

	const int n_masses = 4;
//	double mass_list[n_masses] = { 50.};
	double mass_list[n_masses] = {6., 10., 50., 200.};


	// extract observed limit to graph 
	TGraphAsymmErrors obs_lim(n_masses);
	TGraph obs_pval(n_masses);
	
	double     mu_limit = 0.;
 	double     limit    = 0.;
 	double     lower_limit = -1.; 
 	double     lower_mu_limit = -1.; 
 	double     testStat_at0 = 0.;
	double     mass = 0.;
    	

	obs_limits->SetBranchAddress("mu_limit", &mu_limit);
	obs_limits->SetBranchAddress("mass", &mass);
    	obs_limits->SetBranchAddress("lower_mu_limit", &lower_mu_limit);
    	obs_limits->SetBranchAddress("limit", &limit);
    	obs_limits->SetBranchAddress("lower_limit", &lower_limit);
    	obs_limits->SetBranchAddress("testStat_at0", &testStat_at0);

	for( Long64_t m =0; m < n_masses; m++){
		obs_limits->GetEntry(m);
		//double givePval(TTree *tree, double value, TString var, TString cut)
		double pval = plotHelpers::givePval(limits, testStat_at0, "testStat_at0", TString::Format("testStat_at0>=-0.05 && mass ==%1.f",mass_list[m]));
		cout << "mass "<<mass_list[m] << " Limit " << limit << " Ts_at0  " << testStat_at0 << "  p-val " << pval << endl;
		
		obs_lim.SetPoint(m, mass_list[m], limit);
		obs_pval.SetPoint(m, mass_list[m], pval);
		if(pval <= 1. - 0.9974) obs_lim.SetPointError(m, 0.,0., limit - lower_limit, 0.);
		
	}


	TFile fout("OBSERVED_LIMIT/egg/obs_limit_graph.root","RECREATE");
	
	fout.cd();
	obs_lim.Write("g_observed_limit");
	obs_pval.Write("g_observed_pval");
	
	fout.Close();
	
}
