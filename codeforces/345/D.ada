with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;


procedure d is
	v: array (0..50) of string (1..51);
	n, n2, b, e, x, r: integer;
	q: array (0..1000) of integer;
	met: array (1..50) of integer;
	
begin
	get(n); get_line(v(0), n2);
	for i in 1..n loop
		get_line(v(i), n2);
	end loop;
	
	for i in 1..n loop
		met(i) := 0;
	end loop;
	
	b := 0; e := 1;
	q(0) := 1; met(1) := 1;
	while b < e loop
		x := q(b); b := b+1;
		for i in 1..n loop
			if (v(x)(i) = '1') and (met(i) /= 1) and (i /= n) then
				q(e) := i; e := e+1;
				met(i) := 1;
			end if;
		end loop;
	end loop;
	
	r := 0;
	for i in 1..n loop
		if v(n)(i)='1' and met(i)=1 then
			r := r+1;
		end if;
	end loop;
	
	put(r, 0);
end;
