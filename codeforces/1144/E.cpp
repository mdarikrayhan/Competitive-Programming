#include<bits/stdc++.h>
using namespace std;

string gj_minus(string a, string b, int jz) {
    vector<int> c,d,e;
    int lena=a.size(),lenb=b.size();
    if(lena<lenb || (lena==lenb && a<b)){
        cout<<"-";
        swap(a,b);
        swap(lena,lenb);
    }
    
    int n=max(lena,lenb);
    c.resize(n, 0);
    d.resize(n, 0);
    e.resize(n, 0);
    
    for(int i=0;i<lena;i++){
        c[i]=a[lena-1-i]-'a';
    }
    for(int i=0;i<lenb;i++){
        d[i]=b[lenb-1-i]-'a';
    }
    
    for(int i=0;i<n;i++){
        e[i]+=c[i]-d[i];
        if(e[i]<0){
            e[i]+=jz;
            e[i+1]-=1;
        }
    }
    while(e[n-1]==0 && n>1){
        n--;
    }
    string result="";
    for(int i=n-1;i>=0;i--){
        result+=char(e[i]+'a');
    }
    return result;
}

string gj_chufa(string a, int b, int jz){
    vector<int> c,d,e;
    int lena=a.size();
    c.resize(lena, 0);
    e.resize(lena, 0);
    for(int i=0;i<lena;i++){
        c[i]=a[i]-'a';
    }
    int x=0;
    for(int i=0;i<lena;i++){
        e[i]=(x*jz+c[i])/b;
        x=(x*jz+c[i])%b;
    }
    int n=0;
    while(e[n]==0 && n<lena-1){
        n++;
    }
    string result="";
    for(int i=n;i<lena;i++){
        result+=char(e[i]+'a');
    }
    return result;
}

string gj_jiafa(string a, string b, int jz){
    vector<int> c,d,e;
    int n=max(a.size(),b.size());
    c.resize(n, 0);
    d.resize(n, 0);
    e.resize(n+1, 0);
    
    for(int i=0;i<a.size();i++){
        c[i]=a[a.size()-1-i]-'a';
    }
    for(int i=0;i<b.size();i++){
        d[i]=b[b.size()-1-i]-'a';
    }
    
    for(int i=0;i<n;i++){
        e[i]+=c[i]+d[i];
        if(e[i]>=jz){
            e[i+1]+=1;
            e[i]=e[i]%jz;
        }
    }
    if(e[n]!=0){
        cout<<e[n];
    }
    string result="";
    for(int i=n-1;i>=0;i--){
        result+=char(e[i]+'a');
    }
    return result;
}

int main(){
    int k;
    cin>>k;
    string a,b;
    cin>>b>>a;
    cout<<gj_jiafa(b, gj_chufa(gj_minus(a, b, 26), 2, 26), 26);
    return 0;
}

/**
* @runId: 387656
* @language: GNU G++14
* @author: 徐子腾
* @submitTime: 2024-05-07 18:45:02
*/
  	 	 	  			   	 	 		       	 	