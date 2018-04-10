{

  TFile *f = TFile::Open("LIMITS/egg_nx_bugfix/sensitivity.root");
  TFile *f_obs = TFile::Open("OBSERVED_LIMIT/egg_nx_bugfixed/obs_limit_graph.root");


TGraphAsymmErrors *Exp_limitsS1 = (TGraphAsymmErrors*) f->Get("sensitivity_xsec_1s");
TGraphAsymmErrors *Exp_limitsS2 = (TGraphAsymmErrors*) f->Get("sensitivity_xsec_2s");
TGraphAsymmErrors* Exp_limits = (TGraphAsymmErrors*)Exp_limitsS1->Clone("expectedMedian2");
TGraph		  *Obs_limit   = (TGraphAsymmErrors*)  f_obs->Get("g_observed_limit");

//TGraph *LUX_limit    = (TGraph*)    fno->Get("observedLimitNoCLs"); 
//TGraph *LUX_limit    = new TGraph("LUX_full_exp_attempt.limit.txt");
TGraphAsymmErrors *sr0 = new TGraphAsymmErrors("x1t_firstdata_result.csv");

//sr0->SetFillColorAlpha(3,0.7);
sr0->SetFillColorAlpha(0,0.7);
sr0->SetLineColor(2);
sr0->SetMarkerColor(1);
sr0->SetLineWidth(3);
sr0->SetLineStyle(7);
sr0->SetMarkerSize(0);

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


Obs_limit->SetFillColor(0);
Obs_limit->SetLineWidth(3);
Obs_limit->SetMarkerStyle(20);
Obs_limit->SetMarkerSize(0.9);


Exp_limits->SetFillColor(0);
Exp_limits->SetMarkerStyle(7);
Exp_limits->SetMarkerSize(1);
Exp_limits->SetLineStyle(4);
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

sr0->GetXaxis()->SetLimits(5.,20000.);
sr0->SetMinimum(1E-48);
sr0->SetMaximum(1E-43);
sr0->GetYaxis()->SetRangeUser(1E-48,1E-43);

Exp_limitsS2->Draw("AP");
Exp_limitsS1->Draw("sameP");
Exp_limits->Draw("samePX");
//Exp_limits->Draw("PLX");
//run10PRL.Draw("samePL");
Obs_limit->Draw("sameP");
//Obs_limit->Draw("PL");
sr0->Draw("sameLX");


TLegend* lego = new TLegend(0.2,0.9,0.5,0.7);
  lego->SetTextSize(0.033);
  lego->SetFillColor(0);
  lego->SetBorderSize(0);
//  lego->AddEntry(&run10PRL, "Observed run10 PRL 90\% CLs limit");
  lego->AddEntry(Obs_limit, "Observed 90\% CL limit");
  lego->AddEntry(Exp_limits, "Expected 90\% CL limit");
  lego->AddEntry(Exp_limitsS1,"1 #sigma","f");
  lego->AddEntry(Exp_limitsS2,"2 #sigma","f");
  //lego->AddEntry(sr0,"No Safeguard");
  lego->AddEntry(sr0,"SR0");
  lego->Draw();


gPad->SetLogy();
gPad->SetLogx();
gPad->RedrawAxis("g");


}
