#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll x,y,z,l,flag=0,tmp=0,a,b;
    vector<ll>v;
    cin>>x>>y>>z>>l;
    if(x==1&&y==0&&z==0&&l==0){
        cout<<"YES"<<'\n';
        cout<<0<<'\n';
    }
    else if(x==0&&y==1&&z==0&&l==0){
        cout<<"YES"<<'\n';
        cout<<1<<'\n';
    }
    else if(x==0&&y==0&&z==1&&l==0){
        cout<<"YES"<<'\n';
        cout<<2<<'\n';
    }
    else if(x==0&&y==0&&z==0&&l==1){
        cout<<"YES"<<'\n';
        cout<<3<<'\n';
    }
    else if(x>0&&y>0&&z==0&&l==0){
        if(abs(x-y)<=1){
            cout<<"YES"<<'\n';
            if(x>y){
                for(ll i=1;i<=y;i++){
                    cout<<0<<" "<<1<<' ';
                }
                if(x-y==1)cout<<0<<'\n';
            }
            else {
                for(ll i=1;i<=x;i++){
                    cout<<1<<" "<<0<<' ';
                }
                if(y-x==1)cout<<1<<'\n';
            }
        }
        else cout<<"NO"<<'\n';
    }
    else if(x==0&&y>0&&z>0&&l==0){
        if(abs(z-y)<=1){
            cout<<"YES"<<'\n';
            if(z>y){
                for(ll i=1;i<=y;i++){
                    cout<<2<<" "<<1<<' ';
                }
                if(z-y==1)cout<<2<<'\n';
            }
            else {
                for(ll i=1;i<=z;i++){
                    cout<<1<<" "<<2<<' ';
                }
                if(y-z==1) cout<<1<<'\n';
            }
        }
        else cout<<"NO"<<'\n';
    }
    else if(x==0&&y==0&&z>0&&l>0){
        if(abs(l-z)<=1){
            cout<<"YES"<<'\n';
            if(z>l){
                for(ll i=1;i<=l;i++){
                    cout<<2<<" "<<3<<' ';
                }
                if(z-l==1)cout<<2<<'\n';
            }
            else {
                for(ll i=1;i<=z;i++){
                    cout<<3<<" "<<2<<' ';
                }
                if(l-z==1)cout<<3<<'\n';
            }
        }
        else cout<<"NO"<<'\n';
    }
    else if(x>0&&y>0&&z>0&&l==0&&y>=x){
        a=y-x;
        if(y>=x&&z>=a&&z-a<=1){// 0 1 2 1 2 1 2 1 2 1 2
            cout<<"YES"<<'\n';
            for(ll i=1;i<=x;i++)cout<<0<<" "<<1<<" ";
            y-=x;for(ll i=1;i<=y;i++)cout<<2<<" "<<1<<" ";
            if(z-y==1)cout<<2<<'\n';
        }
        else if(y>x&&z<=a&&a-z<=1){
            cout<<"YES"<<'\n';
            for(ll i=1;i<=x;i++)cout<<1<<" "<<0<<" ";
            cout<<1<<' ';
            y-=x;y--;
            for(ll i=1;i<=y;i++)cout<<2<<" "<<1<<" ";
            if(z-y==1)cout<<2<<'\n';
        }
        else cout<<"NO"<<'\n';
    }
    else if(x==0&&y>0&&z>0&&l>0&&z>=y){
        a=z-y;   // 1 5 6
        if(z>=y&&l>=a&&l-a<=1){// 0 1 2 1 2 1 2 1 2 1 2
            cout<<"YES"<<'\n';
            for(ll i=1;i<=y;i++)cout<<1<<" "<<2<<" ";
            z-=y;for(ll i=1;i<=z;i++)cout<<3<<" "<<2<<" ";
            if(l-z==1)cout<<3<<'\n';
        }
        else if(z>y&&l<=a&&a-l<=1){
            cout<<"YES"<<'\n';
            for(ll i=1;i<=y;i++)cout<<2<<" "<<1<<" ";
            cout<<2<<' ';
            z-=y;z--;
            for(ll i=1;i<=z;i++)cout<<3<<" "<<2<<" ";
            if(l-z==1)cout<<2<<'\n';
        }
        else cout<<"NO"<<'\n';
    }
    else if(x>0&y>0&&z>0&&l>0){
        if(x>y)tmp=1;
        else {
            a=y-x;
            if(x==y||(z-a)>=l&&(z-a)-l<=1){  // 1 1
                for(ll i=1;i<=x;i++){
                   v.push_back(0);v.push_back(1);
                }
                y-=x;
                if(z>=y){   // 1 2 1 2 1 2 3 2 3 2 3
                    z-=y;
                    for(ll i=1;i<=y;i++){
                        v.push_back(2);
                        v.push_back(1);
                    }
                }
                else tmp=1;
            }
            else {
                for(ll i=1;i<=min(x,y);i++){
                    v.push_back(1);
                    v.push_back(0);
                }
                v.push_back(1);
                y-=x;// 1 0 1 2 1
                y--;
                if(z>=y){   // 1 2 1 2 1 2 3 2 3 2 3
                    z-=y;
                    for(ll i=1;i<=y;i++){
                        v.push_back(2);
                        v.push_back(1);
                    }
                }
                else tmp=1;
            }
            if(z>=l&&z-l<=1){
                for(ll i=1;i<=l;i++){
                    v.push_back(2);
                    v.push_back(3);
                }
                if(z-l==1)v.push_back(2);
            }
            else tmp=1;
        }
        if(!tmp){
            cout<<"YES"<<'\n';
            for(auto it:v)cout<<it<<" ";
        }
        else cout<<"NO"<<'\n';
    }
    else cout<<"NO"<<'\n';
}
		 	  				   			   	   		 	 			