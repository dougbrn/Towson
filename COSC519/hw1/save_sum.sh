#! /bin/bash
: '
The following script sums two numbers, prints the result and saves it to a file
'
#Add two numbers
a=17
b=5
((sum=a+b))

#Print to screen
echo "The Sum of " $a "and" $b "is" $sum

#save to file
tee sumfile.txt <<< $sum
cat sumfile.txt