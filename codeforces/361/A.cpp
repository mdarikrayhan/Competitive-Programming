#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);/*cin.tie(0);*/cout.tie(0);
//freopen ("input.txt","r",stdin);
//freopen ("output.txt","w",stdout);
//const int N=10e8+5;
//bool mark[N];
bool com(const pair<int,int>&p1, const pair<int,int>&p2)
{
    if(p1.first==p2.first)
    {
        return p1.second<p2.second;
    }
    return p1.first>p2.first;
}
int checkprime(int x)
{
    int i,j;

    vector<int>v(100000,0);
    v[1]=1;
    for(i=2;i*i<=100000;i++)
    {
        if(v[i]==0)
        {
            for(j=i*i;j<=100000;j+=i)
            {
                if(v[j]==0)v[j]=1;
            }
        }
    }
    return v[x];
}
int main(){
   optimize();
   int n,k,i,j;
   cin>>n>>k;
   int a[n][n];
   for(i=0;i<n;i++)
   {
       for(j=0;j<n;j++)
       {
           if(i==j){
           a[i][j]=k;
           }
           else a[i][j]=0;
       }
   }
   for(i=0;i<n;i++)
   {
       for(j=0;j<n;j++)
       {

          cout<<a[i][j]<<" ";
       }
       cout<<endl;
   }

}
