{

/*
  TFile *f = TFile::Open("LIMITS/egg_nx/sensitivity.root");
  TFile *f_egg = TFile::Open("LIMITS/egg/sensitivity.root");
  TFile *f_full = TFile::Open("LIMITS/egg_nx_bugfix/sensitivity.root");

TGraphAsymmErrors *Exp_inner = (TGraphAsymmErrors*) f->Get("sensitivity_xsec_1s");
TGraphAsymmErrors *Exp_full = (TGraphAsymmErrors*) f_full->Get("sensitivity_xsec_1s");
TGraphAsymmErrors *Exp_egg = (TGraphAsymmErrors*) f_egg->Get("sensitivity_xsec_1s");
*/

  TFile *f = TFile::Open("OBSERVED_LIMIT/egg_nx/obs_limit_graph.root");
  TFile *f_egg = TFile::Open("OBSERVED_LIMIT/egg/obs_limit_graph.root");
  TFile *f_full = TFile::Open("OBSERVED_LIMIT/egg_nx_bugfixed/obs_limit_graph.root");

TGraphAsymmErrors *Exp_inner = (TGraphAsymmErrors*) f->Get("g_observed_limit");
TGraphAsymmErrors *Exp_full = (TGraphAsymmErrors*) f_full->Get("g_observed_limit");
TGraphAsymmErrors *Exp_egg = (TGraphAsymmErrors*) f_egg->Get("g_observed_limit");


TGraphAsymmErrors *sr0 = new TGraphAsymmErrors("x1t_firstdata_result.csv");

TCanvas *c1 = new TCanvas("limits", "limit", 600, 600);


sr0->SetFillColorAlpha(0,0.7);
sr0->SetLineColor(1);
sr0->SetMarkerColor(1);
sr0->SetLineWidth(3);
sr0->SetLineStyle(7);
sr0->SetMarkerSize(0);


sr0->SetTitle("");
sr0->GetYaxis()->SetTitle("#sigma [cm^{2}]");
sr0->GetXaxis()->SetTitle("M  [GeV]");
sr0->GetXaxis()->SetLimits(5.,20000.);
sr0->GetYaxis()->SetRangeUser(2E-47,1E-44);
sr0->GetXaxis()->SetLimits(5.,300.);

sr0->Draw("ALX");

//sr0->Print();

//sr0_obs->Print();


Exp_inner->SetFillColor(0);
Exp_inner->SetLineColor(3);
Exp_inner->SetMarkerColor(2);
Exp_inner->SetLineWidth(3);
Exp_inner->SetMarkerSize(1);

Exp_full->SetFillColor(0);
Exp_full->SetLineColor(4);
Exp_full->SetMarkerColor(4);
Exp_full->SetLineWidth(3);
Exp_full->SetMarkerSize(1);


Exp_egg->SetFillColor(0);
Exp_egg->SetLineColor(6);
Exp_egg->SetMarkerColor(6);
Exp_egg->SetLineWidth(3);
Exp_egg->SetMarkerSize(1);



Exp_inner->Draw("sameXL");
Exp_full->Draw("sameXL");
Exp_egg->Draw("sameXL");




TLegend* lego = new TLegend(0.2,0.9,0.5,0.7);
  lego->SetTextSize(0.033);
  lego->SetFillColor(0);
  lego->SetBorderSize(0);
//  lego->AddEntry(&run10PRL, "Observed run10 PRL 90\% CLs limit");
  lego->AddEntry(sr0, "SR0 LIMIT");
  lego->AddEntry(Exp_egg,"LIMIT EGG no NX");
  lego->AddEntry(Exp_inner, "LIMIT EGG+NX (before bugfix)");
  lego->AddEntry(Exp_full,"LIMIT EGG+NX (post bugfix)");
  lego->Draw();


gPad->SetLeftMargin(0.15);
gPad->SetLogy();
gPad->SetLogx();
gPad->RedrawAxis("g");


}
