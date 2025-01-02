#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
int main(){
	int n;
	cin>>n;
	int qs;
	cin>>qs;
	deque<int>v;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	vector<long long>q;
	for (int i = 0; i < qs; ++i)
	{
		long long x;
		cin>>x;
		q.push_back(x);
	}
	vector<pair<int,int> >initial;
	int a = 0;
	int b = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		a = v[0];
		v.pop_front();
		b = v[0];
		v.pop_front();
		initial.push_back(make_pair(a,b));
		v.push_back(min(a,b));
		v.push_front(max(a,b));
	}
	int i = 0;
	while(i < q.size()){
		if (q[i] < n)
		{
			a = initial[q[i] - 1].first;
			b = initial[q[i] - 1].second;
		}else{
			int j = (q[i] - n)%(n - 1) + 1;
			a = v[0];
			b = v[j];
		}
		cout<<a<<" "<<b<<endl;
		i++;
	}
	return 0;
}