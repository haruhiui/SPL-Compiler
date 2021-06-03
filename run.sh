make
for filename in `ls *.spl *.pas`
do
    ./spl $filename
    echo "\nNow run '$filename'"
    ./a.out
done
