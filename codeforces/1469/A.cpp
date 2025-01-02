#include <iostream>
int main() {int t;scanf("%d",&t);while(t--){std::string s;std::cin>>s;if(s.size()&1 || s[0]==')' || s.back()=='(')puts("NO");else puts("YES");}}