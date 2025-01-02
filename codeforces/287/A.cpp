#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

#define int long long

//    bool is_prime(int n ){
//        if (n==1)return false ;
//        for (int i = 2; i*i <=n ; ++i) {
//            if (n%i==0){
//                return false ;
//            }
//        }
//        return true ;
//    }

//a *b =lcm*gcd
//int LCM(int num1 , int num2 , int num3){
//    return num1*(num2/num3) ;
//}

//    vector<pair<int,int>> primFactors(int num ){
//        vector<pair<int,int>>v ;
//        for (int i = 2; i*i <=num ; ++i) {
//            int power=0;
//            while (num%i==0){
//                num/=i ;
//                power++;
//            }
//            if (power>0)v.push_back({i, power}) ;
//
//        }
//        if (num>1)v.push_back({num, 1});
//        return v ;
//    }
//vector<int>GetMultiples(int n ,int x){
//    vector<long long>v;
//    v.push_back(0);
//    for(int m =x;m<=n;m+=x){
//        v.push_back(m);
//    }
//    return v;
//}
//string comp(string s1 ,string s2){
//    if (s1.size()==s2.size() ||s1.size()<s2.size() ) return s1 ;
//    else return  s2 ;
//}

//bool isPowerOfTwo(int n)
//{
//    return (ceil(log2(n)) == floor(log2(n)));
//}
//    vector<int> get_divisors(int m) {
//        vector<int> v;
//        for (int i = 1; i * i <= m; ++i) {
//            if (m % i == 0) {
//                v.push_back(i);
//                if (i * i != m)v.push_back(m / i);
//            }
//        }
//        return v ;
//    }
//   vector<int> primeFactorization(int n) {
//        vector<int> factors;
//        for (int i = 2 ; i  <= n/i ; ++i) {
//            while (n % i == 0) {
//                // ****NOTE****
//                // FIRST DIVISOR FOR ANY NUMBER (COMPOSITE OR PRIME) IS A PRIME NUMBER
//                factors.push_back(i);
//                n /= i;
//            }
//        }
//        if (n > 1) {
//            factors.push_back(n);
//        }
//        return factors;
//    }
//
//int fact (int n){
//    if (n<2)return 1;
//    return n * fact(n-1);
//
//}
//int fPower(int base , int power){
//    if (power == 0) return 1;
//
//    int p = fPower(base , power / 2);
//
//    return ( (power & 1 ) ?  p * p * base :  p * p ) ;
//
//}
//
//int GCD (int a , int b){
//    if (b == 0)return a;
//   return GCD(b,a%b);
//}
//int fib(int num ){
//    if (num==2)return 1 ;
//    else if (num==1)return 0 ;
//    return fib(num-1)+ fib(num-2) ;
//}
//
template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x : v) in >> x;
    return in;
}
template <typename T = int>ostream& operator<<(ostream& out, const vector<T>& v) {
    for (const auto& x : v) {
        out << x <<" ";
    }
    return out;
}



int32_t main() {
    fast
    int t =1;//cin>>t ;
    while (t--){
        char arr[4][4] ;
        for (int i = 0; i <4 ; ++i)for (int j = 0; j <4 ; ++j)cin>>arr[i][j] ;
        bool dal3ni=false ;
        for (int i = 0; i <3 ; ++i) {
            for (int j = 0; j <3 ; ++j) {
                int count=0 ;
                if (arr[i][j]!=arr[i][j+1])count++ ;
                if (arr[i][j]!=arr[i+1][j])count++ ;
                if (arr[i][j]!=arr[i+1][j+1])count++ ;
                if (count !=2){
                    dal3ni=true ;
                    break;
                }
            }
        }
        if (dal3ni)cout<<"YES"<<"\n" ;
        else cout<<"NO"<<"\n" ;
    }

    return 0;
}