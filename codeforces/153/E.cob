       Program-ID.E.
       Data Division.
       Working-Storage Section.
       01	s	Pic	X(12).
       01	t	Pic 9(9).
       01	a	Pic 9(9).
       01	i	Pic 9(9).
       01	j	Pic 9(9).
       01	n	Pic 9(9).
       01	.
       	03	x	Pic S9(9)	Occurs 64 times.
       	03	y	Pic	S9(9)	Occurs 64 times.
       Procedure	Division.
       Accept s.
       Move s to n;
       Perform varying i from 1 by 1 until i>n
       	Accept s
       	Move s to x(i)
       	Accept s
       	Move s to y(i)
       End-perform
       Perform varying i from 2 by 1 until i>n
        Perform varying j from 1 by 1 until j=i
         compute t=(x(i)-x(j))*(x(i)-x(j))+(y(i)-y(j))*(y(i)-y(j))
         if t>a
         	Move t to a
         End-if
        End-perform
       End-perform.
       Display function sqrt(a).
       Stop run.
