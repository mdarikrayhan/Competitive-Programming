void main(){
	int n=(int)Stdio.stdin.gets(),y,x;
	string a=Stdio.stdin.gets(),b=Stdio.stdin.gets();
	n=(x=strlen(a))+(y=strlen(b))-n;
	if(x<y)y=x;
	for(x=0;x<y&&a[x]==b[x];++x);
	write(x*2>=n?"Yes":"No");
}
