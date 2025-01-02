#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll val(vector<ll>&arr,int start){
    int ind;
    int n=arr.size();
    ll result=0;
    if(start==1){
        ind=0;
        ll choto=arr[0];
        for(int i=1;i<n-1;i++){
            if(arr[i]<=choto){
                result+=1ll*(i-ind)*choto;
                 // cout<<"haha "<<start<<" "<<result<<endl;
                choto=arr[i];
                ind=i;
            }
        }
        result+=1ll*(n-1-ind)*max(choto,arr[n-1]);
       // cout<<"haha "<<start<<" "<<result<<endl;
        return result;
    }else{
        ll choto=arr[n-1];
        ind=n-1;
        for(int i=n-2;i>=1;i--){
            if(arr[i]<=choto){
                result+=1ll*(ind-i)*choto;
                 // cout<<"haha "<<start<<" "<<result<<endl;
                choto=arr[i];
                ind=i;
            }
        }
       // cout<<"haha "<<start<<" "<<result<<endl;
        result+=1ll*ind*(max(choto,arr[0]));
       // cout<<"haha "<<start<<" "<<result<<endl;
        return result;

    }
}
int main() {
     int t;
     cin>>t;
     while(t--){

	   int n;
	   cin>>n;
	   vector<ll>arr(n+1);
	   ll sum=0;
	   for(int i=0;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
	   }
	   if(n==1 && arr[0]==1){
        cout<<"YES"<<endl;
        continue;
	   }
	   int flag=0;
	   vector<ll>fibo(60);
	   ll fst=0,snd=1;
	   fibo[0]=1;
	   int hobe;
	   ll sum1=1;
	   for(int i=1;i<=60;i++){
         ll tot=fst+snd;
         fst=snd;
         snd=tot;
         fibo[i]=tot;
         sum1+=tot;
        // cout<<sum1<<" "<<sum<<endl;
        if(sum1>sum){
                flag=1;
                break;
        }
        if(sum1==sum){
                 hobe=i;
                break;
        }

	}
	//cout<<flag<<" "<<hobe<<endl;
	if(flag){
        cout<<"NO"<<endl;
	}else{
	   vector<priority_queue<ll>>st(60+1);
	   	    for(int i=0;i<n;i++)st[hobe].push(arr[i]);
	   while(hobe>=0){
          ll lagbe=fibo[hobe];
            if(st[hobe].size()==0){
                    flag=1;
                    break;
            }
          ll val=st[hobe].top();
          st[hobe].pop();
         // cout<<lagbe<<" "<<val<<endl;
          if(val<lagbe){
            flag=1;
            break;
          }else{
             ll rem=val-lagbe;
             if(hobe-2>=0 && rem>0)st[hobe-2].push(rem);
          }
          while(st[hobe].size()>0 && hobe-1>=0){
            st[hobe-1].push(st[hobe].top());
            st[hobe].pop();
          }
          --hobe;
	   }
	   if(flag){
        cout<<"NO"<<endl;
	   }else cout<<"YES"<<endl;
	}
     }

	return 0;
}
