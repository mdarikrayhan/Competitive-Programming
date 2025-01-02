/****~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~****\
 |  Problems! Problems! Problems! I Don't Like It, I Avoid.             |
 |  But Problems Likes Me! I can't Avoid!                               |
 |                                                                      |
 |  * A.H.M. Fahim Morshed  *                                           |
 |  Github   - ahm-fahim                                                |
 |  Linkedin - https://www.linkedin.com/in/md-fahim-morshed-5b2126233/  |
 |  Gmail    - <a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="3655595842575542575e5b50575e5f5b76515b575f5a1855595b">[email&#160;protected]</a>                                |
\****~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~****/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define make_fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu () { cerr << endl;}
template < typename T, typename ... hello>void faltu( T arg, const hello &... rest) {cerr << arg << ' ';faltu(rest...);}


int main()
{
    make_fast();
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;

        if(n % 2 == 0){
            cout << n/2 << " " << n/2 << "\n";
            continue;
        }
        ll x = n / 2, y = n - x;
        if(n%20 == 19){
             string c=to_string(n);
            string a=c,b=c;
            int SOD1=0,SOD2=0;
 
            for(int i=0;i<a.size();i++){
                int v1,v2;
                v1=(c[i]-'0')/2;
                v2=(c[i]-'0')-v1;
                if(v1==v2){
                    a[i]='0'+v1;
                    b[i]='0'+v2;
                }
                if(v1>v2)swap(v1,v2);
                if(SOD1>=SOD2){
                    b[i]='0'+v2;
                    a[i]='0'+v1;
                    SOD2+=(b[i]-'0');
                    SOD1+=(a[i]-'0');
                }
                else{
                    a[i]='0'+v2;
                    b[i]='0'+v1;
                    SOD2+=(b[i]-'0');
                    SOD1+=(a[i]-'0');
                }
            }
            reverse(a.begin(),a.end());
            reverse(b.begin(),b.end());
            while(b.back()=='0')b.pop_back();
            while(a.back()=='0')a.pop_back();
            reverse(a.begin(),a.end());
            reverse(b.begin(),b.end()); 
            cout<<a<<" "<<b<<endl;
        }else{
            cout << x << " " << y << '\n';
        }
    }
    return 0;   
}