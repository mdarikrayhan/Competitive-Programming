#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()

int query(int i, int j){
    printf("? %d %d\n", i, j);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    return x;
}

int main(){
    int arr[] = {4, 8, 15, 16, 23, 42};
    int ans[6] = {0};
    
    int mul, mul1 = query(1, 2);
    int mul2 = query(1, 3);
    int mul3 = query(1, 4);
    int mul4 = query(1, 5);
    
    for (int i = 6 - 1; i >= 0; i--)
    {
        if(mul2%arr[i] == 0 && mul1%arr[i] == 0 && mul3%arr[i] == 0 && mul4%arr[i] == 0){
            ans[0] = arr[i];
            ans[1] = mul1/arr[i];
            ans[2] = mul2/arr[i];
            ans[3] = mul3/arr[i];
            ans[4] = mul4/arr[i];
            break;
        }
    }
    
    
    for (int i = 0; i < 6; i++)
    {
        bool c = false;
        for (int j = 0; j < 6; j++)
        {
            if(arr[i] == ans[j]) c = true;
        }
        if(!c){
            ans[5] = arr[i];
        }
    }
    
    printf("!");
    for (int i = 0; i < 6; i++)
    {
        printf(" %d", ans[i]);
    }
    printf("\n");
    
    return 0;
}