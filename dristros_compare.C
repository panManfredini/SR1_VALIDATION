{

    gStyle->SetOptStat(0);
    
    errorHandler::globalPrintLevel = 1;
    gInterpreter->AddIncludePath("../Xephyr/src"); // in this case is just XEPHYR src from next dir.
    gROOT->ProcessLine(".L ../SR1/StatisticalAnalyses/xephyr_sr1_likelihood/src/likelihoodDef.cxx");

    pdfLikelihood *likeHood = getTheLikelihoodByType(50., 0);
	    //getTheLikelihoodToFit(100, 50, 1, 1); //getTheLikelihood_SR1_outer(50.); // 50. GeV mass

    TString inputDir = "/home/pan/work/XEPHYR_PKG/SR1/StatisticalAnalyses/inputs_for_likelihood/lax_1.2.3/data/";
    TString data_filename = "xephyr_none_SR1_pax6.8.0_hax2.1.1_lax1.2.3_cs1LT200.root" ;
//    TString data_filename = "xephyr_none_SR1_pax6.8.0_hax2.4.0_lax1.4.0_cs1LT200_fv1_cuts1.root";

    TString data_treeName = "tree_inner";
    TString calibration_filename = "null_G1_Cal.root";
    TString calibration_treeName = "null_G1_Cal0";

  /*  TString inputDir = "lax_1.2.3/data/"; 
   
    TString data_filename = "xephyr_none_SR1_pax6.8.0_hax2.1.1_lax1.2.3_cs1LT200.root";
    TString data_treeName = "tree_inner";
    TString calibration_filename = "null_e001_G1_Cal.root";
    TString calibration_treeName = "null_e001_G1_Cal1";
*/
    dataHandler *data = new dataHandler("dmData",inputDir + data_filename, data_treeName);
   // dataHandler *calibration = new dataHandler("calibration", inputDir + calibration_filename, calibration_treeName);

    likeHood->setDataHandler(data);
//    likeHood->setCalibrationData(calibration);

    likeHood->setWithSafeGuard(false);
//    likeHood->setTreeIndex(2);
    likeHood->setPrintLevel(INFO);
    likeHood->initialize();
    likeHood->getPOI()->setCurrentValue(1);
    double ll = likeHood->maximize(false);

    // class example to compare histograms
    histoCompare p = likeHood->getModelCompare();
    //p.setNameofComponent(1,"flat");
    //p.setNameofComponent(1,"AC");
    p.setNameofComponent(1, "CNNS");
    p.setNameofComponent(2, "Radio");
    p.setNameofComponent(3, "AC");
    p.setNameofComponent(4, "Wall");
    p.setNameofComponent(5, "ER");
    p.setNameofComponent(6, "WIMP 50 GeV ");
    p.rebinY = 1;
    p.rebinX = 1;
    p.doStack = true;
    p.titleY = "Entries/[PE]";
    p.titleX = "log10(cS2_bottom [PE])";
    p.projectionMin = 1.;//2.; //1.;
    p.projectionMax =  70.;//3.9; //70.;
    p.projectionX = false; //false;
//    p.compareWithRatio();
    p.compare();

    p.printModels();

    likeHood->printEventSummary();

    TH2F er_bkg = likeHood->getBkgComponent("hbkg")->getDefaultHisto();
    int binMin = er_bkg.GetXaxis()->FindBin(p.projectionMin);
    int binMax = er_bkg.GetXaxis()->FindBin(p.projectionMax);
    er_bkg.RebinY(3);
    er_bkg.Scale(337./er_bkg.Integral());
    TH1D* pr_bkg = er_bkg.ProjectionY("_px",binMin, binMax);
    pr_bkg->SetLineColor(4);
    pr_bkg->SetLineWidth(3);
    pr_bkg->Draw("hist same");    

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
