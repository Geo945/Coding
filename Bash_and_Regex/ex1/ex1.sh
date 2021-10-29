#Să se scrie un shell/bash script care primește 3 numere ca și argumente pe linie de comandă și afișeaza cel mai mare dintre ele.

if test $# != 3
then 
	echo "Problema are nevoie de trei parametrii"
	exit 1
fi

if test $1 -ge $2
then
	if test $1 -ge $3
	then	max=$1
	else
		max=$3
	fi
else
	if test $2 -ge $3
	then	max=$2
	else
		max=$3
	fi
fi

echo "Maximul este: $max"