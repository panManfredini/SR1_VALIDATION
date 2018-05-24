void coverage()
{
//=========Macro generated from canvas: c1/c1
//=========  (Tue May  1 17:56:10 2018) by ROOT version6.10/00
   TCanvas *c1 = new TCanvas("c1", "c1",754,232,700,502);
   c1->Range(-4.470349e-08,0.8625,6,0.9375);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1001[3] = {
   1,
   2,
   5};
   Double_t Graph0_fy1001[3] = {
   0.9,
   0.9,
   0.9};
   Double_t Graph0_fex1001[3] = {
   0,
   0,
   0};
   Double_t Graph0_fey1001[3] = {
   0.01,
   0.01,
   0.01};
   TGraphErrors *gre = new TGraphErrors(3,Graph0_fx1001,Graph0_fy1001,Graph0_fex1001,Graph0_fey1001);
   gre->SetName("Graph0");
   gre->SetTitle("Graph");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#cccccc");
   gre->SetFillColor(ci);
   
   TH1F *Graph_Graph1001 = new TH1F("Graph_Graph1001","Graph",100,0.6,5.4);
   Graph_Graph1001->SetMinimum(0.87);
   Graph_Graph1001->SetMaximum(0.93);
   Graph_Graph1001->SetDirectory(0);
   Graph_Graph1001->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1001->SetLineColor(ci);
   Graph_Graph1001->GetXaxis()->SetTitle("True number of signal events");
   Graph_Graph1001->GetXaxis()->SetLabelFont(42);
   Graph_Graph1001->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1001->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph1001->GetXaxis()->SetTitleOffset(0.94);
   Graph_Graph1001->GetXaxis()->SetTitleFont(42);
   Graph_Graph1001->GetYaxis()->SetTitle("Coverage");
   Graph_Graph1001->GetYaxis()->SetLabelFont(42);
   Graph_Graph1001->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1001->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph1001->GetYaxis()->SetTitleOffset(0);
   Graph_Graph1001->GetYaxis()->SetTitleFont(42);
   Graph_Graph1001->GetZaxis()->SetLabelFont(42);
   Graph_Graph1001->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1001->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1001->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1001);
   
   gre->Draw("ae3l");
   
   Double_t Graph1_fx1002[3] = {
   0.9885387,
   2,
   5};
   Double_t Graph1_fy1002[3] = {
   0.9043038,
   0.899667,
   0.898333};
   Double_t Graph1_fex1002[3] = {
   0,
   0,
   0};
   Double_t Graph1_fey1002[3] = {
   0.01,
   0.01,
   0.01};
   gre = new TGraphErrors(3,Graph1_fx1002,Graph1_fy1002,Graph1_fex1002,Graph1_fey1002);
   gre->SetName("Graph1");
   gre->SetTitle("Graph");
   gre->SetLineColor(0);
   gre->SetMarkerStyle(4);
   gre->SetMarkerSize(1.5);
   
   TH1F *Graph_Graph1002 = new TH1F("Graph_Graph1002","Graph",100,0.6,5.4);
   Graph_Graph1002->SetMinimum(0.8857441);
   Graph_Graph1002->SetMaximum(0.9168109);
   Graph_Graph1002->SetDirectory(0);
   Graph_Graph1002->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1002->SetLineColor(ci);
   Graph_Graph1002->GetXaxis()->SetLabelFont(42);
   Graph_Graph1002->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1002->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1002->GetXaxis()->SetTitleFont(42);
   Graph_Graph1002->GetYaxis()->SetLabelFont(42);
   Graph_Graph1002->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1002->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1002->GetYaxis()->SetTitleOffset(0);
   Graph_Graph1002->GetYaxis()->SetTitleFont(42);
   Graph_Graph1002->GetZaxis()->SetLabelFont(42);
   Graph_Graph1002->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1002->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1002->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1002);
   
   gre->Draw("px");
   
   Double_t Graph2_fx1003[3] = {
   0.9971346,
   2,
   5};
   Double_t Graph2_fy1003[3] = {
   0.9018987,
   0.896222,
   0.897889};
   Double_t Graph2_fex1003[3] = {
   0,
   0,
   0};
   Double_t Graph2_fey1003[3] = {
   0.01,
   0.01,
   0.01};
   gre = new TGraphErrors(3,Graph2_fx1003,Graph2_fy1003,Graph2_fex1003,Graph2_fey1003);
   gre->SetName("Graph2");
   gre->SetTitle("Graph");
   gre->SetLineColor(0);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(1.5);
   
   TH1F *Graph_Graph1003 = new TH1F("Graph_Graph1003","Graph",100,0.6,5.4);
   Graph_Graph1003->SetMinimum(0.8836553);
   Graph_Graph1003->SetMaximum(0.9144557);
   Graph_Graph1003->SetDirectory(0);
   Graph_Graph1003->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1003->SetLineColor(ci);
   Graph_Graph1003->GetXaxis()->SetLabelFont(42);
   Graph_Graph1003->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1003->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1003->GetXaxis()->SetTitleFont(42);
   Graph_Graph1003->GetYaxis()->SetLabelFont(42);
   Graph_Graph1003->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1003->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1003->GetYaxis()->SetTitleOffset(0);
   Graph_Graph1003->GetYaxis()->SetTitleFont(42);
   Graph_Graph1003->GetZaxis()->SetLabelFont(42);
   Graph_Graph1003->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1003->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1003->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1003);
   
   gre->Draw("px");
   
   Double_t Graph3_fx1004[3] = {
   1,
   1.994269,
   5};
   Double_t Graph3_fy1004[3] = {
   0.913619,
   0.9041139,
   0.900476};
   Double_t Graph3_fex1004[3] = {
   0,
   0,
   0};
   Double_t Graph3_fey1004[3] = {
   0.01,
   0.01,
   0.01};
   gre = new TGraphErrors(3,Graph3_fx1004,Graph3_fy1004,Graph3_fex1004,Graph3_fey1004);
   gre->SetName("Graph3");
   gre->SetTitle("Graph");
   gre->SetLineColor(0);
   gre->SetMarkerColor(2);
   gre->SetMarkerStyle(29);
   gre->SetMarkerSize(2);
   
   TH1F *Graph_Graph1004 = new TH1F("Graph_Graph1004","Graph",100,0.6,5.4);
   Graph_Graph1004->SetMinimum(0.8871617);
   Graph_Graph1004->SetMaximum(0.9269333);
   Graph_Graph1004->SetDirectory(0);
   Graph_Graph1004->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1004->SetLineColor(ci);
   Graph_Graph1004->GetXaxis()->SetLabelFont(42);
   Graph_Graph1004->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1004->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1004->GetXaxis()->SetTitleFont(42);
   Graph_Graph1004->GetYaxis()->SetLabelFont(42);
   Graph_Graph1004->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1004->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1004->GetYaxis()->SetTitleOffset(0);
   Graph_Graph1004->GetYaxis()->SetTitleFont(42);
   Graph_Graph1004->GetZaxis()->SetLabelFont(42);
   Graph_Graph1004->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1004->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1004->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1004);
   
   gre->Draw("px");
   TLine *line = new TLine(0.9,0.9,5,0.9);
   line->SetLineColor(0);
   line->SetLineStyle(9);
   line->SetLineWidth(3);
   line->Draw();
   
   TLegend *leg = new TLegend(0.4398281,0.6708861,0.7406877,0.871308,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.033);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Graph2","Nominal coverage for EGG ","lpf");
   entry->SetFillStyle(1001);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1.5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph1","Nominal coverage for NO EGG","lpf");
   entry->SetFillStyle(1001);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(4);
   entry->SetMarkerSize(1.5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph3","Coverage for data driven switch","lpf");
   entry->SetFillStyle(1001);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(2);
   entry->SetMarkerStyle(29);
   entry->SetMarkerSize(2);
   entry->SetTextFont(42);
   leg->Draw();
   
   TPaveText *pt = new TPaveText(0.4398567,0.9342405,0.5601433,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextColor(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("Graph");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
