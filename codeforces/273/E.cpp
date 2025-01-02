#include<bits/stdc++.h>
#define cir(i,a,b) for(int i=a;i<b;++i)
using namespace std;
static constexpr auto MOD=(int)(1e9+7);
int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int n,k;cin>>n>>k;
    const vector sg={
        pair(1,0),pair(3,1),pair(4,2),pair(5,1),pair(7,2),pair(9,0),pair(13,1),pair(15,2),pair(19,0),pair(27,1),
        pair(39,2),pair(40,0),pair(57,2),pair(58,1),pair(81,2),pair(85,0),pair(120,2),pair(121,1),pair(174,2),
        pair(179,0),pair(255,2),pair(260,1),pair(363,2),pair(382,0),pair(537,2),pair(544,1),pair(780,2),pair(805,0),
        pair(1146,2),pair(1169,1),pair(1632,2),pair(1718,0),pair(2415,2),pair(2447,1),pair(3507,2),pair(3622,0),
        pair(5154,2),pair(5260,1),pair(7341,2),pair(7730,0),pair(10866,2),pair(11011,1),pair(15780,2),pair(16298,0),
        pair(23190,2),pair(23669,1),pair(33033,2),pair(34784,0),pair(48894,2),pair(49549,1),pair(71007,2),pair(73340,0),
        pair(104352,2),pair(106510,1),pair(148647,2),pair(156527,0),pair(220020,2),pair(222970,1),pair(319530,2),
        pair(330029,0),pair(469581,2),pair(479294,1),pair(668910,2),pair(704371,0),pair(990087,2),pair(1003364,1),
        pair(1437882,2),pair(1485130,0),pair(2113113,2),pair(2156822,1),pair(3010092,2),pair(3169669,0),pair(4455390,2),
        pair(4515137,1),pair(6470466,2),pair(6683084,0),pair(9509007,2),pair(9705698,1),pair(13545411,2),pair(14263510,0),
        pair(20049252,2),pair(20318116,1),pair(29117094,2),pair(30073877,0),pair(42790530,2),pair(43675640,1),
        pair(60954348,2),pair(64185794,0),pair(90221631,2),pair(91431521,1),pair(131026920,2),pair(135332446,0),
        pair(192557382,2),pair(196540379,1),pair(274294563,2),pair(288836072,0),pair(405997338,2),pair(411441844,1),
        pair(589621137,2),pair(608996006,0),pair(866508216,2),pair(884431705,1),pair(1000000007,1)
    };
    auto sum=[&](int l,int r){
        swap(l,r);l=k-l;r=k-r;
        return 1ll*(l+r)*(r-l+1)/2%MOD;
    };
    vector<int> cnt(3);
    cir(i,0,(int)(sg.size())-1){
        const auto sgi=sg[i].second;
        const auto l=sg[i].first,r=min(k,sg[i+1].first-1);
        if(l>k) break;
        (cnt[sgi]+=sum(l,r))%=MOD;
    }
    vector<int> f(4);f[0]=1;
    cir(i,0,n){
        const auto lf=f;
        fill(f.begin(),f.end(),0);
        cir(x,0,4) cir(w,0,3){
            (f[x^w]+=1ll*lf[x]*cnt[w]%MOD)%=MOD;
        }
    }
    cout<<((long long)(f[1])+f[2]+f[3])%MOD<<'\n';
    return 0;
}

 			    	  	 	 	   			    			 	