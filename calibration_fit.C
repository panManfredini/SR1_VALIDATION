{

    gStyle->SetOptStat(0);
    
    errorHandler::globalPrintLevel = 1;
    gInterpreter->AddIncludePath("../Xephyr/src"); // in this case is just XEPHYR src from next dir.
    gROOT->ProcessLine(".L ../SR1/StatisticalAnalyses/xephyr_sr1_likelihood/src/likelihoodDef.cxx");

    pdfLikelihood *likeHood = getTheLikelihood_SR1_calibration(50.);


    likeHood->setPrintLevel(INFO);
    likeHood->getPOI()->setCurrentValue(1);

    double ll = likeHood->maximize(false);

    // class example to compare histograms
    histoCompare p = likeHood->getModelCompare();
    //p.setNameofComponent(1,"flat");
    //p.setNameofComponent(1,"AC");
    p.setNameofComponent(1, "AC");
    p.setNameofComponent(2, "ER");
    p.setNameofComponent(3, "WIMP 50 GeV - 10 Events");
    p.rebinY = 1;
    p.rebinX = 3;
    p.doStack = true;
    p.titleY = "Entries/[PE]";
    p.titleX = "log10(cS2_bottom [PE])";
    p.projectionMin = 1.7; //1.;
    p.projectionMax =  3.9; //70.;
    p.projectionX = true; //false;
//    p.compareWithRatio();
    p.compare();

   likeHood->printEventSummary(); 


}

