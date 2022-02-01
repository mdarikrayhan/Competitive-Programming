    #include<bits/stdc++.h>
    using namespace std;
     
    int main()
    {int t;
    cin>>t;
    while(t--)
    {int n;
    cin>>n;
    int a=n%7;
    if(a<=n%10)
    n-=a;
    else n+=7-a;
    cout<<n<<"\n";
    }
    }