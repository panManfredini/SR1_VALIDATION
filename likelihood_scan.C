{

    gStyle->SetOptStat(0);
    
    errorHandler::globalPrintLevel = 1;
    gInterpreter->AddIncludePath("../Xephyr/src"); // in this case is just XEPHYR src from next dir.
    gROOT->ProcessLine(".L ../SR1/StatisticalAnalyses/xephyr_sr1_likelihood/src/likelihoodDef.cxx");

    pdfLikelihood likeHood = getTheLikelihood(50.); // 50. GeV mass

    TString inputDir = "../RESULTS/GENtrees/";
    TString data_filename = "alternate_M50_mu100_G1.root";
    TString data_treeName = "alternate_M50_mu100_G1_484";
    TString calibration_filename = "null_G1_Cal.root";
    TString calibration_treeName = "null_G1_Cal0";

    dataHandler *data = new dataHandler("dmData",inputDir + data_filename, data_treeName);
    dataHandler *calibration = new dataHandler("calibration", inputDir + calibration_filename, calibration_treeName);

    likeHood.setDataHandler(data);
    likeHood.setCalibrationData(calibration);
    
   // likeHood.POI->setMinimum(0.);
    likeHood.POI->setMaximum(5);
    TGraph *likeScan = likeHood.getGraphOfLogLikelihood(10);

    likeScan->SetLineWidth(3);
    likeScan->SetLineColor(4);
    likeScan->Draw("A*");
   
}
