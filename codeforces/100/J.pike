#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
	int n=(int)Stdio.stdin->gets();
	array l=allocate(n),r=allocate(n);
	rep(i,n){
		int pl,pr;
		sscanf(Stdio.stdin->gets(),"%c%f,%f%c",pl,l[i],r[i],pr);
		if(pl=='(') l[i]+=0.5;
		if(pr==')') r[i]-=0.5;
	}

	sort(l,r);

	int ans=1;
	rep(i,n-2) if(r[i]>=l[i+1] && r[i+1]>=l[i+2]) ans=2;

	write(ans+"\n");

	return 0;
}
