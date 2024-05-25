//Author : silenttkillerr
#include<vector>
#include<map>
#include<set>
#include<unordered_map>
#include<algorithm>
#include<iostream>
#include<cassert>
#include<math.h>
#include<string>
#include<bitset>
#include<stdio.h>
#include<utility>
#include<queue>
#include<stack>
#include<deque>
#include<iterator>
#include<list>
#include<iomanip>
#include<chrono>
#include<unordered_set>
#include<string>
#include<cmath>
#include<cstring>
using namespace std;
#define fast ios_base::sync_with_stdio(0),cin.tie(0)
#define ll long long
#define cout std::cout
#define cin std::cin
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define syes cout<<"Yes"<<endl;
#define sno cout<<"No"<<endl;
#define pb push_back
#define sorta(vec) sort(vec.begin(),vec.end())
#define sortd(vec) sort(vec.begin(),vec.end(),greater<int>())
#define vll vector<vector<ll int>>
#define vl vector<ll>
#define nline "\n"
#define all(v) (v).begin(),(v).end()
#define pii pair<ll int,ll int>
#define piii pair<ll int,pair<ll int,ll int>>
//less , less_equal , greater , greater_equal -> rule for insertion
#define start_execution auto start = std::chrono::high_resolution_clock::now();
#define stop_execution auto stop = std::chrono::high_resolution_clock::now();
#define execution_time auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); cerr<<"Time taken : "<<((long double)duration.count())/((long double)1e9) <<"s"<<endl; 
void entry_check(){cout<<"Entered"<<endl;}
void yn(bool res){if(res==true){yes;}else{no;}}
//const ll mod=1000000007;
const ll mod=998244353;
//ll int mod=1000000000000000000;
template<class T>
void print_v(vector<T>&vec)
{
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}
void debug(ll int n)
{
    cout<<n<<endl;
}
void debug(int n)
{
    cout<<n<<endl;
}
void debug(string n)
{
    cout<<n<<endl;
}
void debug(vector<int>&vec)
{
    for(int i=0;i<vec.size();i++)
    {
        cout<<"[ "<<i<<" "<<vec[i]<<" ]"<<endl;
    }
}
void debug(vector<ll int>&vec)
{
    for(int i=0;i<vec.size();i++)
    {
        cout<<"[ "<<i<<" "<<vec[i]<<" ]"<<endl;
    }
}
ll int inv(ll int r)
{
	if(r==1) return 1;
	return (mod-((mod/r)*inv(mod%r))%mod+mod)%mod;
}
ll mod_add(ll int a,ll int b){a=a%mod;b=b%mod;return (((a+b)%mod)+mod)% mod;}
ll mod_mul(ll int a,ll int b){a=a%mod;b=b%mod;return (((a*b)% mod)+mod)%mod;}
ll mod_sub(ll int a, ll int b){a=a%mod;b=b%mod;return (((a - b)%mod)+mod)%mod;}
ll mod_div(ll a,ll b){a=a%mod;b=b%mod;return (a*inv(b))%mod;}
ll int ceil_div(ll int a,ll int b){return (a+b-1)/b;}
ll int gcd(ll int a,ll int b)
{
    if (!a)
    {
        return b;
    }
    return gcd(b%a,a);
}
ll int lcm(ll int a,ll int b)
{
    //ll int g=__gcd(a,b);
   // return (1LL*a*b)/g;
}
ll int pwr(ll int a,ll int b)
{
    if(b==0)
    {
        return 1;
    }
    if(b%2==0)
    {
        ll int ans1=pwr(a,b/2);
        ll int ans2=(ans1*ans1)%mod;
        return ans2;
    }
    ll int ans1=pwr(a,b/2);
    ll int ans2=(ans1*ans1)%mod;
    ans2=(ans2*a)%mod;
    return ans2;
}
class factorial
{
    public:
    vector<ll int>fact;
    factorial(int n)
    {
        fact.resize(n+1,0);
        fact[0]=1;
        for(int i=1;i<=n;i++)
        {
            fact[i]=mod_mul(fact[i-1],i);
        }
    }

