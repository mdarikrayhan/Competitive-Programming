string h(int c,int k){
	if(k==0)return c+"\n";
	return (c==1?"":c+"*")+(k>1?("X^"+k):"X");
}
void main(){
	int i,j,n=(int)Stdio.stdin.gets(),t;
	array(int) a=allocate(n+1);
	a[0]=1;
	for(i=0;i<n;++i){
		t=(int)Stdio.stdin.gets();
		for(j=i;j>=0;--j)a[j+1]+=a[j]*t;
	}
	write(h(1,n));
	for(i=1;i<=n;++i)if(a[i])
		write((a[i]>0?"+":"-")+h(abs(a[i]),n-i));
}
