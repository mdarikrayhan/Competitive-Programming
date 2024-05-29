with Ada.Integer_Text_IO;use Ada.Integer_Text_IO;
procedure c is
	n,y,m,d,tm,ty,x,ans :  Integer;
begin
	Get(Item=>n);
	ans:=0;
	for i in 1..n loop
		Get(Item=>y);
		Get(Item=>m);m:=-m;
		Get(Item=>d);d:=-d;
		if m >2 then
			tm := m-2;
			ty := y;
		else
			tm := m+10;
			ty := y-1;
		end if;
		x := (ty + ty/4 - ty/100 + ty/400 + d + (tm * 13 -1)/5) mod 7;
		if x=5 and d =13 then
			ans := ans +1;
		end if;
	end loop;
	Put(Item=> ans);
end c;
