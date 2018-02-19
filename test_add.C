{

TFile f("CNNSBackgroundModel_SR1_From_Combined180104Fit.root","UPDATE");
TH2F *h_old = (TH2F*)f.Get("hmc");

TH2F *h_new = (TH2F*) h_old->Clone("cnns");

for(int x=1; x <=67; x++){
	for(int y=1; y <=125; y++){
		double c = h_new->GetBinContent(x,y) + 1.E-6;
		h_new->SetBinContent(x,y,c);
	}

}

h_new->Write("cnns");
f.Close();

}
