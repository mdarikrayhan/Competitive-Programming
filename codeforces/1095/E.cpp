
 #include<iostream>
  #include<bits/stdc++.h>
  using namespace  std;
 typedef long long ll;
  typedef unsigned long long ull;
  typedef long long  int lli;
  #define  pb   push_back
  #define  ins insert
  #define YES cout<<"YES"<<endl
  #define NO cout<<"NO"<<endl
  #define Yes cout<<"Yes"<<endl
  #define No cout<<"No"<<endl
  #define sorted(k) sort(k.begin(),k.end())
  #define rsorted(k) sort(k.rbegin(),k.rend())
  #define reversed(k) reverse(k.begin(),k.end())

    ll  modul;


   void   sol()
   {
        string s,s1,s2,str;
        map<ll,ll>   my_map,map1,map2;
        map<ll,vector<ll>>  v_map,v_map1,v_map2;
        vector<ll>  v1,v2;
        vector<vector<ll>> vec,vec1,vec2;
          bool  found,found1;
         ll n,res=0,l,sum,sum0,sum1=0,sum2=0,limit,r,cur,num,num1,num2,val,val1,val2,rem,x,y,x1,x2,y1,y2,sz,sz1,sz2,z=0,o=1,total,max_num,
         min_num,max1,max2,min1,min2,total1,total2,index,index1,index2,ind,ind1,ind2,left,right,mid,left1,right1,mid1,streak;


           cin>>n>>s;

             vector<ll>  v(n),suff(n);

                sum=0;

                  for(ll i=0;i<n;i++)
                  {
                        sum+=s[i]=='(';
                          sum-=s[i]==')';
                            v[i]=sum;
                  }

                   min_num=v.back();



                          for(ll i=n-1;i>=0;i--)
                          {
                              min_num=min(min_num,v[i]);
                                suff[i]=min_num;
                          }


                            for(ll i=0;i<n;i++)
                            {
                                  s[i]=='('?num=-2:num=2;
                                  found=1;
                                     res+=v[i]+num>=0  &&   suff[i]+num>=0  && v.back()+num==0;

                                    if(v[i]<0)
                                          break;
                            }

                             cout<<res<<endl;
   }


    int main()
    {

              ios_base::sync_with_stdio(false);
              cin.tie(NULL);
              sol();
    }



