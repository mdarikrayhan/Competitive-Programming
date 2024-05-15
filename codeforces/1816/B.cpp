#include<bits/stdc++.h>
#define ll long long int
#define us unsigned

using namespace std;

ll abs(ll a,ll b)
{
	if(a>b)
	return a-b;
	else
	return b-a;
}

ll gcd(ll a,ll b)
{
	if(b==0)
	return a;

	if(a%b == 0)
	return b;

	return gcd(b,a%b);
}

// kadane's algo
ll kadaneAlgo(vector<int> &v)
{
	int size = v.size();
	ll sum = 0;
	ll ans = 0;
	for(int i=0;i<size;i++)
	{
		sum = sum+v[i];
		if(sum < 0)
		{
			sum = 0;
		}
		ans = max(ans,sum);
	}
	return ans;
}
int binarySearch(vector<ll> &v,ll key) // lower bound // index return
{
	// if(key<v[0])
	// return -1;
	
	int start = 0,end = v.size()-1;
	int mid;
	int ans=0;
	while(start<=end)
	{
		mid = ((end-start)/2)+start;

		if(v[mid]==key)
		{
			// ans = mid;
			return mid;
		}
		else if(v[mid]<key)
		{
			// ans = mid;
			start = mid+1;
		}
		else if(v[mid]>key)
		{
			end = mid-1;
		}
	}
	return -1;
	// return ans;
}
vector<ll> factor(ll n)
{
	ll root = sqrt(n);
	vector<ll> ans;
	ans.push_back(1);
	for(int i=2;i<=root;i++)
	{
		if(n%i==0)
		{
			ans.push_back(i);
		}
	}
	int size = ans.size();
	for(int i=size-1;i>=0;i--)
	{
		ll div = n/ans[i];
		if(div != ans[i])
		{
			ans.push_back(div);
		}
	}
	return ans;
}
void PrefixSum(vector<ll> &v)
{
	int size = v.size();
	for(int i=1;i<size;i++)
	{
		v[i] = v[i]+v[i-1];
	}
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second; // If first values are equal, sort by second value
    }
    return a.first < b.first; // Sort by first value
}
void solve(int t)
{
	int n;
	cin>>n;

	int max =2*n;

	vector<int> arr(n,0);
	int val = max;
	for(int i=0;i<n;i=i+2)
	{
		arr[i] = val;
		val = val-2;
	}
	val = 2;
	for(int i=1;i<n;i=i+2)
	{
		arr[i] = val;
		val = val+2;
	}

	for(auto i:arr)
	cout<<i<<" ";

	cout<<endl;

	val = 1;
	for(int i=0;i<n;i=i+2)
	{
		arr[i] = val;
		val = val+2;
	}
	val = max-1;
	for(int i=n-1;i>=0;i=i-2)
	{
		arr[i] = val;
		val = val-2;
	}

	for(auto i:arr)
	cout<<i<<" ";

	cout<<endl;
	
	return;
}
int main()
{
	int i;
	cin>>i;
    int j = 1;
	while(j<=i)
	{
		solve(j);
		j++;
	}
	// solve();

	return 0;
}