    ll int ncr(int n,int r)
    {
        ll int a=fact[n];
        ll int b=fact[r];
        ll int c=fact[n-r];

        c=mod_mul(c,b);
        a=mod_div(a,c);
        return a;
    }
};
template<class ForwardIterator>
void read(ForwardIterator first,ForwardIterator last) 
{
    while (first != last) 
    {
        cin >> (*first);
        ++first;
    }
}
template<class T>
void read(vector<T> &v) 
{
    read(v.begin(), v.end());
}
template<class T>
void read1(vector<T>&v) 
{
    for(int i=1;i<v.size();i++)
    {
        cin>>v[i];
    }
}
ll int polynomial_hash(string & s) 
{
    const int p=31;
    const int m=1e9+9;
    //const int m=1e16+7;
    ll int hash_value = 0;
    ll int p_pow=1;
    for (char c:s) 
    {
        hash_value=(hash_value+(c-'a'+1)*p_pow)%m;
        p_pow=(p_pow*p)%m;
    }
    return hash_value;
}
bool cmp(vector<int>&a,vector<int>&b)
{
    if(abs(a[0])<abs(b[0]))
    {
        return true;
    }
    return false;
}

//code starts here

// pair<int,vector<vector<int> > > c(int n,int m,vector<vector<int> >vec,int p){
//     int ans=0;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if((i+j)%2){
//                 if(vec[i][j]%2==p){

//                 }
//                 else{
//                     vec[i][j]++;
//                     ans++;
//                 }
//             }
//             else{
//                 if(vec[i][j]%2==(!p)){

//                 }
//                 else{
//                     ans++;
//                     vec[i][j]++;
//                 }
//             }
//         }
//     }
//     return make_pair(ans,vec);
// }
// bool dfs2(int start,int end,int index,vector<vector<int> >&graph,vector<int>&dp){
//     dp[index]=1;
//     if(index==end){
//         return true;
//     }
//     for(auto x:graph[index]){
//         if(dp[x]){

//         }
//         else{
//             if(dfs2(start,end,x,graph,dp)){
//                 return true;
//             }
//         }
//     }
//     dp[index]=0;
//     return false;
// }
// ll int tot=0;
// int f[200005];
// int dfs(int index,vector<vector<int> >&graph,vector<int>&dp,int d,int p){
//     dp[index]=d;
//     int ans=0;
//     for(auto x:graph[index]){
//         if(x==p){
//             continue;
//         }
//         if(dp[x]!=0){
//            // cout<<d<<" "<<dp[index]<<" ds"<<endl;
//             int v=d-dp[x];
//             int sz=graph.size();
//             for(int i=0;i<sz;i++){
//                 dp[i]=0;
//             }
//             dfs2(index,x,index,graph,dp);
//             return v;
//         }
//         ans=max(ans,dfs(x,graph,dp,d+1,index));
//         if(ans>0){
//             return ans;
//         }
//     }
//     dp[index]=0;
//     return ans;
// }

// int dfs(int index,vector<vector<int> >&graph,vector<int>&dp){
//     dp[index]=1;
//     int ans=1;
//     for(auto x:graph[index]){
//         if(dp[x]!=0){
//             continue;
//         }
//         ans+=dfs(x,graph,dp);
//     }
//     return ans;
// }

// void mix(vector<int>&vec,vector<int>&v){
//     vector<vector<int> >nv;
//     int ptr=0;
//     for(auto x:v){
//         int sz=x;
//         vector<int>t;
//         while(sz--){
//             t.push_back(vec[ptr]);
//             ptr++;
//         }
//         nv.push_back(t);
//     }
//     int n=vec.size();
//     int av=n-1;

//     for(auto x:nv){
//         int sz=x.size();
//         int start=av-sz+1;
//         av=start-1;
//         for(auto y:x){
//             vec[start]=y;
//             start++;
//         }
//     }
// }

// bool f1(int p,int n,vector<int>&vec){
//     vector<int>ans(n,0);
//     vector<vector<int> >ele;
//     vector<vector<int> >rem;
//     rem.push_back({vec[0],0});
//     rem.push_back({vec[n-1],0});
//     for(int i=1;i<n-1;i++){
//         if(i%2==p){
//             ele.push_back({vec[i],i});
//         }
//         else{
//             rem.push_back({vec[i],i});
//         }
//     }

