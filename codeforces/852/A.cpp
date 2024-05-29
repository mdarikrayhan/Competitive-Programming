// LUOGU_RID: 141010981
// LUOGU_RID: 141010249
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define mp(x,y) make_pair(x,y)
#define lb(x) (x&(-x))
#define fi first
#define se second
#define pii pair<int,int>
int read(){
	int x=0,f=1;
    char ch=getchar();
	while(ch<'0'||ch>'9'){
    	if(ch=='-')f=-1;
		ch=getchar();
    }
	while(ch>='0'&&ch<='9'){
    	x=x*10+ch-48;
		ch=getchar();
    }
	return x*f;
}
void writ(int x){
    if(x<0){
		putchar('-'),x=-x;
	}
    if(x>9){
		writ(x/10);
	}
    putchar(x%10 +'0');
}
void write(int x,char p=' '){
    writ(x);
    putchar(p);
}
string sread(){
    string t="";
    char c=getchar();
    while(c==' '||c=='\t'||c=='\r'||c=='\n'||c==0||c==EOF){
        c=getchar();
    }
    while(!(c==' '||c=='\t'||c=='\r'||c=='\n'||c==0||c==EOF)){
        t+=c,c=getchar();
    }
    return t;
}
const int QMR=924844033,LSJ=998244353,inf=2e18+31,N=1e6+5;
//int cal(int a,int b=QMR-2){
//	int base=a,ret=1;
//	while(b){
//		if(b&1){
//			ret=ret*base%QMR;
//		}
//		base=base*base%QMR;
//		b>>=1;
//	}
//	return ret;
//}
mt19937 rnd(time(0)^clock());
int n; 
string s,ans[5],tmp;
string qmr(int t){
	string num="";
	num+=(char)(t+'0');
	return num;
}
signed main(){
    //freopen("qmr.in","r",stdin);
    //freopen("qmr.out","w",stdout);
    n=read();
    s=sread();
    tmp=s;
    int num=1;
    while(num<=3){
    	int t=0;
    	for(int i=0;i<s.size();i++){
    		if(rnd()%19==7&&i+1<s.size()){
    			t+=(s[i]-'0')*10+s[i+1]-'0';
    			if(i)ans[num]+='+';
    			ans[num]+=s[i];
    			ans[num]+=s[i+1];
    			i++;
			}
			else{
//				if(s.size()<=10)cout<<i<<" "<<s.size()<<endl;
    			if(i)ans[num]+='+';
//				if(s.size()<=10)cout<<i<<" "<<s.size()<<endl;
    			ans[num]+=s[i];
//				if(s.size()<=10)cout<<i<<" "<<s.size()<<endl;
				t+=s[i]-'0';
//				if(s.size()<=10)cout<<i<<" "<<s.size()<<endl;
			}
		}
//		cout<<ans[num]<<" "<<t<<endl;
		if(t<10){
			for(int i=num+1;i<=3;i++){
				ans[i]=qmr(t);
			}
			break;
		}
		s="";
		if(num==3&&t>=10){
			num=1;
			s=tmp;
			for(int i=1;i<=3;i++)ans[i]="";
			continue;
		}
		while(t){
			s=qmr(t%10)+s;
			t/=10;
		}
//		cout<<s<<"Qwq"<<endl;
		++num;
	}
	for(int i=1;i<=3;i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}
