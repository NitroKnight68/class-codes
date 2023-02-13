VAR=$(grep -n History scammer.txt | cut -d ":" -f -1)
VAR=$((VAR+2))
echo "$VAR"
sed "${grep -n History scammer.txt | cut -d ":" -f -1}d" scammer.txt
