{

    gStyle->SetOptStat(0);
    
    errorHandler::globalPrintLevel = 1;
    gInterpreter->AddIncludePath("../Xephyr/src"); // in this case is just XEPHYR src from next dir.
    gROOT->ProcessLine(".L ../SR1/StatisticalAnalyses/xephyr_sr1_likelihood/src/likelihoodDef.cxx");

//    CombinedProfileLikelihood *likeHood = getTheCombinedLikelihood(10, 50, 1) ; // getTheLikelihoodToFit(10, 50, 0, 1); 
    pdfLikelihood *likeHood =  getTheLikelihoodToFit(10, 50, 0, 1); 

   likeHood->setWithSafeGuard(false);
   likeHood->initialize();
 
//    likeHood->setPrintLevel(DEBUG);
   
   AsymptoticExclusion ae (likeHood, 0.1);





 ae.generateAndSetAsimov(0.);
   ae.computeSensitivity();


}
