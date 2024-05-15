 #include <bits/stdc++.h>

    #define yes cout << "YES" << endl;
    #define no cout << "NO" << endl;
    #define zero cout << '0' << endl;
    #define mone cout << "-1" << endl;
    #define one cout << '1' << endl;
    #define endl "\n"
    #define ll long long
    #define pb push_back
    #define pp pop_back
    using namespace std;

    signed solve()
    {
    int n,a,p;
    int money = 0, price = 101;
    cin>>n;
  while(n--){
    cin>>a>>p;
    if(price > p){ price = p; }
    money += price * a;
  }
    cout<<money;
    }




    signed main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
       cout << fixed << setprecision(6);
        int T=1;
        //cin >> T;
        while(T--)
        {
            solve();
        }

        return 0;
    }
;
