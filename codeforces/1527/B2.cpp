#include<bits/stdc++.h>
#define pub push_back
#define ll long long int
#define l long int
#define endl '\n'
#define modu 1000000007
#define fastio() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
string binary(int num){
      //converts the number to binary
      //and removes leading zeroes
    //  return bitset<32>(num).to_string().substr(32 - log2(num));
    string st="";
    while (num>0)
    {
        if(num &1)
        st+='1';
        else 
        st+='0';
        num=num>>1;
    }
    reverse(st.begin(),st.end());
    return st;
}
ll  fact(ll a)
{
    if (a==1 || a==0)
    {
        return 1;
    }
    else 
    {
        return (a*fact(a-1)%modu)%modu;
    }
}
int gcd(ll a,ll b)
{
    if (b==0)
    {
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}
void powwr(vector <int> curr,vector <vector<int>> &ans,vector <int> &inp,int indx )
{
    if (indx>=inp.size())
    {
        ans.push_back(curr);
        return;
    }
    powwr(curr, ans,inp, indx+1);
    curr.push_back(inp[indx]);
    powwr(curr,ans,inp, indx+1);

}/*to print all possible subarrays in extreme case
    vector <vector <int>> v1;
    vector <int> curr;
    powwr(curr,v1,v,0);-- >> to get vector of all possible vectors in v1 vector v is the input vector
        */
ll binary_expo(ll a,ll b)
{
    if (b==0)
    {
        return 1;
    }
    ll res=binary_expo(a,b/2);
    if (b%2)
    {
        return res*res*a;
    }
    else
    {
        return res*res;
    }
}
int main()
{
    fastio()
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int a,b,c,d;
        cin>>a;
        string st;
        cin>>st;
        bool bt=true;

        int cntunp=0;
        for (int j=0;j<a/2 + a%2;j++)
        {
            if (st[j]!=st[a-1-j])
            {
                bt=false;
                cntunp+=1;
                // break;
            }
        }
        if (!bt)
        {
            if (a%2==0)
            {
            // vector<int> vsin,vdou;
                set<int> ssin,sdou;
                for (int j=0;j<a/2 + a%2;j++)
                {
                    if (st[j]=='1')
                    {
                        if (st[a-1-j]!='1')
                        {
                            ssin.insert(a-1-j);
                        }
                    }
                    else if (st[j]=='0')
                    {
                        // ssin.insert(j);
                        if (st[a-1-j]!='1')
                        {
                            sdou.insert(j);
                            sdou.insert(a-1-j);
                        }
                        else
                        {
                            ssin.insert(j);
                        }
                    }
                }
                if (ssin.size()==0)
                {
                    cout <<"BOB"<<endl;
                }
                else{
                    cout <<"ALICE"<<endl;
                }
            }
            else
            {
                set<int> ssin,sdou;
                for (int j=0;j<a/2;j++)
                {
                    if (st[j]=='1')
                    {
                        if (st[a-1-j]!='1')
                        {
                            ssin.insert(a-1-j);
                        }
                    }
                    else if (st[j]=='0')
                    {
                    // ssin.insert(j);
                        if (st[a-1-j]!='1')
                        {
                            sdou.insert(j);
                            sdou.insert(a-1-j);
                        }
                        else
                        {
                            ssin.insert(j);
                        }
                    }
                }
                bool spe=false;
                if (st[round(a/2) ]=='0')
                {
                    spe=true;
                }
                // cout <<spe<<endl;
                if (!spe)
                {
                            if (ssin.size()==0)
                        {
                            cout <<"BOB"<<endl;
                        }
                        else{
                            cout <<"ALICE"<<endl;
                        }
                }
                else
                {
                    if ((ssin.size()==1) && (sdou.size()==0))
                    {
                        cout <<"DRAW"<<endl;
                    }
                    else if (sdou.size()==0) 
                    {
                        cout <<"ALICE"<<endl;
                    }
                    else
                    {
                        // continue;
                        cout <<"ALICE"<<endl;
                    }
                }
            }

        }
        else
        {
                if (a%2==0)
            {
                cout <<"BOB"<<endl;
            }
            else if (a==1)
            {
                cout <<"BOB"<<endl;
            }
            else
            {
                int cnt=0;
                for (int j=0;j<a;j++)
                {
                    if (st[j]=='0')
                    {
                        cnt+=1;
                    }
                }
                if (cnt==1)
                {
                    cout << "BOB"<<endl;
                }
    
                else if (cnt%2==0)
                {
                    cout <<"BOB"<<endl;
                }
                else
                {
                    cout <<"ALICE"<<endl;
                }
    
            }
        }

    } 
    return 0;

}