// LUOGU_RID: 157336109
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int a[500][100],b,d,e,f,ans1=1000000,ans;
int m,n,c[110][110],v[100];
int p[10]= {0,500,1000,1500,2000,2500,3000},dd[10]= {0,1,2,4,8,16,32};
int chuli(int xx,int yy,int ren) {
    if(v[xx]*dd[yy]<=n+ren&&(v[xx]*dd[yy+1]>n+ren)/*||(v[xx]==0&&yy==6))*/)
	{
//	    cout<<xx<<" "<<yy+1<<v[xx]*dd[yy+1]<<" "<<n<<endl;
	    return 0;
	}
	else if(v[xx]*dd[yy]<=n+ren&&(v[xx]==0&&yy==6))
    {
  //      cout<<xx<<" "<<yy<<endl;
        return 0;
    }
	else if(c[1][xx]==-1&&v[xx]*dd[yy]<=n+ren)
    {
    return 1000000;
    }
	else if(v[xx]*dd[yy]>=n+ren) {
		return v[xx]*dd[yy]-n-ren;
	}
	else if(v[xx]*dd[yy+1]<=n+ren)
	{
		for(int x=1; x<=ren; x++) {
			if((v[xx]+x)*dd[yy+1]>n+ren) {
				return 0;
			}
		}
		int l1=1,r1=3600,mid;
		while(l1<r1-1)
        {
            mid=(l1+r1);
            if(v[xx]+mid+ren*dd[yy+1]<=n+mid+ren)
            {
            l1=mid;
            }
            else
            {
            r1=mid;
            }
        }
        mid=r1-1;
        if(v[xx]+mid+ren*dd[yy+1]<=n+mid+ren)
        {
            r1--;
        }
        mid=r1-1;
        if(v[xx]+mid+ren*dd[yy+1]<=n+mid+ren)
        {
            r1--;
        }
        return r1;
	}
	return 0;
}
int main() {
	cin>>n;
	for(int x=1; x<=n; x++) {
		for(int y=1; y<=5; y++) {
			cin>>a[x][y];
			if(a[x][y]!=-1)
			{
                v[y]++;
			}
		}
		if(x==1) {
			if(a[1][1]!=-1) {
				c[1][1]=251-1-a[1][1];
			}
			else{c[1][1]=-1;}
			if(a[1][2]!=-1) {
				c[1][2]=251-1-a[1][2];
			}
			else{c[1][2]=-1;}
			if(a[1][3]!=-1) {
				c[1][3]=251-1-a[1][3];
			}
			else{c[1][3]=-1;}
			if(a[1][4]!=-1) {
				c[1][4]=251-1-a[1][4];
			}
			else{c[1][4]=-1;}
			if(a[1][5]!=-1) {
				c[1][5]=251-1-a[1][5];
			}
			else{c[1][5]=-1;}
		} else if(x==2) {
			if(a[2][1]!=-1) {
				c[2][1]=251-1-a[2][1];
			}
			else{c[2][1]=-1;}
			if(a[2][2]!=-1) {
				c[2][2]=251-1-a[2][2];
			}
			else{c[2][2]=-1;}
			if(a[2][3]!=-1) {
				c[2][3]=251-1-a[2][3];
			}
			else{c[2][3]=-1;}
			if(a[2][4]!=-1) {
				c[2][4]=251-1-a[2][4];
			}
			else{c[2][4]=-1;}
			if(a[2][5]!=-1) {
				c[2][5]=251-1-a[2][5];
			}
			else{c[2][5]=-1;}
		}
	}
	for(int x1=1; x1<=6; x1++) {
		for(int x2=1; x2<=6; x2++) {
			for(int x3=1; x3<=6; x3++) {
				for(int x4=1; x4<=6; x4++) {
					for(int x5=1; x5<=6; x5++) {
							long long zhi1=0,zhi2=0;
							if(c[1][1]!=-1) {
								zhi1+=(p[x1]/250)*c[1][1];
							}
							if(c[1][2]!=-1) {
								zhi1+=(p[x2]/250)*c[1][2];
							}
							if(c[1][3]!=-1) {
								zhi1+=(p[x3]/250)*c[1][3];
							}
							if(c[1][4]!=-1) {
								zhi1+=(p[x4]/250)*c[1][4];
							}
							if(c[1][5]!=-1) {
								zhi1+=(p[x5]/250)*c[1][5];
							}
							if(c[2][1]!=-1) {
								zhi2+=(p[x1]/250)*c[2][1];
							}
							if(c[2][2]!=-1) {
								zhi2+=(p[x2]/250)*c[2][2];
							}
							if(c[2][3]!=-1) {
								zhi2+=(p[x3]/250)*c[2][3];
							}
							if(c[2][4]!=-1) {
								zhi2+=(p[x4]/250)*c[2][4];
							}
							if(c[2][5]!=-1) {
								zhi2+=(p[x5]/250)*c[2][5];
							}
							if(zhi1>zhi2) {
                                ans=0;
								ans+=chuli(1,x1,ans);
								if(ans1<ans)
                                {
                                    break;
                                }
								ans+=chuli(2,x2,ans);
								if(ans1<ans)
                                {
                                    break;
                                }
								ans+=chuli(3,x3,ans);
								if(ans1<ans)
                                {
                                    break;
                                }ans+=chuli(4,x4,ans);
								if(ans1<ans)
                                {
                                    break;
                                }ans+=chuli(5,x5,ans);
                                ans1=min(ans,ans1);
 
							}
					}
				}
			}
		}
	}
	if(ans1!=1000000)
	{
	    cout<<ans1<<endl;
	}
	else
    {
	    cout<<-1<<endl;
    }
}