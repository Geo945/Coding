#Să se scrie un shell/bash script care afișează un mesaj personalizat după cum urmează:

#"<Salut>, <Username>!"

#<Salut> va avea următoarele valori:

#"Buna dimineata"    (dacă ora curentă este între 6am și 12pm)
#"Buna ziua"              (dacă ora curentă este între 12pm și 6pm)
#"Buna seara"            (dacă ora curentă este între 6pm și 10pm)
#"Noapte buna"        (dacă ora curentă este între 10pm și 6am)
#<Username> va fi numele utilizatorului conectat în acel moment.

#Script-ul se va apela sub forma:#
#./script.sh
#Hint: pentru a afla utilizatorul conectat puteți folosi comanda whoami, respectiv pentru a afla ora curentă puteți apela date urmat de un tipar pentru a extrage doar ora.

hour=`date +%H`
user=`whoami`
salut="Noapte buna"

if test $hour -ge 6
then
	if test $hour -le 12
	then	salut="Buna dimineata"
	fi
fi

if test $hour -gt 12
then 
	if test $hour -le 18
	then	salut="Buna ziua"
	fi
fi

if test $hour -gt 18
then
	if test $hour -le 22
	then	salut="Buna seara"
	fi
fi



echo $salut $user
