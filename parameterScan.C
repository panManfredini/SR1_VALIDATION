{

    gStyle->SetOptStat(0);
    
    errorHandler::globalPrintLevel = 1;
    gInterpreter->AddIncludePath("../Xephyr/src"); // in this case is just XEPHYR src from next dir.
    gROOT->ProcessLine(".L ../SR1/StatisticalAnalyses/xephyr_sr1_likelihood/src/likelihoodDef.cxx");

//    pdfLikelihood *likeHood = getTheLikelihoodToFit(10, 50, 0, 1);
      pdfLikelihood *likeHood = getTheCombinedLikelihood(10, 50, 1);

    /*
    TString inputDir = "../RESULTS/GENtrees/";
    TString data_filename = "alternate_M50_mu20_G1.root";
    TString data_treeName = "alternate_M50_mu20_G1_3";
    TString calibration_filename = "null_G1_Cal.root";
    TString calibration_treeName = "null_G1_Cal0";

    dataHandler *data = new dataHandler("dmData",inputDir + data_filename, data_treeName);
    dataHandler *calibration = new dataHandler("calibration", inputDir + calibration_filename, calibration_treeName);
    

    likeHood.setDataHandler(data);
    likeHood.setCalibrationData(calibration);
    */
    
    likeHood->getPOI()->setMinimum(0.);
    likeHood->getPOI()->setMaximum(50);

    vector<TGraph*> likeScan = likeHood->getGraphOfParameters(10);

    TCanvas *c1 = new TCanvas();
    c1->Print("parascan.pdf[");
    for(unsigned int i=0; i < likeScan.size(); i++){
	    likeScan[i]->SetLineWidth(3);
	    likeScan[i]->SetLineColor(4);
	    likeScan[i]->Draw("AC*");
    	    c1->Print("parascan.pdf[");
    }

    c1->Print("parascan.pdf]");
}
