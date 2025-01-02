for s in[*open(0)][1:]:a,b,c=sorted(map(int,s.split()));print('YNEOS'[b/a+c/a>5or
b%a+c%a>0::2])