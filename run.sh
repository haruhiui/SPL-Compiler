make
for filename in `ls *.spl`
do
    ./spl $filename
    echo "\nNow run '$filename'"
    ./a.out
done
