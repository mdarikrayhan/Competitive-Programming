#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MX=3e5+5;

int N;
int cnt[5];

int main() {
        cin.tie(0); ios_base::sync_with_stdio(0);

        cin>>N;
        for(int i=0;i<N;i++) {
                int x;
                cin>>x;
                cnt[x]++;
        }

        int ans=0;
        int m=min(cnt[1],cnt[2]);

        cnt[1]-=m;
        cnt[2]-=m;
        ans+=m;
        cnt[3]+=m;

        if(cnt[1]>0) {
                cnt[3]+=cnt[1]/3;
                ans+=(cnt[1]/3)*2;
                cnt[1]%=3;
        }
        if(cnt[2]>0) {
                cnt[3]+=(cnt[2]/3)*2;
                ans+=(cnt[2]/3)*2;
                cnt[2]%=3;
        }

        if(cnt[1]>0) {
                if(cnt[1]==1) {
                        if(cnt[3]>0) {
                                ans+=1;
                        } else {
                                if(cnt[4]>=2) {
                                        ans+=2;
                                } else {
                                        cout<<-1<<'\n';
                                        return 0;
                                }
                        }
                } else {
                        if(cnt[4]>0) {
                                ans+=2;
                        } else {
                                if(cnt[3]>=2) {
                                        ans+=2;
                                } else {
                                        cout<<-1<<'\n';
                                        return 0;
                                }
                        }
                }
        } else if(cnt[2]>0) {
                if(cnt[2]==1) {
                        if(cnt[4]>0) {
                                ans+=1;
                        } else {
                                if(cnt[3]>=2) {
                                        ans+=2;
                                } else {
                                        cout<<-1<<'\n';
                                        return 0;
                                }
                        }
                } else {
                        ans+=2;
                }
        }

        cout<<ans<<'\n';
}