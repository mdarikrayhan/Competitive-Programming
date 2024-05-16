/*	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	
	int argc,char * argv[]
*/
#include <bits/stdc++.h>
//#include <windows.h>
using namespace std;

#define endl '\n'
#define ll long long
#define i8 __int128

#define ou cerr<<"      "

const int RRR=1145141919;
void dd(int o1=RRR,int o2=RRR,int o3=RRR,int o4=RRR,int o5=RRR,int o6=RRR){
	int eeee[7]={0,o1,o2,o3,o4,o5,o6};for(int i=1;i<=6;i++){
		if(eeee[i]==RRR) break;
		cout<<eeee[i]<<" ";}cout<<endl;
}

void ddd(int aaaa[],int nnnn){
	for(int i=1;i<=nnnn;i++) cout<<aaaa[i]<<" ";
	cout<<endl;
}

void vec(vector<int> ssss){
	int llll=ssss.size();
	for(int i=0;i<llll;i++) cout<<ssss[i]<<" ";
	cout<<endl;
}

//void i8_write(i8 x){
//	if(x<0) putchar('-'),x*=-1;
//	static int r[33];int top=0;
//	while(x){top++;r[top]=x%10;x/=10;}
//	while(top){putchar(r[top]+'0');top--;}
//
//}

bool M1;

//


int t;
string s;
const int N=5;
int a[N];


//

bool M2;
#define info cerr<<"\n\n"; \
cerr<<fixed<<setprecision(6)<<(double)(&M1-&M2)/1000000000<<"MB\n"; \
cerr<<fixed<<setprecision(3)<<(double)(T2-T1)/CLOCKS_PER_SEC<<"s\n";

int main()
{
	int T1=clock();
	//
	
	
	cin>>t;
	for(int kk=1;kk<=t;kk++)
	{
		cin>>s;
		int l=s.size();
		for(int i=0;i<l;i++)
		{
			a[i+1]=s[i]-48;
			if(a[i+1]==0) a[i+1]=10;
		}
		a[0]=1;
		int sum=4;
		for(int i=1;i<=4;i++) sum+=abs(a[i]-a[i-1]);
		ou;cout<<sum<<endl;
	}
	
	
	//
	int T2=clock();
	info
	return 0;
}

/*


114514*/