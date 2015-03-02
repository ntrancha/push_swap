timestamp() {
  date +"%T"
}
echo "Compilation"
gcc *.c -I libft/includes/ libft/libft.a -g
echo "Génération de stacks"
python -c "import random; print ' '.join([str(a) for a in random.sample(xrange(0, $1), $1)])" > random
python -c "import random; print ' '.join([str(a) for a in random.sample(xrange(0, $1), $1)])" > random2
python -c "import random; print ' '.join([str(a) for a in random.sample(xrange(0, $1), $1)])" > random3
python -c "import random; print ' '.join([str(a) for a in random.sample(xrange(0, $1), $1)])" > random4
python -c "import random; print ' '.join([str(a) for a in random.sample(xrange(0, $1), $1)])" > random5
rm -rf result*
t1=`date +%s`;
./a.out `cat random` | wc -w >> result
t2=`date +%s`;
tf=`expr $t2 - $t1`
result=`cat result`
echo "$result en ${tf}s"
t1=`date +%s`;
./a.out `cat random2` | wc -w > result2
t2=`date +%s`;
tf=`expr $t2 - $t1`
result=`cat result2`
echo "$result en ${tf}s"
t1=`date +%s`;
./a.out `cat random3` | wc -w > result3
t2=`date +%s`;
tf=`expr $t2 - $t1`
result=`cat result3`
echo "$result en ${tf}s"
t1=`date +%s`;
./a.out `cat random4` | wc -w > result4
t2=`date +%s`;
tf=`expr $t2 - $t1`
result=`cat result4`
echo "$result en ${tf}s"
t1=`date +%s`;
./a.out `cat random5` | wc -w > result5
t2=`date +%s`;
tf=`expr $t2 - $t1`
result=`cat result5`
echo "$result en ${tf}s"
