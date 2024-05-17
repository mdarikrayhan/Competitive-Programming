#include <iostream>
#include <string>

using namespace std;

bool sonEquivalentes(string& a, string& b) {
    if (a == b) {
        return true;
    }
    if (a.size() % 2 != 0) {
        return false;
    }
    string a1 = a.substr(0, a.size()/2);
    string a2 = a.substr(a.size()/2);
    string b1 = b.substr(0, b.size()/2);
    string b2 = b.substr(b.size()/2);
    return (sonEquivalentes(a1, b2) && sonEquivalentes(a2, b1)) || (sonEquivalentes(a1, b1) && sonEquivalentes(a2, b2));
}

int main() {
    string a;
    string b;
    cin >> a;
    cin >> b;
    if (sonEquivalentes(a,b)){
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
		  		     	  		 		   		 	   	