//     int start=(n-2)/2;

//     sort(all(ele));
//     reverse(all(ele));
//     sort(all(rem));

//     for(auto x:ele){
//         ans[x[1]]=start;
//         start++;
//     }
//     start=(n-2)/2;
//     start--;

//     for(auto x:rem){
//         ans[x[1]]=start;
//         start--;
//     }

//     for(int i=1;i<n-1;i++){
//         if(i%2==p){
//             if(vec[i]+ans[i]<=vec[i-1]+ans[i-1] || vec[i]+ans[i]<=vec[i+1]+ans[i+1]){
//                 return false;
//             }
//         }
//     }
//     vec=ans;
//     return true;
// }

// string check(int len,int k,string &s)
// {
//     map<char,int>mp;
//     string g="";
//     for(int i=0;i<=len;i++){
//         mp[s[i]]++;
//         g.push_back(s[i]);
//     }

//     //Now

//     bool f=false;
//     int n=s.size();

//     int sz=g.size();
//     if(sz==n){
//         return g;
//     }
//     bool got=false;
//     for(char c='a';c<='z';c++){
//         if(c<=s[sz]){
//             continue;
//         }
//         got=true;
//         sz++;
//         g.push_back(c);
//         mp[c]++;
//         break;
//     }
//     //cout<<g<<endl;
//     if(got==false){
//         return "-1";
//     }

//     int r=0;
//     map<char,int>rem;
//     for(auto x:mp){
//         int h=x.second;
//         h=k-h;
//         h=h%k;
//         r+=h;
//         rem[x.first]=h;
//       //  cout<<x.first<<" "<<h<<endl;
//     }
    
//     int d=sz-r;
//     //cout<<sz<<" "<<r<<endl;
//     while(d>0){
//         d--;
//         g.push_back('a');
//     }

//     //string l="";
//     for(auto x:rem){
//         int fr=x.second;
//         //cout<<x.first<<" "<<fr<<" "<<g<<endl;
//         while(fr--){
//             g.push_back(x.first);
//         }
//     }
//     //cout<<g<<endl;
//     return g;

// }
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>pbds; // find_by_order, order_of_key(0-indexed)

