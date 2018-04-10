{

   TFile *rad_file = TFile::Open("../../SR1/StatisticalAnalyses/inputs_for_likelihood/lax_1.4.0/models_extended/Background_wall_ac_templates_v4_SR1_2018-02-25.root");
   TH3F *wall = (TH3F*)rad_file->Get("wallbg_0.00") ;
   TH1D *R_pdf = (TH1D*) wall->Project3D("z");

   TFile *r = 0;

for(int i=18; i >=14; i = i -1){
	
	r = TFile::Open("Rmax_bin"+TString::Itoa(i,10)+".root");
	TGraphAsymmErrors *g = (TGraphAsymmErrors*)r->Get("expectedMedian");
	double r_max =	sqrt(R_pdf->GetXaxis()->GetBinUpEdge(i));
	g->SetTitle(TString::Format("Rmax %1.3f",r_max));
	g->SetLineWidth(2);
//	g->SetMarkerStyle(kFullCircle);
	if(i ==18) g->Draw("XCA* PLC PFC");
	else g->Draw("XC*  PLC PFC");

}

gPad->BuildLegend();
}
