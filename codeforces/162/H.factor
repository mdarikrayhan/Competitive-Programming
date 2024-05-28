USING: io kernel math sequences ascii ;

readln
[ odd? [ ch>lower ] [ ch>upper ] if ]
map-index print
