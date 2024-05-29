void main(){
	constant r=Stdio.stdin;
	int n=(int)r->gets(),m,i,y=2111;
	string s,t;
	array(string) a=allocate(n);
	array(int) b=allocate(n);
	for(i=0;i<n;++i)sscanf(r->gets(),"%s %d",a[i],b[i]);
	mapping l=mkmapping(a,b);
	m=(int)r->gets();
	while(m--){
		t=r->gets();
		i=l[t];
		if((i==y&&t>s) || i<y){
			s=t;
			y=i;
		}
	}
	write(s);
}
