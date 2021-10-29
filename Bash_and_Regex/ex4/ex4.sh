#Să se scrie un shell/bash script care primește ca parametru un director și un caracter după forma:
#set_mode.sh <director> <caracter>

#<caracter> specifică drepturi de scriere/citire/executie după forma (poate fi): 
#r - read
#w - write
#x - execute

#Script-ul va scana acel director (recursiv/nerecursiv) și pentru toate fisierele cu extensia .txt va seta dreptul după cum primește ca parametru. 

#Exemplu: 
#set_mode.sh directory x 

#va seta la toate fișierele cu extensia .txt dreptul de execute.

#Indicații:
#- pentru parsarea directoarelor se pot folosi comenzi precum ls (sau ls -l), cd
#- pentru setarea drepturilor se poate folosi comanda chmod
# apel: cd /.../ex4Cv      apoi    ./ex4.sh test (r/w/x)
if [ $# -eq 2 ]
then
	if [ ! -d $1 ]
	then
		echo "Directory $1 doesn't exist"
		exit
	fi
	files=$(cd $1 && ls *.txt)
	cd $1
	for i in $files
	do
		if [ -e $i ]
		then
			echo "The files $i exists, changing permission"
			{ sudo chmod +$2 $i; } && { echo "Granted $2 permission to file $i"; }
		fi
	done
else
	echo "This script takes 2 arguments: one directory and one permission to set"
fi




 
