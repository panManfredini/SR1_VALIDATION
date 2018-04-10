{


  TFile *f = TFile::Open("LIMITS/inner_volume_v1/sensitivity.root");
  TFile *f_obs = TFile::Open("OBSERVED_LIMIT/inner_volume_v1/obs_limit_graph.root");

TGraphAsymmErrors *Exp_limitsS1 = (TGraphAsymmErrors*) f->Get("sensitivity_xsec_1s");
TGraphAsymmErrors *Exp_limitsS2 = (TGraphAsymmErrors*) f->Get("sensitivity_xsec_2s");
TGraphAsymmErrors* Exp_limits = (TGraphAsymmErrors*)Exp_limitsS1->Clone("expectedMedian2");
TGraph		  *Obs_limit   = (TGraphAsymmErrors*)  f_obs->Get("g_observed_limit");


TGraphAsymmErrors *sr0 = new TGraphAsymmErrors("sensitivitySR0.txt");
TGraph *sr0_obs        = new TGraph("sr0_limit.txt");

TCanvas *c1 = new TCanvas("limits", "limit", 600, 600);


sr0->SetFillColorAlpha(4,0.7);
sr0->SetLineColor(4);
sr0->SetMarkerColor(4);
sr0->SetLineWidth(0);
sr0->SetMarkerSize(0);

sr0_obs->SetFillColor(0);
sr0_obs->SetLineColor(6);
sr0_obs->SetLineWidth(3);
sr0_obs->SetMarkerStyle(20);
sr0_obs->SetMarkerSize(1);


sr0->SetTitle("");
sr0->GetYaxis()->SetTitle("#sigma [cm^{2}]");
sr0->GetXaxis()->SetTitle("M  [GeV]");
sr0->GetXaxis()->SetLimits(5.,20000.);
sr0->GetYaxis()->SetRangeUser(1E-48,1E-43);
sr0->GetXaxis()->SetLimits(5.,20000.);
sr0->GetYaxis()->SetRangeUser(1E-48,1E-43);

sr0->Draw("ALE3");

//sr0->Print();

//sr0_obs->Print();


Exp_limitsS1->SetFillColorAlpha(3,0.5);
Exp_limitsS1->SetLineColor(3);
Exp_limitsS1->SetMarkerColor(3);
Exp_limitsS1->SetLineWidth(3);
Exp_limitsS1->SetMarkerSize(0);

Exp_limitsS2->SetFillColorAlpha(5,0.7);
Exp_limitsS2->SetLineColor(5);
Exp_limitsS2->SetLineWidth(3);
Exp_limitsS2->SetMarkerColor(5);
Exp_limitsS2->SetMarkerSize(0);


Obs_limit->SetFillColor(0);
Obs_limit->SetLineWidth(3);
Obs_limit->SetMarkerStyle(20);
Obs_limit->SetMarkerSize(1);


Exp_limits->SetFillColor(0.);
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
//LUX_limit->GetYaxis()->SetRangeUser(1E-48,1E-43);


Exp_limits->Print();
Exp_limitsS2->Draw("sameE3");
Exp_limitsS1->Draw("sameE3");
Exp_limits->Draw("sameLX");

//Exp_limits->Draw("PLX");
//run10PRL.Draw("samePL");
//Obs_limit->Draw("samePL");
Obs_limit->Draw("samePL");
sr0_obs->Draw("sameL");



TLegend* lego = new TLegend(0.2,0.9,0.5,0.7);
  lego->SetTextSize(0.033);
  lego->SetFillColor(0);
  lego->SetBorderSize(0);
//  lego->AddEntry(&run10PRL, "Observed run10 PRL 90\% CLs limit");
  lego->AddEntry(sr0_obs, "Observed SR0");
  lego->AddEntry(sr0, "1 #sigma SR0");
  lego->AddEntry(Obs_limit, "Observed SR1 SALTED ");
  lego->AddEntry(Exp_limits, "Expected SR1 ");
  lego->AddEntry(Exp_limitsS1,"1 #sigma","f");
  lego->AddEntry(Exp_limitsS2,"2 #sigma","f");
  //lego->AddEntry(LUX_limit,"No Safeguard");
  lego->Draw();


gPad->SetLeftMargin(0.15);
gPad->SetLogy();
gPad->SetLogx();
gPad->RedrawAxis("g");


}
