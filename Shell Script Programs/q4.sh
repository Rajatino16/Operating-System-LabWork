echo "enter the number"
read num

for((i=1;i<=10;i++))
{
  y=$((num * i))  #fact = fact * i
  echo -n "$y "
}
echo ""

   