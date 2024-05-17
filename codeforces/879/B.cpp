#include <bits/stdc++.h>
using namespace std;
#define MAX (int)2e5
int main() {
    long long winner[MAX];
    long long n;
    cin>>n;
    long long k;
    cin>>k;
    long long maxi=-1;
    long long arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    queue<long long>q;
    for(int i=0;i<n;i++) {
        if(arr[i]>maxi) maxi=arr[i];
        q.push(arr[i]);
    }
    long long ans=-1;
    if(k>=n-1) {
        ans=maxi;
    }
    else {
    while(!q.empty()) {
    long long player=q.front();
    q.pop();
    long long flag=0;
    while(1) {
        if(winner[player]==k) {
            flag=1;
            ans=player;
            break;
        }
    long long player2=q.front();
    if(player>player2) {
        winner[player]++;
        q.pop();
        q.push(player2);
    }
    else {
        q.push(player);
        winner[player2]++;
        break;
    }
    }
    if(flag==1) break;
    }
    }
    cout<<ans<<endl;
    return 0;
}