#include <iostream>
#include <cstdint>
using namespace std;

int64_t suma[5001] , maxim[5001];

int main ()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int numar_teste;
    for (cin >> numar_teste ; numar_teste-- ; )
    {
        int lungime , termen;
        cin >> lungime >> termen;

        maxim[0] = suma[0] = 0;
        for (int indice = 1 ; indice <= lungime ; indice++)
        {
            maxim[indice] = INT64_MIN;
            suma[indice] = 0;

            int valoare;
            cin >> valoare;

            for (int _indice = indice ; _indice ; _indice--)
                { maxim[_indice] = max(maxim[_indice] , suma[_indice] = max(suma[_indice - 1] + valoare + termen , suma[_indice] + valoare)); }

            maxim[0] = max(maxim[0] , suma[0] = max(0LL , max(suma[0] + valoare , (int64_t)valoare)));
        }

        cout << maxim[0] << ' ';
        for (int indice = 1 ; indice <= lungime ; indice++)
            { cout << (maxim[indice] = max(maxim[indice - 1] , maxim[indice])) << ' '; }
        cout << '\n';
    }

    return 0;
}