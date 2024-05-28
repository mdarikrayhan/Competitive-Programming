       Program-ID.C.
       Data	Division.
       Working-Storage	Section.
       77	S	Pic	X(11).
       77	i	Pic	9(10).
       77	w	Pic	X(11).
       77	t	Pic	9(10).
       77	k	Pic	9(10).
       Procedure Division.
       Accept	S.
       Accept	w.
       Move	w to k.
       Perform varying i from 1 by 1 until S(i:1)=' '
       	Compute t=function Ord(S(i:1))
       	Add	k to t;
       	IF t>91 then
       		Subtract 26 from t
       	End-if
        Display function char(t) with no advancing
       End-perform.
       Stop	Run.
