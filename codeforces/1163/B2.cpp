#include <iostream>
#define NMAX 300050
using namespace std;
int n, x, fr[NMAX], frfr[NMAX], nrmin, nrmax, xmax, frmin=2e9, frmax=-1, nrp;
int main()
{
    cin>>n;

    for(int i=1;i<=n;++i)
    {
        cin>>x;
        if(fr[x]==0)
            nrp++;

        if(fr[x]==frmin)
        {
            --nrmin;
            if(nrmin==0)
            {
                nrmin=frfr[frmin+1];
                frmin++;
            }
        }

        ++fr[x];
        --frfr[fr[x]-1];
        ++frfr[fr[x]];


        if(fr[x]==frmin)
            ++nrmin;
        if(fr[x]<frmin)
        {
            nrmin=1;
            frmin=fr[x];
        }

        if(fr[x]==frmax)
            ++nrmax;
        else if(fr[x]>frmax)
        {
            frmax=fr[x];
            nrmax=1;
        }
/*

Cazuri:
frmax-frmin > 1     : posibil daca nrmin == 1 && frmin == 1 && nrmax == i - 1
frmax-frmin  == 1   : posibil daca nrmax == 1
frmax-frmin  == 0   : posibil daca frmax == 1

*/
        if((frmax==frmin && frmin==1 && nrmin==nrp)||(frmax==frmin && nrmin==1 && frmin==i))
            xmax=i;

        if((frmax-frmin==1 && nrmax==1 && nrmin==nrp-1) ||( frmin==1 && nrmin==1 && nrmax==nrp-1))
            xmax=i;
    }

    cout<<xmax;


    return 0;
}
