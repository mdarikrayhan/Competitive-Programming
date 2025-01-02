#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug1 cout<<"test1"<<endl;
#define debug2 cout<<"test2"<<endl;
ll read(){
    ll x = 0;char ch = getchar();int f = 1;
    while(ch<'0'||ch>'9'){if(ch=='-') f = -1;ch = getchar();}
    while(ch>='0' && ch<='9'){x = x*10+ch-'0';ch = getchar();}
    return x*f;
}
//std::chrono::system_clock::time_point nowtime(){return std::chrono::high_resolution_clock::now();}
//void printtime(std::chrono::system_clock::time_point a , std::chrono::system_clock::time_point b){
    //auto c = std::chrono::duration_cast<std::chrono::nanoseconds>(b - a);printf(\"%.3f\n\" , c.count() * 1e-9);return;
//}
const int N = 40000007;

int temp[2000007];
int ls[N] , rs[N] , sum[N] , tot = 0 , rt[2000007];
int n = read();
void update(int& u,int pre ,int l,int r ,int x){
    if(pre == 0) return;
    u = ++ tot;
    sum[u] = sum[pre] + 1 , ls[u] = ls[pre] , rs[u] = rs[pre]; 

    int mid = (l + r) >> 1;
    if(x <= mid) update(ls[u] , ls[pre] , l , mid , x);
    else update(rs[u] , rs[pre] , mid + 1 , r , x);
    return;
}
int query(int u,int l,int r,int x,int y){
    if(r < x || y < l) return 0;
    if(u == 0) return 0;
    if(x <= l && r <= y) return sum[u];
    int mid = (l + r) >> 1;
    return query(ls[u] , l , mid , x , y) + query(rs[u] , mid + 1 , r , x , y);
}

void build(int& u,int l,int r){
    u = ++ tot;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(ls[u] , l , mid) , build(rs[u] , mid + 1 , r);
    return;
}



int f(int z , int x){
    return ((z - 1 + x) % n) + 1;
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);

    for(int i = 1;i <= n;i ++){
        temp[read()] = i;
    }

    build(rt[0] , 1 , n);

    for(int i = 1;i <= n;i ++){
        // num[i] = temp[read()];
        update(rt[i] , rt[i - 1] , 1 , n , temp[read()]);
    }



    int x = 0;

    int m = read();
    for(int i = 1;i <= m;i ++){

        int a = read() , b = read() , c = read() , d = read();

        a = f(a , x) , b = f(b , x) , c = f(c , x) , d = f(d , x);

        int l1 = min(a , b) , r1 = max(a , b) , l2 = min(c , d) , r2 = max(c , d);

        int ans1 = query(rt[r2] , 1 , n , l1 , r1);
        int ans2 = query(rt[l2 - 1] , 1 , n , l1 , r1);

        printf("%d\n" , ans1 - ans2);

        x = ans1 - ans2 + 1;
    }



    return 0;
}