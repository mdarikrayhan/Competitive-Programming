with Ada.Integer_Text_IO;
use Ada.Integer_Text_IO;

with Ada.Float_Text_IO;
use Ada.Float_Text_IO;

with Ada.Text_IO,
     Ada.Characters.Handling; 
 use Ada.Text_IO,
     Ada.Characters.Handling;

procedure ProbE is
  maxx : Float;
  function solve(a, b, c:float) return float is
    val : float;
    mid : float;
  begin
    val := Float'min(c, a * maxx * maxx + b * maxx + c);
    mid := -b / (2.0 * a);
    if (0.0 <= mid) and (mid <= maxx) then
      val := Float'min(val, a * mid * mid + b * mid + c);
    end if;
    return val;
  end;

  N : Integer;
  v, u : Float;

  x, y : float;
  minv : float;
  ans : integer := 0;
begin
  Get(maxx);
  Get(v);
  Get(u);
  Get(n);
  while n > 0 loop
    Get(x); get(y);
    minv := solve(1.0 - u * u / (v * v), - 2.0 * x, x * x + y * y);
    if minv <= 1.0e-6 then
      ans := ans + 1;
    end if;
    n := n - 1;
  end loop;
  put(ans);
end ProbE;