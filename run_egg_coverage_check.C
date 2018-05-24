{

    gROOT->ProcessLine(".L egg_coverage_check.C");

    TString  mu_str = "50";
    double   mu     = 5.;
    double sum_cover = 0.;
    double sum_all = 0.;
    
    CombinedProfileLikelihood *like = getTheCombinedLikelihood("egg_final_nx",5,50,3);
    for(int gen =1; gen <= 10; gen++){

	    TString Gen = TString::Itoa(gen,10);
	    std::pair<double,double> p = coverage(like, "egg_coverage/egg_final_nx_M50/normal_nx/rebinned_egg_final_nx_M50/rebinned_egg_final_nx_M50_mu"+mu_str+"_G"+Gen+"_V0.root","../build/RESULTS/LIMITtrees/limits_egg_final_nx_M50/limits_egg_final_nx_M50_G"+Gen+"_muTrue"+mu_str+".root", "../build/RESULTS/LIMITtrees/limits_rebinned_egg_final_nx_M50/limits_rebinned_egg_final_nx_M50_G"+Gen+"_muTrue"+mu_str+".root", mu);
	    sum_cover += p.first;
	    sum_all   += p.second;

    cout << "\n\n\n\n Partial coverage: " << sum_cover << " / " << sum_all << "  =  " << sum_cover / sum_all << endl;
    }	    


    cout << "\n\n\n\n Final coverage: " << sum_cover << " / " << sum_all << "  =  " << sum_cover / sum_all << endl;


}
