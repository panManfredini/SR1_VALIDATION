{

    gStyle->SetOptStat(0);
    
    errorHandler::globalPrintLevel = 1;


      pdfLikelihood *likeHood = getDMLikelihood(50., 0);
//    CombinedProfileLikelihood *likeHood = getDMCombinedLikelihood(50.);
//    likeHood->getPOI()->setCurrentValue(129.6542);


    likeHood->printEventSummary();
//    double ll = likeHood->maximize(false);
    likeHood->printEventSummary(true);

    cout << " sig multipl. :  " << likeHood->getSignalMultiplier() << endl;


    // class example to compare histograms
    histoCompare p = likeHood->getModelCompare();
    p.setNameofComponent(1, "CNNS");
    p.setNameofComponent(2, "RadioNX");
    p.setNameofComponent(3, "Radio");
    p.setNameofComponent(4, "AC");
    p.setNameofComponent(5, "Wall");
    p.setNameofComponent(6, "ER");
    p.setNameofComponent(7, "WIMP 50 GeV ");
    p.rebinY = 1;
    p.rebinX = 1;
    p.doStack = true;
    p.titleY = "Entries/[PE]";
 //   p.titleX = "cS1 [PE]";
    p.titleX = "log10(cS2_bottom [PE])";
    p.projectionMin = 3.;//1.7; //1.;
    p.projectionMax = 70.;//3.9;
    p.projectionX = false;//    p.compareWithRatio();
    p.compare();

    p.printModels();


/*
    TH2F er_bkg = likeHood->getBkgComponent("hbkg")->getDefaultHisto();
    int binMin = er_bkg.GetXaxis()->FindBin(p.projectionMin);
    int binMax = er_bkg.GetXaxis()->FindBin(p.projectionMax);
    er_bkg.RebinY(3);
    er_bkg.Scale(337./er_bkg.Integral());
    TH1D* pr_bkg = er_bkg.ProjectionY("_px",binMin, binMax);
    pr_bkg->SetLineColor(4);
    pr_bkg->SetLineWidth(3);
    pr_bkg->Draw("hist same");    
*/

/*
    TH2F bkg = likeHood->bkg_components[0]->getInterpolatedHisto();
    TH2F sig = likeHood->signal_component->getInterpolatedHisto();

    TCanvas *c2 = new TCanvas();

    plotHelpers::addHisto(&bkg, &sig, 1.);
    bkg.Draw("colz");
    TGraph g_data = calibration->getS1S2();
    g_data.Draw("sameP");

    TFile *f_data = TFile::Open(inputDir+ calibration_filename);
    TTree *d_tree   = (TTree*)f_data->Get(calibration_treeName);
    d_tree->Draw("cs2:cs1", "type!=\"hbkg\"", "same*");
*/
}
