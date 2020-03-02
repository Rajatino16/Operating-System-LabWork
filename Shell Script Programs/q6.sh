echo "enter the number"
read num 
y=num
sum=0
for((i=1;y>0;i++))
{
    x=$((y % 10))
    sum=$((sum + x))
    y=$((y/10))
}
echo "$sum"