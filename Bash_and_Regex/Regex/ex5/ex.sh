#De citit linii de la tastatura daca repr o prop corecta afisam corect  
#Reguli: 
#-prop contine litere cifre spatii punct virgula. 
#-prop incepe cu litera mare 
#-se termina cu punct si nu mai contine alt punct in interior 
#-nu contine cuvantul "si" dupa virgula si oricate spatii ar fi intre virgula si "si"

regex1='^[A-Z]'
regex2='^[^.]*.$'
regex3=', *si'
regex4='[A-Za-z0-9,. ]*'

test="Mere, si."
test2="Mere, mere."

while read i
do

if test -z "$i"
then 
	exit
fi

echo $i | egrep '^[A-Z]' | egrep '^[^.]*.$' | egrep -v ', *si' | egrep -x '[A-Za-z0-9,. ]*'

done