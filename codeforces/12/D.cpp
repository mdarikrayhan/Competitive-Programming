#include <iostream>
#include <algorithm>
using namespace std;

struct Candidat { int valoare[3]; } sir[500001];
pair <int , int> copie[500001];
int maxim[500001];

inline int Query (int indice , const int limita)
{
    int rezultat = 0;
    for ( ; indice <= limita ; indice += (indice & -indice))
        { rezultat = max(rezultat , maxim[indice]); }

    return rezultat;
}

inline void Update (int indice , const int valoare)
{
    for ( ; indice ; indice ^= (indice & -indice))
        { maxim[indice] = max(maxim[indice] , valoare); }
}

int main ()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int lungime;
    cin >> lungime;

    for (int indice = 1 ; indice <= lungime ; indice++)
        { cin >> sir[indice].valoare[0]; }
    for (int indice = 1 ; indice <= lungime ; indice++)
        { cin >> sir[indice].valoare[1]; }
    for (int indice = 1 ; indice <= lungime ; indice++)
        { cin >> sir[indice].valoare[2]; }

    sort(sir + 1 , sir + lungime + 1 , [] (const Candidat optiune_1 , const Candidat optiune_2) -> bool { return optiune_1.valoare[0] < optiune_2.valoare[0]; });

    for (int indice = 1 ; indice <= lungime ; indice++) 
        { copie[indice] = {sir[indice].valoare[1] , indice}; }

    sort(copie + 1 , copie + lungime + 1);

    int limita = 0;
    for (int indice = 1 ; indice <= lungime ; indice++)
    {
        limita++;
        const int initial = indice--;
        while (indice < lungime && copie[indice + 1].first == copie[initial].first)
            { sir[copie[++indice].second].valoare[1] = limita; }
    }

    int total = 0;
    for (int dreapta = lungime ; dreapta ; dreapta--)
    {
        int stanga = dreapta + 1;
        while (stanga > 1 && sir[stanga - 1].valoare[0] == sir[dreapta].valoare[0])
            { stanga--; total += (Query(sir[stanga].valoare[1] + 1 , limita) > sir[stanga].valoare[2] ? 1 : 0); }

        dreapta++;
        while (dreapta > stanga)
            { dreapta--; Update(sir[dreapta].valoare[1] , sir[dreapta].valoare[2]); }
    }

    cout << total;
    return 0;
}