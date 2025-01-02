#include<bits/stdc++.h>
using namespace std;

int countab(string s)
{
    int ab=0;
    for(int i=0;i<s.length()-1;i++)
    if(s[i]=='a'&&s[i+1]=='b')
    ab++;
    return ab;
}
int countba(string s)
{
    int ba=0;
    for(int i=0;i<s.length()-1;i++)
    if(s[i]=='b'&&s[i+1]=='a')
    ba++;
    return ba;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        if(s.length()==1)
        {
            cout<<s<<endl;
            continue;
        }
        int ab=countab(s);
        int ba=countba(s);
        if(ab==ba)
        cout<<s<<endl;
        else
        {
            for(int i=0;i<s.length();i++)
            {
                string st=s;
                if(s[i]=='a')
                st[i]='b';
                else
                st[i]='a';
                int x=countab(st);
                int y=countba(st);
                if(x==y)
                {
                    cout<<st<<endl;
                    break;
                }
            }
        }
    }
}