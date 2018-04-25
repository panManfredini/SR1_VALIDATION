void change_my_name(TString fileName) 
{

	TString OutDir = "normal_nx/";
	TString inDir =  "./";
  	
	gSystem->Exec(Form("mkdir -p %s", OutDir.Data()));

	TFile *f_in = TFile::Open(fileName);

	if(f_in == NULL)  { cout << "file does not exist" <<endl; exit(100); }
	
	if(fileName.Contains("V0")) { cout << " you are running on wrong file V0" << endl; exit(100); }

	bool isV1 = (fileName.Contains("V1") && !fileName.Contains("V2") );
	
	TString newFileName = fileName;
	if(isV1) {
		int index = newFileName.Index("V1");
		newFileName = newFileName.Replace(index + 1, 1, "0");
		newFileName = "extra_" + newFileName ;
		cout << newFileName << endl;
	}
	else {
		int index = newFileName.Index("V2");
		newFileName = newFileName.Replace(index + 1, 1, "1");
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
            if(isV1) {
		int index = treeNewName.Index("V1");
		treeNewName = treeNewName.Replace(index + 1, 1, "0");
	    }
	    else {
		int index = treeNewName.Index("V2");
		treeNewName = treeNewName.Replace(index + 1, 1, "1");
	    }
	    t->SetBranchStatus("*",1);
	    TTree *newTree = t->CloneTree();
	    f_out.cd();
	    newTree->Write(treeNewName);

        }

	f_out.Close();
}
