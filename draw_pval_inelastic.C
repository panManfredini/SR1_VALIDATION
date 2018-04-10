{

TFile *f_exp = TFile::Open("LIMITS/expected_discovery.root");
TFile *f_obs = TFile::Open("OBSERVED_LIMIT/obs_limit_graph.root");

TGraph *pval_obs = (TGraph*)f_obs->Get("g_observed_pval");
TGraphAsymmErrors *pval_exp = (TGraphAsymmErrors*)f_exp->Get("expected_discovery_pval");
TGraphAsymmErrors *pval_exp_line = (TGraphAsymmErrors*)pval_exp->Clone("line");


TColor *col26 = gROOT->GetColor(428);
col26->SetAlpha(0.01);

pval_exp->SetFillColorAlpha(428, 0.05);
pval_exp->SetLineColor(4);
pval_exp->SetMarkerColor(4);
pval_exp->SetLineWidth(3);
pval_exp->SetMarkerSize(0);

pval_exp_line->SetLineColor(4);
pval_exp_line->SetMarkerColor(4);
pval_exp_line->SetLineWidth(3);
pval_exp_line->SetMarkerSize(1);

pval_obs->SetFillColor(0);
pval_obs->SetLineWidth(3);
pval_obs->SetMarkerStyle(20);
pval_obs->SetMarkerSize(1);

double xmin = 500.;
double xmax = 1500.;

pval_exp->SetTitle("");
pval_exp->GetYaxis()->SetTitle("p_val null Hypo");
pval_exp->GetXaxis()->SetTitle("M  [GeV]");
pval_exp->GetXaxis()->SetLimits(xmin, xmax);
pval_exp->GetYaxis()->SetLimits(1E-5,1.);
pval_exp->GetYaxis()->SetRangeUser(1E-5,1.);

pval_exp->Draw("AE3");
pval_exp_line->Draw("same XPL");
pval_obs->Draw("sameP");


TLine *line_1sigma = new TLine(xmin + xmin*0.01 ,1. -0.682689492137086 ,xmax - xmax*0.01 , 1. -0.682689492137086); 
TLine *line_2sigma = new TLine(xmin + xmin*0.01,  1./22. ,xmax - xmax*0.01, 1./22.); 
TLine *line_3sigma = new TLine(xmin + xmin*0.01,  1./370. ,xmax - xmax*0.01, 1./370.); 
TLine *line_4sigma = new TLine(xmin + xmin*0.01, 1./15787.,xmax - xmax*0.01,1./15787.); 
TLine *line_5sigma = new TLine(xmin + xmin*0.01, 1./1744278.,xmax - xmax*0.01,1./1744278.); 


line_1sigma->SetLineWidth(3);
line_1sigma->SetLineStyle(9);
line_1sigma->SetLineColor(920);

line_2sigma->SetLineWidth(3);
line_2sigma->SetLineStyle(9);
line_2sigma->SetLineColor(920);

line_3sigma->SetLineWidth(3);
line_3sigma->SetLineStyle(9);
line_3sigma->SetLineColor(920);

line_4sigma->SetLineWidth(3);
line_4sigma->SetLineStyle(9);
line_4sigma->SetLineColor(920);

line_5sigma->SetLineWidth(3);
line_5sigma->SetLineStyle(9);
line_5sigma->SetLineColor(920);

line_1sigma->Draw("same");
line_2sigma->Draw("same");
line_3sigma->Draw("same");
line_4sigma->Draw("same");
line_5sigma->Draw("same");

   TText *t1 = new TText(xmax -xmax*0.1,0.5,"1 sigma");
   t1->SetTextAlign(22);
   t1->SetTextColor(920);
   t1->Draw("same");

   TText *t2 = new TText(xmax -xmax*0.1,1./15.,"2 sigma");
   t2->SetTextAlign(22);
   t2->SetTextColor(920);
   t2->Draw("same");
   
   TText *t3 = new TText(xmax -xmax*0.1,1./220.,"3 sigma");
   t3->SetTextAlign(22);
   t3->SetTextColor(920);
   t3->Draw("same");

   
   TText *t4 = new TText(xmax -xmax*0.1,1./10787,"4 sigma");
   t4->SetTextAlign(22);
   t4->SetTextColor(920);
   t4->Draw("same");

   TText *t5 = new TText(xmax -xmax*0.1,1./1044278.,"5 sigma");
   t5->SetTextAlign(22);
   t5->SetTextColor(920);
   t5->Draw("same");

TLegend* lego = new TLegend(0.2,0.9,0.5,0.7);
  lego->SetTextSize(0.033);
  lego->SetFillColor(0);
  lego->SetBorderSize(0);
//  lego->AddEntry(&run10PRL, "Observed run10 PRL 90\% CLs limit");
  lego->AddEntry(pval_obs, "Observed p-value");
  lego->AddEntry(pval_exp, "Expected pval for #sigma SR0 limit","f");
  //lego->AddEntry(LUX_limit,"No Safeguard");
  lego->Draw();

gPad->SetLogy();
gPad->RedrawAxis("g");

}
