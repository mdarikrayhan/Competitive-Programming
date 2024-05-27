#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() 
{
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout); 
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n+1,vector<int> (m+1));
    vector<int> rows(n+1,0);
    vector<int> cols(m+1,0);
    for (int i = 1; i<=n;i++) {
      ll cou = 0;
      for (int j = 1;j<=m;j++) {
        cin>>a[i][j];
        cou+=a[i][j];
      }
      rows[i] = rows[i-1] + cou;
    }
    for (int i = 1; i<=m;i++) {
      ll cou = 0;
      for (int j = 1;j<=n;j++) {
        cou+=a[j][i];
      }
      cols[i] = cols[i-1] + cou;
    }
    vector<int> tr(3);
    ll ans = 0;
    cin>>tr[0]>>tr[1]>>tr[2];
    sort(tr.begin(),tr.end());
    for (int l = 1;l<n - 1;l++) {
      for (int r = l+1;r<n;r++) {
        vector<int> de(3);
        de[0] = rows[r] - rows[l], de[1] = rows[l],de[2] = rows[n] - rows[r];
        sort(de.begin(),de.end());
        if (de[0] == tr[0] && de[1] == tr[1] && de[2] == tr[2]) {
          ans++;
        }
      }
    }
    for (int l = 1;l<m - 1;l++) {
      for (int r = l+1;r<m;r++) {
        vector<int> de(3);
        de[0] = cols[r] - cols[l], de[1] = cols[l],de[2] = cols[m] - cols[r];
        sort(de.begin(),de.end());
        if (de[0] == tr[0] && de[1] == tr[1] && de[2] == tr[2]) {
          ans++;
        }
      }
    }
    /*for (int i = 1;i<=n;i++) {
      cout<<rows[i]<<' ';
    } cout<<endl;
    for (int j=1;j<=m;j++) {
      cout<<cols[j]<<' ';
    } cout<<endl;*/ 
    cout<<ans;
    
    return 0; 
}