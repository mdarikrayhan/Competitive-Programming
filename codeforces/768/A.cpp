///avtor:
/*
_____________________________________________________________________________________________________________________________
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||_|
   ___________________                                                                                                    ||_|
  //                //       ____                                                                                         ||_|
 //    ____________//       ||  ||                                                                                        ||_|
 ||   //                    ||__||       ________              __               __         ________________________       ||_|
 ||   ||                     ____       ||       \\           //\\             //\\       /___________________    /       ||_|
 ||   ||                    ||  ||      ||        \\         ||  ||           ||  ||                        //  //        ||_|
 ||   ||                    ||  ||      ||  ||\\   \\        ||  ||           ||  ||                      //  //          ||_|
 ||   ||___________         ||  ||      ||  || \\   \\       ||  ||           ||  ||                    //  //            ||_|
 ||              //         ||  ||      ||  ||  \\   \\      ||  ||           ||  ||                  //  //              ||_|
 ||    _________//          ||  ||      ||  ||   \\  //      ||  ||           ||  ||                //  //                ||_|
 ||   ||                    ||  ||      ||  ||____\\ /       ||  ||           ||  ||              //  //                  ||_|
 ||   ||                    ||  ||      ||       \\          ||  ||           ||  ||            //  //                    ||_|
 ||   ||                    ||  ||      ||  ||\\  \\         ||  ||           ||  ||          //  //                      ||_|
 ||   ||                    ||  ||      ||  || \\  \\        ||  ||___________||  ||        //  //                        ||_|
 ||   ||                    ||  ||      ||  ||  \\  \\       ||                   ||      //  //________________          ||_|
 ||___||                    ||__||      ||__ ||  \\__\\      ||___________________||     /_____________________/          ||_|
__________________________________________________________________________________________________________________________||_|
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||_|
Language:                           ||_|
   ______                           ||_|
  /  _   \                          ||_|
 / /   \__\__          __           ||_|
|  |      |  |        |  |          ||_|
|  |    __|  |__    __|  |__        ||_|
|  |   |        |  |        |       ||_|
|  |   |__    __|  |__    __|       ||_|
|  |      |  |        |  |          ||_|
 \ \_____ |__|        |__|          ||_|
  \______/                          ||_|
____________________________________||_|
||||||||||||||||||||||||||||||||||||||||

*/
#include<bits/stdc++.h>
#define ll long long
#define en cout << endl;
using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, cnt = 0, c = 0,mx = -999999999, mn = 999999999;
    cin >>n;
    int a[n];
    for(int  i = 0 ; i <n ; i ++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }
    sort(a, a + n);
    for(int i = 0; i < n ; i++)
    {
        if(a[i] == mx)cnt++;
        if(a[i] == mn)c++;
    }
    cout << max(n-c-cnt, 0);

}
