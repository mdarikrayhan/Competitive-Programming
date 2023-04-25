#include<iostream>
#include<queue>
#include<map>
#include<string>
using namespace std;
map<int,char>mp;
int main()
{
mp[0]='w';
mp[1]='i';
mp[2]='n';
int t,m,i,j,p,temp1,temp2,k;
int l[3];
string temp;
cin>>t;
while(t--)
{
vector<vector<int>>ans;
queue<int>q[3][3];
cin>>m;
for(i=0;i<m;i++)
{
cin>>temp;
l[0]=l[1]=l[2]=0;
for(auto x:temp)
{
if(x=='w')l[0]++;
else if(x=='i')l[1]++;
else l[2]++;
}
for(j=0;j<3;j++)if(l[j]>1)for(p=0;p<3;p++)if(!l[p])q[j][p].push(i);
}
for(p=0;p<3;p++)for(i=0;i<3;i++)for(j=i+1;j<3;j++)
{
while(!q[i][j].empty()&&!q[j][i].empty())
{
temp1=q[i][j].front();q[i][j].pop();temp2=q[j][i].front();q[j][i].pop();
ans.push_back({temp1,i,temp2,j});
}
for(k=0;k<3;k++)while(!q[i][j].empty()&&!q[j][k].empty())
{
temp1=q[i][j].front();q[i][j].pop();temp2=q[j][k].front();q[j][k].pop();
ans.push_back({temp1,i,temp2,j});
q[i][k].push(temp2);
}
}
cout<<ans.size()<<endl;
for(auto x:ans)cout<<x[0]+1<<" "<<mp[x[1]]<<" "<<x[2]+1<<" "<<mp[x[3]]<<endl;
}
}