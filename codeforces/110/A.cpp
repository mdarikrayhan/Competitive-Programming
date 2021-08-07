#include <iostream>

using namespace std;

int main()
{
    int count = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
    
        if (s[i] == 52 || s[i] == 55)
        {
            count++;
        }
    }
    if(count==4 || count==7){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}