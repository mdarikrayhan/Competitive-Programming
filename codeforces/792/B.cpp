#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int lungime , repetari;
    cin >> lungime >> repetari;

    bool eliminat[101] = { };
    for (int indice = 0 , actual = 1 ; indice < repetari ; indice++)
    {
        int valoare;
        cin >> valoare;

        valoare %= lungime - indice;
        while (valoare) {
            if (!eliminat[actual]) 
                { valoare--; }
            if (actual == lungime)
                { actual = 1; }
            else
                { actual++; }
        }

        while (eliminat[actual]) {
            if (actual == lungime) 
                { actual = 1; }
            else
                { actual++; }
        }

        cout << actual << ' ';
        eliminat[actual] = true;
        
        while (eliminat[actual]) {
            if (actual == lungime) 
                { actual = 1; }
            else
                { actual++; }
        }
    }

    return 0;
}