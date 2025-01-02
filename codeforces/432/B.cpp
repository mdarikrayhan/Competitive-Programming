#include <bits/stdc++.h>

using namespace std;

int kitCounts[100001];

int main()
{
    int numberOfTeams;
    cin >> numberOfTeams;
    
    int homeKits[numberOfTeams], awayKits[numberOfTeams];
    
    for(int i = 0; i < numberOfTeams; i++){
        cin >> homeKits[i] >> awayKits[i];
        kitCounts[homeKits[i]]++;
    }
   
    for(int i = 0; i < numberOfTeams; i++){
        cout << (numberOfTeams - 1) + kitCounts[awayKits[i]] << " " << (numberOfTeams - 1) - kitCounts[awayKits[i]] << endl;
    }
    
    return 0;
}
