USING: io kernel sequences math ;
 
readln
1 [ [ 0 ] [ CHAR: ( = [ 1 + ] [ 1 - ] if ] if-zero ] reduce
1 = [ "YES" ] [ "NO" ] if print
