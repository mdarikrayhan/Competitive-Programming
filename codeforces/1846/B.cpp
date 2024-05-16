/*#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--){
        string s1,s2,s3;
        string winner = "DRAW";
        cin >>s1>>s2>>s3;
        string strings[3] = {s1,s2,s3};
        if((s1[0] == s2[1] && s2[1] == s3[2]) ||(s1[2]==s2[1] && s2[1]== s3[0]))
            winner = s2[1]; //winner in cross
        for (int i = 0; i < 3; ++i) {
            if(s1[i] == s2[i] && s2[i] == s3[i])//winner in columns
                winner = s1[i];
            //winner in rows
            if(strings[i] == string(3,'X'))
                winner = "X";
            else if(strings[i] == string(3,'O'))
                winner = "O";
            else if(strings[i] == string(3,'+'))
                winner = "+";
        }
        cout << winner<<endl;
    }
    return 0;
}*/
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2, s3;
        string winner = "DRAW";
        cin >> s1 >> s2 >> s3;
        char c[3] = {'X','O','+'}; //allowed chars
        // Check diagonals
        if ((s1[0] == s2[1] && s2[1] == s3[2]) || (s1[2] == s2[1] && s2[1] == s3[0]))
            if(s2[1] == 'X' ||s2[1] == 'O' ||s2[1] == '+')
                winner = s2[1];
        for (int i = 0; i < 3; ++i) {
            if (s1[i] == s2[i] && s2[i] == s3[i]) //check columns
                if(s1[i] == 'X' || s1[i] == 'O' || s1[i] == '+')
                    winner = s1[i];

            //check rows
            if(s1 ==string(3, c[i]))
                winner = s1[0];
            else if(s2 == string(3,c[i]))
                winner = s2[0];
            else if(s3 == string(3,c[i]))
                winner = s3[0];
        }
        cout << winner<<endl;
    }
    return 0;
}

 		   		     		  		  	  				 		