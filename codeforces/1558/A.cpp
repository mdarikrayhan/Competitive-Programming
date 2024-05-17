#include <bits/stdc++.h>
#define ll long long
#define lli long long int
#define ulli unsigned long long int
#define vi vector<int>
#define pii pair<int,int>
#define vlli vector<lli>
#define vpii vector<pii>
#define vvi vector<vector<int> > 
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,a,b) for(int i=a;i>=b;i--)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(a)  (int)a.size()
#define ld  long double
#define ff  first
#define ss  second


using namespace std;

//ctrl + B to compile and run
//ctrl + Q to stop infinite loop
//Here is one interesting fact. There always exists a power of prime p in the range [x,p*x] for any positive integer x
//With any positive integer x, there is at least one square number in [x,2x]
//if getting precision error write the formula in different ways and try also make sure to perform all multiplications before your division
//if no output check out of bounds, array size,, division by zero, modulo with 0, division long long by int

template<typename T> istream& operator>>(istream &in, vector<T>& a) { for(auto &x:a) in >> x; return in; }
template<typename T> ostream& operator<<(ostream &out, vector<T>& a) { for(auto &x:a) out << x << " "; return out; }
template<typename T> void prt(T to_print){cout << to_print << '\n';return;}
template<typename T1,typename T2> ostream& operator<<(ostream &out,pair<T1,T2> &p){out << "{" << p.first << "," << p.second<<"} ";return out;}







void solve(){


    int awon,bwon;cin >> awon >> bwon;
    int aserves = (awon+bwon+2-1)/2;
    int bserves = (awon+bwon)/2;
    set<int> st;
    for(int i=0;i<2;i++){
        for(int j=0;j<=aserves;j++){
            int bbeatsa = j;
            int abeatsb = awon-aserves+bbeatsa;
            if(abeatsb>=0 && abeatsb<=bserves && bbeatsa>=0 && bbeatsa<=aserves){
                st.insert(abeatsb+bbeatsa);
            }
        }
        swap(aserves,bserves);
    }
    cout << st.size() << '\n';
    for(auto x:st){
        cout << x << " ";
    }
    cout << '\n';


    


   


    











    


    



    //cout << "\n-------------------------\n";
    return;
    
}




int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);

    
    int t;cin >> t;
    while(t--) 
        solve();
    
    

    return 0;
}