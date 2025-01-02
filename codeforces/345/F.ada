with Ada.Containers.Ordered_Maps;
with Ada.Characters.Handling; use Ada.Characters.Handling;
with Ada.Strings.Unbounded; use  Ada.Strings.Unbounded;
with Ada.Strings.Unbounded.Text_IO; use  Ada.Strings.Unbounded.Text_IO;
with Ada.Text_IO; use  Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
with Ada.Float_Text_IO; use Ada.Float_Text_IO;

procedure p345f is
package Associative_Int is new Ada.Containers.Ordered_Maps(Unbounded_String, Integer);
use Associative_Int;
Counter : Map;
S: String(1..60);
U: Unbounded_String;
R: Natural;
M: Natural := 0;
Length: natural;
Q: boolean;
index: cursor;
Z: array(1..60) of Unbounded_String;

begin

while not End_Of_File loop
Get_Line(S, Length);
S := to_lower(S);
if S(1) = '*' then
    U := to_unbounded_string("");
    Q := false;
    for I in Integer range 3..length loop
        if S(I) = ' ' then
            if not Q then append(U, ' '); end if;
            Q := true;
        else
            Q := false;
            append(U, S(I));
        end if;
    end loop;
    if contains(counter, U) then 
        replace(counter, U, element(counter, U) + 1);
    else
        insert(counter, U, 1);
    end if;
    M := Integer'Max(M, element(counter, U));
end if;
end loop;

R := 1;
index := counter.first;
while index /= no_element loop
    if element(index) = M then Z(R) := key(index) ; R := R + 1 ; end if;
    index := next(index);
end loop;

R := R-1;
for x in Integer range 1..(R-1) loop
for y in Integer range (x+1)..R loop
    if Z(x) > Z(y) then
        U := Z(x);
        Z(x) := Z(y);
        Z(y) := U;
    end if;
end loop;
end loop;

for x in Integer range 1..R loop
    Put_Line(Z(x));
end loop;

end p345f;
