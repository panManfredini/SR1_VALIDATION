{
   bool islow = false;

    gStyle->SetOptStat(0);
    
    errorHandler::globalPrintLevel = 1;
    gInterpreter->AddIncludePath("../Xephyr/src"); // in this case is just XEPHYR src from next dir.
    gROOT->ProcessLine(".L ../SR1/StatisticalAnalyses/xephyr_sr1_likelihood/src/likelihoodDef_splitvolume.cxx");


   TFile *rad_file = TFile::Open("../SR1/StatisticalAnalyses/inputs_for_likelihood/lax_1.4.0/models_extended/Background_wall_ac_templates_v4_SR1_2018-02-25.root");
   TH3F *wall = (TH3F*)rad_file->Get("wallbg_0.00") ;
   TH1D *R_pdf = (TH1D*) wall->Project3D("z");

   int maxmax = 21;
   int fix_bin = 17;
   if (islow) maxmax = 16;
   if (islow) fix_bin = 11;

   for(int max_bin = maxmax; max_bin >= fix_bin; max_bin = max_bin -1){

    for(int split_bin = 2; split_bin <= max_bin; split_bin++){ 
	 
	    cout << "Max bin " << max_bin << "   split bin " << split_bin << endl;

 	  CombinedProfileLikelihood *likeHood =  getTheCombinedLikelihood_split(50., split_bin, max_bin);
 
	  TString max_r = "Rmax"+TString::Itoa(max_bin,10) ;

	  AsymptoticExclusion ae (likeHood, 0.1);
	  ae.setAlternativeXAxisVal( R_pdf->GetXaxis()->GetBinLowEdge(split_bin) );
   
	  ae.computeSensitivity();
	  ae.writeToFile("VOLUME_SPLIT/"+max_r+"_");

	   delete likeHood;
	}
   }


}
