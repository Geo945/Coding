parOrImpar(){
	if [ $1 -eq '0' ]
	then echo $2 "Este par"
	else echo $2 "Este impar"
	fi
}

functie(){

	case $2 in
	"*") res=`expr $1 \* $3 ` 
	echo "Parametrul este: ori";;
	"+") res=`expr $1 + $3 `
	echo "Parametrul este: plus";;
	"-") res=`expr $1 - $3 `
	echo "Parametrul este: minus";;
	"/") res=`expr $1 / $3 `
	echo "Parametrul este: impartire";;
	esac
	
	p1=`expr $1 % 2`
	p2=`expr $3 % 2`
	p3=`expr $res % 2`

	parOrImpar $p1 $1
	parOrImpar $p2 $3
	parOrImpar $p3 $res
	writeToLog $res
}

writeToLog(){
	if test $1 -gt 5535
	then 
		echo $1 >> log.txt
	fi
}

if [ $# -eq 0 ]
then
	while read linie
	do
		res=`expr $linie`
		writeToLog $res
		echo ${linie}=$res
	done
elif [ $# -eq 3 ]
then
	functie $1 $2 $3
	echo $1$2${3}=$res		
elif [ $# -eq 4 ]
then
	file=$1
	shift
	functie $1 $2 $3
	echo $1$2${3}=$res >> $file		
fi
	
