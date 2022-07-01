#include<bits/stdc++.h>
using namespace std;
int main(){
string s;
cin>>s;
regex reg("WUB");
cout<<regex_replace(s,reg," ");
}