{


	TGraphErrors cov_egg_neutral(3);
	cov_egg_neutral.SetPoint(0,1., 0.901889);
	cov_egg_neutral.SetPoint(1,2.,0.896222 );
	cov_egg_neutral.SetPoint(2,5., 0.897889);
	cov_egg_neutral.SetPointError(0,0., 0.01);
	cov_egg_neutral.SetPointError(1,0., 0.01);
	cov_egg_neutral.SetPointError(2,0., 0.01);

	TGraphErrors cov_no_egg_neutral(3);
	cov_no_egg_neutral.SetPoint(0,1., 0.904222);
	cov_no_egg_neutral.SetPoint(1,2.,0.899667 );
	cov_no_egg_neutral.SetPoint(2,5., 0.898333);
	cov_no_egg_neutral.SetPointError(0,0., 0.01);
	cov_no_egg_neutral.SetPointError(1,0., 0.01);
	cov_no_egg_neutral.SetPointError(2,0., 0.01);

	TGraphErrors cov(3);
	cov.SetPoint(0,1., 0.913619);
	cov.SetPoint(1,2., 0.904095 );
	cov.SetPoint(2,5., 0.900476);
	cov.SetPointError(0,0., 0.01);
	cov.SetPointError(1,0., 0.01);
	cov.SetPointError(2,0., 0.01);

	TGraphErrors covi(3);
	covi.SetPoint(0,1., 0.9);
	covi.SetPoint(1,2., 0.9 );
	covi.SetPoint(2,5., 0.9);
	covi.SetPointError(0,0., 0.01);
	covi.SetPointError(1,0., 0.01);
	covi.SetPointError(2,0., 0.01);

	covi.SetFillColor(kGray);
	covi.Draw("AE3L");
	cov_no_egg_neutral.Draw("same*X");
	cov_egg_neutral.SetMarkerColor(2);
	cov_egg_neutral.Draw("same*X");
	cov.Draw("same*X");

	TLine *line = new TLine(0.9,0.9,5,0.9);
	line->SetLineColor(2);
	line->Draw("same");

TLegend* lego = new TLegend(0.2,0.9,0.5,0.7);
  lego->SetTextSize(0.033);
  lego->SetFillColor(0);
  lego->SetBorderSize(0);
//  lego->AddEntry(&run10PRL, "Observed run10 PRL 90\% CLs limit");
  lego->AddEntry(&cov_egg_neutral,"Nominal coverage for EGG ");
  lego->AddEntry(&cov_no_egg_neutral,"Nominal coverage for NO EGG");
  lego->AddEntry(&cov,"Coverage for data driven switch");
  lego->Draw();


}
