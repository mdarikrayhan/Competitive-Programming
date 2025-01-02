#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using std::cin;using std::cout;
constexpr int N=12000000,K=86400;
int s,m,h,d,dat,mo,n,day=1,date=4,month=1,year=1970;
long long t;
std::vector<long long>w;
inline int limit(int y,int m){
	if(m==4||m==6||m==9||m==11) return 30;
	if(m==2) return (y%4==0&&y%100!=0||y%400==0)?29:28;
	return 31;
}
inline long long check(long long u){
	for(int i=0;i<K;++i)
		if((h==-1||i/3600==h)&&(m==-1||i/60%60==m)&&(s==-1||i%60==s)&&u*K+i>t)
			return u*K+i;
	return -1;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>s>>m>>h>>d>>dat>>mo>>n;
	for(int i=0;i<=N;++i){
		if(month==mo||mo==-1){
			bool g1=(day==dat),g2=(date==d);
			if(g1||g2) w.push_back(i);
			else{
				g1|=(dat==-1);
				g2|=(d==-1);
				if(g1&&g2) w.push_back(i);
			}
		}
		++date;if(date>7) date=1;
		++day;if(day>limit(year,month)){++month;day=1;}
		if(month>12){++year;month=1;}
	}
	for(int i=1;i<=n;++i){
		cin>>t;
		int now=std::lower_bound(w.begin(),w.end(),t/K)-w.begin();
		long long ans=check(w[now]);
		if(ans==-1) ans=check(w[++now]);
		cout<<ans<<'\n';
	}
	return 0;
}