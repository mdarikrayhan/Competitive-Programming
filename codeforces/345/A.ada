with Ada.Text_IO; use Ada.Text_IO;
with Ada.Float_Text_IO; use Ada.Float_Text_IO;

procedure a is
	str: string(1..100);
	l: natural;
	x, p: float;
	
begin
	get_line(str, l);
	get(p); x := 0.0;

	for i in 1..l loop
		if str(i) = '1' then x := x+1.0;
		elsif str(i) = '?' then x := x+p;
		end if;	
	end loop;
	x := x/float(l);
	
	put(x, 0, 5, 0);
end;