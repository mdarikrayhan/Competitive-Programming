
#include <iostream>
#include <map>

using namespace std;

int main() {

cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(0);

int n;
cin >> n;
map<int, int> solo;
map<pair<int, int>, int> pairs;
long long ans = 0;
for (int i = 0; i < n; i++) {
int w, h;
cin >> w >> h;
if (w > h) {
swap(w, h);
}
if (w == h) {
ans += solo[w];
solo[w] += 1;
} else {
ans += solo[w] + solo[h] - pairs[{w, h}];
solo[w] += 1;
solo[h] += 1;
pairs[{w, h}] += 1;
}
}
cout << ans << endl;

}