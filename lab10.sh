
#SABA SYED 
#MATHEW CHUA
#LAB10

#!/bin/bash

clear

# SABA: Set the filename
FILENAME='for.results.sh'
# SABA: Check the file if it exists or not
if [ -f $FILENAME ] 
   then
   rm  $FILENAME
   echo $FILENAME is removed

fi

touch $FILENAME

# SABA: Set the FILENAME2
FILENAME2='while.results.sh'
# SABA: Check the file if it exists or not
if [ -f $FILENAME2 ]
   then
   rm  $FILENAME2
   echo $FILENAME2 is removed
fi

touch $FILENAME2 


echo Enter two numbers:
# SABA: ask two input
read -r A B
# SABA: assign temp
X=$A
Y=$B

# SABA: test for proper input number
test "$A" -eq "$A" 2>/dev/null
  if [ $? -ne 0 ]
  then 
	echo Input given is invalid sorry. Program would now exit
	exit 1
  fi

# SABA: test for proper input number2
test "$B" -eq "$B" 2>/dev/null
  if [ $? -ne 0 ]
  then 
	echo Input given is invalid sorry. Program would now exit
	exit 1
  fi

clear	

# SABA: Compute for LCM
TEMP=`expr $A \* $B`
while [ $A != $B ]
do
  if [ $A -gt $B ]
  then
    A=`expr $A - $B`
  else	
    B=`expr $B - $A`
  fi
done

LCM=`expr $TEMP / $B`

# SABA: print lcm
echo The Least Common Multiple of $X and $Y is: $LCM

# MATHEW: for loop start 
FOR_LOOP_START_TIME="$(date -u +%s%N)"

for FORNUMBER in `seq 1 1 1000`
do 
	# MATHEW:start time
	START_TIME="$(date -u +%s%N)"
	#MATHEW:format
	TIME1=$(date +"%H:%M:%s:%N")
	#MATHEW:condition mod for lcm
	if [ $(expr $FORNUMBER % $LCM) = "0" ]
	then
	#MATHEW:end time
	END_TIME="$(date -u +%s%N)"
	#MATHEW:end time format
	TIME2=$(date -u +"%H:%M:%s:%N")
	#MATHEW:compute for elapsed time
	ELAPSED="$(($END_TIME-$START_TIME))"
	#MATHEW:echo in for.result.sh
	echo Number: $FORNUMBER TIMESTART: $TIME1 TIMESTOP: $TIME2 Took $ELAPSED nanoseconds MontclairState >> $FILENAME
	#MATHEW:echo in stdout
	echo $FORNUMBER MontclairState

	# MATHEW:same comments just different conditions
	START_TIME="$(date -u +%s%N)"
	TIME1=$(date +"%H:%M:%s:%N")
	elif [ $(expr $FORNUMBER % $Y) = "0" ]
	then
	END_TIME="$(date -u +%s%N)"
	TIME2=$(date -u +"%H:%M:%s:%N")
	ELAPSED="$(($END_TIME-$START_TIME))"
	echo Number: $FORNUMBER TIMESTART: $TIME1 TIMESTOP: $TIME2 Took $ELAPSED nanoseconds State >> $FILENAME
	echo $FORNUMBER State

	START_TIME="$(date -u +%s%N)"
	TIME1=$(date +"%H:%M:%s:%N")
	elif [ $(expr $FORNUMBER % $X) = "0" ]
	then
	END_TIME="$(date -u +%s%N)"
	TIME2=$(date -u +"%H:%M:%s:%N")
	ELAPSED="$(($END_TIME-$START_TIME))"
	echo Number: $FORNUMBER TIMESTART: $TIME1 TIMESTOP: $TIME2 Took $ELAPSED nanoseconds Montclair >> $FILENAME
	echo $FORNUMBER Montclair
	
	START_TIME="$(date -u +%s%N)"
	TIME1=$(date +"%H:%M:%s:%N")
	else
	END_TIME="$(date -u +%s%N)"
	TIME2=$(date -u +"%H:%M:%s:%N")
	ELAPSED="$(($END_TIME-$START_TIME))"
	echo Number: $FORNUMBER TIMESTART: $TIME1 TIMESTOP: $TIME2 Took $ELAPSED nanoseconds NONE >> $FILENAME
	
	fi
	
