#include <iostream>
#include<vector>
#include<queue>

using namespace std;

int main()
{
    int x,y;cin>>x>>y;
    vector<int>v(x);
    queue<int>q;
    for(int i=0;i<x;i++){
        cin>>v[i];
        q.push(i);
    }
    while(q.size()>1){
        if(v[q.front()]<=y){
            q.pop();
        }
        else{
            v[q.front()]-=y;
            q.push(q.front());
            q.pop();
        }
    }
    cout<<q.front()+1;

    return 0;
}

  	        			 	  		   			