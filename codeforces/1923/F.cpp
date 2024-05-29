#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
const int N=5e5+5;
struct Hash{
	int mod;ll h[N],pw[N];
	string s;int n;
	void init()
	{
		pw[0]=1;
		for(int i=1;i<=n;i++)pw[i]=pw[i-1]*2%mod;
		for(int i=0;i<n;i++)
			h[i]=((i==0?0:h[i-1])*2+s[i]-'0')%mod;
		return;
	}
	int query(int l,int r)
	{
		return (h[r]-(l?h[l-1]*pw[r-l+1]%mod:0)+mod)%mod;
	}
}s[2];
struct String{
	int tp,l,r,len;
}ans;int n,m,sum[N];char c[N];
string getit()
{
	string res="";
	for(int i=ans.l;i<=ans.r;i++)res+=s[ans.tp].s[i];
	for(int i=0;i<ans.len;i++)res+="1";
	return res;
}
int Q(int l,int r){return sum[r]-(l?sum[l-1]:0);}
int clr(int tp,int l,int r)
{
	if(!tp){
		int rem=l;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(sum[mid]==(!rem?0:sum[rem-1]))
				l=mid+1;
			else
				r=mid-1;
		}
		return l;
	}else{
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if((mid==n-1?0:sum[n-mid-2])==sum[n-l-1])
				l=mid+1;
			else
				r=mid-1;
		}return l;
	}
}
void update(String a)
{
	a.l=clr(a.tp,a.l,a.r);
	int lena=ans.r-ans.l+1+ans.len;
	int lenb=a.r-a.l+1+a.len;
	//cout<<a.tp<<" "<<a.l<<" "<<a.r<<" "<<lena<<" "<<lenb<<'\n';
	if(lena!=lenb)return ans=(lena>lenb?a:ans),void();
	int str=min(ans.r-ans.l+1,a.r-a.l+1);
	if(str){
		int l=1,r=str;
		while(l<=r){
			int mid=(l+r)>>1;
			int maska=s[ans.tp].query(ans.l,ans.l+mid-1);
			int maskb=s[a.tp].query(a.l,a.l+mid-1);
			if(maska==maskb)
				l=mid+1;
			else
				r=mid-1;
		}if(l!=str+1){
			if(s[ans.tp].s[ans.l+l-1]>s[a.tp].s[a.l+l-1])
				ans=a;
		}else if(ans.r-ans.l+1<str)ans=a;//else cout<<l<<" "<<ans.l<<" "<<ans.r<<" "<<a.l<<" "<<a.r<<"GG?\n";
	}else ans=(lena==ans.len?a:ans);
	return;
}
void upd(int tp,int l,int r)//0:put zero at the end;1:put zero at the front
{
//	cout<<tp<<" "<<l<<" "<<r<<"\n";//bool spj=(tp==1&&l==5&&r==8);
	int rst=sum[n-1]-Q(l,r),rem=r;String u;u.tp=tp;
	if(!tp){
		u.l=l,u.r=r;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(mid-rem+1-Q(mid,rem)<=rst)
				r=mid-1;else l=mid+1;
		}u.len=u.r-r;u.r=r;//cout<<u.l<<" "<<u.r<<" "<<u.len<<"?\n";
	}else{
		u.l=n-r-1,u.r=n-l-1;rem=l;
//		cout<<u.l<<" "<<u.r<<" "<<rst<<"G\n";
		while(l<=r){
			int mid=(l+r)>>1;
			if(mid-rem+1-Q(rem,mid)<=rst)
				l=mid+1;else r=mid-1;
		}u.len=u.r-(n-l-1);u.r=n-l-1;//cout<<u.l<<" "<<u.r<<" "<<rst<<"?\n";
	}update(u);
	return;
}

int main()
{
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	scanf("%d%d",&n,&m);s[0].mod=s[1].mod=1e9+7;
	scanf("%s",c);string S="",REM;
	for(int i=0;i<n;i++)S+=c[i],sum[i]=(!i?0:sum[i-1])+(c[i]=='1');
	s[0].s=S;reverse(S.begin(),S.end());s[1].s=REM=S;s[0].n=s[1].n=n;
	reverse(S.begin(),S.end());int fro=0,lst=m-1;ans.tp=1;ans.len=n;ans.l=0,ans.r=-1;s[0].init();s[1].init();//cout<<s[1].query(5,5)<<"?\n";
	for(int i=n-1;lst&&i>=0;i--){
		if(S[i]=='1'){
			while(fro<=i&&S[fro]=='1')fro++;
			if(fro>i)break;
			else{
				lst--;swap(S[fro],S[i]);//fro+1~i-1
				if(!lst)ans.l=n-i,ans.r=n-fro-2,ans.l=clr(ans.tp,ans.l,ans.r),ans.len=fro+1;
			}
		}
	}S=REM;
	fro=0,lst=m;String tmp;tmp.tp=0;
	for(int i=n-1;lst&&i>=0;i--){
		if(S[i]=='1'){
			while(fro<=i&&S[fro]=='1')fro++;
			if(fro>i)break;else{
				lst--;swap(S[fro],S[i]);//fro+1~i-1
				if(!lst)tmp.l=n-i,tmp.r=n-fro-2,tmp.l=clr(tmp.tp,tmp.l,tmp.r),tmp.len=fro+1,update(tmp);
			}
		}
	}//string preans=getit();cout<<ans.tp<<" "<<ans.l<<" "<<ans.r<<" "<<ans.len<<" "<<getit()<<"?\n";//return 0;
	for(int i=0;i<n;i++)
	{
		int l=i+sum[n-1]-1,r=n-1;
		if(l>=n)break;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			int cost=sum[n-1]-Q(i,mid);
			if(cost<=m-2)
				r=mid-1;
			else
				l=mid+1;
		}int border=r+1;
		if(border<n)upd(0,i,border),upd(1,i,border);
		l=i+sum[n-1]-1,r=n-1;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			int cost=sum[n-1]-Q(i,mid);
			if(cost<=m-1)
				r=mid-1;
			else
				l=mid+1;
		}border=r+1;
		if(border<n)upd(1,i,border);
	}//cout<<clock()<<"\n";
	S=getit();int ot=0;
	for(int i=0;i<(int)S.size();i++)ot=(ot*2%((int)1e9+7)+S[i]-'0')%((int)1e9+7);
//	cout<<ans.l<<" "<<ans.r<<" "<<ans.len<<"\n";
	printf("%d\n",ot);return 0;
}