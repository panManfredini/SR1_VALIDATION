{

    gStyle->SetOptStat(0);
    
    errorHandler::globalPrintLevel = 1;
    gInterpreter->AddIncludePath("../Xephyr/src"); // in this case is just XEPHYR src from next dir.
    gROOT->ProcessLine(".L ../SR1/StatisticalAnalyses/xephyr_sr1_likelihood/src/likelihoodDef.cxx");

//    pdfLikelihood *likeHood = getTheLikelihoodToFit(10, 50, 0, 1);
    //CombinedProfileLikelihood* likeHood = getTheCombinedLikelihood(10,50,1);
    //pdfLikelihood *likeHood = getTheLikelihoodToFit("sr1",0, 50, 0, 1);
//    pdfLikelihood *likeHood = getDMLikelihood(50., 1);
   CombinedProfileLikelihood *likeHood = getDMCombinedLikelihood(50.);
   //pdfLikelihood *likeHood = getDMLikelihood(50., 0);
    
    
    
    likeHood->setPrintLevel(INFO);
    likeHood->printCurrentParameters();
    likeHood->getPOI()->setMaximum(2);
    likeHood->getGraphOfLogLikelihood(5);

    	TGraph *likeScan = likeHood->getGraphOfLogLikelihood(5);
    	likeScan->SetLineWidth(3);
    	likeScan->SetLineColor(4);
    	likeScan->SetTitle("signal events = 0");
    	likeScan->Draw("AC* PLC PFC");
   
       /*	
    TString pdfName = "full_like_scan";

    TCanvas *c1 = new TCanvas();
    c1->Print("./PARA_SCAN/"+pdfName+".pdf[");

    map <int, LKParameter*> *params = likeHood->getParameters();

	likeHood->maximize(false);
    
    int itr = 0;
    TFile f ("./PARA_SCAN/"+pdfName+".root","RECREATE");

    for(ParameterIterator ip=params->begin(); ip!=params->end(); ip++){
    	itr++;
	if(itr == 1) continue;

        LKParameter *par = ip->second;

	//    likeHood->setTreeIndex(i);
    	likeHood->getPOI()->setMaximum(2);
    	//likeHood->setPrintLevel(ERROR);
    
//        par->setMinimum(-1.5);
//        par->setMaximum(1.5);
    
    //likeHood->getParameter(2)->setType(FIXED_PARAMETER);
    //likeHood->getParameter(2)->setCurrentValue(1.5);

    	TGraph *likeScan = likeHood->getLikelihoodScanOfParameter(5,par, 0.85);
    	likeScan->SetLineWidth(3);
    	likeScan->SetLineColor(4);
    	likeScan->SetTitle("signal events = 0.85");
    	likeScan->Draw("AC* PLC PFC");
  
    	gPad->BuildLegend();
        c1->Print("./PARA_SCAN/"+pdfName+".pdf[");
	likeScan->Write(par->getName());

    }
    
    f.Close();

    c1->Print("./PARA_SCAN/"+pdfName+".pdf]");

*/
}


