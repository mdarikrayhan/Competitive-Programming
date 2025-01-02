// Hydro submission #66448f539ff061bfd2eebb2f@1715769172584
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int h,m;
	string s;
	cin>>s;
	h=stoi(s.substr(0,2));
	m=stoi(s.substr(3,2));
	while(1){
		string s3,s2;
		m++;
		if(m==60){ 
			m=0;
			h++;
			if(h==24){
				cout<<"00:00";
				break; 
			}
		}
		if(h<10){
			s3+='0';
			s3+=to_string(h)+':';
		}else{
			s3+=to_string(h)+':';
		}
		if(m<10){
			s3+='0';
			s3+=to_string(m);
		}else{
			s3+=to_string(m);
		}
		s2=s3;
		reverse(s2.begin(),s2.end());
		if(s2==s3){
			cout<<s2;
			break;
		}
	}
	return 0;
}