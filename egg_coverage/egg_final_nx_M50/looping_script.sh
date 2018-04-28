
outDir="normal_nx"

for f in *.root 
do 
	root -l -b -q "change_my_name.C(\"$f\")"
done

for f in *V0*.root 
do
	hadd $outDir/rebinned_$f $outDir/inner_rebinned_$f $outDir/extra_rebinned_$f
done

