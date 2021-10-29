#Se considera o adresa MAC de forma: 
#001122334455

#Cerinta simpla: Sa se scrie un shell/bash script care transforma formatul adresei MAC de mai sus in urmatoul format:
#00:11:22:33:44:55

#Cerinta mai dificila: Aceasi cerinta ca si cerinta precedenta dar rezolvarea problemei sa se faca printr-o constructie folosind comanda sed.




#Rezolvare cerinta simpla:

if test $# -eq 1
then

	mac=$1
	if test ${#mac} -ne 12
	then
		echo "Argument should be 12 characters long"
		exit
	fi
	result=$(echo ${mac:0:2}:${mac:2:2}:${mac:4:2}:${mac:6:2}:${mac:8:2}:${mac:10:2} )

	echo "Cerinta simpla: $result"	

fi

#Rezolvare cerinta mai dificila:

if test $# -eq 1
then

	mac=$1
	if test ${#mac} -ne 12
	then
		echo "Argument should be 12 characters long"
		exit
	fi
	
	result=$(sed "s/\(..\)\(..\)\(..\)\(..\)\(..\)\(..\)/\1:\2:\3:\4:\5:\6/" <<< "$mac")
	echo "Cerinta mai dificila: $result"
	
fi




 
