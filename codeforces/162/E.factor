USING: io kernel math math.parser ;
USING: io kernel math sequences ascii ;


readln
dup
dup
0
swap
[ CHAR: H = ] any? [ 1 + ] [ ] if
swap
[ CHAR: Q = ] any? [ 1 + ] [ ] if
swap
[ CHAR: 9 = ] any? [ 1 + ] [ ] if
0 > [ "YES" print ] [ "NO" print ] if
