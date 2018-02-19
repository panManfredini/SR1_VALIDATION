{

    gStyle->SetOptStat(0);
    
    errorHandler::globalPrintLevel = 1;
    gInterpreter->AddIncludePath("../Xephyr/src"); // in this case is just XEPHYR src from next dir.
    gROOT->ProcessLine(".L ../SR1/StatisticalAnalyses/xephyr_sr1_likelihood/src/likelihoodDef.cxx");

//    pdfLikelihood *likeHood = getTheLikelihoodToFit(10, 50, 0, 1);
    CombinedProfileLikelihood* likeHood = getTheCombinedLikelihood(10,50,1);
/*
    TString inputDir = "../RESULTS/GENtrees/";
    TString data_filename = "alternate_M50_mu100_G1.root";
    TString data_treeName = "alternate_M50_mu100_G1_484";
    TString calibration_filename = "null_G1_Cal.root";
    TString calibration_treeName = "null_G1_Cal0";
*/
/*    TString inputDir = "../build/TEST/";
    TString data_filename = "e003_M50_mu10_G1.root";
    TString data_treeName = "e003_M50_mu10_G1_921";
    TString calibration_filename = "null_e001_G1_Cal.root";
    TString calibration_treeName = "null_e001_G1_Cal39";
    dataHandler *data = new dataHandler("dmData",inputDir + data_filename, data_treeName);
    dataHandler *calibration = new dataHandler("calibration", inputDir + calibration_filename, calibration_treeName);
*/
   // likeHood.setDataHandler(data);
   // likeHood.setCalibrationData(calibration);

    TCanvas *c1 = new TCanvas();
    c1->Print("like_scan_py.pdf[");

 //   for(int i=72; i < 82; i++){

    likeHood->setPrintLevel(INFO);
    likeHood->setTreeIndex(75);
    likeHood->getPOI()->setCurrentValue(1.);
    likeHood->maximize(true);
    likeHood->setPrintLevel(ERROR);
    
    //likeHood.POI->setMinimum(0.);
    //likeHood.POI->setMaximum(50);
    LKParameter* par = likeHood->getParameter(1);
    par->setMinimum(-2);
    par->setMaximum(2);
    
    likeHood->getParameter(2)->setType(FIXED_PARAMETER);
    likeHood->getParameter(2)->setCurrentValue(1.5);

    TGraph *likeScan = likeHood->getLikelihoodScanOfParameter(10,par, 1.);
    likeScan->SetLineWidth(3);
    likeScan->SetLineColor(4);
    likeScan->SetTitle("signal events = 0");
    likeScan->Draw("AC* PLC PFC");
  
    
    /*
    TGraph *likeScan1 = likeHood.getLikelihoodScanOfParameter(10,par, 10);
       likeScan1->SetLineWidth(3);
        likeScan1->SetLineColor(4);
        likeScan1->SetTitle("signal events = 10");
        likeScan1->Draw("C PLC PFC");
 */
   
       /*
		for(double mu =0.05 ; mu < 1; mu = mu + 0.2){  
        TGraph *likeScan1 = new TGraph(*likeHood.getLikelihoodScanOfParameter(10,par, mu));

        likeScan1->SetLineWidth(3);
        likeScan1->SetTitle("signal events = " + TString::Format("%1.1f",mu));
        likeScan1->Draw("C* PLC PFC");
   
    }
 */    
    gPad->BuildLegend();
    c1->Print("like_scan_py.pdf[");

//    }

    c1->Print("like_scan_py.pdf]");
}
