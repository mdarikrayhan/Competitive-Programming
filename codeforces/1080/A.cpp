#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;

    cin >> n >> k;

    // 2n red , 5n green 8n blue
    // k sheets in each notebook

    int red , green ,blue;

    if((2*n)%k!=0){
        red = (2*n/k)+1;
    }
    else if((2*n)%k==0){
        red = (2*n/k);
    }

    if((5*n)%k!=0){
        green = (5*n/k)+1;
    }
    else if((5*n)%k==0){
        green = (5*n/k);
    }

    if((8*n)%k!=0){
        blue = (8*n/k)+1;
    }
    else if((8*n)%k==0){
        blue = (8*n/k);
    }

    cout << red+blue+green << endl;

    return 0;

}