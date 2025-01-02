#include<iostream>
#include<deque>
using namespace std;
int main(){
	int t,n,a;	cin>>t;
	deque<int>d;
	while(t--){
		d.clear();
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>a;
			a>d[0]?d.push_back(a):d.push_front(a);
		}
		for(int j=0;j<n;j++)	cout<<d[j]<<" ";
		cout<<endl;
	}
} 