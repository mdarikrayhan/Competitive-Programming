

							    // *		*		*		*		*
							    // *		*		*		*		*
							    // *		*		*		*		*
							    // *********		*		*		*
							    // *		*		*		*		*
							    // *		*		*		*		*
							    // *		*		*********		*
							    
							    // *		*		*		*		*
							    // *		*		*		*		*
							    // *		*		*		*		*
							    // **********		*		*		*
							    // *		*		*		*		*
							    // *		*		*		*		*
							    // *		*		*********		*




#include<bits/stdc++.h>


//- जय हनुमंत संत हितकारी, सुनि लीजै प्रभु विनय हमारी।
//जन के काज विलम्ब न कीजै, आतु दौर महासुख दीजै।। 
#define ll long long 
#define double long double
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pb push_back
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define INF INT_MAX
#define INM INT_MIN
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;

using namespace std;



void solved( )
{
	string s;
	cin>>s;
	// cout<<s<<endl;
	string ans;
	int i =0; 
	while(i<s.length())
	{
		while(ans.length() && ans.back()<s[i])
		{
			ans.pop_back();
		}
		ans.push_back(s[i]);
		i++;
	}
	cout<<ans<<endl;



   
}


signed main(){
    speed;
    // int tc=1;
    // // cin>>tc;
    // int T=tc;

    // while(tc--)
    // {   
        solved();
    // }
    // return 0;
}


