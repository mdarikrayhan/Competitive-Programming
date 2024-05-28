#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 2e5 + 10;
const int MOD = 1009;

void get_roots(bool f, int n, vector<complex<double>>& roots) {
        const static double PI = acosl(-1);
        for (int i = 0; i < n/2; i++) {
                double alpha = i*((2*PI)/n);
                if (f) alpha = -alpha;
                roots[i] = {cos(alpha), sin(alpha)};
        }
}

template<typename T> void fft(vector<T>& a, bool f, int N, vector<int>& rev) {
        for (int i = 0; i < N; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
        int l, r, m;
        vector<T> roots(N);
        for (int n = 2; n <= N; n *= 2) {
                get_roots(f, n, roots);
                for (int pos = 0; pos < N; pos += n) {
                        l = pos + 0, r = pos + n/2, m = 0;
                        while (m < n/2) {
                                auto t = roots[m] * a[r];
                                a[r] = a[l] - t;
                                a[l] = a[l] + t;
                                l++, r++, m++;
                        }
                }
        }
        if (f) {
                auto invN = T(1) / T(N);
                for (int i = 0; i < N; i++) a[i] = a[i] * invN;
        }
}

template<typename T> vector<T> convolution(vector<T>& a, vector<T>& b) {
        vector<T> l(a.begin(), a.end()), r(b.begin(), b.end());
        int N = l.size()+r.size()-1;
        int n = 1, log_n = 0;
        while (n <= N) n *= 2, log_n++;
        vector<int> rev(n);
        for (int i = 0; i < n; i++) {
                rev[i] = 0;
                for (int j = 0; j < log_n; j++) if (i>>j&1)
                        rev[i] |= 1 << (log_n-1-j);
        }
        assert(N <= n);
        l.resize(n);
        r.resize(n);
        fft(l, false, n, rev);
        fft(r, false, n, rev);
        for (int i = 0; i < n; i++) l[i] *= r[i];
        fft(l, true, n, rev);
        l.resize(N);
        return l;
}

int cnt[MAX];
vector<complex<double>> solve(int lo, int hi){
    if(lo == hi) return vector<complex<double>>(cnt[lo]+1, 1);

    int mid = (lo+hi)/2;
    vector<complex<double>> s1 = solve(lo, mid), s2 = solve(mid+1, hi);

    vector<complex<double>> res = convolution(s1, s2);
    for(auto &x : res) x = (ll)round(x.real())%MOD;

    return res;
}

int main() { _
    int n, m, k; cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        int x; cin >> x; x--;
        cnt[x]++;
    }

    vector<complex<double>> ans = solve(0, m-1);
    cout << (ll)round(ans[k].real())%MOD << endl;

    return 0;
}