{


    gStyle->SetOptStat(0);
    
    errorHandler::globalPrintLevel = 1;


//    pdfLikelihood *likeHood = getDMLikelihood(50., 0);
    CombinedProfileLikelihood* likeHood = getDMCombinedLikelihood(50.);

    likeHood->printEventSummary();
/*
    likeHood->getBkgComponent("acbg_yx_r0_f")->getScaleSys("ACscale0")->setCurrentValue(-1.);
    likeHood->getBkgComponent("acbg_yx_r0_f")->getScaleSys("ACscale0")->setType(FREE_PARAMETER);
    likeHood->getBkgComponent("hmc_extruded_yx_r0_f")->getScaleSys("CNNSscale0")->setCurrentValue(-1.);
    likeHood->getBkgComponent("hmc_extruded_yx_r0_f")->getScaleSys("CNNSscale0")->setType(FREE_PARAMETER);
    likeHood->getBkgComponent("wallbg_0.00_yx_r0_f")->getScaleSys("Wallscale0")->setCurrentValue(-0.99);
    likeHood->getBkgComponent("wallbg_0.00_yx_r0_f")->getScaleSys("Wallscale0")->setType(FREE_PARAMETER);
    likeHood->getBkgComponent("hbkg_Eth_0.00")->getScaleSys("ERscale0")->setCurrentValue(0.020123);
    likeHood->getBkgComponent("hbkg_Eth_0.00")->getScaleSys("ERscale0")->setType(FIXED_PARAMETER);
    likeHood->getBkgComponent("hbkg_Eth_0.00")->getShapeSys("_rf0_")->setCurrentValue(-0.39850);
    likeHood->getBkgComponent("hbkg_Eth_0.00")->getShapeSys("_rf0_")->setType(FIXED_PARAMETER);
    likeHood->getBkgComponent("hbkg_Eth_0.00")->getShapeSys("_py0_")->setCurrentValue(0.);
    likeHood->getBkgComponent("hbkg_Eth_0.00")->getShapeSys("_py0_")->setType(FIXED_PARAMETER);
*/
  
   likeHood->maximize(false);

    likeHood->printEventSummary();

    AsymptoticExclusion ae (likeHood, 0.05); // 95% CL comparison with Knut
   
    ae.computeLimits();
    ae.writeToFile("OBSERVED_LIMIT/ASYMPTOTICS/asy_");



}
