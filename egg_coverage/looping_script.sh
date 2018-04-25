
outDir="normal_nx"

for f in *.root 
do 
	root -l -b -q "change_my_name.C(\"$f\")"
done

for f in *V0*.root 
do
	hadd $outDir/$f $f $outDir/extra_$f
done

