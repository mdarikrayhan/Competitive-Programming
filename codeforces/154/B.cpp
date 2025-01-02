#include <bits/stdc++.h>
using namespace std;
typedef int64_t T;
#define ll long long 
const int M = 1e9+7;
const int N = 2e5+10;

int gcd(int a, int b){
    if(b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
    
}

//*****log(x)

vector<int> factors(int x,vector<int> &spf){
    vector<int> ans;
    while(x!=1){
        int prime = spf[x];
        while(x%prime == 0){
            x = x/prime;
        }

        ans.push_back(prime);
    }

    return ans;
}

//*****


void solve(){
    // cout<<"THE"<<endl;
    int n,m;
    cin>>n>>m;

    vector<int> is_active(n+1);
    vector<int> occupied(n+1);


    //***** nlog(log(n))
    vector<bool> isPrime(n+1,true);
    vector<int> spf(n+1, 1e9);

    isPrime[0]=false;
    isPrime[1]=false;

    for(int i=2;i <= n;i++){
        if(isPrime[i]){
            spf[i] = i;

            for(int j=2*i;j <= n;j=j+i){
                isPrime[j]=false;
                spf[j] = min(spf[j],(int)i);
            }
        }
    }

    //*****


    for(int i=0;i<m;i++){
        char c;
        cin>>c;
        int val;
        cin>>val;

        vector<int> primes = factors(val, spf);

        if(is_active[val] == 1 && c == '+'){
            cout<<"Already on"<<endl;
        }else if(is_active[val] == 0 && c == '-'){
            cout<<"Already off"<<endl;
        }else if(is_active[val] == 0 && c == '+'){

            

            int conflict = 0;

            for(auto &it : primes){
                if(occupied[it]){
                    conflict = occupied[it];
                }
            }

            if(conflict){
                cout<<"Conflict with "<<conflict<<endl;
            }else{
                cout<<"Success"<<endl;
                for(auto &it : primes){
                    occupied[it] = val;
                }
                is_active[val] = 1;
            }



            



        }else{
            cout<<"Success"<<endl;
            is_active[val] = 0;
            for(auto &it : primes){
                occupied[it] = 0;
            }
        }


    }
}


int main() {
    

    int t=1;
    // cin >> t;
    while (t--) {
        solve();
          
    }
    return 0;
}

/*


*/