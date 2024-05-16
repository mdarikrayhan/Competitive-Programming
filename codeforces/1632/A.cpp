        #include <iostream>
        #include <string>
        using namespace std;
        int main()
        {
            int t;
            cin>>t;
            for(int tt=0;tt<t;tt++)
            {
                int n;
                string s;
                cin>>n;
                cin>>s;
                if(n==2 && s[0]==s[1])
                    cout<<"NO\n";
                else if(n<3)
                    cout<<"YES\n";
                else cout<<"NO\n";
            }
            return 0;
        }