{

    TString mu = "2";
    bool isUncond = false;

    gStyle->SetOptStat(0);
    
    errorHandler::globalPrintLevel = 1;
    //gInterpreter->AddIncludePath("../Xephyr/src"); // in this case is just XEPHYR src from next dir.
    //gROOT->ProcessLine(".L ../SR1/StatisticalAnalyses/xephyr_sr1_likelihood/src/likelihoodDef.cxx");
   gROOT->ProcessLine(".L style.C");
   setStyle();

    TString inputDir = "../build/RESULTS/FITtrees/";
//    TString filename = "post_fit_sr1_M50_mu100_G2.root"; 
    TString filename = "post_fit_sr1_M50.root";
    TString treeName = "post_fit_tree";


    TFile *f_pull = TFile::Open(inputDir+filename);
    TTree *tree   = (TTree*)f_pull->Get(treeName);

   TGraphErrors band(20);
   TGraphErrors band2(20);
    for (int i=0; i < 20; i++) { band.SetPoint(i,i,0); band.SetPointError(i, 0,1); band2.SetPoint(i,i,0); band2.SetPointError(i, 0,0); }

    TGraphAsymmErrors pull_mu = plotHelpers::pulls(tree, "./pulls/", "alt_1_" + mu, "mu_fit=="+mu,  isUncond );

    gPad->SetBottomMargin(0.25);
    
    pull_mu.SetMarkerStyle(20);
    if(isUncond) pull_mu.SetTitle("#mu_{true} = 2 Hypo Unconditional fit ");
    else pull_mu.SetTitle("#mu_{true} = 2 Conditional fit #mu="+mu +" events");
    //pull_mu.SetMinimum(-0.5);
    //pull_mu.SetMaximum(0.5);

    pull_mu.Draw("AP");

    band2.SetLineStyle(7);
    band2.SetLineWidth(3);

    band.SetFillColor(3);
    band.Draw("sameE3");
    band2.Draw("sameL");
    pull_mu.Draw("sameP");


//    gPad->Update();
    gPad->RedrawAxis();
    }
