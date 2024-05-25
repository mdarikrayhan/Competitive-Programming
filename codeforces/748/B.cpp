#include<bits/stdc++.h>
using namespace std;

int main(){
	string a,b;
	cin >> a >> b;
	
	if(a==b)
		cout << 0 << endl;
	else{
		
		int ans=0;
		string s="",same="";
		for(int i=0;i<b.length();i++){
			if(a[i]==b[i]){
				if(s.find(a[i])==-1){
					same+=a[i];
				}
				else{
					ans=-1;
					break;
				}
			}
			else{
				if(same.find(a[i])!=-1||same.find(b[i])!=-1){
					ans=-1;
					break;
				}
				else{
					int posa=s.find(a[i]);
					int posb=s.find(b[i]);
					
					if(posa==-1&&posb==-1){
						ans++;
						s+=a[i];
						s+=b[i];
					}
					else if(posa!=-1){
						if(posa%2==0){
							if(b[i]!=s[posa+1]){
								ans=-1;
								break;
							}
						}
						else{
							if(b[i]!=s[posa-1]){
								ans=-1;
								break;
							}
						}
					}
					else{
						if(posb%2==0){
							if(a[i]!=s[posb+1]){
								ans=-1;
								break;
							}
						}
						else{
							if(a[i]!=s[posb-1]){
								ans=-1;
								break;
								
							}	
						}	
					}
				}
			}
		}
		if(ans==-1)
			cout << ans << endl;
		else{
			cout << ans << endl;
			for(int i=0;i<s.length();i+=2){
				cout << s[i] << " " << s[i+1] << endl;
			}
		}
	}
}
	    			    	 						 	  					