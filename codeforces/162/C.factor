USING: io kernel math math.parser ;
USING: io kernel math sequences ascii ;

""
readln
string>number
[ dup 2 mod 0 = over 2 > and ]
[ swap "*" append "2" append swap 2 / ] while
[ dup 3 mod 0 = over 3 > and ]
[ swap "*" append "3" append swap 3 / ] while
[ dup 5 mod 0 = over 5 > and ]
[ swap "*" append "5" append swap 5 / ] while
[ dup 7 mod 0 = over 7 > and ]
[ swap "*" append "7" append swap 7 / ] while
[ dup 11 mod 0 = over 11 > and ]
[ swap "*" append "11" append swap 11 / ] while
[ dup 13 mod 0 = over 13 > and ]
[ swap "*" append "13" append swap 13 / ] while
[ dup 17 mod 0 = over 17 > and ]
[ swap "*" append "17" append swap 17 / ] while
[ dup 19 mod 0 = over 19 > and ]
[ swap "*" append "19" append swap 19 / ] while
[ dup 23 mod 0 = over 23 > and ]
[ swap "*" append "23" append swap 23 / ] while
[ dup 29 mod 0 = over 29 > and ]
[ swap "*" append "29" append swap 29 / ] while
[ dup 31 mod 0 = over 31 > and ]
[ swap "*" append "31" append swap 31 / ] while
[ dup 37 mod 0 = over 37 > and ]
[ swap "*" append "37" append swap 37 / ] while
[ dup 41 mod 0 = over 41 > and ]
[ swap "*" append "41" append swap 41 / ] while
[ dup 43 mod 0 = over 43 > and ]
[ swap "*" append "43" append swap 43 / ] while
[ dup 47 mod 0 = over 47 > and ]
[ swap "*" append "47" append swap 47 / ] while
[ dup 53 mod 0 = over 53 > and ]
[ swap "*" append "53" append swap 53 / ] while
[ dup 59 mod 0 = over 59 > and ]
[ swap "*" append "59" append swap 59 / ] while
[ dup 61 mod 0 = over 61 > and ]
[ swap "*" append "61" append swap 61 / ] while
[ dup 67 mod 0 = over 67 > and ]
[ swap "*" append "67" append swap 67 / ] while
[ dup 71 mod 0 = over 71 > and ]
[ swap "*" append "71" append swap 71 / ] while
[ dup 73 mod 0 = over 73 > and ]
[ swap "*" append "73" append swap 73 / ] while
[ dup 79 mod 0 = over 79 > and ]
[ swap "*" append "79" append swap 79 / ] while
[ dup 83 mod 0 = over 83 > and ]
[ swap "*" append "83" append swap 83 / ] while
[ dup 89 mod 0 = over 89 > and ]
[ swap "*" append "89" append swap 89 / ] while
[ dup 97 mod 0 = over 97 > and ]
[ swap "*" append "97" append swap 97 / ] while
"*" swap number>string append append rest print
