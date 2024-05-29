#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353



struct segtree_min
{
    vector<int> v;

    void init(int n)
    {
        int curr=1;
        while(curr<n){curr=curr*2;}
        for(int i=0;i<2*curr;i++)
            {
                v.push_back(0);
            }
    }

    void update(int lx,int rx,int curr,int i,int z)
    {
        if(rx-lx==1){v[curr]+=z;return;}
        int m=(lx+rx)/2;
        if(i<m)
            {
                update(lx,m,2*curr+1,i,z);
            }
        else
            {
                update(m,rx,2*curr+2,i,z);
            }
        v[curr]=min(v[2*curr+1],v[2*curr+2]);
    }

    int getans(int lx,int rx,int curr,int l,int r)
    {
        if(lx>=l && rx<=r){return v[curr];}
        if(l>=rx || lx>=r){return 1e12;}

        int m=(lx+rx)/2;
        return min(getans(lx,m,2*curr+1,l,r),getans(m,rx,2*curr+2,l,r));
    }

    void clear()
    {
        v.clear();
    }
};


struct segtree_max
{
    vector<int> v;

    void init(int n)
    {
        int curr=1;
        while(curr<n){curr=curr*2;}
        for(int i=0;i<2*curr;i++)
            {
                v.push_back(0);
            }
    }

    void update(int lx,int rx,int curr,int i,int z)
    {
        if(rx-lx==1){v[curr]+=z;return;}
        int m=(lx+rx)/2;
        if(i<m)
            {
                update(lx,m,2*curr+1,i,z);
            }
        else
            {
                update(m,rx,2*curr+2,i,z);
            }
        v[curr]=max(v[2*curr+1],v[2*curr+2]);
    }

    int getans(int lx,int rx,int curr,int l,int r)
    {
        if(lx>=l && rx<=r){return v[curr];}
        if(l>=rx || lx>=r){return -1e12;}

        int m=(lx+rx)/2;
        return max(getans(lx,m,2*curr+1,l,r),getans(m,rx,2*curr+2,l,r));
    }

    void clear()
    {
        v.clear();
    }
};



struct segtree_max st_max;
struct segtree_min st_min;


int seive[1000005];

int a[1000005];

void my_swap(int i,int j,int groups)
{
    st_max.update(0,groups,0,i%groups,-a[i]);
    st_min.update(0,groups,0,i%groups,-a[i]);
    st_max.update(0,groups,0,j%groups,-a[j]);
    st_min.update(0,groups,0,j%groups,-a[j]);
    st_max.update(0,groups,0,i%groups,a[j]);
    st_min.update(0,groups,0,i%groups,a[j]);
    st_max.update(0,groups,0,j%groups,a[i]);
    st_min.update(0,groups,0,j%groups,a[i]);
    swap(a[i],a[j]);
}

pair<int,int> min_frac(pair<int,int> a,pair<int,int> b)
{
    if(a.first*b.second<a.second*b.first){return a;}
    return b;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    for(int i=2;i<=1000005;i++)
    {
        if(seive[i]==0)
        {
            seive[i]=i;
            for(int j=i*i;j<1000005;j+=i)
            {
                seive[j]=i;
            }
        }
    } 


    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        int godly[n];
        for(int i=0;i<n;i++){cin>>godly[i];}

        vector<int> primes;

        int c=n;

        while(c>1)
        {
            primes.push_back(seive[c]);
            int x=seive[c];
            while(c%x==0){c=c/x;}
        }

        pair<int,int> ans={1e9,1};

        for(auto x:primes)
        {
            st_max.clear();
            st_min.clear();
            st_max.init(x);
            st_min.init(x);
            for(int j=0;j<n;j++)
            {
                st_max.update(0,x,0,j%x,godly[j]);
                st_min.update(0,x,0,j%x,godly[j]);
                a[j]=godly[j];
            }

            for(int i=0;i<n-1;i++)
            {
                //swap a[i] with a[i+1]
                int maxa=st_max.getans(0,x,0,0,x);
                int mina=st_min.getans(0,x,0,0,x);
                ans=min_frac(ans,make_pair(maxa,mina));

                my_swap(i,i+1,x);

               maxa=st_max.getans(0,x,0,0,x);
                mina=st_min.getans(0,x,0,0,x);
                ans=min_frac(ans,make_pair(maxa,mina));             
            }
        }

        int g=__gcd(ans.first,ans.second);
        cout<<ans.first/g<<" "<<ans.second/g<<"\n";
    } 


   
   

}
