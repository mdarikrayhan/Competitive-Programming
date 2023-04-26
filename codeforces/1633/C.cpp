#import<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,c,d,n,x,y,v;
main()
{
	for(cin>>n;cin>>a>>b>>c>>d>>n>>x>>y;)
	{
		for(int i=0;i<=n;i++)
			if(ceil(1.0*c/(b+i*x))<=ceil(1.0*(a+(n-i)*y)/d))
				v=1;
		puts(v?"YES":"NO"),v=0;
	}
}