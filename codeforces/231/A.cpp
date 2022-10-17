#include <bits/stdc++.h>
const char nl='\n';
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
    int a,b,c;
    cin>>a>>b>>c;
    if((a+b+c)>=2){
        sum++;
    }
    }
    cout<<sum<<nl;
    return 0;
}
