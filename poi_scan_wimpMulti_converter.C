{


    gStyle->SetOptStat(0);
    
   // load likelihood 
   CombinedProfileLikelihood *likeHood = getDMCombinedLikelihood(50.);

   TFile *f = TFile::Open("PARA_SCAN/apr_v2/poi_scan.root");


   TGraph *g_mu = (TGraph*)f->Get("Graph");

   const int n = g_mu->GetN();
   
   double factor = likeHood->getSignalMultiplier() ; 

   // converting to wimp rate multiplier 

   TGraph g_wrm(n);


   for(int i=0; i < n; i++){

	g_wrm.SetPoint(i, g_mu->GetX()[i] * factor,  g_mu->GetY()[i] );

	cout << g_mu->GetY()[i] << endl;
   }

   g_wrm.GetYaxis()->SetTitle("-2Log(L(#sigma)/L(#hat{#sigma})");
   g_wrm.GetXaxis()->SetTitle("wimp_rate_multiplier");
   g_wrm.SetTitle("");
   g_wrm.SetLineColor(4);
   g_wrm.SetLineWidth(4);
   g_wrm.Draw("A*L");


}
