#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,b,a) for(int i=(b);i>=(a);i--)
#define VS vector<string>
#define VVS vector<VS>
using namespace std;string s;
VS combine(VVS p){int mx=0,tot=0;rep(i,0,(int)p.size()-1)mx=max(mx,(int)p[i][0].size()),tot+=p[i].size()+1;int cnt=0;VS ret(--tot);
rep(i,0,(int)p.size()-1){rep(j,0,(int)p[i].size()-1){if(i+1==p.size()&&j>1)ret[cnt]+="   ";else ret[cnt]+=(j==1?"+->":"|  ");ret[cnt]+=p[i][j];
rep(k,p[i][j].size(),mx)ret[cnt]+=(j==1?"-":" ");if(i+1==p.size()&&j>1)ret[cnt++]+="  ";else ret[cnt++]+=(j==1?">+":" |");}
if(i+1<p.size()){ret[cnt]+="|";rep(j,1,mx+4)ret[cnt]+=" ";ret[cnt++]+="|";}}ret[0][0]=ret[0][mx+5]=' ';return ret;}
VS construct(VS p,char type){int siz=p.size(),len=p[0].size()+6;int t=(type=='?'?3:(type=='*'?5:2));VS ret(t+siz);
if(type=='?'||type=='*'){rep(i,1,len)ret[0]+=" ";ret[1]+="+";rep(i,2,len-2)ret[1]+="-";ret[1]+=">+";ret[2]+="|";rep(i,2,len-1)ret[2]+=" ";ret[2]+="|";
rep(i,3,siz+2){if(i>=5&&type=='?')ret[i]+="   ";else if(i==4)ret[i]+="+->";else ret[i]+="|  ";ret[i]+=p[i-3];if(i>=5&&type=='?')ret[i]+="   ";else if(i==4)ret[i]+="->+";else ret[i]+="  |";}
if(type=='*'){ret[siz+3]+="|";rep(i,2,len-1)ret[siz+3]+=" ";ret[siz+3]+="|";ret[siz+4]+="+<";rep(i,3,len-1)ret[siz+4]+="-";ret[siz+4]+="+";}
}else if(type=='+'){rep(i,0,siz-1){if(i==0)ret[i]+="   ";else if(i==1)ret[i]+="+->";else ret[i]+="|  ";ret[i]+=p[i];if(i==0)ret[i]+="   ";else if(i==1)ret[i]+="->+";else ret[i]+="  |";}
ret[siz]+="|";rep(i,2,len-1)ret[siz]+=" ";ret[siz]+="|";ret[siz+1]+="+<";rep(i,3,len-1)ret[siz+1]+="-";ret[siz+1]+="+";}return ret;}
VS link(VVS p){int mx=0;rep(i,0,(int)p.size()-1) mx=max(mx,(int)p[i].size());VS ret(mx);
rep(i,0,mx-1){rep(j,0,(int)p.size()-1){if(j)ret[i]+=(i==1?"->":"  ");if(p[j].size()>=i+1)ret[i]+=p[j][i];else rep(k,1,p[j][0].size())ret[i]+=" ";}}return ret;}
VS surround(int l,int r){ VS ret(3);ret[0]+="+",ret[2]+="+";rep(i,1,r-l+3)ret[0]+="-",ret[2]+="-";ret[0]+="+",ret[2]+="+";ret[1]+="+ ";rep(i,l,r)ret[1].push_back(s[i]);ret[1]+=" +";return ret;}
VS wrap(VS k,string oper){per(i,(int)oper.size()-1,0)k=construct(k,oper[i]);return k;}
VS work(int l,int r){if(l>r)return {};VVS p;bool distruct=false;int cnt=0,lst=l;
rep(i,l,r){if(s[i]=='(')cnt++;if(s[i]==')')cnt--;if(s[i]=='|'&&cnt==0){distruct=true;p.push_back(work(lst,i-1));lst=i+1;}}
if(distruct){p.push_back(work(lst,r));VS ret=combine(p);return ret;}lst=r;string wait="";
per(i,r,l){bool single=false;if(s[i]>='A'&&s[i]<='Z')if(wait.size())single=true;else continue;if(single){p.push_back(wrap(surround(i,i),wait));wait="",lst=i-1;continue;}
if(lst>i){p.push_back(surround(i+1,lst));}if(s[i]==')'){int t=i-1,cnt=0;while(cnt||s[t]!='('){if(s[t]==')')cnt++;if(s[t]=='(')cnt--;t--;}
p.push_back(wrap(work(t+1,i-1),wait));i=t,wait="";}else wait.push_back(s[i]);lst=i-1;}if(lst>=l)p.push_back(wrap(surround(l,lst),wait));reverse(p.begin(),p.end());VS ret=link(p);return ret;}
int main(){ios::sync_with_stdio(false);cin>>s;VS ans=work(0,(int)s.size()-1);cout<<ans.size()<<" "<<ans[0].size()+6<<endl;
rep(i,0,(int)ans.size()-1){if(i==1)cout<<"S->";else cout<<"   ";cout<<ans[i];if(i==1)cout<<"->F\n";else cout<<"   \n";}return 0;}