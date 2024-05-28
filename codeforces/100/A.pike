int main(){
	int n,k,a;
	sscanf(Stdio.stdin.gets(),"%d %d %d",n,k,a);
	write((n>a*sqrt(k)?"NO":"YES"));
	return 0;
}
