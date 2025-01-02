#include<iostream>
#include<string>
using namespace std;

int main() {

  string str;
  cin >> str;

  for (int i = 0; i < str.length(); i++) {

    if (str[i] == 72 || str[i] == 81 || str[i] == 57) {
      cout << "YES" << endl;
      return 0;
    }
  }
cout<<"NO"<<endl;
  return 0;
}