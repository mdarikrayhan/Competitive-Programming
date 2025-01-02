#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <unordered_map>
#include <cstring>
#include<map>
#include <cmath>
#include <queue>
using namespace std;
//n<=5时，只有n==4行
//n>=6时，输出
//2*3=6
//6*4=24
//1+5=6,6-6=0
//0*(k)=0,k>6
//24+0=0;
inline void solve(){
    int n;cin>>n;
    if(n<=5){
        if(n==4){
            puts("YES");
            printf("1 * 2 = 2\n");
            printf("2 * 3 = 6\n");
            printf("6 * 4 = 24\n");
        }
        else if(n==5){puts("YES");
        puts("5 - 3 = 2");
        puts("2 * 4 = 8");
        puts("1 + 2 = 3");
        puts("8 * 3 = 24");
        }
        else
        puts("NO");
        return;
    }
    puts("YES");
    printf("2 * 3 = 6\n");
    printf("6 * 4 = 24\n");
    printf("1 + 5 = 6\n");
    printf("6 - 6 = 0\n");
    for(int i=7;i<=n;i++){
        printf("0 * %d = 0\n",i);
    }
    printf("0 + 24 = 24\n");
}
int main(){
    solve();
    return 0;
}