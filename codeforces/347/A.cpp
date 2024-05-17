#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <cmath>

using namespace std;

#define DBG(z) cerr << #z << ": " << (z) << endl
#define NEWL cerr << endl
#define passert(x, m) {if (!(x)) {cerr << m << "  ::  ";} assert(x);}
#define err(s) cerr << "[92m" << s << "[0m" << endl
#define LINE cerr << "DEBUG LINE: " << __LINE__ << endl

#define IT(v) __typeof((v).begin())
#define mem(f, a) memset(f, a, sizeof(f))
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define for_each(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define next_int() ({int __t; scanf("%d", &__t); __t;})

int main() {
    int n = next_int();
    vector <int> a(n);
    for (int i = 0; i < a.size(); ++i) a[i] = next_int();
    sort(all(a));
    swap(a[0], a[n - 1]);
    for (int i = 0; i < a.size(); ++i) {
        if (i) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}

