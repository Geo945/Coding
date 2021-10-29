#Să se scrie un shell/bash script care primește 3 argumente pe linie de comandă: primul și al treilea argument vor reprezenta operanzii, iar al doilea va reprezenta un operator aritmetic.

if test $# != 3
then 
	echo "Problema are nevoie de trei parametrii"
	exit 1
fi

result=`expr $1 $2 $3`

echo "The result is: $result"
