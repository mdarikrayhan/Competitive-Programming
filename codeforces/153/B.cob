       Program-ID.B.
       Data	Division.
       Working-Storage	Section.
       77	T	Pic	X(99).
       77	X	Pic	9(10).
       77	A	Pic	X(99).
       77	Y	Pic 9(1).
       Procedure Division.
       Accept	T.
       Move	T	to	X.
       Perform until X=0
       	Divide	X by 2 giving X	Remainder Y
       	String	Y A into T
       	Move T to A
       End-perform.
       Display	A.
       Stop	Run.
