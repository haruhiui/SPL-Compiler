make
touch log
rm -f log
touch log
echo "Result has been saved in the file 'log'"
echo "And error will directly been shown here:"
for filename in `ls *.spl *.pas`
do
    ./spl $filename >> log
    echo "Now run '$filename'" >> log
    ./a.out >> log
    echo "\n" >> log
done

