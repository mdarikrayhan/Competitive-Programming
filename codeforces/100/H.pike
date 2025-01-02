int d(){
	int i,j,l,k,u,c,t=0;
	array(string) p = allocate(11);
	for(i=0;i<=10;++i)p[i]=Stdio.stdin.gets();
	for(i=0;i<9;++i)
		for(j=0;j<9;++j)
			if(p[i][j]=='*'&&p[i+1][j+1]=='*'||p[i][j+1]=='*'&&p[i+1][j]=='*')
				return 0;
	for(l=4;c=0,l>=0;--l){
		for(i=0;i<10;++i)
			for(j=0;j+l<10;++j){
				for(u=1,k=0;k<=l&&u;++k)u&=(p[i][j+k]=='*');
				if(u){
					c++;
					for(k=0;k<=l;++k)p[i][j+k]='0';
				}
				for(u=1,k=0;k<=l&&u;++k)u=u&&(p[j+k][i]=='*');
				if(u){
					c++;
					for(k=0;k<=l;++k)p[j+k][i]='0';
				}
			}
		if(l==4&&c)return 0;
		if(4!=l+c)return 0;
	}
	return 1;
}
void main(){
	for(int m=(int)Stdio.stdin.gets();m--;)write(d()?"YES\n":"NO\n");
}
