#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    ll n, q, numMt, s;
    int t;
    ll qt1 = 0;

    cin >> n >> q;

    int matriz[n];
    for (int i = 0; i < n; i++) {
        cin >> numMt;
        matriz[i] = numMt;
        if (numMt == 1) {
            qt1++;
        }
    } 

    while (q > 0) {
        cin >> t >> s;

        if (t == 2 && s <= qt1) {
            cout << 1 << '\n';
        }
        else if (t == 2 && s > qt1) {
            cout << 0 << '\n';
        }
        else if (t == 1) {
            if (matriz[s - 1] == 1) {
                qt1--;
                matriz[s - 1] = 0;
            }
            else {
                qt1++;
                matriz[s - 1] = 1;
            }
        }
        q--;
    }
    return 0;
}
				 			  				  	  	   	 	 			