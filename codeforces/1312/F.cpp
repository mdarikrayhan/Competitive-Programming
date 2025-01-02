#include <bits/stdc++.h>
#define ll long long
#define all(v) v.begin(),v.end()
#define MASK(i) (1LL << (i))
#define ii pair<int,int>
#define fi first
#define se second
#define endl '\n'
#define forr(i,l,r,add) for(ll i = l;i <= r; i = i + add)
#define fodd(i,l,r,sub) for(ll i = l;i >= r ; i = i - sub)
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) {if (a > b) {a = b; return true;} return false;}
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) {if (a < b) {a = b; return true;} return false;}

using namespace std;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

long long Rand(long long l , long long h){
	assert(l <= h);
	return l + 1ll * rd() % (h - l + 1) * (rd() % (h - l + 1)) % (h - l + 1);
}


//////////////////////////////////////////////////////////// end of template ////////////////////////////////////////////////////////////

const int MAX = 3e5 + 5;
ll a[MAX];
int n , val[5];
int MEX[3005][4];
int tests;
int res[10];
bool ok[5];

///// end declare /////

int tim(vector <int> s){
    for(auto x : s) ok[x] = 0;
    for(int i = 0 ; 1 ; i++){
        if(ok[i]){
            for(auto x : s) ok[x] = 1;
            return i;
        }
    }
}

int MX(int a , int b){
    return max(a , b);
}

void build(){
    //memset(MEX , 0x3f , sizeof(MEX));
    for(int i = 1 ; i <= 3000 ; i++){
        MEX[i][1] = tim({MEX[MX(0 , i - val[1])][1] ,MEX[MX(0 , i - val[2])][2] ,MEX[MX(0 , i - val[3])][3]});
        MEX[i][2] = tim({MEX[MX(0 , i - val[1])][1] ,MEX[MX(0 , i - val[3])][3]});
        MEX[i][3] = tim({MEX[MX(0 , i - val[1])][1] ,MEX[MX(0 , i - val[2])][2]});
        //if(MEX[i][1] == MEX[i][2] && MEX[i][2] == MEX[i][3] && MEX[i][3] == 0) cout << i << endl;
    }
    /*for(int i = 0 ; i <= 3000 ; i++){
        for(int j = 1 ; j <= 3 ; j++) if(MEX[i][j] > 4) MEX[i][j] = 0;
    }*/
}

//TH1 : 1 3 4 : 7
//TH2 : 5 3 4 : 7 8 9
//TH3 : 1 2 3 : 5
//Lap lai:

void INP(){
    cin >> n >> val[1] >> val[2] >> val[3];
    forr(i , 1 , n , 1) cin >> a[i];
    build();
    int laplai = (val[1] + val[2]) * (val[2] + val[3]) * (val[3] + val[1]);
    memset(res , 0 , sizeof(res));
    int X = 0;
    forr(i , 1 , n , 1){
        if(a[i] > laplai * 2) a[i] = (a[i] % laplai) + laplai + laplai;
        X ^= MEX[a[i]][1];
        res[(MEX[a[i]][1] ^ MEX[MX(0 , a[i] - val[1])][1])]++;
        res[(MEX[a[i]][1] ^ MEX[MX(0 , a[i] - val[2])][2])]++;
        res[(MEX[a[i]][1] ^ MEX[MX(0 , a[i] - val[3])][3])]++;
    }
    cout << res[X] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #define TASK ""
    //freopen(TASK".inp" , "r" , stdin);
    //freopen(TASK".out" , "w" , stdout);
    memset(ok , 1 , sizeof(ok));
    cin >> tests;
    while(tests--) INP();
    return 0;
}
