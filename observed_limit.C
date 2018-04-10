{



    gStyle->SetOptStat(0);
    
    gInterpreter->AddIncludePath("../Xephyr/src"); // in this case is just XEPHYR src from next dir.
    gROOT->ProcessLine(".L ../SR1/StatisticalAnalyses/xephyr_sr1_likelihood/src/likelihoodDef.cxx");

    errorHandler::globalPrintLevel = INFO;
    const int n_masses = 4;
    double mass[n_masses] = {6, 10, 50, 200};

    TFile *f = TFile::Open("../build/RESULTS/Quantum/egg_nx_before_correction/ts_distros_quantiles.root");
    //TFile *f = TFile::Open("../build/RESULTS/Quantum/egg/ts_distros_quantiles.root");
    //TFile *f = TFile::Open("../build/RESULTS/Quantum/egg_nx_bugfixed/egg_nx_bugfixed.root");
    //TFile *f = TFile::Open("../buts_distros_quantiles.root");

    for(int m=0; m<n_masses; m++){
	    TGraphAsymmErrors *quantiles = (TGraphAsymmErrors*)f->Get("quantiles_m"+ TString::Itoa(mass[m],10));

	    CombinedProfileLikelihood *likeHood = getDMCombinedLikelihood(mass[m]);
	    // CombinedProfileLikelihood *likeHood = getDMCombinedLikelihood(mass[m]);
	    //pdfLikelihood *likeHood = getDMLikelihood(mass[m], 0);

    
	    ToyFitterExclusion fitter("observed_M" + TString::Itoa(mass[m],10) );
	    fitter.setTheLikelihood(likeHood);
	    fitter.setOutputDir("OBSERVED_LIMIT/egg_nx/");
	    fitter.setInputDir("./"); 
	    //fitter.setTreeName(treeName);         // toy tree name prefix to fit in file
	    fitter.setRandomizeMeasure(false);       // if randomize or not the nuissance parameter measure (default to true)
	
	    fitter.setPrintLevel(DEBUG);
	    //likeHood.setPrintLevel(DEBUG);

	    // spitTheLimit(TGraphAsymmErrors *ninety_quantiles, int stopAt )
	    fitter.spitTheLimit(quantiles, 1);
    }

}
