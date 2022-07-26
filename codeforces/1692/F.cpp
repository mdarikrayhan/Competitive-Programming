    #include <iostream>
    #define I std::cin>>
    int t,l,n,j,c[10];
     
    int f(int i, int k, int s) {
    	return k?k&&i<10&&(c[i]>1&&f(i+1,k-2,s+2*i)||c[i++]&&f(i,k-1,s+i-1)||f(i,k,s)||f(i,3,0)):s%10==3;
    }
     
    int main() {
    	for (I t; t--; std::puts(c[1]>2||f(0,3,0)?"YES":"NO")) {
    		I l;
    		for (int &e:c) e=0;
    		for (j=l; j--; ++c[n%10]) I n;
    	}
    }