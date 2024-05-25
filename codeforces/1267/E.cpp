#include <bits/stdc++.h>
using namespace std;
 
int n,m;
 
int main(){
    scanf("%d%d",&n,&m);
    vector<vector<pair<int,int>>> grid(n-1,vector<pair<int,int>>(m));
    vector<int> opp(m);
    for(int j=0;j<m;j++)
    {
        for(int i=0;i<n-1;i++)
        {
            scanf("%d",&grid[i][j].first);
            grid[i][j].second = j;
        }
        scanf("%d",&opp[j]);
    }
    
    for(int i=0;i<n-1;i++)
        for(int j=0;j<m;j++)
            grid[i][j].first -= opp[j];
    int end_j=m+1,idx;
    
    for(int i=0;i<n-1;i++)
    {   
        sort(grid[i].begin(),grid[i].end());
        int j = m-1;
        for(;j>=0;j--)
        {
            if(j!=m-1)grid[i][j].first += grid[i][j+1].first;
            if(grid[i][j].first < 0)break;
        }
        if(end_j > j)
        {
            end_j = j;
            idx = i;
        }
    }
    
    printf("%d\n",end_j+1);
    for(int j=0;j<=end_j;j++)printf("%d ",grid[idx][j].second+1);
    printf("\n");
    return 0;
}