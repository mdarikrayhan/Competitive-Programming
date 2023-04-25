#include<iostream>
using namespace std;
int q,w,d,h;
int main()
{
cin>>q;
int a,b,f,g;
while(q--)
{
cin>>w>>d>>h>>a>>b>>f>>g;
cout<<min(min(a+f,2*w-a-f)+abs(b-g),min(b+g,2*d-b-g)+abs(a-f))+h<<endl;
}
}