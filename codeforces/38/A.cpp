#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> d(n); 
    for (int i = 1; i < n; ++i) {
        std::cin >> d[i];
    }

    int a, b;
    std::cin >> a >> b;

    int total_years = 0;
    for (int i = a; i < b; ++i) {
        total_years += d[i];
    }

    std::cout << total_years << std::endl;
    return 0;
}

 				  		  	  	  	     	  	 	