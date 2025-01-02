USING: io kernel math math.parser ;
USING: io kernel math sequences ascii ;
IN: template


IN: template
 
: ctoa ( x -- x )
dup 65 < [ 48 - ] [ 65 - 10 + ] if
;
 
: atoc ( x -- x )
dup 10 < [ 48 + ] [ 10 - 65 + ] if
;
 
: stoa ( base s -- base x )
0
[ rot rot over * rot ctoa + ] reduce
;


0
readln string>number
readln string>number
swap
[ readln stoa rot + swap ] times

>base >upper print
