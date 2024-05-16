#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<long long int>ans;
    long long int testcases;
    cin>>testcases;
    for(long long int j=0;j<testcases;j++){
    long long int n,m,k;
    cin>>n>>m>>k;
    vector<long long int>a;
    vector<long long int>b;
    long long int mina=INT64_MAX,minb=INT64_MAX,maxa=0,maxb=0,sum=0;
    for(long long int i=0;i<n;i++){
        long long int ele;
        cin>>ele;
        a.push_back(ele);
        sum+=ele;
        maxa=max(maxa,ele);
        mina=min(mina,ele);
    }
    for(long long int i=0;i<m;i++){
        long long int ele;
        cin>>ele;
        b.push_back(ele);
        maxb=max(maxb,ele);
        minb=min(minb,ele);
    }
    if(mina>maxb){
        if(k%2==1){
            ans.push_back(sum);
        }else{
            sum=sum-maxa+minb;
            ans.push_back(sum);
        }
    }else{
        if(k%2==1){
            sum=sum-mina+maxb;
        }else{
            if(maxa>maxb){
                sum=sum+maxb-maxa;
                if(mina<minb){

                }else{
                    sum=sum+minb-mina;
                }
            }else{
                sum=sum-mina+min(mina,minb);
            }
        }
        ans.push_back(sum);
    }
    }
    for(long long int i=0;i<testcases;i++){
        cout<<ans[i]<<endl;
    }
}