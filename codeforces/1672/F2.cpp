#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
#ifdef  ONLINE_JUDGE
	#define eprintf(...) 42
#else
        #define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
#endif
clock_t startTime;
double getCurrentTime() 
{
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
int solve()
{
	int n;
	cin>>n;
	int a[n], b[n], occu[n+1] = { 0 }, incmng[n+1] = { 0 }, visited[n+1] = { 0 };
	visited[0] = 1;
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
		occu[a[i]]++;
	}
	int mx = max_element(occu, occu+n+1) - occu;
	visited[mx] = 1;

	vector<int> g[n+1];
	for(int i=0; i<n; i++)
	{
		cin>>b[i];
		if(a[i]!=mx && b[i]!=mx)
		{
			g[a[i]].push_back(b[i]);
			incmng[b[i]]++;
			//cout<<"edge?"<<endl;
		}
	}
	queue<int> q;
	for(int i=1; i<=n; i++)
	{
		if(!incmng[i] && i!=mx)
		{
			//cout<<"cool"<<endl;
			q.push(i);	
		}	
	}
	while(!q.empty())
	{
		int ele = q.front();
		q.pop(); visited[ele] = 1;
		//cout<<"visited "<<ele<<endl;
		for(auto stuff : g[ele])
		{
			incmng[stuff]--;
			if(!incmng[stuff])
			{
				q.push(stuff);
			}
		}
	}
	cout<<(*min_element(visited, visited+n+1)>0 ? "AC" : "WA")<<endl;	
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	startTime = clock();
	while(t--)
	{
		startTime = clock();
		solve();
	}
	eprintf("time = %.5lf\n", getCurrentTime());
	return 0;
}