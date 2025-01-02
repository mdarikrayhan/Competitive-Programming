with Ada.Integer_Text_IO;use Ada.Integer_Text_IO;
with Ada.Text_IO;use Ada.Text_IO;
procedure b is
	n,ans,tmp,pre,d,ok : Integer;
begin
	Get(Item=>n);
	ans :=0;
	for b in 4..n-1 loop
		tmp := n;
		pre:=0;
		ok := 0;
		while tmp > 0 loop
			d := tmp mod b;
			loop
				if pre=3 and d mod 10=1 then
					ok:=1;
				end if;
				pre := d mod 10;
				d:=d/10;
				exit when d =0;
			end loop;
			tmp := tmp / b;
		end loop;
		ans := ans + ok;
	end loop;
	while n>0 loop
		if n mod 100 = 13 then
			ans:=-1;
		end if;
		n:=n/10;
	end loop;
	Put(Item=>ans);
end b;
