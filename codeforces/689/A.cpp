// LUOGU_RID: 160126697
#include<bits/stdc++.h>
#define int long long 
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
bool lef=true,rit=true,up=true,dow=true;//定上下左右的布尔，初始化为真
signed main() {
    int n;//n表示长度
    string m;//m表示号码
    cin>>n>>m;//输入
    for(int l=0;l<n;l++){//循环
        if(m[l]=='0'){lef=false;rit=false;dow=false;}//如果这个号码有0，那么下左右就别想了（可以观察一下第一张图）
        if(m[l]=='9'||m[l]=='3'||m[l]=='6') rit=false;//如果这个号码有9，3，6，右就别想了（见图
        if(m[l]=='4'||m[l]=='7'||m[l]=='1')lef=false;//如果这个号码有4，7，1，左就别想了（见图）
        if(m[l]=='1'||m[l]=='2'||m[l]=='3')up=false;//如果这个号码有1，2，3，上就别想了（见图
        if(m[l]=='9'||m[l]=='7') dow=false;//如果这个号码有9，7，下就别想了（见图）
    }
    if(!lef&&!dow&&!rit&&!up){ //最后判断哪个是false
        cout<<"YES"<<endl;//输出
    } 
    else cout<<"NO"<<endl;//输出
    return 0;
}