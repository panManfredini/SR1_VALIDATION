{


TFile *f = TFile::Open("/home/pan/Downloads/distribution_events_rad_50_tot_template.root");


TH2D* radio = (TH2D*)f->Get("rad");


int nx = radio->GetNbinsX();
int ny = radio->GetNbinsY();

for (int x =1 ; x <= nx; x++){
	for(int y=1 ; y<= ny; y++){
		double pos_x = radio->GetXaxis()->GetBinCenter(x);
		double pos_y = radio->GetYaxis()->GetBinCenter(y);

		if(pos_x < 600) {
			if(pos_y > -11 || pos_y < -94) radio->SetBinContent(x, y, 0.);
		}
		else {
			double top_cut  = ( -11. +20. ) / (1800. - 600.) * (1800. - pos_x ) -20.;
			double bottom_cut  = ( -94. +86. ) / (1800. - 1400.) * (1800. - pos_x ) -86.;
			if( pos_y > top_cut ) radio->SetBinContent(x, y, 0.);
			
			if(pos_x < 1400 && pos_y < -94.)  radio->SetBinContent(x, y, 0.); 
			if(pos_x >= 1400 && pos_y < bottom_cut ) radio->SetBinContent(x, y, 0.);

			if(pos_x > 1800) radio->SetBinContent(x, y, 0.);

		}

	}
}

radio->Draw("COLZ");
new TCanvas();
radio->ProjectionX()->Draw();
}
