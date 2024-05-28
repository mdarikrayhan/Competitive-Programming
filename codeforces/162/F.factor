USING: io kernel math math.parser ;
 
0
readln string>number
[ dup 0 > ]
[ 5 /i dup rot + swap ]
while
drop
number>string print
