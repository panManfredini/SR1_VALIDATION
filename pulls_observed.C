{


    CombinedProfileLikelihood *likeHood = getDMCombinedLikelihood(50.);

	 
    // Parameter sigmas
    TFile *f_sigmas  = TFile::Open("pulls_sr1/apr_v2/aprv2_pulls.root");
    TGraphAsymmErrors	*pulls = (TGraphAsymmErrors*)f_sigmas->Get("aprv2_pulls");

       	
    map <int, LKParameter*> *params = likeHood->getParameters();

   double ll =  likeHood->maximize(false);

    int itr = 0;

   // build the bands
   TGraphAsymmErrors *band = (TGraphAsymmErrors*)pulls->Clone("band");
   TGraphAsymmErrors *band3 = (TGraphAsymmErrors*)pulls->Clone("band3");
   TGraphErrors band2(25);

   
    for (int i=0; i < 25; i++) { band->SetPoint(i,i,0); band->SetPointError(i, 0,0,1,1); band2.SetPoint(i,i,0); band2.SetPointError(i, 0,0); }
    for (int i=0; i < 25; i++) { band3->SetPoint(i,i,0); band3->SetPointError(i, 0,0,0,0); } 
   

    TGraph postfit(21);

    for(ParameterIterator ip=params->begin(); ip!=params->end(); ip++){
       	LKParameter *par = ip->second;

	double sigma_low =  pulls->GetErrorYlow(itr);
	double sigma_high =  pulls->GetErrorYhigh(itr);

	double val = par->getCurrentValue() -  pulls->GetY()[itr]  ;
	if(itr ==0 ) val = par->getCurrentValue() ;
	if(par->getMinimum() == 0.00001 || val > 0.)  postfit.SetPoint(itr, itr + 2, val / sigma_high);
        else postfit.SetPoint(itr, itr + 2, val / sigma_low);	
	
	if(par->getType() != FREE_PARAMETER && par->getType()!= PARAMETER_OF_INTEREST) band3->SetPointError(itr +2, 0.5,0.5,1./sigma_low,1./sigma_high);
	cout << val << endl;
  	itr++;
     }

    TCanvas *c1 = new TCanvas();
    
    postfit.SetMarkerStyle(20);

    band2.SetLineStyle(7);
    band2.SetLineWidth(3);
    pulls->GetYaxis()->SetTitle("(P - #bar_{P}) / #sigma_{P}");
    pulls->SetTitle("Observed Post-Fits WRT toy MC Error and Pre-fit Error");
    band->SetFillColorAlpha(3, 0.7);
    band3->SetFillColor(15);
    gPad->SetBottomMargin(0.38);
    gPad->SetLeftMargin(0.11);
    pulls->Draw("APX");
    band3->Draw("sameE2");
    band->Draw("sameE3");
    band2.Draw("sameL");
    postfit.Draw("sameP");


//    gPad->Update();
    gPad->RedrawAxis();


}
