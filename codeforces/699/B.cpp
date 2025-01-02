
#include<bits/stdc++.h>
using namespace std;
int n, m, walls, row[1009], column[1009];
char greed[1009][1009];
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        for(int j = 1; j <= m; j++){
            greed[i][j] = s[j-1];
            if(greed[i][j] == '*') walls++;
        }
    }
 
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(greed[i][j] == '*') row[i]++;
        }
    }
    //row[i] - i striqonshi ramdeni kedelia
    //row[1] - pirvel striqonshi ramdeni kedelia row[2] meoreshi...
 
    for(int j = 1; j <= m; j++){
        for(int i = 1; i <= n; i++){
            if(greed[i][j] == '*') column[j]++;
        }
    }
    //column[i] - i svetshi ramdeni kedelia
 
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int exploded = 0;
            //striqonshi
            /*for(int j2 = 1; j2 <= m; j2++){
                if(greed[i][j2] == '*') exploded++;
            }*/
            //exploded += row[i];
            //svetshi
            /*for(int i2 = 1; i2 <= n; i2++){
                if(greed[i2][j] == '*') exploded++;
            }*/
            //exploded += column[j];
            exploded = row[i] + column[j];
            //
            if(greed[i][j] == '*') exploded--;
            if(exploded == walls){
                cout << "YES\n";
                cout << i << " " << j;
                return 0;
            }
        }
    }
 
    cout << "NO";
    return 0;
}


