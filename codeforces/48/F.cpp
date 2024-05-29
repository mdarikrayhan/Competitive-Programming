#include<bits/stdc++.h>
#define M 500005
using namespace std;
typedef long double ld;
typedef long long ll;

struct node{ int w, c; ld f; } tmp[M];

bool cmp( node x, node y ){ return x.f < y.f; }

int n, m, W, w[M], c[M], a[M];

namespace FastIO{
    char OutputDevide = ' ';
    template<typename T>inline void read(T& x){T f=1;x = 0;char ch = getchar();while(ch<'0'||ch >'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();x*=f;}
    template<typename T,typename ... Args>inline void read(T& x,Args& ...args){read(x),read(args...);}
    template<typename T>inline void write(T x){if(x<0){putchar('-'),write(-x);return;}if(x/10)write(x/10);putchar(x%10+48);}
    template<typename T,typename ... Args>inline void write(T x,Args ...args){write(x),putchar(OutputDevide),write(args...);}
};
using FastIO::read, FastIO::write;

ld ans = 0;

void solve(){
    ll ans = 0; ld ans2 = 0;
    for( int i = 1; i <= n; ++i ){
        for( int j = 1; j <= m; ++j )
            tmp[j] = { w[j], c[j], (ld) c[j] / w[j] }, c[j] -= a[j];
        int l = 1, r = m;
        ll sumw = W;
        while( l < r ){
            int mid = ( l + r ) >> 1;
            nth_element( tmp + l, tmp + mid, tmp + r + 1, cmp );
            ll a = 0, _w = 0;
            for( int i = l; i <= mid; ++i ) a += tmp[i].c, _w += tmp[i].w;
            if( _w > sumw ) r = mid;
            else{
                l = mid + 1;
                sumw -= _w;
                ans += a;
            }
        }
        ld lstans = (ld)sumw * tmp[l].f;
        ans += (ll)lstans, ans2 += lstans - (ll)lstans;
        if( ans2 >= 1.0 ) ans += (ll)ans2, ans2 -= (ll)ans2;
    }
    printf( "%lld.", ans );
    for( int i = 1; i <= 10; ++i ){
        ans2 = ans2 * 10;
        printf( "%d", (int)ans2 );
        ans2 -= (int) ans2;
    }
}

int main(){
    read( n, m, W );
    for( int i = 1; i <= m; ++i ) read( w[i] );
    for( int i = 1; i <= m; ++i ) read( c[i] );
    for( int i = 1; i <= m; ++i ) read( a[i] );
    solve();
    return 0;
}
		 			 				 		 				  	   			