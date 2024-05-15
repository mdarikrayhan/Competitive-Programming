#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int factorial (int n,int k)
{
  if(n==0||n==1)
  return k;
  return factorial(n-1,k*n);
}

int sum (int n)
{
  if(n==0)
  return 0;
  return n+sum(n-1);
}

bool palindrome(string s,int l,int r)
{
  if(r-l<1)
  return true;
  if(s[l]!=s[r])
  return false;
  return palindrome(s,l+1,r-1);
}

int sum_digit(int n)
{
  if(n==0)
  return 0;
  return n%10 + sum_digit(n/10);
}

int gcd(int a,int b)
{
  if(b==0)
  return a;
  return gcd(b,a%b);
}

int binary_search(int a[], int l, int r, int x)
{
  while(l<=r)
  {
    int m=(l+r-1)/2;
    if(a[m]==x)
    return m;
    else if(a[m]<x)
    l=m+1;
    else
    r=m-1;
  }
  return -1;
}

bool is_prime(int n)
{
  if (n <= 1)
        return false;

  for(int i=2;i<=sqrt(n);i++)
  {
    if(n%i==0)
    return false;
  }
  return true;
}

int lower_bound(int a[], int n, int x)
{
    int i = lower_bound(a, a + n, x) - a;
    return i;
}

int upper_bound(int a[], int n, int x)
{
    int i = upper_bound(a, a + n, x) - a;
    return i;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   int t;
   cin>>t;
  //  t=1;
   while(t--)
   {
     int n;
     cin>>n;
     vector<int>v;
     if(n%2==1)
     {
        n=n-3;
        v.push_back(7);
     }
     for(int i=0;i<n/2;i++)
     v.push_back(1);
     int ans=0;
     for(auto e:v)
     {
       cout<<e;
     }
     cout<<endl;
   }
}
