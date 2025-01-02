fmin := method(l,a,st,
  i:=st;
  m:=a at(i);
  mid := st;
  while(i<l,
    if(a at(i)<m,
      m:=a at(i);
      mid:=i
    );
    i:=i+1;
  );
  return mid;
);
 
sort := method(l,a,
  i := 0;
  while(i<l,
    m := fmin(l,a,i);
    h := a at(i);
    a atPut(i, a at(m));
    a atPut(m, h);
    i := i + 1;
  );
  return a;
);
 
count := method(l,a,m,
  if(l==0,return 1);
  c:=0;
  if(a at(0)>1,c:=1);
  index:=1;
  while(index<l,
    if(a at(index)>a at(index-1)+1,
      c:=c+1);
    index:=index+1;
  );
  if(a at(l-1)<m,
    c:=c+1);
  return c;
);
 
and:=method(a,b,
  if(a,
    if(b,
      2>1,
      2<1),
    2<1)
);
 
readint:=method(
  line:=File standardInput readLine .. " ";
  index := 0;
  index1:=0;
  integers := List clone;
  while(index<line size,
    while(line slice(index,index+1) at(0)!=" " at(0),
      index :=index+1
    );
    number :=line slice(index1,index) asNumber;
    integers append(number);
    /*
    number print
    " " print
    */
    index := index + 1;
    index1 := index;
  );
  #integers println
  return integers;
);
 
line1 := readint();
n:=line1 at(0);
m:=line1 at(1);
 
/*
"n: " print
n println
"m: " print
m println
*/
 
line2 := readint();
 
#"" println
 
lent := line2 at(0);
t := line2 slice(1, lent+1);
t := sort(lent, t);
line3:=readint();
lens := line3 at(0);
s := line3 slice(1, lens+1);
s := sort(lens, s);
tc := count(lent,t,n);
sc := count(lens,s,m);
r := (tc*sc);
r print;
