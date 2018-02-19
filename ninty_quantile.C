{

    gStyle->SetOptStat(0);
    
    errorHandler::globalPrintLevel = 1;
    gInterpreter->AddIncludePath("../Xephyr/src"); // in this case is just XEPHYR src from next dir.
    gROOT->ProcessLine(".L ../SR1/StatisticalAnalyses/xephyr_sr1_likelihood/src/likelihoodDef.cxx");

    pdfLikelihood likeHood = getTheLikelihood(50.); // 50. GeV mass

    TString inputDir = "../RESULTS/GENtrees/";
    TString data_filename = "null_G1.root";
    TString data_treeName = "null_G1_47";
    TString calibration_filename = "null_G1_Cal.root";
    TString calibration_treeName = "null_G1_Cal0";

    dataHandler *data = new dataHandler("dmData",inputDir + data_filename, data_treeName);
    dataHandler *calibration = new dataHandler("calibration", inputDir + calibration_filename, calibration_treeName);

    likeHood.setDataHandler(data);
    likeHood.setCalibrationData(calibration);

    TGraph g(3);
    g.SetPoint(0, -0.1, -0.1);
    g.SetPoint(1, 20, -0.1);
    g.SetPoint(1, 20, 7);
    
    likeHood.POI->setMinimum(0.);
    likeHood.POI->setMaximum(10);
    TGraph *likeScan = likeHood.getGraphOfLogLikelihood(10);

    g.GetXaxis()->SetRangeUser(0.,12.);
    g.GetYaxis()->SetRangeUser(0.,6.);
    g.GetYaxis()->SetTitle(likeScan->GetYaxis()->GetTitle());
    g.GetXaxis()->SetTitle("number of signal events");
    g.Draw("AP");

    likeScan->GetXaxis()->SetRangeUser(0, 12);
    likeScan->SetMinimum(0.);
    likeScan->SetMaximum(12.);
    likeScan->SetLineWidth(3);
    likeScan->SetLineColor(4);
    likeScan->Draw("sameC");
    TFile *f = TFile::Open("../RESULTS/Quantum/ts_distros_quantiles_m50.root");
    TGraphAsymmErrors *ninety_q = (TGraphAsymmErrors*)f->Get("quantiles_m50");


    ninety_q->Draw("sameP");

    TGraphAsymmErrors *g2 = (TGraphAsymmErrors*)ninety_q->Clone("fuck");
    g2->SetLineColor(2);
    g2->SetLineStyle(7);
    g2->Draw("sameC");
}