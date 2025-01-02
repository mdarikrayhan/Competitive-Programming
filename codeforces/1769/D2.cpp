#include<bits/stdc++.h>
using namespace std;
string s[18][2];
char c[9]={'6','7','8','9','T','J','Q','K','A'},cc[4]={'C','D','S','H'};
int seq[12]={1,7,6,5,10,16,15,14,2,4,11,13},seq2[4]={0,8,9,17};
void otp(){
	int i,j;
	for(i=0;i<2;i++)
	{
		for(j=0;j<18;j++)cout<<s[j][i]<<' ';
		cout<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int k,i,j;
	for(i=0;i<2;i++)
	{
		for(j=0;j<18;j++)
		{
			s[j][i].push_back(c[j%9]);
			s[j][i].push_back(cc[i*2+j/9]);
		}
	}
	for(i=0;i<4;i++)swap(s[seq2[i]][0],s[seq2[i]][1]);
	cin>>k;
	otp();
	for(i=1;i<k;i++)
	{
		cout<<'\n';
		swap(s[seq[i-1]][0],s[seq[i-1]][1]);
		otp();
	}
	return 0;
}