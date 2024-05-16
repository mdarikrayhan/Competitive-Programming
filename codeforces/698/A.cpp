#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long llint;
#define take(a)  long long int a; cin>>a;
#define f(I,S,E) for(llint I=S;I<E;I++)
#define vi vector<int>
//1e9+7 this is a prime
//int binExpIter(int a,int b){
   // int ans = 1;
   // while(b){
   //     if(b&1)
   //     {
   //         ans  = (ans*1LL*a)%M;
   //     }
   //     a=(a*1LL*a)%M;
   //     b>>=1;
  //  }
  //  return ans;}
//sgt snippet for segment trees
// to calculate the number of times any number appear when given q ranges than make v[r]=1 and v[l-1] as -1 and than do prefix sum at last
// __builtin_clz(x): # 0 at the beg numb, __builtin_ctz(x): # 0 at the beg numb
// __builtin_popcount(x): the number of ones in the number
//Felwick allgo for range queries O(log n) sum and update both
//for doing range update (make a difference sum) you just have to add at l and subtract at r+1 and than prefix sum will give the point query
//for multiplying larger numbers of range 10^18 and M is of the range 10^18
//(a^b)%M = (a%M)^b
//(a^b)%M = (a^(b% phi(M))) %M
//(a/b)%M = ((a%M)*((b^(M-2))%M)%M   here b and M must be coprime
// subtract time pe +M krdia kr
//pow ke saath llint laga lena chahiye
//int binMultiply(llint a,llint b)
//{int ans = 0;
 //   while(b>0){
 //   if(b&1){
 //       ans = (ans + a)%M;
 //   }
 //   a = (a+a)%M;
 //   b>>=1;
 //   }
 //   return ans;
//}
//llint gcd(llint a, llint b){
//    return b == 0 ? a : gcd(b, a % b);
//    }
// -5 % 3 is -2 not 2 be cautios
//endl see in all cases
int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);
int n;
cin>>n;
vector<int> day(n);
for(int i=0;i<n;i++)
{
    cin>>day[i];
}
vector<vector<int> > activity(n , vector<int> (3 , 1e9)); //0 play //1 cont // 2rest
activity[0][2] = 1;
if(day[0]==1 || day[0]==3)
{
    activity[0][1] = 0;
}
if(day[0]==2 || day[0]==3)
{
    activity[0][0] = 0;
}
for(int i=1;i<n;i++)
{
    if(day[i] == 0)
    {
        activity[i][2] = 1 + min(activity[i-1][0] , min(activity[i-1][1] , activity[i-1][2]));
    }
    else if(day[i] == 1)
    {
        activity[i][2] = 1 + min(activity[i-1][0] , min(activity[i-1][1] , activity[i-1][2]));
        activity[i][1] = min(activity[i-1][0] , activity[i-1][2]);
    }
    else if(day[i]==2)
    {
        activity[i][2] = 1 + min(activity[i-1][0] , min(activity[i-1][1] , activity[i-1][2]));
        activity[i][0] = min(activity[i-1][1] , activity[i-1][2]);
    }
    else
    {
        activity[i][2] = 1 + min(activity[i-1][0] , min(activity[i-1][1] , activity[i-1][2]));
        activity[i][1] = min(activity[i-1][0] , activity[i-1][2]);
        activity[i][0] = min(activity[i-1][1] , activity[i-1][2]);
    }
}
cout<< min (min(activity[n-1][0] , activity[n-1][1]) , activity[n-1][2]);
return 0;
}
