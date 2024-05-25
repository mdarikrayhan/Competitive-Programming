// LUOGU_RID: 160212729
//双方不是按单位时间瞬移!
#include<bits/stdc++.h>
using namespace std;
int main(){
	int vp,vd,t,f,c,ans=0;
	cin>>vp>>vd>>t>>f>>c;
	if(vp>=vd)return cout<<0,0;
	double disp=t*vp,disd=0;
	while(disp<c){
		double ti=(disp-disd)/(vd-vp);
		disp+=ti*vp,disd+=ti*vd;
		if(disp>=c)break;
		ans++,disp+=(f+disd/vd)*vp,disd=0;
	}
	return cout<<ans,0;
}