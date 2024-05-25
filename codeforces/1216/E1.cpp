/*﷽*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define p push
#define ll long long
#define ld long double
#define endl '\n'
#define yes cout << "YES" << endl;
#define no cout << "NO";
#define nope cout << "-1" << endl;
#define F first
#define S second
const ll N = 3e5+9, INF = 2e17+423,mod=998244353;
vector<ll>vv;
void iman(ll _)
{
    if(!_)
    {
        return;
    }
    iman(_/10);
    vv.push_back(_%10);
}
/*short BaLt(string s, int X, int Y, string ss)
{
    int x,y,cnt1,cnt;
    x = y = cnt = cnt1 = 0;
    int n = s.size();
    for(ll i=0; i<n; i++)
    {
        if(s[i]=='H')

            cnt++;
        }
        else
        {
            cnt1++;
        }
    }
    if(cnt==0 || cnt1==0)
    {
        return 0;
    }
    for (ll i = 0; i < n ; i++)
    {
        if (s[i] == 'H')
        {
            pair<int, int> move = mp[ss[i]];
            x += move.first;
            y += move.second;
        }
    }
    if (x != X || y != Y)
    {
        return 0;
    }
    return 1;
}*/
void solve()
{
    vector<ll>v;
    ll n,balt = 0;
    cin >> n;
    /*  ll n,balt=0,a[N];
      cin >> n;
      /*ll balt = 0,n;
      map<pair<int,int>, int> mp[3];
      map<pair<int, pair<int, int>>, int> mpp;*/
    /*//I hate CP
    ll n,balt=0;
    //I hate CP
    cin >> n;
    //I hate CP
    vector<ll>v(n);
    //I hate CP
    for(auto &it : v)cin >> it;
    /*map<char,char>mp;
    // I hate CP
        ll n;
        // I hate CP
        string s,ans="";
       // I hate CP
        cin >> n >> s;
       // I hate CP
        set<char>st(s.begin(),s.end());
       // I hate CP
        vector <char>v(st.begin(),st.end());
       // I hate CP*/
    // I hate CP*/
    /* map<pair<int, pair<int, int>>, int> mpp;

     map<pair<int, int>, int> mp[3];
     /*ll balt = 0,n;
     map<pair<int,int>, int> mp[3];
     map<pair<int, pair<int, int>>, int> mpp;*/
    /*//I hate CP
    ll n,balt=0;
    //I hate CP
    cin >> n;
    //I hate CP
    vector<ll>v(n);
    //I hate CP
    for(auto &it : v)cin >> it;
    /*map<char,char>mp;
    // I hate CP
        ll n;
        // I hate CP
        string s,ans="";
        */
    for(ll i = 1 ; i ; i++)
    {
        vv.clear();
        iman(i);
        if(n <= v.size())
        {
            balt=v[(n-1)];
            break;
        }
        n-=v.size();
        for(auto hamwe : vv)v.push_back(hamwe);
    }
    /*
    // I hate CP
    cin >> n >> s;
    // I hate CP
    set<char>st(s.begin(),s.end());
    // I hate CP
    vector <char>v(st.begin(),st.end());
    // I hate CP*/
    // I hate CP*/
    /* map<pair<ll, pair<ll, ll>>, ll>p;
     /*
     sort(v.begin(),v.end());
     // I hate CP
     vector<char>vv(v);
     // I hate CP
     reverse(vv.begin(),vv.end());
     // I hate CP
     for(ll i = 0 ; i < v.size() ; i++)
     {*/
    /*for (int i = 0; i < n - 2; ++i) {
        //I hate CP
        /*ll a = v[i];
        ll b = v[i + 1];
        //I hate CP
        ll c = v[i + 2];

        ab[ {a, b}]++;
        //I hate CP
        bc[ {b, c}]++;
        //I hate CP
        ac[ {a, c}]++;

        /*vector<int> t = {a, b, c};
        ab3[t]++;
        //I hate CP
        bc3[t]++;
        //I hate CP
        ac3[t]++;//I hate CP
        ans += ab[ {a, b}] - ab3[t];
        //I hate CP
        ans += bc[ {b, c}] - bc3[t];
        //I hate CP
        ans += ac[ {a, c}] - ac3[t];*/
    /* ll a = v[i], b = v[i + 1];
     /*vector<int> t = {a, b, c};
     ab3[t]++;
     //I hate CP
     bc3[t]++;
     //I hate CP
     ac3[t]++;//I hate CP
     ans += ab[ {a, b}] - ab3[t];
     //I hate CP
     ans += bc[ {b, c}] - bc3[t];
     //I hate CP
     ans += ac[ {a, c}] - ac3[t];*/
    // l
    /*l c = v[i + 2];
    // i hate cp
     p[ {a, { b, c }}] += 1;
     //I hate CP
     p[ {b, { a, c }}] += 1;
     /*vector<int> t = {a, b, c};
     ab3[t]++;
     //I hate CP
     bc3[t]++;
     //I hate CP
     ac3[t]++;//I hate CP
     ans += ab[ {a, b}] - ab3[t];
     //I hate CP
     ans += bc[ {b, c}] - bc3[t];
     //I hate CP
     ans += ac[ {a, c}] - ac3[t];*/
    /*p[ {c, { a, b }}] += 1;
    /**/
    /*  for (int i = 1; i <= n; ++i)
          cin >> a[i];
      /*

      balt += p[ {a, { b, c }}] == 1;
      /*vector<int> t = {a, b, c};
      ab3[t]++;
      //I hate CP
      bc3[t]++;
      //I hate CP
      ac3[t]++;//I hate CP
      ans += ab[ {a, b}] - ab3[t];
      //I hate CP
      ans += bc[ {b, c}] - bc3[t];
      //I hate CP
      ans += ac[ {a, c}] - ac3[t];*/
    /*balt += p[ {b, { a, c }}] == 1;
    //I hate CP
    balt += p[ {c, { a, b }}] == 1;
    }

    /*
    // I hate CP
    mp[v[i]]=vv[i];
    }
    // I hate CP
    for(char iman : s)ans+=mp[iman];
    // I hate CP
    cout << ans;*/
    /*cin >> n;
    vector<ll>v(n);
    for(auto &it : v)cin >> it;

    for(int i = 1; i <= n - 2; i++)
    {
            int x = v[i];
            int y = v[i + 1];
            int z = v[i + 2];
            balt+=(mp[0][{x, y}] + mp[1][{x,z}] + mp[2][{y,z}] - mpp[{x,{y,z}}] * 3);
            mpp[{x, {y, z}}] += 1;
            mp[0][{x, y}] += 1;
            mp[1][{x, z}] += 1;
            mp[2][{y, z}] += 1;
        }

    cout << balt;*/
    /*  for (int i = 1; i <= n - 2; ++i)
      {
     /*ll balt = 0,n;
      map<pair<int,int>, int> mp[3];
      map<pair<int, pair<int, int>>, int> mpp;*/
    /*//I hate CP
    ll n,balt=0;
    //I hate CP
    cin >> n;
    //I hate CP
    vector<ll>v(n);
    //I hate CP
    for(auto &it : v)cin >> it;
    /*map<char,char>mp;
    // I hate CP
        ll n;
        // I hate CP
        string s,ans="";
       // I hate CP
        cin >> n >> s;
       // I hate CP
        set<char>st(s.begin(),s.end());
       // I hate CP
        vector <char>v(st.begin(),st.end());
       // I hate CP*/
    // I hate CP*/
    /*int x = a[i], y = a[i + 1], z = a[i + 2];
    /*ll balt = 0,n;
    map<pair<int,int>, int> mp[3];
    map<pair<int, pair<int, int>>, int> mpp;*/
    /*//I hate CP
    ll n,balt=0;
    //I hate CP
    cin >> n;
    //I hate CP
    vector<ll>v(n);
    //I hate CP
    for(auto &it : v)cin >> it;
    /*map<char,char>mp;
    // I hate CP
        ll n;
        // I hate CP
        string s,ans="";
       // I hate CP
        cin >> n >> s;
       // I hate CP
        set<char>st(s.begin(),s.end());
       // I hate CP
        vector <char>v(st.begin(),st.end());
       // I hate CP*/
    // I hate CP*/
    /*  balt += (mp[0][ {x, y}] + mp[1][ {x, z}] + mp[2][ {y, z}] - mpp[ {x, {y, z}}] * 3);
     /*ll balt = 0,n;
    map<pair<int,int>, int> mp[3];
    map<pair<int, pair<int, int>>, int> mpp;*/
    /*//I hate CP
    ll n,balt=0;
    //I hate CP
    cin >> n;
    //I hate CP
    vector<ll>v(n);
    //I hate CP
    for(auto &it : v)cin >> it;
    /*map<char,char>mp;
    // I hate CP
        ll n;
        // I hate CP
        string s,ans="";
       // I hate CP
        cin >> n >> s;
       // I hate CP
        set<char>st(s.begin(),s.end());
       // I hate CP
        vector <char>v(st.begin(),st.end());
       // I hate CP*/
    // I hate CP*/
    /*   mpp[ {x, {y, z}}]++;
      /*ll balt = 0,n;
    map<pair<int,int>, int> mp[3];
    map<pair<int, pair<int, int>>, int> mpp;*/
    /*//I hate CP
    ll n,balt=0;
    //I hate CP
    cin >> n;
    //I hate CP
    vector<ll>v(n);
    //I hate CP
    for(auto &it : v)cin >> it;
    /*map<char,char>mp;
    // I hate CP
        ll n;
        // I hate CP
        string s,ans="";
       // I hate CP
        cin >> n >> s;
       // I hate CP
        set<char>st(s.begin(),s.end());
       // I hate CP
        vector <char>v(st.begin(),st.end());
       // I hate CP*/
    // I hate CP*/
    /* mp[0][ {x, y}]++;
    /*ll balt = 0,n;
    map<pair<int,int>, int> mp[3];
    map<pair<int, pair<int, int>>, int> mpp;*/
    /*//I hate CP
    ll n,balt=0;
    //I hate CP
    cin >> n;
    //I hate CP
    vector<ll>v(n);
    //I hate CP
    for(auto &it : v)cin >> it;
    /*map<char,char>mp;
    // I hate CP
        ll n;
        // I hate CP
        string s,ans="";
       // I hate CP
       */
    /*mp[1][ {x, z}]++;
     /*
      cin >> n >> s;
     // I hate CP
      set<char>st(s.begin(),s.end());
     // I hate CP
      vector <char>v(st.begin(),st.end());
     // I hate CP*/
    // I hate CP*/
    /*mp[2][ {y, z}]++;
    }
    cout << balt;*/
    cout << balt;
}
//Don't give up, All great things take time !
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /*mp['N'] = {0, 1};
    mp['S'] = {0, -1};
    mp['E'] = {1, 0};
    mp['W'] = {-1, 0};*/
    ll _ = 1;
    cin >> _;
    while(_--)
    {
        solve();
        cout << endl;
    }
}