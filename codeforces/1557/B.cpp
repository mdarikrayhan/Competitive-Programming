#include <bits/stdc++.h>
using namespace std;
int t,n,k;
pair<int,int> a[100020];
int main() {
cin>>t;
while (t--){
cin>>n>>k;
for (int i=0;i<n;i++){
cin >> a[i].first;
a[i].second=i;
}
sort(a,a+n);
for (int i=1;i<n;i++) if (a[i-1].second+1 != a[i].second) k--;
puts(k>0 ? "Yes" :"No");
}
return 0;
}