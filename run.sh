make
for filename in `ls *.spl`
do
    ./spl $filename
    echo "Now run '$filename'"
    ./a.out
    echo "\n"
done
