void observed_limit(TString ts_quantiles_path, TString out_dir){



    gStyle->SetOptStat(0);
    
    errorHandler::globalPrintLevel = INFO;
    const int n_masses = 1;
    double mass[n_masses] = {200.};
    //double mass[n_masses] = {6, 10, 50.};
    //double mass[n_masses] = {6, 10, 50, 200};

    TFile *f = TFile::Open(ts_quantiles_path);
    //TFile *f = TFile::Open("../build/RESULTS/Quantum/egg_nx_before_correction/ts_distros_quantiles.root");
    //TFile *f = TFile::Open("../build/RESULTS/Quantum/egg/ts_distros_quantiles.root");
    //TFile *f = TFile::Open("../build/RESULTS/Quantum/egg_nx_bugfixed/egg_nx_bugfixed.root");
    //TFile *f = TFile::Open("../buts_distros_quantiles.root");

    for(int m=0; m<n_masses; m++){
	    TGraphAsymmErrors *quantiles = (TGraphAsymmErrors*)f->Get("quantiles_m50");
	    //TGraphAsymmErrors *quantiles = (TGraphAsymmErrors*)f->Get("quantiles_m"+ TString::Itoa(mass[m],10));

	    CombinedProfileLikelihood *likeHood = getDMCombinedLikelihood(mass[m]);
      	    //pdfLikelihood *likeHood = getDMLikelihood(50., 0);
	    // CombinedProfileLikelihood *likeHood = getDMCombinedLikelihood(mass[m]);
	    //pdfLikelihood *likeHood = getDMLikelihood(mass[m], 0);

    
	    ToyFitterExclusion fitter("observed_M" + TString::Itoa(mass[m],10) );
	    fitter.setTheLikelihood(likeHood);
	    fitter.setOutputDir(out_dir);
	    fitter.setInputDir("./"); 
	    //fitter.setTreeName(treeName);         // toy tree name prefix to fit in file
	    fitter.setRandomizeMeasure(false);       // if randomize or not the nuissance parameter measure (default to true)
	
	    fitter.setPrintLevel(DEBUG);
	    //likeHood.setPrintLevel(DEBUG);

	    // spitTheLimit(TGraphAsymmErrors *ninety_quantiles, int stopAt )
	    fitter.spitTheLimit(quantiles, 1);
    }

}
