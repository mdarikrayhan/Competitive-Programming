#include <bits/stdc++.h>
#include <algorithm>
#include <string>

long int inf = 10e9+7;
//0 0 1 0 0
//0 1 3 4
//i   j
using namespace std;

int main(){
  long n, k; cin>>n>>k;
  string s; cin>>s;
  vector<long> arr;
  
  for(long i=0; i<n; i++){
    if(s[i] != '1')
      arr.push_back(i);
  } 

  long i = 0;
  long j = i+k;
  long fazendeiro = 0;
  long max_dist = inf;
  while(j < arr.size()){
    long de = arr[fazendeiro]-arr[i];
    long dd = arr[j]-arr[fazendeiro];

    if(max(de, dd) < max_dist){
      max_dist = max(de, dd);
    }

    if(dd>de){
      fazendeiro++;
    }else{
      i++;
      j++;
    }
  }
  cout<<max_dist<<endl;
}

 		 	 		  		   	  		  	   		 		