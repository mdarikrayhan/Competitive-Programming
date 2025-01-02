using namespace std;
#include <bits/stdc++.h> 
#define int long long
#define endl '\n'
#define f(i,k,n) for(int i=k;i<n;i++)
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define pr(k) cout<<k<<endl;
#define all(x) x.begin(), x.end()
void fn(){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
int32_t main(){
    fn();
    vector<int>two,three,total;
    for(int i=1;i<31;i++)two.push_back(1<<i);
    for(int i=1;i<21;i++)three.push_back(pow(3,i));
    total.push_back(1);
    for(int i:two)total.push_back(i);
    for(int i:three)total.push_back(i);
    for(int i:two)for(int j:three)if(i*j>0&&i*j<2000000000)total.push_back(i*j);
    int l,r;cin>>l>>r;
    sort(all(total));
    int srt=0,end=total.size()-1;
    for(int i=0;i<327;i++){
        if(total[i]>=l){
            srt=i;
            break;
        }
    }
    for(int i=0;i<327;i++){
        if(total[i]<=r)end=i;
    }
    cout<<end-srt+1<<endl; 
}
