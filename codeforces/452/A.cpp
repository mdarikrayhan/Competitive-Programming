#include <bits/stdc++.h>
using namespace std;

#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back
#define printvector(v) f(i,0,v.size()){cout<<v[i]<<' ';}
#define all(x) (x).begin(), (x).end()
#define ll long long
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Ajay cout.tie(NULL);
void solve(){
   int n;
   cin>>n;
   string s;
   cin>>s;
   if(n==8){
      cout<<"vaporeon";
      return;
   }
   if(n==6){
      cout<<"espeon";
      return;
   }
   if(n==7){
      if(s[0]=='j'||s[1]=='o'||s[2]=='l'||s[3]=='t'){
         if((s[2]=='l')&&(s[0]=='j'||s[1]=='o'||s[3]=='t')){
              cout<<"jolteon";
         }else if((s[2]=='l')&&(s[0]=='s'||s[1]=='y'||s[3]=='v')){
            cout<<"sylveon";
         }else{
            cout<<"jolteon";
         }
         return;
      }
      if(s[0]=='s'||s[1]=='y'||s[2]=='l'||s[3]=='v'){
         if((s[2]=='l')&&(s[0]=='j'||s[1]=='o'||s[3]=='t')){
              cout<<"jolteon";
         }else if((s[2]=='l')&&(s[0]=='s'||s[1]=='y'||s[3]=='v')){
            cout<<"sylveon";
         }else{
            cout<<"sylveon";
         }
         return;
      }
      if(s[1]=='l'||s[2]=='a'){
         if((s[1]=='l')&&(s[0]=='g'||s[3]=='c'||s[2]=='a')){
            cout<<"glaceon";
            return;
         }else if ((s[2]=='a')&&(s[0]=='g'||s[3]=='c'||s[1]=='l')){
            cout<<"glaceon";
            return;
         }else{
            if(s[0]=='f'||s[1]=='l'||s[2]=='a'||s[3]=='r'){
         if((s[2]=='a')&&(s[0]=='f'||s[1]=='l'||s[3]=='r')){
              cout<<"flareon";
         }else if((s[3]=='r')&&(s[0]=='u'||s[1]=='m'||s[2]=='b')){
              cout<<"umbreon";
         }else if((s[2]=='a')&&(s[0]=='l'||s[1]=='e'||s[3]=='f')){
            cout<<"leafeon";
         }else{
            cout<<"flareon";
         }
         return;
      }
      if(s[0]=='l'||s[1]=='e'||s[2]=='a'||s[3]=='f'){
         if((s[2]=='a')&&(s[0]=='f'||s[1]=='l'||s[3]=='r')){
              cout<<"flareon";
         }else if((s[2]=='a')&&(s[0]=='l'||s[1]=='e'||s[3]=='f')){
            cout<<"leafeon";
         }else{
            cout<<"leafeon";
         }
         return;
      }
         }
      }
      if(s[0]=='f'||s[1]=='l'||s[2]=='a'||s[3]=='r'){
         if((s[2]=='a')&&(s[0]=='f'||s[1]=='l'||s[3]=='r')){
              cout<<"flareon";
         }else if((s[3]=='r')&&(s[0]=='u'||s[1]=='m'||s[2]=='b')){
              cout<<"umbreon";
         }
         else if((s[2]=='a')&&(s[0]=='l'||s[1]=='e'||s[3]=='f')){
            cout<<"leafeon";
         }else{
            cout<<"flareon";
         }
         return;
      }
      if(s[0]=='l'||s[1]=='e'||s[2]=='a'||s[3]=='f'){
         if((s[2]=='a')&&(s[0]=='f'||s[1]=='l'||s[3]=='r')){
              cout<<"flareon";
         }else if((s[2]=='a')&&(s[0]=='l'||s[1]=='e'||s[3]=='f')){
            cout<<"leafeon";
         }else{
            cout<<"leafeon";
         }
         return;
      }
      if(s[0]=='u'||s[1]=='m'||s[2]=='b'||s[3]=='r'){
         if((s[3]=='r')&&(s[0]=='u'||s[1]=='m'||s[2]=='b')){
              cout<<"umbreon";
         }else if((s[3]=='r')&&(s[0]=='f'||s[1]=='l'||s[2]=='a')){
            cout<<"flareon";
         }else{
            cout<<"umbreon";
         }
         return;
      }
      

      // if(s[0]=='l'||s[1]=='e'||s[3]=='f'){
      //    cout<<"sylveon";
      //    return;
      // }
      // if(s[0]=='f'||s[1]=='l'||s[3]=='r'){
      //    cout<<"sylveon";
      //    return;
      // }
   }
}
int main()
{
Code By Ajay
int t;
t=1;
while(t--){
solve();
}
   
   return 0;
}