#include <iostream>
using namespace std;

const int N=1e6;
int result[N];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
    int n,track=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    while(track<n){
        if(arr[track]==0) break;
        else track++;
    }
    int track2=track-1,count=1;
    while(track2>=0){
        result[track2]=count,count++,track2--;
    }
    track2=track;
    while(track<n){
        count=0;
        while(arr[track]==0&&track<n){
            track++,track2=track-1;
        }
        while(arr[track]!=0&&track<n){
            count++,result[track]=count,track++;
        }
        if(track<n){
            count=0;
            int track3=track-1;
            while(track3>track2){
                count++;
                if(result[track3]>count)result[track3]=count,track3--;
                else break; 
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<result[i]<<" ";
    }
    return 0;
}