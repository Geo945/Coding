#Sa se scrie un shell script care primeste ca argumente pe linie de comanda 2 fisiere: unul de intrare si unul de iesire. Shell script-ul se va apela sub forma:
#./script.sh -i <input_file> -o <output_file>

#Fisierul de intrare este de urmatoarea forma: pe fiecare linie se gaseste cate o intrare formata dintr-o adresa URL si o adresa MAC despartite prin punct-si-virgula (;). 

#Exemplu:
#http://www.google.ro;00:11:22:33:44:55
#https://www.yahoo.com;77:88:99:AA:BB:CC

#Shell scriptul trebuie sa parcurga acest fisier si pentru fiecare linie sa scrie in fisierul de iesire OK sau ERROR daca adresa URL respectiv adresa MAC indeplineste anumite reguli. In cazul in care adresa URL si adresa MAC sunt valide pe linia respectiva se va scrie in fisierul de iesire OK. In caz contrat se va scrie error. 

#Exemplu:
#OK
#ERROR

#Regulile pentru adresa URL sunt urmatoarele:
#sa inceapa cu "http://" sau "https://"
#adresa trebuie sa se termine cu .com sau .ro sau .eu
#corpul adresei, partea de adresa de dupa "http://" sau "https://" sa contina litere mici, litere mari, cifre, cratime si sa inceapa obligatoriu cu litera mica
#Adresa MAC se considera ca este formata din 6 grupe de cate 2 cifre hexazecimale despartite prin doua-puncte (:). 

#Se vor folosi expresii regulate. Se recomanda utilizarea comenzii grep si studiul diferitilor parametri ce se pot da acestei comenzi. 

if test $# -eq 4
then
	if test ! -f $2
	then
		echo "Input file doesn't exist"
		exit
	fi
	
	if test -f $4
	then
		rm $4
	fi
	
	touch $4
	
	content=`cat $2`
	
	for i in $content
	do
		check=$( echo $i | egrep '^(http:\/\/|https:\/\/)[a-z][A-Za-z0-9.-]*(.ro|.com|.eu);[0-9A-F]{2}:[0-9A-F]{2}:[0-9A-F]{2}:[0-9A-F]{2}:[0-9A-F]{2}:[0-9A-F]{2}' )
		if test ! -z $check		
		then	
			echo "OK" >> $4
		else 
			echo "ERROR">> $4
		fi
	done
	
fi









 
