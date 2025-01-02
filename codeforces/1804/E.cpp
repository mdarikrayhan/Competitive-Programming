#include<bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

/*
string numeFisier="";
ifstream fin(numeFisier+".in"); ofstream fout(numeFisier+".out");
#define cin fin
#define cout fout
*/
#define INIT  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define ll long long
#define pii pair<int, int>
#define count_bits __builtin_popcount
//#define int ll




int t, n, m, k, a[300010], q, l, r, u1[500], u2[500];


bool adj[21][21];

bool checked[21];

bool dp[1<<20][20];

int par[1<<20][20];

bool posCycle[1<<20];
int parCycle[1<<20];

int adjMsk[21];


int server[21];


int32_t main(){
    INIT

    /*
    int sum = 0;
    for(int i=20; i>=2; i--){
        sum+=(1<<(i-2))*(i*(i+1));
        cout<<sum<<"\n";
    }
    */


    cin>>n>>m;
    for(int i=1; i<=m; i++){
        cin>>u1[i]>>u2[i];
    }
    for(int i=1; i<=m; i++){
        adj[ u1[i] ][ u2[i] ] = true;
        adj[ u2[i] ][ u1[i] ]=true;
    }

    for(int i=1; i<=n; i++){
        adj[ i ][ i ] = true;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(adj[i][j]){
                adjMsk[i]+=(1<<(j-1));
            }
        }
    }

    /*
    bool pos=false;
    for(int msk = )

    if(!pos){
        cout<<"NO\n";
    }
    else{

    }
    */
    vector<int> cycle;
    bool pos=false;
    for(int origin = 1; origin<=n; origin++){
        dp[1][1]=1;
        par[1][1]=0;
        for(int msk = 1; msk<(1<<(n-origin+1) ); msk++){
                int realMsk = msk<<(origin-1);
            for(int i=origin; i<=n; i++){
                if( (msk & (1<<(i-origin)))==0 )continue;
                for(int j=origin; j<=n; j++){
                    if(j==i)continue;
                    if( adj[i][j] && dp[ msk ][ i-origin+1 ] && ((msk&(1<<(j-origin)))==0) && dp[ msk|(1<<(j-origin) ) ][ j-origin+1]==0 ){
                        par[ msk|(1<<(j-origin) ) ][j-origin+1]=i-origin+1;
                        dp[ msk|(1<<(j-origin) ) ][ j-origin+1]=1;
                    }
                }

            }

            for(int i=origin+1; i<=n; i++){
                if( dp[msk][i-origin+1] && adj[i][origin] ){
                    posCycle[msk]=true;
                    parCycle[msk]=i-origin+1;
                    break;
                }
            }

            if(!posCycle[msk])continue;
            bool posNow=true;
            for(int i=1; i<=n; i++){
                if( ((1<<(i-1))&realMsk)==1 ){
                    //nothing
                }
                else{
                    if( (adjMsk[i]&realMsk)==0 ){
                        posNow=false;
                    }
                }
            }
            //cout<<realMsk<<" "<<posCycle[msk]<<"--\n";
            if(posNow){
                    //cout<<realMsk<<"-\n";
                int acMsk = msk;
                int acPar = parCycle[msk];
                server[ acPar+origin-1 ]=origin;
                while(acMsk!=0){
                        //cout<<acPar<<"---\n";
                    cycle.pb(acPar+origin-1);
                    int nextPar=par[acMsk][acPar];
                    int nextMsk = acMsk^( 1<<(acPar-1) );
                    //acMsk^=(1<<acPar);
                    if(nextPar!=0){server[nextPar+origin-1]=acPar+origin-1;}
                    acPar=nextPar;
                    acMsk=nextMsk;
                }

                for(int i=1; i<=n; i++){
                    if( (( realMsk&( 1<<(i-1) ) )==0) ){
                        for(int j=1; j<=n; j++){
                            if( adj[i][j]==1 && (realMsk&(1<<(j-1) ))>0 ){
                                server[i]=j;
                                break;
                            }
                        }
                    }
                }

                pos=true;
                break;
            }
        }

        if(pos){
            break;
        }

        for(int msk = 0; msk<(1<<(n-origin+1)); msk++){
            for(int i=origin; i<=n; i++){
                dp[msk][i-origin+1]=0;
                par[msk][i-origin+1]=0;
            }
            posCycle[msk]=0;
            parCycle[msk]=0;
        }
    }


    if(!pos){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
        for(int i=1; i<=n; i++){
            cout<<server[i]<<" ";
        }
    }

    return 0;
}
