#include<bits/stdc++.h>
#include<cstring>
//#define Psych_x7's Code
#define   ll         long long
#define   ull        unsigned long long
#define   pb         push_back
#define   em         emplace_back
#define   ff         first
#define   ss         second
#define   all(v)     (v.begin(), v.end())
#define   rall(v)    (v.rbegin(), v.rend())
#define   pi         acos(-1.0)
#define   FastRead   ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define   bug(a)     cerr << #a << " : " << a << endl
using namespace std;

ll binarySearch(ll low,ll high,ll high2)
{
    ll C,D,mid,E;
    C=high;
    D=high2;
    while (low <= high) {
        mid = low + (high - low) / 2;
        // cout<<mid<<endl;
        E=(C-mid)-(D-(mid*2));
        // cout<<E<<endl;
        // Check if x is present at mid
        if (E==(D-(mid*2)))
            return mid;

        // If x greater, ignore left half
        if (E < (D-(mid*2)))
            low = mid + 1;

        // If x is smaller, ignore right half
        else
            high = mid - 1;
    }

    // If we reach here, then element was not present
    return -1;
}
int main() {
	//code
	ll T,X,Y,A,B,F;
	cin>>T;
	while(T--){
	    cin>>X>>Y;
	    A=min(X,Y);
	    B=max(X,Y);
	    F=binarySearch(0,A,B);
	    if(F==-1){
	        cout<<"NO"<<endl;
	    }else{
	        cout<<"YES"<<endl;
	    }
	}
	return 0;
}