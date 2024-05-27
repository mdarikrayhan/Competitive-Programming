

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
  #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace   __gnu_pbds;


  template<class  T> using  oset=tree<T,null_type,less<T>,
  rb_tree_tag,tree_order_statistics_node_update>;


    ll  modul;


   void   sol()
   {
        string s,s1,s2,str;
        map<ll,ll>   my_map,map1,map2;
        map<ll,vector<ll>>  v_map,v_map1,v_map2;
        vector<ll>  v1,v2;
        vector<vector<ll>> vec,vec1,vec2;
          bool  found,found1;
         ll n,m,res,l,sum,sum0,sum1=0,sum2=0,cur1,limit,r,cur,num,num1,num2,val,val1,val2,rem,x,y,x1,x2,y1,y2,sz,sz1,sz2,z=0,o=1,total,max_num,
         min_num,max1,max2,min1,min2,total1,total2,index,index1,index2,ind,ind1,ind2,left,right,mid,left1,right1,mid1,streak;

          str="";


           vector<oset<ll>>  v(62);

              oset<ll>  st;

                 cin>>n>>m;
           cin>>s;


             for(ll i=0;i<n;i++)
                    st.ins(i);

             for(ll i=0;i<n;i++)
             {

                if(s[i]>='a'  &&  s[i]<='z')
                      num=s[i]-'a';

                  else  if(s[i]>='A'  &&  s[i]<='Z')
                      num=26+s[i]-'A';

                    else  num=52+s[i]-'0';

                      v[num].ins(i);
             }


             ll   arr[m][2];
              char c;


                 for(ll i=0;i<m;i++)
                 {
                       cin>>arr[i][0]>>arr[i][1]>>c;

                         arr[i][0]--;
                           arr[i][1]--;


                               if(c>='a'  &&  c<='z')
                      num=c-'a';

                  else  if(c>='A'  &&  c<='Z')
                      num=26+c-'A';

                    else  num=52+c-'0';


                      if(st.size()>0)
                      {
                         l=*st.find_by_order(arr[i][0]);
                          r=*st.find_by_order(arr[i][1]);


                            if(v[num].size()>0)
                            {


                         left=0,right=v[num].size()-1,index1=-1,index2=-1;


                           while(left<=right)
                           {
                                 mid=(left+right)/2;

                                   cur=*v[num].find_by_order(mid);

                                    if(cur<l)
                                          left=mid+1;

                                    else if(cur>r)
                                          right=mid-1;

                                      else
                                      {
                                           index1=mid;
                                            right=mid-1;

                                      }
                           }
                               left=0,right=v[num].size()-1;

                             while(left<=right)
                           {
                                 mid=(left+right)/2;

                                   cur=*v[num].find_by_order(mid);

                                    if(cur<l)
                                          left=mid+1;

                                    else if(cur>r)
                                          right=mid-1;

                                      else
                                      {
                                           index2=mid;
                                           left=mid+1;

                                      }
                           }

                             if(index1!=-1)
                             {
                                  v1.clear();


                                    for(ll j=index1;j<=index2;j++)
                                    {
                                          cur1=*v[num].find_by_order(j);
                                            v1.pb(cur1);
                                    }


                                         for(ll j=0;j<v1.size();j++)
                                         {
                                               v[num].erase(v[num].find(v1[j]));
                                                 st.erase(st.find(v1[j]));
                             }
                      }
                            }
                 }
                 }


                  if(st.size()>0)
                  {
                        for(ll i=0;i<st.size();i++)
                        {
                               cur=*st.find_by_order(i);
                                 str+=s[cur];

                        }
                  }

                   cout<<str<<endl;

   }





    int main()
    {

              ios_base::sync_with_stdio(false);
              cin.tie(NULL);
              sol();
    }


