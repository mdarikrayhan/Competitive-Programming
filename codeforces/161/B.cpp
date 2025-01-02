// Problem: B. Discounts
// Contest: Codeforces - VK Cup 2012 Round 1
// URL: https://codeforces.com/problemset/problem/161/B
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;
#define pb push_back
#define umii unordered_map<int,int>
#define umci unordered_map<char,int>
#define umcc unordered_map<char,char>
#define mii map<int,int>
#define mci map<char,int>
#define mcc map<char,char>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvpii vector<vector<pii>>
#define f(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"

string str_addition(string a,string b){
    if(a.size()<b.size()){
        while(a.size()!=b.size()) a="0"+a;
    }
    if(a.size()>b.size()){
        while(a.size()!=b.size()) b="0"+b;
    }
    int c=0;
    int sz=a.size();
    string res;
    for(int i=sz-1;i>=0;i--){
        c+=(a[i]-'0')+(b[i]-'0');
        res+=(char((c%10)+'0'));
        c/=10;
    }
    if(c){
        res+="1";
    }
    reverse(all(res));
    return res;
}

string str_multiplication(string a,string b){
    vector<string>multiplied_substrings;
    for(int i=b.size()-1;i>=0;i--){
        int c=0;
        int x=b[i]-'0';
        string res;
        for(int j=a.size()-1;j>=0;j--){
            c+=(x*(a[j]-'0'));
            res+=char((c%10)+'0');
            c/=10;
        }
        while(c>0){
            res+=char((c%10)+'0');
            c/=10;
        }
        reverse(all(res));
        int p=b.size()-1-i;
        f(j,p){
            res+="0";
        }
        multiplied_substrings.pb(res);
    }
    string final_res;
    f(i,multiplied_substrings.size()){
        final_res=str_addition(final_res,multiplied_substrings[i]);
    }
    return final_res;
}

string str_power(string x,int y){
    if(y==0) return "1";
    if(y==1) return x;
    if(y%2) return str_multiplication(x,str_power(str_multiplication(x,x),y/2));
    return str_power(str_multiplication(x,x),y/2);
}

vi SPF(int n){
    if(n<=1){
        return {1,1};
    }
    vector<int>a(n+1);
    a[0]=1;
    a[1]=1;
    int sq=sqrt(n);
    for(int i=2;i<=sq;i++){
        if(a[i]==0){
            for(int j=i;j<=n;j+=i){
                a[j]=i;
            }
        }
    }
    for(int i=sq+1;i<=n;i++){
    	if(a[i]==0){
    		a[i]=i;
    	}
    }
    return a;
}

vi manodd(string s){
	/*if s is in form of #a#b#c#..#
	then to check for l...r weather it satisfy or not index 
	l -> 2*l+1
	r -> 2*r+1
	mid("#" if even / "char" if odd) -> l+r+1
	if odd then ans[l...r]=man[mid]-1
	if even then ans[l...r]=man[mid]-1 as well
	*/
	int n=s.size();
	s="@"+s+"&";
	vi man;
	man.resize(n+2);
	int l=1;
	int r=1;
	for(int i=1;i<=n;i++){
		man[i]=max((int)0,min(r-i,man[l+r-i]));
		while(s[i-man[i]]==s[i+man[i]]) man[i]++;
		if(i+man[i]>r){
			r=i+man[i];
			l=i-man[i];
		}
	}
	return vi(man.begin()+1,man.end()-1);
}

int mod_product(int x,int y){
    int z= x*y - mod*(int)(floor((double)x * y / mod));
    z%=mod;
    if(z<0) z+=mod;
    return z;
}

bool is_prime(int n){
    int sq=sqrt(n);
    for(int i=2;i<=sq;i++){
        if((n%i)==0) return false;
    }
    return true;
}

int power(int x,int y){
    int value = 0;
    if(y<0) return 0;
    else if(y==0) return 1;
    else if(y==1) return x;
    else if(y%2) value = (x*(power((x*x)%mod,y/2)%mod))%mod;
    else value = power((x*x)%mod,y/2)%mod;
    return value%mod;
}

int inversemod(int x) {
    return power(x,mod-2)%mod;
}

vi fact,ifact;

void FACT(int n){
	fact.resize(n+1);
	fact[0]=1;
	f1(i,n){
		fact[i]=fact[i-1]*i;
		fact[i]%=mod;
	}
}

void IFACT(int n){
	ifact.resize(n+1);
	ifact[n]=inversemod(fact[n]);
	for(int i=n-1;i>=0;i--){
		ifact[i]=(ifact[i+1]*(i+1))%mod;
	}
}

int NCR(int n,int r){
	return (((fact[n]*ifact[n-r])%mod)*ifact[r])%mod;
}

int NCR1(int n,int r){
	return (((fact[n]*inversemod(fact[r]))%mod)*inversemod(fact[n-r]))%mod;
}

void pp(int k){
    if(k==0)
    cout<<"NO"<<endl;
    else if(k==-1)
    cout<<-1<<endl;
    else
    cout<<"YES"<<endl;
}

void ppe(int x){
	cout<<x<<endl;
}

void ppe(string x){
	cout<<x<<endl;
}

void ppe(vi v){
	for(auto x:v) cout<<x<<' ';
	cout<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int T;
    T=1;
    while(T--){
    	int n,k;
    	cin>>n>>k;
    	vvi s,p;
    	f1(i,n){
    		int x,y;
    		cin>>x>>y;
    		if(y==1) s.pb({x,i});
    		else p.pb({x,i});
    	}
    	sort(all(s));
    	sort(all(p));
    	vector<vvi>ans(k);
    	int i=(int)s.size()-1;
    	int j=k-1;
    	while(i>=0){
    		if(j<0){
    			ans[0].pb(s[i]);
    		}
    		else{
    			ans[j].pb(s[i]);
    		}
    		i--;
    		j--;
    	}
    	double tans=0;
    	if((int)s.size()>=k){
    		f(i,(int)p.size()){
    			ans[0].pb(p[i]);
    		}
    		f(i,k){
    			int mn=1e18;
    			f(j,ans[i].size()){
    				mn=min(mn,ans[i][j][0]);
    			}
    			tans+=mn;
    		}
    	}
    	else{
    		for(int i=0;i<k-(int)s.size();i++){
    			ans[i].pb(p[i]);
    		}
    		for(int i=k-s.size();i<(int)p.size();i++){
    			ans[0].pb(p[i]);
    		}
    		for(int i=0;i<(int)s.size();i++) tans+=s[i][0];
    	}
    	tans/=2.0;
    	double tot=0;
    	f(i,(int)p.size()) tot+=p[i][0];
    	f(i,(int)s.size()) tot+=s[i][0];
    	tot-=tans;
    	if(tot==(int)tot){
    		cout<<setprecision(20)<<tot<<".0"<<endl;
    	}
    	else{
    		cout<<setprecision(20)<<tot<<endl;
    	}
    	f(i,k){
    		cout<<ans[i].size()<<' ';
    		f(j,ans[i].size()) cout<<ans[i][j][1]<<' ';
    		cout<<endl;
    	}
    }
	// your code goes here
	return 0;
}
/**/