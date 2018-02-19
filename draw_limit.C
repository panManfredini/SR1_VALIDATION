{

  TFile *f = TFile::Open("sensitivity.root");


TGraphAsymmErrors *Exp_limitsS1 = (TGraphAsymmErrors*) f->Get("sensitivity_xsec_1s");
TGraphAsymmErrors *Exp_limitsS2 = (TGraphAsymmErrors*) f->Get("sensitivity_xsec_2s");
TGraphAsymmErrors* Exp_limits = (TGraphAsymmErrors*)Exp_limitsS1->Clone("expectedMedian2");
//TGraph		  *Obs_limit   ;// = (TGraph*) 	       f->Get("observedLimitNoCLs");

//TGraph *LUX_limit    = (TGraph*)    fno->Get("observedLimitNoCLs"); 
TGraph *LUX_limit    = new TGraph("LUX_full_exp_attempt.limit.txt");

TCanvas *c1 = new TCanvas("limits", "limit", 600, 600);

Exp_limitsS1->SetFillColor(3);
Exp_limitsS1->SetLineColor(3);
Exp_limitsS1->SetMarkerColor(3);
Exp_limitsS1->SetLineWidth(3);
Exp_limitsS1->SetMarkerSize(0);

Exp_limitsS2->SetFillColor(5);
Exp_limitsS2->SetLineColor(5);
Exp_limitsS2->SetLineWidth(3);
Exp_limitsS2->SetMarkerColor(5);
Exp_limitsS2->SetMarkerSize(0);

/*
Obs_limit->SetFillColor(0);
Obs_limit->SetLineWidth(3);
Obs_limit->SetMarkerStyle(20);
Obs_limit->SetMarkerSize(1);
*/

Exp_limits->SetFillColor(0);
Exp_limits->SetMarkerSize(3);
Exp_limits->SetLineStyle(7);
Exp_limits->SetLineWidth(3);


//Exp_limitsS2->GetYaxis()->SetTitle("#sigma#timesBR( #phi #rightarrow #tau#tau )  [pb]");
Exp_limitsS2->SetTitle("");
Exp_limitsS2->GetYaxis()->SetTitle("#sigma [cm^{2}]");

Exp_limitsS2->GetXaxis()->SetTitle("M  [GeV]");


Exp_limitsS2->GetXaxis()->SetLimits(5.,20000.);
Exp_limitsS2->GetYaxis()->SetRangeUser(1E-48,1E-43);

Exp_limits->GetXaxis()->SetLimits(5.,20000.);
//Exp_limits->GetYaxis()->SetRangeUser(1.,1E+15);
Exp_limits->GetYaxis()->SetRangeUser(1E-48,1E-43);

LUX_limit->SetLineColor(9);
LUX_limit->Draw("ALP");
LUX_limit->SetMinimum(1E-48);
LUX_limit->SetMaximum(1E-43);
//LUX_limit->GetYaxis()->SetRangeUser(1E-48,1E-43);

Exp_limitsS2->Draw("sameP");
Exp_limitsS1->Draw("sameP");
Exp_limits->Draw("PLX");
//run10PRL.Draw("samePL");
//Obs_limit->Draw("samePL");
//Obs_limit->Draw("PL");


TLegend* lego = new TLegend(0.2,0.9,0.5,0.7);
  lego->SetTextSize(0.033);
  lego->SetFillColor(0);
  lego->SetBorderSize(0);
//  lego->AddEntry(&run10PRL, "Observed run10 PRL 90\% CLs limit");
//  lego->AddEntry(Obs_limit, "Observed 90\% CL limit");
  lego->AddEntry(Exp_limits, "Expected 90\% CL limit");
  lego->AddEntry(Exp_limitsS1,"1 #sigma","f");
  lego->AddEntry(Exp_limitsS2,"2 #sigma","f");
  //lego->AddEntry(LUX_limit,"No Safeguard");
  lego->AddEntry(LUX_limit,"Lux");
  lego->Draw();


gPad->SetLogy();
gPad->SetLogx();
gPad->RedrawAxis("g");


}
