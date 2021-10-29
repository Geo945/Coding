#Să se scrie un shell/bash script care primește ca parametru un director și un fișier de ieșire după forma:
#count.sh <director> <output_file>
#Script-ul va scana acel director și pentru fiecare fișier cu extensia .txt va afla numărul de caractere și va scrie în fișierul de ieșire pe câte o linie numele fișierului urmat de numărul de caractere găsit. La sfârșit, în fișierul de ieșire se va scrie o linie ce va conține numărul total de caractere sub forma "TOTAL <nr caractere>"
#Indicații:
#- pentru parsarea directoarelor se pot folosi comenzi precum ls (sau ls -l), cd
#- pentru aflarea numărului de caractere dintr-un fișier se poate folosi comanda wc (word cound - verificați pagina de manual)

#!/bin/sh

if [ $# -eq 2 ]
then

	if [ ! -d $1 ]
	then
		echo "Directory $1 doesn't exist"
		exit
	fi
	
	if [ -e $2 ]
	then
		rm $2
	fi
	touch $2
	
	total=0
	cd $1
	files=$(ls *.txt)
	
	for i in $files
	do
		content=$(cat $i)
		count=`echo $content | wc -m `
		total=`expr $total + $count`
		cd ..
		echo "${i}: $count">> $2
		cd $1
	done
	cd ..
	echo "TOTAL: $total">>$2
else
	echo "Script requires 2 arguments: <directory> <output_file>"
fi

