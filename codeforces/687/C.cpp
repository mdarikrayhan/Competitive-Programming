#include <iostream>
#include <bitset>
using namespace std;

bitset <501> posibil[501];

int main ()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int lungime , suma;
    cin >> lungime >> suma;

    posibil[0].set(0);
    while (lungime--)
    {
        int valoare;
        cin >> valoare;

        for (int _suma = suma ; _suma >= valoare ; _suma--)
            { posibil[_suma] |= (posibil[_suma - valoare] | (posibil[_suma - valoare] << valoare)); }
    }

    cout << posibil[suma].count() << '\n';

    for (int indice = 0 ; indice <= suma ; indice++) {
        if (posibil[suma][indice])
            { cout << indice << ' '; }
    }

    return 0;
}