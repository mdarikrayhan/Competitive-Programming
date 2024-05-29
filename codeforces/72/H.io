b := File standardInput readLine
if(b at(0) == 45, "-" print)
b asMutable strip("-0") reverse print