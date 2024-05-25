#include <bits/stdc++.h>
using namespace std;

char sir[100005] , stiva[100005];

int main ()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int64_t cantitate; int numar_teste;
    cin >> cantitate >> numar_teste;

    int limita = 0;
    while ((1LL << limita) < ((cantitate + 1) >> 1))
        { limita++; }

    while (numar_teste--)
    {
        int64_t valoare;
        cin >> valoare >> sir;

        int adancime = 0;
        for (int64_t actual = (1LL << limita) ; actual != valoare ; ) {
            if (actual > valoare) { actual -= (1LL << (limita - adancime - 1)); stiva[++adancime] = 'L'; }
            else { actual += (1LL << (limita - adancime - 1)); stiva[++adancime] = 'R'; }
        }

        for (int indice = 0 ; sir[indice] ; indice++) {
            switch (sir[indice]) {
                case 'U': {
                    if (adancime == 0) { continue; }
                    if (stiva[adancime] == 'L') { valoare += (1LL << (limita - adancime)); }
                    else { valoare -= (1LL << (limita - adancime)); }
                    adancime--;
                } break;
                case 'L': {
                    if (adancime == limita) { continue; }
                    valoare -= (1LL << (limita - adancime - 1));
                    stiva[++adancime] = 'L';
                } break;
                case 'R': {
                    if (adancime == limita) { continue; }
                    valoare += (1LL << (limita - adancime - 1));
                    stiva[++adancime] = 'R';
                } break;
            }
        }

        cout << valoare << '\n';
    }

    return 0;
}