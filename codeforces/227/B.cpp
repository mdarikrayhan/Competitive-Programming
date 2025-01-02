#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n;
    cin>>n;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
    	int x;
    	cin>>x;
    	m[x]=i+1;
    }
    int q;
    cin>>q;
    int k=q;
    long long int vasya=0,petya=0;
    while(q--){
    	int a;
    	cin>>a;
    	vasya=vasya+m[a];
    	petya=petya+(n-m[a])+1;
    }
    cout<<vasya<<" "<<petya<<endl;

}
