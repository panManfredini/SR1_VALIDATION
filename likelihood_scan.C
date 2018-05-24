{

    gStyle->SetOptStat(0);
    
    errorHandler::globalPrintLevel = 1;

   CombinedProfileLikelihood *likeHood = getDMCombinedLikelihood(50.);

    
    likeHood->getPOI()->setMaximum(6);
    TGraph *likeScan = likeHood->getGraphOfLogLikelihood(8);

    TCanvas *c1 = new TCanvas();
    likeScan->SetTitle("likelihood scan of the parameter of interest");
    likeScan->SetLineWidth(3);
    likeScan->SetLineColor(4);
    likeScan->Draw("A*L");
  
   TFile f("PARA_SCAN/apr_v2/poi_scan.root","RECREATE");

   likeScan->Write();
   f.Close();

   c1->Print("PARA_SCAN/apr_v2/poi_scan.png");

}
