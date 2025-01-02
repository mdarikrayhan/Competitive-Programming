#include <bits/stdc++.h>
// علمكم الله ما ينفعكم و نفعكم بما تعلمتم و زادكم علما
// وَأَن لَّيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ، وَأَنَّ سَعْيَهُ سَوْفَ يُرَىٰ
using namespace std;
#define ll long long
#define int long long
#define ull unsigned long long
#define lol long long int
#define endl '\n'
#define Ceil(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define fr first
#define sc second
#define Zied() (ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr));
#define fixed(n) fixed << setprecision(n)
#define sz(s) int32_t(s.size())
#define debug(x) cout << #x << ": " << (x) << "\n";
#define getline(s) getline(cin >> ws, s)
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
#define pi  3.141592653589793
#define all(vec) vec.begin(), vec.end()
typedef pair<int , int> pii;
#define cin(vec) for(auto& i : vec) cin >> i
#define cout(vec) for(auto& i : vec) cout << i << " "; cout << "\n";
const int N = 2e5 + 5;
const ll inf = INFINITY;
template<typename T = int> istream& operator >>(istream& in, vector<T>& v) {
    for (auto& x : v)
        in >> x;
    return in;
}
template<typename T = int> ostream& operator <<(ostream& out, const vector<T>& v) {
    for (const T& x : v)
        out << x << ' ';
    return out;
}

int dx[] = {1, 0, -1, 0, -1, -1, 1, 1};
int dy[] = {0, -1, 0, 1, -1, 1, -1, 1};
char di[] = {'D', 'L', 'U', 'R'};
vector <int > last(N , -1);
void Solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x, y; cin >> x >> y;
        vector<int> div;
        for (int j = 1; j <= x / j; j++) {
            if (x % j)continue;
            div.push_back(j);
            if (x / j != j) div.push_back(x / j);
        }
        int cnt = 0;
        for (auto d: div) {
            if (last[d] < i - y) cnt++;
            last[d] = i;
        }
        cout << cnt <<endl;
    }
}

int32_t main() {
    Zied()
    int test_cases = 1;
//    freopen("mex.in", "r", stdin);
//    freopen("balancing.out", "w", stdout);
//    cin >> test_cases;
    for (int tc = 1; tc <= test_cases; tc++) {
        //        cout << "Case #" << tc << ": ";
        Solve();
        //        cout << endl;
    }
    //    Time
}
/*
              ,   .-'"'=;_  ,
              |\.'-~`-.`-`;/|
              \.` '.'~-.` './
              (\`,__=-'__,'/)
           _.-'-.( d\_/b ).-'-._
         /'.-'   ' .---. '   '-.`\
       /'  .' (=    (_)    =) '.  `\
      /'  .',  `-.__.-.__.-'  ,'.  `\
     (     .'.   V       V  ; '.     )
     (    |::  `-,__.-.__,-'  ::|    )
     |   /|`:.               .:'|\   |
     |  / | `:.              :' |`\  |
     | |  (  :.             .:  )  | |
     | |   ( `:.            :' )   | |
     | |    \ :.           .: /    | |
     | |     \`:.         .:'/     | |
     ) (      `\`:.     .:'/'      ) (
     (  `)_     ) `:._.:' (     _(`  )
     \  ' _)  .'           `.  (_ `  /
      \  '_) /   .'"```"'.   \ (_`  /
       `'"`  \  (         )  /  `"'`
   ___   MZ   `.`.       .'.'        ___
 .`   ``"""'''--`_)     (_'--'''"""``   `.
(_(_(___...--'"'`         `'"'--...___)_)_)
*/