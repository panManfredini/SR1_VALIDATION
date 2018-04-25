void change_my_name(TString fileName) 
{

	TString OutDir = "normal_nx/";
	TString inDir =  "./";
	TString prefix = "rebinned_";
  	
	gSystem->Exec(Form("mkdir -p %s", OutDir.Data()));

	TFile *f_in = TFile::Open(fileName);

	if(f_in == NULL)  { cout << "file does not exist" <<endl; exit(100); }
	

	bool isV1 = (fileName.Contains("V1") && !fileName.Contains("V2") );
	
	TString newFileName = fileName;
	if(fileName.Contains("V0")) {
		newFileName = "inner_" + prefix + fileName;
	}
	else if(isV1) {
		int index = newFileName.Index("V1");
		newFileName = newFileName.Replace(index + 1, 1, "0");
		newFileName = "extra_" + prefix + newFileName ;
		cout << newFileName << endl;
	}
	else {
		int index = newFileName.Index("V2");
		newFileName = prefix + newFileName.Replace(index + 1, 1, "1");
		cout << newFileName << endl;
	}

	TFile f_out(OutDir + newFileName, "RECREATE");
	
	

	// loop over tree in file //
   	TIter keyList(f_in->GetListOfKeys());
	TKey *key;
   	while ((key = (TKey*)keyList())) {
     	    TClass *cl = gROOT->GetClass(key->GetClassName());
      	    if (!cl->InheritsFrom("TTree")) continue;

	    TTree *t = (TTree*)key->ReadObj();

 	    TString treeNewName(t->GetName());

	    if(fileName.Contains("V0")) {
		treeNewName = prefix + treeNewName;
	    }
	    else if(isV1) {
		int index = treeNewName.Index("V1");
		treeNewName = prefix + treeNewName.Replace(index + 1, 1, "0");
	    }
	    else {
		int index = treeNewName.Index("V2");
		treeNewName = prefix + treeNewName.Replace(index + 1, 1, "1");
	    }

	    
	    float cs1 = 0.; 
            float cs2 = 0.;
            string type = "DummyLabel";
	    int likelihoodType = 0;
	    int toyItr = 0;
	    int Gen = 0; 

	    t->SetBranchAddress("cs1",&cs1 ); 
	    t->SetBranchAddress("cs2",&cs2 ); 
//	    t->SetBranchAddress("type",&type ); 
	    t->SetBranchAddress("generation",&Gen ); 
	    t->SetBranchAddress("likelihoodType",&likelihoodType ); 
	    t->SetBranchAddress("toyItr",&toyItr ); 
	    t->SetBranchStatus("*",1);
        

	    TTree *newTree = new TTree(treeNewName, "sucker tree");
	    newTree->Branch("cs1",&cs1,"cs1/F");
            newTree->Branch("cs2",&cs2,"cs2/F");
            newTree->Branch("type",&type);
            newTree->Branch("generation",&Gen,"generation/I");
            newTree->Branch("likelihoodType",&likelihoodType,"likelihoodType/I");
            newTree->Branch("toyItr",&toyItr,"toyItr/I");  
		
	    for (Long64_t i=0; i< t->GetEntries(); i++) {
		   t->GetEntry(i);
		   newTree->Fill();
	    }

	    f_out.cd();
	    newTree->Write(treeNewName);



	}

	f_out.Close();
}
