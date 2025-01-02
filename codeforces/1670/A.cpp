#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void F(){
    int n;
    std::cin >> n;
    int k = 0;
    int a[n];
    for (int i = 0; i < n; i++){
        std::cin >> a[i];
        if (a[i] < 0){
            k++;
        }
        a[i] = abs(a[i]);
    }

    for(int i = 0; i < n; i++){
        if (k == 0){
            break;
        }
        k--;
        a[i] = -a[i];
    }

    int flag = 0;
    for (int i = 1; i < n; i++){
        if(a[i] < a[i - 1]){
            flag = 1;
            break;
        }
    }

    if (flag == 1){
        std::cout << "NO" << std::endl;
    } else if(flag == 0){
        std::cout << "YES" << std::endl;
    }
}

int main(){
    int t;
    std::cin >> t;
    while(t--){
    F();
    }
}
