make
for filename in `ls *.spl`
do
    ./spl < $filename
    clang output.o
    echo "\nNow run '$filename'"
    ./a.out
done
make clean
