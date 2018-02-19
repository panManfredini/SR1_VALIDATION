{

   gStyle->SetOptTitle(kFALSE);
   gStyle->SetPalette(kSolar);
   double x[5]  = {1,2,3,4,5};
   double k0[5] = {1.0,2.0,1.0,2.5,3.0};
   double k2[5] = {1.1,2.1,1.1,2.6,3.1};
   double k3[5] = {1.2,2.2,1.2,2.7,3.2};
   double k4[5] = {1.3,2.3,1.3,2.8,3.3};
   double k5[5] = {1.4,2.4,1.4,2.9,3.4};
   TGraph *g1 = new TGraph(5,x,k0); g1->SetTitle("Graph with a red star");
   g1->Draw("CA* PLC PFC");
   g1 = new TGraph(5,x,k2); g1->SetTitle("Graph with a circular marker");
   g1->Draw("CA* PLC PFC");
   g1 = new TGraph(5,x,k3); g1->SetTitle("Graph with an open square marker");
   g1->Draw("CA* PLC PFC");
   g1= new TGraph(5,x,k4); g1->SetTitle("Graph with a blue star");
   g1->Draw("CA* PLC PFC");
   g1 = new TGraph(5,x,k5); g1->SetTitle("Graph with a full square marker");
   g1->Draw("CA* PLC PFC");
   gPad->BuildLegend();
}
