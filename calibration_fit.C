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
    p.rebinY = 2;
    p.rebinX = 3;
    p.doStack = true;
    p.titleY = "Entries/[PE]";
    p.titleX = "log10(cS2_bottom [PE])";
    p.projectionMin = 1.;
    p.projectionMax = 70.;
    p.projectionX = false; //false;
//    p.compareWithRatio();
    p.compare();

   likeHood->printEventSummary(); 

    TH2F er_bkg = likeHood->getBkgComponent("hbkg")->getDefaultHisto();
    int binMin = er_bkg.GetXaxis()->FindBin(p.projectionMin);
    int binMax = er_bkg.GetXaxis()->FindBin(p.projectionMax);
    er_bkg.RebinY(2);
    er_bkg.Scale(5625./er_bkg.Integral());
    TH1D* pr_bkg = er_bkg.ProjectionY("_px",binMin, binMax);
    pr_bkg->SetLineColor(4);
    pr_bkg->SetLineWidth(3);
    pr_bkg->Draw("hist same");    

}

