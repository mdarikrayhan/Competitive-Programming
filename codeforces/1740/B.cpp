#include<bits/stdc++.h>
using namespace std;
pair<int,int>p[200100];
int main() {
    int n,x,y,t;
	cin >> t;
	while (t--) {
		cin >> n;
		long long sum=0;
		for(int i=0;i<n;i++){
                cin >> x >> y;
                if(y<x){
                    p[i].first=x;
                    p[i].second=y;
                }
                else{
                    p[i].first=y;
                    p[i].second=x;
                }
                sum+=p[i].second;
        }
		sum*=2;
		sort(p,p+n);
        reverse(p,p+n);
        sum+=p[0].first;
		for(int i=0;i<n-1;i++)sum+=p[i].first-p[i+1].first;
		cout <<sum+p[n-1].first << endl;
	}
}
