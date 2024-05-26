#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cstdint>
using namespace std;

int64_t Cmmdc (const int64_t valoare_1 , const int64_t valoare_2)
{
    return valoare_2 ? Cmmdc(valoare_2 , valoare_1 % valoare_2) : valoare_1;
}

const int mod(998244353);
unordered_map <int64_t , int> aparitii;

int main ()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int lungime;
    cin >> lungime;

    int64_t sir[501] = { };
    while (lungime--)
    {
        int64_t valoare;
        cin >> valoare;

        int stanga = 1 , dreapta = 200000 , radacina = 0;
        while (stanga <= dreapta)
        {
            const int candidat = stanga + ((dreapta - stanga) >> 1);
            if ((int64_t)candidat * candidat > valoare / ((int64_t)candidat * candidat)) { dreapta = candidat - 1; }
            else { stanga = candidat + 1; radacina = candidat; }
        }

        if ((int64_t)radacina * radacina * radacina * radacina == valoare)
            { aparitii[radacina] += 4; continue; }

        stanga = 1 , dreapta = 2000000000 , radacina = 0;
        while (stanga <= dreapta)
        {
            const int candidat = stanga + ((dreapta - stanga) >> 1);
            if ((int64_t)candidat * candidat > valoare) { dreapta = candidat - 1; }
            else { stanga = candidat + 1; radacina = candidat; }
        }

        if ((int64_t)radacina * radacina == valoare)
            { aparitii[radacina] += 2; continue; }
            
        stanga = 1 , dreapta = 2000000 , radacina = 0;
        while (stanga <= dreapta)
        {
            const int candidat = stanga + ((dreapta - stanga) >> 1);
            if ((int64_t)candidat * candidat > valoare / candidat) { dreapta = candidat - 1; }
            else { stanga = candidat + 1; radacina = candidat; }
        }

        if ((int64_t)radacina * radacina * radacina == valoare)
            { aparitii[radacina] += 3; continue; }

        sir[++sir[0]] = valoare;
    }
    
    for (int indice_1 = sir[0] ; indice_1 ; indice_1--) 
    {
        bool gasit = false;
        for (auto &candidat : aparitii) {
            if (sir[indice_1] % candidat.first == 0)
            {
                candidat.second++;
                aparitii[sir[indice_1] / candidat.first]++;
                gasit = true;
                break;
            }
        }

        if (gasit) 
        {
            sir[0]--;
            for (int indice_2 = indice_1 ; indice_2 <= sir[0] ; indice_2++)
                { sir[indice_2] = sir[indice_2 + 1]; }
            
            indice_1 = sir[0] + 1;
            continue;
        }

        for (int indice_2 = sir[0] ; indice_2 > indice_1 ; indice_2--) {
            if (sir[indice_1] != sir[indice_2])
            {
                const int64_t candidat = Cmmdc(sir[indice_1] , sir[indice_2]);
                if (candidat > 1)
                {
                    int64_t stiva[501]; stiva[stiva[0] = 1] = candidat;
                    while (stiva[0])
                    {
                        int ramas = 0;
                        const int64_t actual = stiva[stiva[0]--];
                        for (int indice_3 = 1 ; indice_3 <= sir[0] ; indice_3++) {
                            if (sir[indice_3] % actual == 0)
                            {
                                aparitii[actual]++;
                                aparitii[sir[indice_3] / actual]++;
                                stiva[++stiva[0]] = sir[indice_3] / actual;
                            }
                            else
                                { sir[++ramas] = sir[indice_3]; }
                        }

                        sir[0] = ramas;
                    }

                    indice_1 = sir[0] + 1;
                    break;
                }
            }
        }
    }

    sort(sir + 1 , sir + sir[0] + 1);

    int64_t numar_divizori = 1;
    for (int stanga = 1 ; stanga <= sir[0] ; stanga++)
    {
        int dreapta = stanga;
        while (dreapta < sir[0] && sir[dreapta + 1] == sir[dreapta])
            { dreapta++; }
            
        numar_divizori = numar_divizori * (dreapta - stanga + 2) % mod;
        numar_divizori = numar_divizori * (dreapta - stanga + 2) % mod;
        stanga = dreapta;
    }

    for (auto factor : aparitii)
        { numar_divizori = numar_divizori * (factor.second + 1) % mod; }

    (cout << numar_divizori).flush();
    return 0;
}