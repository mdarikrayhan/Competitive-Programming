#include<iostream>
#include<vector>

using namespace std ;

bool check(int y, int nums[]){

    int a = y;

    while(a > 0){
        int n = a % 10;
        a = a / 10;

        nums[n]++;
        if(nums[n] > 1) return false;
    }

    return true;
}

int main(){
    int y;
    cin>>y;
    int a = 1;

    while(true){
        y++;
        int nums[10] = {0};
        if(check(y, nums)) break;
    }

    cout<<y<<endl;
    return 0;

}