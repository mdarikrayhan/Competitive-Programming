// LUOGU_RID: 159882582
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<stack>
#include<ctime>
#include<cmath>
#include<cctype>
#include<bitset>
#include<vector>
#include<cstdio>
#include<random>
#include<climits>
#include<cstring>
#include<iostream>
#include<algorithm>
#define inf 0x3f3f3f3f
#define INF 1e9
#define LLINF 1e18
#define ll long long
#define N 100005
using namespace std;
int read(){
	int x=0,f=1,ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f=(ch=='-')?-1:1;
	for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
	return x*f;
}
void print(int x){
	if(x<0) putchar('-'),x=~(x-1);
	if(x>9) print(x/10);
	putchar(x%10+48);
}
int n;
bool check(vector<int>vec){
	multiset<int>s1,s2;
	for(int i:vec) s1.insert(i);
	for(int i=1;i<vec.size()-1;++i) s2.insert(vec[i-1]+vec[i+1]);
	s2.insert(vec[1]),s2.insert(vec[vec.size()-2]);
	return s1==s2;
}
int main(){
	n=read();
	if(n&1){
		if(n<7){
			puts("NO");
			return 0;
		}
		puts("YES");
		vector<int>vec={-5,-4,3,-1,-2};
		for(int i=0;i<5;++i) printf("%d ",vec[i]);
		vector<int>v={4,1,-1,3,-3,-4};
		for(int i=6;i<=n;++i) printf("%d ",v[i%6]);
		puts("");
	}
	else{
		puts("YES");
		int a=1,b=3;
		vector<int>vec={a,b,-b,a-b,b-a,-a};
		for(int i=0;i<n;++i) printf("%d ",vec[i%6]);
		puts("");
	}
	return 0;
}