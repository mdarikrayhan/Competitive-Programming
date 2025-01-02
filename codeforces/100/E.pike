void main(){
	mixed r=Stdio.stdin;
	int n=(int)r->gets(),i,m,j;
	array(string) l=r->gets()/" ";
	m=(int)r->gets();
	array(string) p=r->gets()/" ";
	array(int) c=allocate(n+1);
	for(i=0;i<m;++i)c[(int)p[i]]++;
	for(i=n;i;--i)
		for(j=i*2;j<=n;j+=i)c[j]+=c[i];
	for(i=0;i<n;++i)
		write((c[i+1]%2)?(l[i]=="on"?"off ":"on "):(l[i]+" "));
}
