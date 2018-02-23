{

    TFile *f = TFile::Open("../../build/RESULTS/FITtrees/post_fit_sr1_eth.root");
    TTree *tree = (TTree*)f->Get("post_fit_tree");

    TCanvas *c1 = new TCanvas();
    
    tree->Draw("uncond_params[6]","mu_fit ==2");
    ((TH1F*)gPad->GetPrimitive("htemp"))->GetXaxis()->SetTitle("Eth");
    c1->Print("eth_distro.png");
    tree->Draw("uncond_params[6]:uncond_params[7]","mu_fit ==2");
    ((TH2F*)gPad->GetPrimitive("htemp"))->GetXaxis()->SetTitle("PY");
    ((TH2F*)gPad->GetPrimitive("htemp"))->GetYaxis()->SetTitle("Eth");
    c1->Print("corr_eth_py.png");
    tree->Draw("uncond_params[6]:uncond_params[8]","mu_fit ==2");
    ((TH2F*)gPad->GetPrimitive("htemp"))->GetXaxis()->SetTitle("RF");
    ((TH2F*)gPad->GetPrimitive("htemp"))->GetYaxis()->SetTitle("Eth");
    c1->Print("corr_eth_rf.png");
    tree->Draw("cond_params[6]:cond_params[0]","","COLZ");
    ((TH2F*)gPad->GetPrimitive("htemp"))->GetXaxis()->SetTitle("mu");
    ((TH2F*)gPad->GetPrimitive("htemp"))->GetYaxis()->SetTitle("Eth");
    c1->Print("corr_eth_mu.png");
    

}