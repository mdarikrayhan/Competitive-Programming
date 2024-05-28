var
  n, res, ans, now, bef, i : longint;
  a : array[-1..100010] of longint;
begin
  readln(n);
  for i := 1 to n do 
    read(a[i]);
  ans := 1;
  res := 0;
  now := 0;
  for i := 1 to n do
  begin
    if now = 0 then
    begin
      now := 1;
      bef := a[i];
    end
    else
    begin
      if a[i] <> bef then
      begin
        if res = 0 then res := now
        else if res <> now then ans := 0;
        bef := a[i];
        now := 1;
      end
      else
      begin
        inc(now);
      end;
    end;
  end;
  if res > 0 then
    if now > 0 then
      if res <> now then
        ans := 0;
  if ans = 0 then writeln('NO')
  else writeln('YES');
end.