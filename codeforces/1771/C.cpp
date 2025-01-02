#include <bits/stdc++.h>             //                          الْحَمْدُ لِلَّهِ وَحْدَهُ
using namespace std;                 //           وَالصَّلاَةُ وَالسَّلاَمُ عَلَى مَنْ لاَ نَبِيَّ بَعْدَهُ

typedef long long       ll;          //        All praise is due to Allah alone,
typedef vector<int>     vi;          //  and peace and blessings be upon him after
typedef pair<int, int>  pii;         //         whom there is no other Prophet.
typedef map<int,int>    mii;    

#define cin(ar)         for(auto &i: ar) cin >> i;
#define cout(ar)        for(auto i: ar) cout << i <<' '; cout << '\n';
#define all(ar)         ar.begin(), ar.end();

const int N = 32000;
bitset<N>mark;
vi prime;
void pre(){
    prime.emplace_back(2);
    for(int i = 3; i < N; i+=2){
        if(mark[i] == 0) prime.emplace_back(i);
        for(int j = i * i; j < N; j += i){
            mark[j] = true;
        }
    }
}
void test_case(){
    int n; cin >> n;
    bool check = false;
    map<int, bool> save;
    function<void(int)> khali_kali_function = [&save,&check](int logn)->void{
        for(int i : prime){
            if(logn % i == 0){
                check |= save.find(i) != save.end();
                while(logn % i == 0) logn /= i;
                save[i];
            }
        }
        if(logn > 1) {
            check |= save.find(logn) != save.end();
            save[logn];
        }
    };
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        if(check) continue;
        khali_kali_function(x);
    }
    if(check) cout << "YES\n";
    else cout << "NO\n";
}
/// في سبيل الله
signed l9_30; signed main(){
    cin.tie(0)->sync_with_stdio(false);

    pre();
    l9_30 = true;    cin>>l9_30;
    for(int T = 1; T <= l9_30; T++){
        test_case();
    }
    return l9_30 ^ l9_30;
}