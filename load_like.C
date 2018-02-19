{

    gInterpreter->AddIncludePath("../Xephyr/src"); // in this case is just XEPHYR src from next dir.
    gROOT->ProcessLine(".L ../SR1/StatisticalAnalyses/xephyr_sr1_likelihood/src/likelihoodDef.cxx");
    
    pdfLikelihood *likeHood = getTheLikelihoodToFit("sr1", 10, 50, 0, 1); //getTheLikelihood_SR1_outer(50.); // 50. GeV mass

    likeHood->getBkgComponent("hbkg")->plotInterpolatedSpace(false, 3,70, 5, true);

}
