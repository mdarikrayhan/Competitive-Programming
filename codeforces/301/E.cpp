// LUOGU_RID: 160596425
// Problem: 
//     Yaroslav and Arrangements
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF301E
// Memory Limit: 250 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// Ah, si je pouvais vivre dans l'eau,
// le monde serait-il plus beau ?
// Nous pardonneras-tu, ô chère mère ?
// L'eau dans son courant fait danser nos vies.
// Et la cité, elle nourrit.
// Ainsi que toi, mon doux amour.
// 
// Non, le grand amour ne suffit pas.
// Seul un adieu fleurira.
// C'est notre histoire de vie, douce et amère.
// Moi, je suis et serai toujours là,
// à voir le monde et sa beauté.
// Et ça ne changera jamais, jamais...

#include<bits/stdc++.h>
#define endl '\n' 
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int P=1e9+7;
void chkmax(int &x,int y){if(x<y)x=y;}
void chkmin(int &x,int y){if(x>y)x=y;}
int qpow(int a,int k,const int p=P){
	int ret=1;
	while(k){
		if(k&1)ret=ret*(long long)a%p;
		a=a*(long long)a%p;
		k>>=1;
	}
	return ret;
}
int inc(int x){return x>=P?x-P:x;}
int reduce(int x){return x<0?x+P:x;}
void add(int&x,int y){if((x+=y)>=P)x-=P;}
struct IO_Tp {
    const static int _I_Buffer_Size = 2 << 24;
    char _I_Buffer[_I_Buffer_Size], *_I_pos = _I_Buffer, *_I_end= _I_Buffer + _I_Buffer_Size;

    const static int _O_Buffer_Size = 2 << 24;
    char _O_Buffer[_O_Buffer_Size], *_O_pos = _O_Buffer;

	string name;
    IO_Tp(string s="") { name=s;if(s.length()>0)freopen((s+".in").c_str(),"r",stdin);fread(_I_Buffer, 1, _I_Buffer_Size, stdin); }
    ~IO_Tp() { if(name.length()>0)freopen((name+".out").c_str(),"w",stdout);fwrite(_O_Buffer, 1, _O_pos - _O_Buffer, stdout); }

#if __cplusplus >= 202002L
	template<integral T>
    IO_Tp &operator>>(T &res) {
#else
	IO_Tp &operator>>(int &res){
#endif
    	int f=1;
        while (_I_pos!=_I_end&&!isdigit(*_I_pos)&&(*_I_pos)!='-') ++_I_pos;
        assert(_I_pos!=_I_end);
        if(*_I_pos=='-')f=-1,++_I_pos;
        res = *_I_pos++ - '0';
        while (_I_pos!=_I_end&&isdigit(*_I_pos)) res = res * 10 + (*_I_pos++ - '0');
        res*=f;
        assert(_I_pos!=_I_end);
        return *this;
    }

    
    IO_Tp &operator>>(string &res){
    	res="";
    	auto blank=[&](char ch){
    		if(ch==' '||ch=='\n'||ch=='\r'||ch=='	'||ch=='\0')return 1;
    		return 0;
		};
		while(_I_pos!=_I_end&&blank(*_I_pos)) ++_I_pos;
    	while (_I_pos!=_I_end&&!blank(*_I_pos))res += *_I_pos++;
    	assert(_I_pos!=_I_end);
    	return *this;
	} 
#if __cplusplus>=202002L
	template <ranges::range T>
	IO_Tp &operator>>(T &x) {
		for (auto &y : x) operator>>(y);
	    return *this;
	}
	template <ranges::range T>
	IO_Tp &operator>>(T &&x) {
		for (auto &y : x) operator>>(y);
	    return *this;
	}
#endif

#if __cplusplus >= 202002L
	template<integral T>
    IO_Tp &operator<<(T n) {
#else
	IO_Tp &operator<<(int n){
#endif
    	if(n<0)*_O_pos++='-',n=-n;
        static char _buf[10];
        char *_pos = _buf;
        do
            *_pos++ = '0' + n % 10;
        while (n /= 10);
        while (_pos != _buf) *_O_pos++ = *--_pos;
        return *this;
    }

    IO_Tp &operator<<(char ch) {
        *_O_pos++ = ch;
        return *this;
    }
    
    IO_Tp &operator<<(string &res){
    	for (char ch:res) *_O_pos++ = ch;
    	return *this;
	} 
	
	IO_Tp &operator<<(const char*res){
		int n=strlen(res);
		rep(i,0,n-1)*_O_pos++=res[i];
    	return *this;
	} 
#if __cplusplus>=202002L
	template <ranges::range T>
	IO_Tp &operator<<(const T&x) {
		for (auto &y:x)operator<<(y),*_O_pos++ = ' ';
	    return *this;
	}
#endif
} IO;
const int N=105;
int n,m,K,f[2][N][N][N];
int main(){
	IO>>n>>m>>K;n++;
	f[0][0][1][1]=1;
	int ans=0;
	rep(i,0,m-1){
		memset(f[i&1^1],0,sizeof f[i&1^1]);
		rep(j,0,n)rep(k,1,n)rep(l,1,K)if(f[i&1][j][k][l]){
			int v=1;
			rep(t,k,n-j){
				if(l*v>K)break;
				add(f[i&1^1][j+t][t-k][l*v],f[i&1][j][k][l]);
				v=v*t/(t-k+1);
			}
		}
		rep(j,2,n)rep(l,1,K)add(ans,1ll*f[i&1^1][j][0][l]*(m-i)%P);
	}
	IO<<ans<<endl;
	return 0;
} 
