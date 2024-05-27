#include <iostream>
#include <algorithm>
#include <cstdint>
using namespace std;

int sir[200001] , inlocuitor[200001] , suma[200001];
pair <int , int> operatii[100001] , copie[200001];

inline int Query (int indice , const int limita)
{
    int total = 0;
    for ( ; indice <= limita ; indice += (indice & -indice))
        { total += suma[indice]; }

    return total;
}

inline void Update (int indice)
{
    for ( ; indice ; indice ^= (indice & -indice))
        { suma[indice]++; }
}

int main ()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int lungime;
    cin >> lungime;

    for (int indice = 1 ; indice <= lungime ; indice++)
    {
        cin >> operatii[indice].first >> operatii[indice].second;
        copie[(indice << 1) - 1] = {operatii[indice].first , (indice << 1)};
        copie[(indice << 1)] = {operatii[indice].second , (indice << 1) | 1};
    }

    sort(copie + 1 , copie + (lungime << 1) + 1);

    int limita = 0;
    for (int indice = 1 ; indice <= (lungime << 1) ; indice++)
    {
        const int initial = indice--;
        inlocuitor[++limita] = copie[initial].first;
        while (indice < (lungime << 1) && copie[indice + 1].first == copie[initial].first)
            { indice++; ((copie[indice].second & 1) ? operatii[copie[indice].second >> 1].second = limita : operatii[copie[indice].second >> 1].first = limita); }
    }

    for (int indice = 1 ; indice <= limita ; indice++)
        { sir[indice] = indice; }

    for (int indice = 1 ; indice <= lungime ; indice++)
        { swap(sir[operatii[indice].first] , sir[operatii[indice].second]); }

    int64_t inversiuni = 0;
    for (int indice = 1 ; indice <= limita ; indice++)
    {
        inversiuni += Query(sir[indice] + 1 , limita);
        Update(sir[indice]);

        if (indice < sir[indice])
            { inversiuni += (int64_t)inlocuitor[sir[indice]] - inlocuitor[indice] - sir[indice] + indice; }
        else
            { inversiuni += (int64_t)inlocuitor[indice] - inlocuitor[sir[indice]] - indice + sir[indice]; }
    }

    cout << inversiuni;
    return 0;
}