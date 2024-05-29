// LUOGU_RID: 147215675
#include<bits/stdc++.h>
std::map<std::string,std::string>mp;
std::string s="RRRRPSSPRR",k,S;
void init(){
	mp["1111000011"]="RRRRRRRRRR",
	mp["0000100100"]="PPPPPPPPPP",
	mp["0000011000"]="SSSSSSSSSS",
	mp["0010000010"]="SRPSRPSRPS",
	mp["0000110000"]="PSRPSRPSRP",
	mp["0000000110"]="SPRSPRSPRS";
}
main(){
	init();
	for(int i=0;i<10;i++){
		std::cout<<s[i]<<std::endl,std::cin>>k;
		if(k=="ai")S+="0";
		else S+="1";
	}
	s=mp[S];
	for(int i=0;i<10;i++)std::cout<<s[i]<<std::endl,std::cin>>k;
	return 0;
}
