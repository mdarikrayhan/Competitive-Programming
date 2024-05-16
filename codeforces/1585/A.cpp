#include <vector>
#include <iostream>

void F(){
    int t = 0;
    std::cin >> t;
    std::vector<int> vec;
    while (t--) {
        int n = 0, mark = 0, sum = 1, day = 0, r = 0;
        std::cin >> n;
        for (int i = 0; i < n; i++) {
            std::cin >> day;
                if (day == 1) {
                    if ((i != 0) && mark == 1 ){
                        sum += 5;
                        mark = 1;
                    }
                    else {
                        sum += 1;
                        mark = 1;
                    }
                }
                else if (mark == 1) {
                    mark = 0;
                }
                else if(i == 0){
                    mark = 0;
                }
                else {
                    r = -1;
                    sum = -1;
                }
        }
    if (r == 0) {
      vec.push_back(sum);
    }
    else {
      vec.push_back(-1);
    }
  }
  for (int i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << std::endl;
  }
}

int main() {
    F();
}
