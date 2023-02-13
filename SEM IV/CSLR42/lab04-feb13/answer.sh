sed --version
grep Tiruchirapalli scammer.txt | tail -1
sed 's/Tiruchirapalli/Trichy/g' scammer.txt > file1.txt
sed -e '0,/Trichy/s//TPJ/; 0,/Trichy/s//TPJ/; 0,/Trichy/s//TPJ/;' scammer.txt > file2.txt
sed -e '0,/city/s/city/Tiruchirapalli/' scammer.txt > file3.txt
sed '19d' scammer.txt > file4.txt
sed '19,20d' scammer.txt > file5.txt

sed '/^$/d' scammer.txt > file7.txt

