void setLikelihood(CombinedProfileLikelihood *likeHood, int G, int index, TTree *limit_tree){

	double        uncond_params[50] = {0.};
	int inputTreeIndex1 = 0;
	int Gen1 =0;
	int nParams = 0;

	
	limit_tree->SetBranchAddress("inputTreeIndex", &inputTreeIndex1);
//	limit_tree->SetBranchAddress("generation", &Gen);
	limit_tree->SetBranchAddress("uncond_params", uncond_params);
	limit_tree->SetBranchAddress("n_params", &nParams);

	bool isFound = false;

	for (Long64_t i=0; i< limit_tree->GetEntries(); i++) {
		limit_tree->GetEntry(i);
		if(inputTreeIndex1 == index){
			cout << "Fount Tree " << index << "   Generation " << G <<  " Nparams : "<< nParams<< endl;
			// set the likelihood
			map<int,LKParameter*> *params= likeHood->getParameters();
			int counter = 0;
			for(ParameterIterator ip=params->begin(); ip!=params->end(); ip++){
				LKParameter *param=ip->second;
				param->setCurrentValue(uncond_params[counter]);
				cout << "\t\tsetting parameter " << counter << "  to value " << uncond_params[counter] << endl; 
				counter++;
			}
			
			isFound = true;
			break;
		}
	}
	if(!isFound) {cout << "NOT FOUND!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl; exit(100) ; }
	limit_tree->ResetBranchAddress(NULL);
}

std::pair<double,double> getMuLimit(int G, int index, TTree *limit_tree){  

	int inputTreeIndex = 0;
	int Gen2 =0;
	double mu_limit = 0.;
	double lower_mu_limit = 0.;

	limit_tree->SetBranchAddress("inputTreeIndex", &inputTreeIndex);
	limit_tree->SetBranchAddress("lower_mu_limit", &lower_mu_limit);
	limit_tree->SetBranchAddress("mu_limit", &mu_limit);
//	limit_tree->SetBranchAddress("generation", &Gen);
	limit_tree->SetBranchStatus("*",1);
	limit_tree->SetBranchStatus("generation",0);

	bool isFound = false;

	for (Long64_t i=0; i< limit_tree->GetEntries(); i++) {
		limit_tree->GetEntry(i);
		if(inputTreeIndex == index){

			isFound = true;
			break;
		}
	}
	if(!isFound) {cout << "NOT FOUND!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl; exit(100) ; }

	cout << mu_limit << "    " << lower_mu_limit << endl;
	double dummy1 = mu_limit;
	double dummy2 = lower_mu_limit;
	std::pair<double,double> p(dummy1,dummy2);
	limit_tree->ResetBranchAddress(NULL);
	return p;
}


std::pair<double,double> coverage(CombinedProfileLikelihood *like, TString dataFile, TString egg_limitFile, TString noegg_limitFile, double mu_true){

	TFile F_data(dataFile);
	TFile F_egg(egg_limitFile);
	TFile F_noegg(noegg_limitFile);

	    int switching = 0;

	TTree *egg_lim_tree = (TTree*) F_egg.Get("limit_tree");
	TTree *noegg_lim_tree = (TTree*) F_noegg.Get("limit_tree");
//	TTree *noeegg_clone = noegg_lim_tree->CloneTree();
// LOOP over Trees in file ///
	double counter_tot =0.;
        double counter_cover = 0.;	
/// no eggg
	double        uncond_params[50] = {0.};
	int inputTreeIndex1 = 0;

	
	noegg_lim_tree->SetBranchAddress("inputTreeIndex", &inputTreeIndex1);
	noegg_lim_tree->SetBranchAddress("uncond_params", uncond_params);

	double mu_limit = 0.;
	double lower_mu_limit = 0.;

	noegg_lim_tree->SetBranchAddress("lower_mu_limit", &lower_mu_limit);
	noegg_lim_tree->SetBranchAddress("mu_limit", &mu_limit);

	TIter keyList(F_data.GetListOfKeys());
	TKey *key;
   	while ((key = (TKey*)keyList())) {
     	    TClass *cl = gROOT->GetClass(key->GetClassName());
      	    if (!cl->InheritsFrom("TTree")) continue;

	    TTree *data_tree = (TTree*)key->ReadObj();

	    float cs1 = 0.; 
            float cs2 = 0.;
	    int likelihoodType = 0;
	    int toyItr = 0;
	    int Gen = 0; 
	    
	    data_tree->SetBranchAddress("cs1",&cs1 ); 
	    data_tree->SetBranchAddress("cs2",&cs2 ); 
	    data_tree->SetBranchAddress("generation",&Gen ); 
	    data_tree->SetBranchAddress("likelihoodType",&likelihoodType ); 
	    data_tree->SetBranchAddress("toyItr",&toyItr ); 
	    data_tree->SetBranchStatus("*",1);
	    data_tree->GetEntry(0);
	
	    // load the likelihood
	    // set post fit values to likelihood
	    cout << "\n\nGetting likelihood for Gen " << Gen << "  toy " << toyItr << endl;
	//    setLikelihood(like, Gen, toyItr, noegg_lim_tree);
	bool isFound = false;

	for (Long64_t i=0; i< noegg_lim_tree->GetEntries(); i++) {
		noegg_lim_tree->GetEntry(i);
		if(inputTreeIndex1 == toyItr){
			cout << "Fount Tree " << toyItr << "   Generation " << Gen  << endl;
			// set the likelihood
			map<int,LKParameter*> *params= like->getParameters();
			int counter = 0;
			for(ParameterIterator ip=params->begin(); ip!=params->end(); ip++){
				LKParameter *param=ip->second;
				param->setCurrentValue(uncond_params[counter]);
				cout << "\t\tsetting parameter " << counter << "  to value " << uncond_params[counter] << endl; 
				counter++;
			}
			
			isFound = true;
			break;
		}
	}
	if(!isFound) {cout << "NOT FOUND!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl; exit(100) ; }

	    int Nwimplike_1 = 0;
	    int Nwimplike_2 = 0;
        
	    for (Long64_t i=0; i< data_tree->GetEntries(); i++) {
		   data_tree->GetEntry(i);

		   // Count how many Wimplike events in volume 0 and 1
		   double fb = plotHelpers::giveBackgroundLikelihood((pdfLikelihood*)like->getProfile(2), cs1, cs2) ;
		   double fs = plotHelpers::giveSignalLikelihood((pdfLikelihood*)like->getProfile(2), cs1, cs2) ;
		   if(fs >  fb && likelihoodType == 1 ) Nwimplike_2++ ;
		   if(fs >  fb && likelihoodType == 0 ) Nwimplike_1++; 
	    }
	    
	    cout << "Nwimplike_1 " << Nwimplike_1 << "  Nwimplike_2 " << Nwimplike_2 << endl;
	    // compute coverage flipping egg or not.
	    std::pair <double, double>  limit_mu;
	     if(Nwimplike_1 >= Nwimplike_2) {
//		     limit_mu = getMuLimit(Gen, toyItr, noegg_lim_tree);
//
	for (Long64_t i=0; i< noegg_lim_tree->GetEntries(); i++) {
		noegg_lim_tree->GetEntry(i);
		if(inputTreeIndex1 == toyItr){
			limit_mu = std::pair <double, double> (mu_limit,lower_mu_limit);
			isFound = true;
			break;
		}
		}
	     }
	     else  { limit_mu = getMuLimit(Gen, toyItr, egg_lim_tree); switching++;}
	     cout << limit_mu.first << "    " << limit_mu.second << endl;
	     if(limit_mu.first >= mu_true && limit_mu.second <= mu_true ) counter_cover += 1.; 
	     counter_tot++;

	}

	cout << " number of switched time in dataset " << switching << endl;
	std::pair<double,double> p(counter_cover,counter_tot);

	return p;
}
