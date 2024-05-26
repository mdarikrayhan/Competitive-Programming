#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
                
bool isPrime(int number){
    if(number < 2) return false;
    if(number == 2) return true;
    if(number % 2 == 0) return false;
    for(int i=3; (i*i)<=number; i+=2){
    if(number % i == 0 ) return false;
    }
    return true;
}           
    
std::string toBinary(int n)
{
    std::string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}
 
/*break	try	catch	char	class	const	continue
default	delete	auto	else	friend	for	float
long	new	operator	private	protected	public	return
short	sizeof	static	this	typedef	enum	throw
mutable	struct	case	register	switch	and	or
namespace	static_cast	goto	not	xor	bool	do
double	int	unsigned	void	virtual	union	while*/
 
struct Interval {
    int start, end;
};
 
// Compares two intervals
// according to starting times.
bool compareInterval(Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}
bool isPalindrome(string S)
{
    // Stores the reverse of the
    // string S
    string P = S;
 
    // Reverse the string P
    reverse(P.begin(), P.end());
 
    // If S is equal to P
    if (S == P) {
        // Return "Yes"
        return true;
    }
    // Otherwise
    else {
        // return "No"
        return false;
    }
}

int ada(int **a, int x, int y){
    if(a[x][y]==0){return 0;}
    else{
        int temp = a[x][y];
        a[x][y] = 0;
        return (temp + ada(a, x+1 , y) + ada(a, x-1, y) + ada(a, x, y+1) + ada(a, x, y-1));
    }
}
 
 
int main(){ 
    FAST
    int t,n,aa[1000],b[1000],p,q,r,x,y,z,d,e,f,k,m,H,A,B,C,D,E,F,xx,yy,zz;
    t=1;
    //cin>>t;
    while (t--){  
        
        cin>>n;
        p=0;
        q=0;
        d=0;
        for(int i=1;i<=n;i++){
            cin>>x>>y;
            k=x-p;
            
            q=max(0,q-k);
            //q-=k;

            q+=y;
            p=x;
            d=max(d,q);
        }
        cout<<p+q<<' '<<d<<'\n';
        

    }    
} 