// void erase_pbds(pbds &st,ll int ele)
// {
//     int rank = st.order_of_key(ele);
//     auto it= st.find_by_order(rank);
//     st.erase(it);
// }
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //freopen("error.txt","w",stderr);
    #endif
    fast;
    start_execution
    int tt=1;
    cin>>tt;
    for(int tc=0;tc<tt;tc++)
    {
        int n,k;
        cin>>n>>k;

        string s;
        cin>>s;

        map<char,int>mp;
        for(auto x:s){
            mp[x]++;
        }
        set<vector<int>>st;
        int left=0;
        for(auto x:mp){
            if(x.second%k){
                left+=x.second%k;
                st.insert({x.first-'a',x.second});
            }
        }
        if(st.size()==0){
            cout<<s<<endl;
            continue;
        }

        bool res=false;
        for(int i=n-1;i>=0;i--)
        {
            if(res){
                break;
            }
            //remove character at i

            int f=mp[s[i]];

            if(f%k==0){

            }
            else{
                st.erase({s[i]-'a',f});
            }

            //we have to remove so 
            f--;
            mp[s[i]]--;
            if(f%k){
                st.insert({s[i]-'a',f});
            }

            //Now try to insert any character bigger then s[i] and try to balance all the f

            for(char c='a';c<='z';c++){
                if(c<=s[i] || res==true){
                    continue;
                }

                //we will put here c, is it feasabile
                int rem=0;
                for(char a='a';a<='z';a++){

                    if(a==c){
                        mp[a]++;
                    }
                     int p=mp[a]%k;
                   //cout<<a<<" "<<p<<endl;
                   p=k-p;
                   p=p%k;
                   rem+=p;

                    if(a==c){
                        mp[a]--;
                    }
                    
                }

                int space=n-i;
                space--;

                if(space>=rem){
                    int d=space-rem;
                    if(d%k){
                        continue;
                    }
                    //mp['a']+=d;

                    //we can build 
                    res=true;

                    string ns="";

                    for(int j=0;j<i;j++){
                        ns.push_back(s[j]);
                    }
                    
                    ns.push_back(c);
                    //cout<<ns<<endl;
                    //put all order
                    mp[c]++;

                    for(char a='a';a<='z';a++){

                   int p=mp[a]%k;
                   //cout<<a<<" "<<p<<endl;
                   p=k-p;
                   p=p%k;
                   while(p--){
                    ns.push_back(a);
                   }
                   if(a=='a'){
                    while(d--){
                        ns.push_back('a');
                    }
                   }
                   
                    
                }
                int v=ns.size();
                assert(v==n);
                cout<<ns<<endl;
               // cout<<i<<" "<<c<<endl;
                   break;

                }
            }
        }

        if(res==false){
            cout<<-1<<endl;
        }


        // int n,x1;
        // cin>>n>>x1;

        // vector<int>vec(n);

        // read(vec);

        // priority_queue<int>pq;

        // int f=0;
        // int t=0;
        // for(auto x:vec){

        //     int c=f;
        //     //f+=x;
        //     if(f+x<=(t*x1)){
        //         pq.push(x);
        //         f+=x;
        //     }
        //     else{
        //         if(pq.size()>0){
        //             int z=pq.top();
        //             pq.pop();
        //             f-=z;
        //             pq.push(min(z,x));
        //             f+=min(z,x);
        //         }
        //     }
        //     t++;
        // }

        // cout<<pq.size()<<endl;

        // vector<vector<int> >f;

        // for(int i=0;i<n;i++){
        //     f.push_back({vec[i],i});
        // }
        // sort(all(vec));
        // pbds<int>st;

        // int ans=0;

        // for(auto x:f){
        //     int cost=x[0];
        //     int index=x[1];

        //     int below=st.order_of_key(index);

        //     ll int gc=
        // }



        // vector<ll int>pref(n,0);
        // ll int tot=0;
        // for(int i=0;i<n;i++){
        //     int c,h;
        //     cin>>c;
        //     h=1;
        //     tot+=h;
        //     pref[i]=c;
        //     vector<int>p;
        //     p.push_back(c);
        //     p.push_back(h);
        //     vec.push_back(p);
        // }

        // ll int dp[n+10][tot+10];


        // memset(dp,-1,sizeof(dp));
        // for(int i=0;i<n;i++){
        //     dp[i][0]=0;
        // }
        // for(int i=0;i<n;i++){

        //     if(i==0){
        //         dp[i][0]=0;
        //         if(vec[i][0]==0){
        //             dp[i][vec[i][1]]=0;
        //             //cout<<i<<" "<<vec[i][1]<<endl;
        //         }
        //         continue;
        //     }
        //     for(int happ=0;happ<=tot;happ++){
                
        //         //I want this happiness at this index

        //         ll int offer=vec[i][1];
                

        //         if(happ-offer>=0 && dp[i-1][happ-offer]!=-1){

        //             ll int need=dp[i-1][happ-offer]+vec[i][0];

        //             if(need<=(1LL*x*i)){
        //                 dp[i][happ]=need;
        //             }
        //         }

        //         if(i==1 && happ==10){
        //             //cout<<offer<<endl;
        //         }

        //         if(dp[i-1][happ]!=-1){
        //             if(dp[i][happ]==-1){
        //                 dp[i][happ]=dp[i-1][happ];
        //             }
        //             else{
        //                 dp[i][happ]=min(dp[i][happ],dp[i-1][happ]);
        //             }
                   
        //         }
        //     }
        // }
        // ll int ans=0;

        // for(int i=0;i<=tot;i++){
        //    // cout<<dp[n-1][i]<<endl;
        //     if(dp[n-1][i]>-1){
        //         ans=i;
        //     }
        // }

        // cout<<ans<<endl;
        

    
      


    
    }
    #ifndef ONLINE_JUDGE
    cout<<" Remove light"<<endl;
    cout<<" Remove light"<<endl;
    cout<<" Remove light"<<endl;
    #endif
    stop_execution
    //execution_time
    return 0;
} 