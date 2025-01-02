#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <numeric>
#include <functional>
#include <climits>
#include <assert.h>
#include <array>
#include <ctime>
#include <cstring>
#include <random>
#include <bitset>

#define ll long long
#define ff first
#define ss second
#define please return
#define AC 0
#define YES "YES"
#define NO "NO"
#define Yes "Yes"
#define No "No"
#define endl "\n"
#define sendl " \n"
#define space " "



void solve(){
    int n;
    std::cin >> n;
    std::vector<std::string> cur(n);
    for(auto& s : cur)
        std::cin >> s;

    //0 foe w, 1 for i, 2 for n
    //mp[i][j] i for more, j for leak
    std::vector mp(3, std::vector<std::set<int>>(3));
    std::vector<std::vector<int>> count(3, std::vector<int>(n, 0));

    std::function<void(int)> change = [&](int j) -> void{
        int w = count[0][j];
        int i = count[1][j];
        int n = count[2][j];
        if(w >= 2){
            if(i == 0)
                mp[0][1].insert(j);
            if(n == 0)
                mp[0][2].insert(j);
        }
        if(i >= 2){
            if(w == 0)
                mp[1][0].insert(j);
            if(n == 0)
                mp[1][2].insert(j);
        }
        if(n >= 2){
            if(i == 0)
                mp[2][1].insert(j);
            if(w == 0)
                mp[2][0].insert(j);
        }
    };

    std::function<void(int)> del = [&](int j) -> void{
        int w = count[0][j];
        int i = count[1][j];
        int n = count[2][j];
        if(w >= 2){
            if(i == 0)
                mp[0][1].erase(j);
            if(n == 0)
                mp[0][2].erase(j);
        }
        if(i >= 2){
            if(w == 0)
                mp[1][0].erase(j);
            if(n == 0)
                mp[1][2].erase(j);
        }
        if(n >= 2){
            if(i == 0)
                mp[2][1].erase(j);
            if(w == 0)
                mp[2][0].erase(j);
        }
    };

    for(int j = 0; j < n; j++){
        count[0][j] = std::count(cur[j].begin(), cur[j].end(), 'w');
        count[1][j] = std::count(cur[j].begin(), cur[j].end(), 'i');
        count[2][j] = std::count(cur[j].begin(), cur[j].end(), 'n');
        change(j);
    }

    std::vector<std::vector<int>> op;

    for(int j = 0; j < n; j++){
        int more = -1;
        for(int k = 0; k < 3; k++)
            if(count[k][j] >= 2)
                more = k;
        

        for(int k = 0; k < 3; k++){
            if(count[k][j] == 0){
                for(int z = 0; z < 3; z++){
                    int now = (more + z) % 3;
                    if(mp[k][now].size()){
                        int who = *mp[k][now].begin();
                        
                        op.push_back({j, more, who, k});
                        del(j);
                        del(who);

                        count[k][j] += 1;
                        count[more][j] -= 1;

                        count[more][who] += 1;
                        count[k][who] -= 1;

                        change(j);
                        change(who);
                        break;
                    }
                }
            }
        }
    }

    std::array<char, 3> ch = {'w', 'i', 'n'};
    std::cout << op.size() << endl;
    for(int i = 0; i < op.size(); i++){
        std::cout << op[i][0] + 1 << space;
        std::cout << ch[op[i][1]] << space;
        std::cout << op[i][2] + 1 << space;
        std::cout << ch[op[i][3]] << endl;
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int t;
    t = 1;
    std::cin >> t;
    while (t--){
        solve();
    }
    please AC;
}

/*
.';....  .7'   .,,,,,.,,,,,,,.;looo3;;;';'','7;',,'',,..:3;,,,7,....,,  . .7::;,.......,';,',,';::;';:::::;:;;;;;;
 .',,.. .,.   .,,,,,,,,,,,..;37ooo:3:;;';;,,'3;',,,',,..:,3,,,':,,...,. .. ;:;,';,,........,,,,,'',';:::::;::;;;
.,,,,....   .,,,,,,,,,,,,,'7b3loob,'l;;,;;,,'3',,,,,,,..;,,;,,,::,...,, ...,:7',,',;:,,...,,,,''.   ,,;;;;;;;;;;;
 .,,,,.   .,,,,,,,,,,:::7:::blooo3,,l7;',;,,,l',,,,,,,.';,.,;'',37,..,' ...,7::,,,,.7777',,,.,':,. ...;,';:::::::
 .,,.   .,,,,,,,,,,7bdo:3:::booob',;:d37';,,,l',,,,,,,,7.   .,,,;:'..,;.....7::;,,,,'777:,'',,.,.,,,:::';::,,,,;,
,,.    ,,,,,,,,,,;:obbd373::bodd7.  .;l;,',,;o,,,,,,,,,7.     ,,,77,,,:.....7:::',,,.:7:7:,,,,,.   .. .,,,,',,',.
.     ,,,,,,,,,;::;3bbbd7l:7dboo.    ,l3',,,:l,,,,,,',3,       ',;';.,:,...,7::::,,,,.:7',,,,  ,,.  ,..,,,,,',,,.
     .,,,,,,,'3d;:;7booob3l:boo'      ,l3,,,73,,,,,;,;7  . .;lobd3,:,,7,...,77::::,,,,.77;,,,,,.',,;:,,,,,,,,,,...
   ..,,,,,,,37;l:',,,,,.,ol7obl      ..,l:,,3:,,,,':'3.  ,ONXK0b'b0,;,7,...::77:::;,,,..77;,,,,,;. .:,,,;,..,,,,.
   .,,,,,,,,,,,,,,,..,,3,,olld,  .,,,...'o''o',,,'7;3'  ,X000000x.,0:;7,...37::7:::;,,,.,,,.,.,,:,.;:':;,,,.......
 ..,,,,,,,,,,....,,':dbl,,,ooxb0XNNKb:::,73:l,,,'7777   ;K00OO0OO, 'll:...;77:,'::::;,,..,',.      .':,.:,.......
..,,,,,,,,.,':7;;:l::ob3,,.;NNK000000Kl..,337,,;7773.    000k7OOO' .:b,.,,b777;,,;':7',,,,           .:.,'',.....
.,,,,,,,,,3bl777'':3::d3,,;WX00000000x0;  :l',;7773.     7kkKKkl',  ,o.,.obl37:,,7;,::';.              :,';7,,,
,,,,,,,,lxdbobb7:'':l:lo,,dXK000O,O0bkbk  ,l,::777,       ;7;;,,:   .;.,7bb3o77'':,',,7.  ..........   .;,.,,,,..
,,,..,,:koooobx37:'';l:o,,K,K00x0O00l7,,  .7::;,:;          .,,:.   ,,,73bblb37:::..:,'  ............   ,..,,....
,,;7,   :bbbbbxo:7:'''l3:;l3'Odolbb7,',,  ,;:,..;,           ... . ,,;:,looolo77:;..',.  ...........,   ,....,,'
ooooo..;3;,'7oxdb7::;''7o;..,,3;.,...,7  .',. . ..               .,,,3:,oolo3b7::,.,,l   ...........,.  ,..,,..'l
obdd:,lbo:...,3bddo7;''''33.     ,,'',...,.                      .  ,ll,boll3d7::.',.3   ...........,. .,7773337l
dx7,..;doo'. .,7oddbl7;''';3,.     .....                            ;ololool3d7:;7:,.'.. ........,,,,. .'o''l3llll
do7.  .ddoo,.  .:lbdooo3:'',',,. ......                             lloldoo37d;377:'.'..  ,..,,,,,,,,. .:ooooooo3
b'd   .:ddll,    ,7odooool7;;,,,,..                                77lo3bob73,37777,,,... ,,,,,,,,,,' ..33:llloll3
3:b    .lddl3,     ,7ooodbol7:7:,,,,,..                          ,o777o3ooo3,;77777',,,.. .,,,,,,,,,' ..l7;olooll;
'll     ,odxo3,     .:73odxdol7;:;,,..              _          .:d37,7l3obl',,:77777,,' .. ,,,,,,,,,' .,ooooooo7
;7o     ;;bdxb7,.     .:';bddddb3'';,...                     .7dll7;,333ob3,,,,,,,,,',,,....,,,,,,,,,..'oooooo7';7
:,,.     o;bdxd3,,      ;7,3dddxdol;';.                    .7ddbo77,,73ld37;,,,,,,,:7:.,.....,,,,,,,,..7ol3:;,,,,
:,.,.....,o:ddxxl;:.  .  ,3:7bdddo':7;;,.                ,ldbddbl7:,,;3db777777;:77777:,; ....,,,,,,,,..
:,.      ..l7ddxxb7';. ...;373obddb;'';77;',,,,...     ,oddbbddo37;,,'oob77777o777777773::.....,,,.
;,,......,,dooddxxxo;7;,':773:::3odd7'';ol;,,''''';bbobbbddbbddb3:',,'d3d7;'77ll3777773:::7.....
3l7;,....,,3xldddxxxd3777o7773:::::3bl:,bll,,,,,,,'lbbbbbddbbddd7:',,:d3b3:,,:7o33377o;:::7:,.
7773b7,,,...,;lddxxxxxo773l:7:ll7::;;:7ooll:,,,,,,,,ooooooo7bddx3:',,33o3b7,,,;lo3333o;:::7,              .,
7773b7b3',,,,...,:bxxxxb77o3:::oboo37::;7lo3:'',,.,,,;7llll3,7lob;',,3773ob;,,,'lo77773:::.            .;odb7
777lb7bdxo7:',,,,,.,;lxxdl3b77:7obooooll377ool;';;,,.,,'l3lll:;lo3;,,3:77:3l7;,,,7l',,,;7           .;lol;.
777oo7odxb7'33:,,,::;',:oddbl:77:bdbbbboooooooo7',':7,  ,l3ooo3'lo7,,3:77,,;:7337773;,,;. ..,,,...'
773b37bxdb,,..';:;,'bxxdbbxkd3:::lllloolool:'';73',,,;:,.:l::773,ll3''3773;,,,;:7773333. ,  .,,'..,7,
77lb77bxd,..   ...:;,:bddboodd:773llolllllll3;. .:',,,'','7o,,,,;.','7377733',,,,;:::7;..,.,....,..,.
73bl77xd,,.     .. ,7;,:,,,,7xl77l7:73oo377:'':l37',,',,, ,:l,,,,'.';;;:7733l7,,,,,:7l',,,., .,....,
3bblbob,,.       .  .'::7..,bbd77ool;',.,'',,,,,,7'',:,,'. ,l:,,,,,.,7l,,,':7lo7',,,'7,,,,.,,,,.,,.'
,'o337:;.   ..   ..  . .,7:oodx333l7,,,,,..,,,,,,,'':;,,,'.,ll,,;,,.,,::,,.,,,,7,:l3:; .,....,,...,.    ;xb
,,,;7''''.,,,... .   ..,;lloddk:,,3';,,,,,,,...,,':77,,,,oolbl3,;',' ',,:,....,.  .,:; .l;..,..,,.          ..,,,
..,,';:733333337777777333lddb:...,,,,',,,,,,,,,..;73',,,'lllbll';',,,.,,,,,..,.   .  , ox7...       ..,,'';;;;;;;
  ..,';''':,,';:7:::77733;,.....,,,,,,,,,,,,,,,,'37'';,,7;,,'7l7',,,, ,,,,,',,  ..   ,3xb.     .,,';;;;;;;;;;;;;;
 .....,,,,:.   ....,...........,,,,;,,',,,,,,,,,3',:7;,;,,,,,,,l,,,,,,.,,,,,,, .. .  .lx,.  .';;;;;;;;;;'',,,,,..
     ..'',,' .,,,,;,,,.......,,,,,,,;,;,,,,,,':;,'777,:,..,,,,,:;,,,,,.,,,,,,,,,  ... 7l  .,,,,,,,,..............
  .,,,,,''';,,..,,,,,,',,,,,,,,,,,,,l,:',,,':;','777;:,,,,. .,,'7,,,,,.,,,,,,,,,. ..,,:l3. ..,....................
     ...,;;;:.,,,,,,....',,,,,,,,,,,l':7'::;;;,,7777;,,,,,,,,..,7,,,,,.,,,,,,,,,,,,';73377,. .....................
       .,7:7o,,..   ,   .',,,,,,,,,,337737:;;,,'777',,,,,,,,,,,,;,,,,,.,,,,,,,,,,,';37:77::7;,.. ........,,,,,,,,;'
    ....,733o',,,.   . ..,,,,,,,,,,,737l7:;;',,;73',,,,,,,,,,,,,;,,,,,.,,,';'''';;',,l3;,'';:77;,,.....,,,,,,:,,,;
.......,,:lox;,,,,,..,..,,,,,,,,,,,,7l33:;;;',,;:l3;,,,,,,,,,,,'',,,,.,,:7::::::::;,;l337',,,,:7777',,,......::';3
,,,..,,,,7xxdddb3:,,,,...,;,,,,,,,,'7bb:;;;;',,,:l33:,,,,,,,,,,::'33:.7337777:::77''3l777':',,,,,'',,,,,,,,,';73:o
*/