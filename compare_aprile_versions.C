{

 gStyle->SetOptStat(0);
 
 const int N = 4;

 double limits[N] = {  3.707027E-47, 3.632972E-47, 3.692820E-47, 3.671992E-47  };
                     // ER1_RG1_W1  // ER2_RG1_W1 // ER2_RG2_W1 // ER2_RG2_W2 
 
 double x[N]  = { 1., 2., 3., 4. };

 const char *labels[N] = {"ER1_RG1_W1","ER2_RG1_W1","ER2_RG2_W1","ER2_RG2_W2"};
 
 TFile *f_ER1_RG1_W1 = TFile::Open("LIMITS/aprv1/sensitivity.root");
 TFile *f_ER2_RG1_W1 = TFile::Open("LIMITS/apr_ER2_RG1_W1/sensitivity.root");
 TFile *f_ER2_RG2_W1 = TFile::Open("LIMITS/apr_ER2_RG2_W1/sensitivity.root");
 TFile *f_ER2_RG2_W2 = TFile::Open("LIMITS/apr_ER2_RG2_W2/sensitivity.root");

 TGraphAsymmErrors *s_ER1_RG1_W1 = (TGraphAsymmErrors*) f_ER1_RG1_W1->Get("sensitivity_xsec_1s");
 TGraphAsymmErrors *s_ER2_RG1_W1 = (TGraphAsymmErrors*) f_ER2_RG1_W1->Get("sensitivity_xsec_1s");
 TGraphAsymmErrors *s_ER2_RG2_W1 = (TGraphAsymmErrors*) f_ER2_RG2_W1->Get("sensitivity_xsec_1s");
 TGraphAsymmErrors *s_ER2_RG2_W2 = (TGraphAsymmErrors*) f_ER2_RG2_W2->Get("sensitivity_xsec_1s");

 vector<TGraphAsymmErrors*> v_sensi;
 v_sensi.push_back(s_ER1_RG1_W1);
 v_sensi.push_back(s_ER2_RG1_W1);
 v_sensi.push_back(s_ER2_RG2_W1);
 v_sensi.push_back(s_ER2_RG2_W2);

 TGraphAsymmErrors g_sensi(N);
 TGraph g_limit(N, x, limits);

 TH1D *compa = new TH1D("compa","",N+2,-0.5,N+1.5);

 
 for(unsigned int i=0; i < (unsigned int)N; i++){

	 compa->Fill(x[i],(v_sensi[i])->GetY()[0] );
 	 compa->GetXaxis()->SetBinLabel(i+2, labels[i] ) ;
 	 g_sensi.SetPoint(i,x[i], (v_sensi[i])->GetY()[0] );
	 g_sensi.SetPointError( i,0,0, (v_sensi[i])->GetErrorYlow(0), (v_sensi[i])->GetErrorYhigh(0) );

	 cout << "| " << labels[i] << " | " << (v_sensi[i])->GetY()[0] << " | " << (v_sensi[i])->GetY()[0] + (v_sensi[i])->GetErrorYhigh(0)  << " | " << (v_sensi[i])->GetY()[0] - (v_sensi[i])->GetErrorYlow(0) << " | " << limits[i] << " | "<< endl;
 }


 g_sensi.SetFillColor(4);
 g_sensi.SetLineWidth(50);
 g_sensi.SetLineColor(kAzure -4);
 g_sensi.SetMarkerStyle(10);
// compa->GetYaxis()->SetRangeUser(1.E-48, 1.E-46);
 compa->SetLineColor(1);
 compa->Draw("axis");
 g_sensi.Draw("sameP");
 g_limit.Draw("same*");
 compa->Draw("hist same ][");
 
}
