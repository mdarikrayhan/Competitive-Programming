with Ada.Integer_Text_IO;
use Ada.Integer_Text_IO;
with Ada.Text_IO;
use Ada.Text_IO;
with Interfaces;
use Interfaces;
procedure Program is
n, v, ans, len, free, j : Integer;
kk : array (Integer range 1 .. 234567) of Integer;
link : array (Character range 'a' .. 'z', Integer range 1 .. 234567) of Integer;
s : String (1 .. 234567);
begin
  Get(Item => n);
  Get_Line(Item => s, Last => len);
  free := 1;
  ans := 0;
  for i in Integer range 1 .. n loop
    Get_Line(Item => s, Last => len);
    v := 1;
    for jj in Integer range 1 .. len loop
      j := len - jj + 1;
      if link(s(j), v) = 0 then
        free := free + 1;
        link(s(j), v) := free;
      end if;
      v := link(s(j), v);
    end loop;
    kk(v) := kk(v) + 1;
  end loop;
  for i in Integer range 1 .. free loop
    if ans < kk(i) then
      ans := kk(i);
    end if;
    for c in Character range 'a' .. 'z' loop
      if link(c, i) /= 0 then
        kk(link(c, i)) := kk(link(c, i)) + kk(i);
      end if;
    end loop;
  end loop;
  Put(Item => ans, Width => 1);
end Program;