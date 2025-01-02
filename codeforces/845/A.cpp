#include <bits/stdc++.h>

using namespace std;

typedef long long ll; 
#define pb push_back
#define be(a) a.begin(), a.end()
#define vi vector<int> 
#define vl vector<ll>
#define vs vector<string>
#define vc vector<char>
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;

void funk() 
{
    ll n;cin>>n;
    vl pew;
    for(int i=0;i<2*n;i++)
    {
        ll gg;cin>>gg;pew.pb(gg);
    }
    sort(be(pew));
    if(pew[n]>pew[(n)-1]){yes;}
    else{no;}

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t=1;
    while (t--)
    {
        funk();
    }
    return 0;
}

/*                                                               
           .-+********+=:                         
         .+**************+:                       
        -***********+***+**+.                     
       :*********+****=+****+:                    
       +***************:+****+.                   
      :***********+++*#.:+#***+                   
      -*******+***=---.   .=***=                  
      -*******===-      .:..+***+.        .       
      :*******. .:.    .:.. +***==.     ...:..    
      -*******=--.          +****:-        ..     
      =*+******:          .+++***-.   ......      
      =+-******+:       .=*+*****-..  .......     
      .+:****#*****::::-*#######*- . .   .:..     
       .+****##***#=:::.=*###*#**#-**+==:.:.      
        +******##**#*:  .*#******#-********       
       .*######*****##--*******####*******:       
       ****#*######***#############******#+       
      :*****#**#*#############*###*******#+       
      -****#*****#*##**#####***####******#-       
      -*****##***#*##****##*****###*****###.
*/  
