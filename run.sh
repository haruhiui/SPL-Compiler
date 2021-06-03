make
for filename in `ls *.spl *.pas`
do
    ./spl $filename
    echo "Now run '$filename'"
    ./a.out
    echo "\n"
done