done
# MATHEW:for loop end time
FOR_LOOP_END_TIME="$(date -u +%s%N)"
# MATHEW: compute for loop elapse time
FOR_LOOP_ELAPSE="$(($FOR_LOOP_END_TIME-$FOR_LOOP_START_TIME))"

# MATHEW: declare starting index for while loop
WHILENUMBER=1

# MATHEW:while loop start time
WHILE_LOOP_START_TIME="$(date -u +%s%N)"
while [ $WHILENUMBER -le 1000 ]
do 
	
	START_TIME="$(date -u +%s%N)"
	TIME1=$(date +"%H:%M:%s:%N")
	if [ $(expr $WHILENUMBER % $LCM) = "0" ]
	then
	END_TIME="$(date -u +%s%N)"
	TIME2=$(date -u +"%H:%M:%s:%N")
	ELAPSED="$(($END_TIME-$START_TIME))"
	echo Number: $WHILENUMBER TIMESTART: $TIME1 TIMESTOP: $TIME2 Took $ELAPSED nanoseconds MontclairState >> $FILENAME2
	echo $WHILENUMBER MontclairState

	START_TIME="$(date -u +%s%N)"
	TIME1=$(date +"%H:%M:%s:%N")
	elif [ $(expr $WHILENUMBER % $Y) = "0" ]
	then
	END_TIME="$(date -u +%s%N)"
	TIME2=$(date -u +"%H:%M:%s:%N")
	ELAPSED="$(($END_TIME-$START_TIME))"
	echo Number: $WHILENUMBER TIMESTART: $TIME1 TIMESTOP: $TIME2 Took $ELAPSED nanoseconds State >> $FILENAME2
	echo $WHILENUMBER State

	START_TIME="$(date -u +$s%N)"
	TIME1=$(date +"%H:%M:%s:%N")
	elif [ $(expr $WHILENUMBER % $X) = "0" ]
	then
	END_TIME="$(date -u +%s%N)"
	TIME2=$(date -u +"%H:%M:%s:%N")
	ELAPSED="$(($END_TIME-$START_TIME))"
	echo Number: $WHILENUMBER TIMESTART: $TIME1 TIMESTOP: $TIME2 Took $ELAPSED nanoseconds Montclair >> $FILENAME2
	echo $WHILENUMBER Montclair
	
	START_TIME="$(date -u +%s%N)"
	TIME1=$(date +"%H:%M:%s:%N")
	else
	END_TIME="$(date -u +%s%N)"
	TIME2=$(date -u +"%H:%M:%s:%N")
	ELAPSED="$(($END_TIME-$START_TIME))"
	echo Number: $WHILENUMBER TIMESTART: $TIME1 TIMESTOP: $TIME2 Took $ELAPSED nanoseconds NONE >> $FILENAME2
	
	fi

# MATHEW: while loop iteration
WHILENUMBER=$(( $WHILENUMBER + 1 ))
done

# MATHEW: while loop end time
WHILE_LOOP_END_TIME="$(date -u +%s%N)"
# MATHEW:while loop elapse
WHILE_LOOP_ELAPSE="$(($WHILE_LOOP_END_TIME-$WHILE_LOOP_START_TIME))"

#SABA: echo elapse times
echo For loop elapse time is $WHILE_LOOP_ELAPSE nanoseconds
echo While loop elapse time is $FOR_LOOP_ELAPSE nanoseconds

#SABA: let user know which loop is faster
if [ $WHILE_LOOP_ELAPSE -lt $FOR_LOOP_ELAPSE ]
then
    echo For loop is faster than while loop
else	
    echo While loop is faster than for loop
fi
