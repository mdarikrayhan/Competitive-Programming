#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
int aij[110][110];
int bij[110][110];
int cij[110][110];
vector<pair<int,int> > XD;
int main(){
    int n,m,k,i,j,q,w;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;i++){
        scanf("%*s");
        for(j=0;j<m;j++)scanf("%d%d%d",&aij[i][j],&bij[i][j],&cij[i][j]);
    }
    int ans=0;
    for(i=0;i<n;i++)for(j=0;j<n;j++){
        XD.clear();
        for(q=0;q<m;q++)if(aij[i][q]<bij[j][q]){
            XD.push_back(make_pair(-(bij[j][q]-aij[i][q]),cij[i][q]));
        }
        sort(XD.begin(),XD.end());
        int a=0,kk=k;
        for(q=0;q<XD.size()&&kk;q++){
            if(XD[q].second<kk){
                a+=-XD[q].first*XD[q].second;
                kk-=XD[q].second;
            }else{
                a+=-XD[q].first*kk;
                kk=0;
            }
        }
        if(ans<a)ans=a;
    }
    printf("%d\n",ans);
}

