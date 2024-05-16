//CodeForces - 1060A
//https://vjudge.net/contest/575132#problem/H

#include<bits/stdc++.h>

using namespace std;

#define nl "\n"

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    fast();

    int n;
    cin >> n;

    string s;
    for(int i =0; i<n; i++)
    {
        char x;
        cin>> x;
        s.push_back(x);
    }
    int cont = count(s.begin(), s.end(), '8');
    int z = n/11;

    cout << min(cont,z) << nl;

}

	 	  		 		  				  				 	   		 	