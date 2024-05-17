
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


   void   sol()
   {
        string s,s1,s2,str;
        map<ll,ll>   my_map,map1,map2;
        map<ll,vector<ll>>  v_map,v_map1,v_map2;
        vector<ll>  v,v1,v2;
        vector<vector<ll>> vec,vec1,vec2;
          bool  found,found1;
         ll n,k,res,l,sum,sum0,sum1=0,sum2=0,limit,r,cur,num,num1,num2,val,val1,val2,rem,x,y,x1,x2,y1,y2,sz,sz1,sz2,z=0,o=1,total,max_num,
         min_num,max1,max2,min1,min2,total1,total2,index,index1,index2,ind,ind1,ind2,left,right,mid,left1,right1,mid1;


           cin>>n>>k;
           vector<ll>  arr(n);


             for(ll  &  a:arr)
                   cin>>a;


                   v=arr;

                     sorted(v);

                      min_num=v[0],max_num=v.back();


                        if(max_num-min_num>k)
                        {
                             NO;
                             return;
                        }


                          else
                          {
                                YES;

                              for(ll i=0;i<n;i++)
                              {
                                    for(ll j=1;j<=arr[i];j++)
                                    {
                                          if(j<=min_num)
                                             cout<<1<<" ";

                                            else  cout<<j-min_num<<" ";
                                    }
                                          cout<<"\n";
                              }

                          }


   }


    int main()
    {

              ios_base::sync_with_stdio(false);
              cin.tie(NULL);
              sol();
    }

