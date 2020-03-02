echo "Enter the first number"
read N
echo "Enter the second number"
read M


for (( i=$N+1; i <= $M-1; i++ ))
do
flag=0
for (( j=2; j <= $i-1; j++ ))
do
if [ `expr $i % $j` = 0 ]
then
flag=1
break
fi
done
if [ `expr $flag` = 0 ]
then
echo $i
fi
done