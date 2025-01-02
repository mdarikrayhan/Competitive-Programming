#include<bits/stdc++.h>
#define ll long long
#define rg int
#define ci const int
#define ls x<<1
#define rs x<<1|1
#define mid ((L+R)>>1)
#define ld long double
#define fo(i,l,r) for(int i=(l);i<=(r);++i)
#define fd(i,l,r) for(int i=(l);i>=(r);--i)
#define fu(i,l,r) for(int i=(l);i<(r);++i)
using namespace std;
ci N=2e6+5;
const ld eps=1e-10;
const ll inf=1e9;
ll n,m,a[20],b[20],t[20];
char ch[N],c[N],wtc[N];
inline ll read(){ll u,f=1;char o;while((o=getchar())<48||o>57)if(o==45)f=-1;u=(o^48);while((o=getchar())>=48&&o<=57)u=(u<<1)+(u<<3)+(o^48);return u*f;}
void write(ll x){if(x<0)putchar(45),x=-x;if(x>9)write(x/10);putchar(x%10+48);}
int main()
{
	int T=1;
	while(T--)
	{
		cin>>ch;
		n=strlen(ch);
		fo(i,0,n-1)
		{
			int u=ch[i]-'0';
			a[u]++;
		}
		cin>>c;
		m=strlen(c);
		fo(i,0,m-1)
		{
			int u=c[i]-'0';
			b[u]++;
			a[u]--;
		}//cout<<n<<' '<<m<<'\n';
		int s=n-m;
		fo(i,0,s)
		{
			ll len=s-i,x=i+m,q=0;
			memset(t,0,sizeof(t)); 
			while(x)
			{
				++q;
				t[x%10]++;
				x/=10;
			}
//			cout<<len<<' '<<q<<'\n';
			if(q==len)
			{
//				cout<<i<<' ';
				bool f=0;
				fo(i,0,9)if(t[i]>a[i])
				{
					f=1;
					break;
				}
				if(!f)
				{
					memset(wtc,0,sizeof(wtc));
					int w=inf;
					fo(i,0,9)
					{
						a[i]-=t[i];
						if(a[i]>0&&i>0)w=min(w,i);
					}
					ll u=0;
					if(w!=inf)wtc[u++]=w+'0';
					fo(i,0,9)
					{
						fo(j,1,a[i]-(w==i))
						{
							wtc[u++]=i+'0';
						}
					}
//					cout<<u<<' '<<m<<'\n';
					bool f=0;
					fu(i,0,min(u,m))
					{
						if(c[i]<wtc[i])break;
						if(c[i]>wtc[i])
						{
							f=1;
							break;
						}
					}//cout<<f<<'\n';
					if(w==inf||(c[0]!='0'&&!f))
					{
						cout<<c;
						sort(wtc,wtc+u);
						cout<<wtc<<'\n';
					}
					else
					{
						if(u>0)cout<<wtc[0];
						fo(i,0,c[0]-'0'-1)
						{
							fo(j,1,a[i]-(w==i))
							{
								cout<<i;
							}
						}
						ll u=0;memset(wtc,0,sizeof(wtc));
						fo(i,c[0]-'0',9)
						{
							fo(j,1,a[i]-(w==i))
							{
								wtc[u++]=i+'0';
							}
						}
						bool f=0;
//						if(m>u)f=1;
//						cout<<u<<' '<<m<<'\n';
//						fu(i,0,min(u,m))
//						{
//							if(c[i]<wtc[i])
//							{
//								f=0;
//								break;
//							}
//							if(c[i]>wtc[i])
//							{
//								f=1;
//								break;
//							}
//						}//cout<<f<<'\n';
						fu(i,0,m)if(c[i]!=c[0])
						{
							if(c[i]>c[0])f=1;
							break;
						}
							if(!f)
							{
								cout<<c;
								cout<<wtc;
							}
							else
							{
								int i=c[0]-'0';
								fo(j,1,a[i]-(w==i))
								{
									cout<<i;
								}//cout<<"wre";
								cout<<c;
								fo(i,c[0]-'0'+1,9)
								{
									fo(j,1,a[i]-(w==i))
									{
										cout<<i;
									}
								}
							}
					}
					return 0;
				}
			}
		}
	}
	return 0;
}