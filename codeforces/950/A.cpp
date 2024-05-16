using namespace std;
#include <bits/stdc++.h>


int main() {
    int left,right, amb;
    cin>>left>>right>>amb;
    int tot=0;
    
   
    if(right>left)
        swap(left,right);


    while(right!=left && amb > 0){
     right++;
     amb--;
    }
    if(right == left){
    amb=amb/2;
    tot=(right+amb)+(left+amb);
    }
    
    else if(amb==0){
     tot=(right*2);
    }
    
    cout<<tot;
    return 0;
}