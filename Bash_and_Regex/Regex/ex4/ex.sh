


if test $# -eq 1
then

	if test ! -f $1
	then
		echo "Invalid file"
		exit
	fi
	
	content=$( cat $1 )
	for i in $content
	do
		result=`echo $i | egrep -x '^\"?[A-Za-z][a-z]*( |,|;|?|:|!|.)?\"?$'`
		if test ! -z $result
		then
			echo "Cuvant: $result"
		fi
		
	done

fi

