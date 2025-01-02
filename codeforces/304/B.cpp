#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

void solve(){
    string ini, fim; cin >> ini >> fim;
    ll count = 0;
    if(fim < ini) swap(ini, fim);
    // days are in formart yyyy:mm:dd
    //perform operations to count days between ini and fim
    int year = stoi(ini.substr(0, 4));
    int month = stoi(ini.substr(5, 2));
    int day = stoi(ini.substr(8, 2));
    int end_year = stoi(fim.substr(0, 4));
    int end_month = stoi(fim.substr(5, 2));
    int end_day = stoi(fim.substr(8, 2));
    while(year < end_year or month < end_month or day < end_day){  
        if(day == 31 and month == 12){
            year++;
            month = 1;
            day = 1;
        }
        else if(day == 31 and (month == 1 or month == 3 or month == 5 or month == 7 or month == 8 or month == 10)){
            month++;
            day = 1;
        }
        else if(day == 30 and (month == 4 or month == 6 or month == 9 or month == 11)){
            month++;
            day = 1;
        }
        else if(day == 29 and month == 2 and (year % 4 == 0 and year % 100 != 0 or year % 400 == 0)){
            month++;
            day = 1;
        }
        else if(day == 28 and month == 2 and !(year % 4 == 0 and year % 100 != 0 or year % 400 == 0)){
            month++;
            day = 1;
        }
        else{
            day++;
        }
        count++;
    }

    cout << count << endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}


