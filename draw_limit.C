{

  //TFile *f = TFile::Open("LIMITS/egg_nx_bugfix/sensitivity.root");
  //TFile *f_obs = TFile::Open("OBSERVED_LIMIT/egg_nx_bugfixed/obs_limit_graph.root");
  TFile *f = TFile::Open("LIMITS/apr_ER2_RG2_W2/sensitivity.root");
  TFile *f_obs = TFile::Open("OBSERVED_LIMIT/apr_ER2_RG2_W2/obs_limit_graph.root");
/*
 x[0]=6, y[0]=4.11804e-44, exl[0]=0, exh[0]=0, eyl[0]=1.92352e-44, eyh[0]=3.95602e-44
x[1]=10, y[1]=6.33661e-46, exl[1]=0, exh[1]=0, eyl[1]=3.27165e-46, eyh[1]=5.75749e-46
x[2]=50, y[2]=3.24473e-47, exl[2]=0, exh[2]=0, eyl[2]=1.84128e-47, eyh[2]=2.54357e-47
x[3]=200, y[3]=8.32344e-47, exl[3]=0, exh[3]=0, eyl[3]=4.75616e-47, eyh[3]=6.03872e-47
root [3] sensitivity_xsec_2s->Print()
x[0]=6, y[0]=4.11804e-44, exl[0]=0, exh[0]=0, eyl[0]=2.43659e-44, eyh[0]=8.92661e-44
x[1]=10, y[1]=6.33661e-46, exl[1]=0, exh[1]=0, eyl[1]=4.15081e-46, eyh[1]=1.25912e-45
x[2]=50, y[2]=3.24473e-47, exl[2]=0, exh[2]=0, eyl[2]=2.54612e-47, eyh[2]=5.35861e-47
x[3]=200, y[3]=8.32344e-47, exl[3]=0, exh[3]=0, eyl[3]=6.55745e-47, eyh[3]=1.33878e-46

x[3]=200, y[3]=1.08565e-46, exl[3]=0, exh[3]=0, eyl[3]=0, eyh[3]=0
*/

TGraphAsymmErrors *Exp_limitsS1 = (TGraphAsymmErrors*) f->Get("sensitivity_xsec_1s");
TGraphAsymmErrors *Exp_limitsS2 = (TGraphAsymmErrors*) f->Get("sensitivity_xsec_2s");
TGraph		  *Obs_limit   = (TGraphAsymmErrors*)  f_obs->Get("g_observed_limit");

// adding the 200 GeV remove me!!
Exp_limitsS1->SetPoint(3, 200, 8.32344e-47);
Exp_limitsS1->SetPointError(3, 0,0, 4.75616e-47, 6.03872e-47);
Exp_limitsS2->SetPoint(3, 200, 8.32344e-47);
Exp_limitsS2->SetPointError(3, 0,0, 6.55745e-47, 1.33878e-46);
Obs_limit->SetPoint(3, 200, 1.08565e-46);

TGraphAsymmErrors* Exp_limits = (TGraphAsymmErrors*)Exp_limitsS1->Clone("expectedMedian2");


//TGraph *LUX_limit    = (TGraph*)    fno->Get("observedLimitNoCLs"); 
//TGraph *LUX_limit    = new TGraph("LUX_full_exp_attempt.limit.txt");
TGraph *SR1_public_limit    = new TGraph("uls.csv");
TGraphAsymmErrors *sr0 = new TGraphAsymmErrors("x1t_firstdata_result.csv");

//sr0->SetFillColorAlpha(3,0.7);
sr0->SetFillColorAlpha(0,0.7);
sr0->SetLineColor(2);
sr0->SetMarkerColor(1);
sr0->SetLineWidth(3);
sr0->SetLineStyle(7);
sr0->SetMarkerSize(0);

SR1_public_limit->SetLineColor(4);
SR1_public_limit->SetMarkerColor(4);
SR1_public_limit->SetLineWidth(3);
SR1_public_limit->SetLineStyle(7);
SR1_public_limit->SetMarkerSize(0);

TCanvas *c1 = new TCanvas("limits", "limit", 600, 600);

Exp_limitsS1->SetFillColor(3);
Exp_limitsS1->SetLineColor(3);
Exp_limitsS1->SetMarkerColor(3);
Exp_limitsS1->SetLineWidth(15);
Exp_limitsS1->SetMarkerSize(0);

Exp_limitsS2->SetFillColor(5);
Exp_limitsS2->SetLineColor(5);
Exp_limitsS2->SetLineWidth(15);
Exp_limitsS2->SetMarkerColor(5);
Exp_limitsS2->SetMarkerSize(0);


Obs_limit->SetFillColor(0);
Obs_limit->SetLineWidth(15);
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
SR1_public_limit->Draw("sameLX");


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
  lego->AddEntry(SR1_public_limit,"SR1+SR0 Published");
  lego->Draw();


gPad->SetLogy();
gPad->SetLogx();
gPad->RedrawAxis("g");


}
