/***************************************************//*    . Author : Md. Arik Rayhan  . .  . . .  . . . . *//*   . .  Github : github.com/mdarikrayhan   .  . . .  *//***************************************************/#include<cstdio>
int t,n,a[1007],l,r,p,q,i,s,pi,qi;
main(){
	for(scanf("%d",&t);t--;){
		for(scanf("%d",&n),i=0;i<n;) scanf("%d",a+i++);
		for(r=n-1,l=p=s=q=pi=qi=0;l<=r;s++){
			if(s&1){
				for(qi=0;l<=r && qi<=pi;r--) qi+=a[r];
				q+=qi;
			}
			else{
				for(pi=0;l<=r && pi<=qi;l++) pi+=a[l];
				p+=pi;
			}
		}
		printf("%d %d %d\n",s,p,q);
	}
}