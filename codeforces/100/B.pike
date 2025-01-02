int main()
{
	int n=(int)Stdio.stdin->gets(); int x=1;
	array a=(array(int))(Stdio.stdin->gets()/",");
    for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			x=(a[i]%a[j]==0||a[j]%a[i]==0); } }
	write(x?"FRIENDS \n":"NOT FRIENDS\n"); 
}