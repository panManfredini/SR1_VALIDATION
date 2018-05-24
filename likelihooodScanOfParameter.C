{

    gStyle->SetOptStat(0);
    
    errorHandler::globalPrintLevel = 1;

//    pdfLikelihood *likeHood = getTheLikelihoodToFit(10, 50, 0, 1);
    //CombinedProfileLikelihood* likeHood = getTheCombinedLikelihood(10,50,1);
    //pdfLikelihood *likeHood = getTheLikelihoodToFit("sr1",0, 50, 0, 1);
//    pdfLikelihood *likeHood = getDMLikelihood(50., 1);
   CombinedProfileLikelihood *likeHood = getDMCombinedLikelihood(50.);
   //pdfLikelihood *likeHood = getDMLikelihood(50., 0);
    
   TString out_dir = "./PARA_SCAN/apr_v2/";

    
    likeHood->setPrintLevel(INFO);
    likeHood->printCurrentParameters();

    
/*
 //Only likelihood scan
 
       likeHood->getPOI()->setMaximum(4);
    	TGraph *likeScan = likeHood->getGraphOfLogLikelihood(5);
    	likeScan->SetLineWidth(3);
    	likeScan->SetLineColor(4);
    	likeScan->SetTitle("signal events = 0");
    	likeScan->Draw("AC* PLC PFC");
  */ 

	 
    // Parameter sigmas
    TFile *f_sigmas  = TFile::Open("pulls_sr1/apr_v2/aprv2_pulls.root");
    TGraphAsymmErrors	*pulls = (TGraphAsymmErrors*)f_sigmas->Get("aprv2_pulls");

       	
    TString pdfName = "full_like_scan";

    TCanvas *c1 = new TCanvas();
//    c1->Print(out_dir +pdfName+".pdf[");

    map <int, LKParameter*> *params = likeHood->getParameters();

   double ll =  likeHood->maximize(false);

   double mu_hat = likeHood->getSigmaHat();   
    
    int itr = 0;
    TFile f (out_dir + pdfName+".root","RECREATE");

    for(ParameterIterator ip=params->begin(); ip!=params->end(); ip++){

	//if(itr !=0 ) {
	if(itr == 19 ) {

        	LKParameter *par = ip->second;
	
		// setting minimum and maximum of parameters based on pulls sigmas
   		double min_para = pulls->GetY()[itr] - pulls->GetErrorYlow(itr);
   		double max_para = pulls->GetY()[itr] + pulls->GetErrorYhigh(itr);
		// 1.5 sigma 
		if(min_para > 1E-3 || min_para < -1.E-3) min_para = min_para - min_para * 0.5;  
		max_para = max_para +  max_para * 0.5;  

		//par->setMinimum(min_para);
        	//par->setMaximum(max_para);
		par->setMinimum(-1);
        	par->setMaximum(0.1);
    

    		TGraph *likeScan = likeHood->getLikelihoodScanOfParameter(8,par, mu_hat);
    		likeScan->SetLineWidth(3);
    		likeScan->SetLineColor(4);
    		likeScan->SetTitle("signal best fit #mu = " + TString::Itoa(mu_hat,10) );
    		likeScan->Draw("AC* PLC PFC");
  
    		//gPad->BuildLegend();
  //      	c1->Print(out_dir + pdfName+".pdf[");
        	c1->Print(out_dir + TString(par->getName()) + ".png");
		likeScan->Write(par->getName());
	}

	itr++;

    }
    
    f.Close();

    //c1->Print( out_dir + pdfName+".pdf]");


}


