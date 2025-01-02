#include <bits/stdc++.h>
using namespace std;

int sir[200001];

int main ()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int lungime;
    cin >> lungime;

    for (int indice = 1 ; indice <= lungime ; indice++)
        { cin >> sir[indice]; }

    sort(sir + 1 , sir + lungime + 1);

    int minim = INT32_MAX , aparitii = 0;
    for (int indice = 1 ; indice < lungime ; indice++) {
        if (sir[indice + 1] - sir[indice] < minim) { minim = sir[indice + 1] - sir[indice]; aparitii = 1; }
        else { aparitii += (sir[indice + 1] - sir[indice] == minim ? 1 : 0); }
    }

    cout << minim << ' ' << aparitii;
    return 0;
}