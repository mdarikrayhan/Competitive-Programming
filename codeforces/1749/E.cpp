// LUOGU_RID: 160444257
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
vector<int> dist[N],pre[N];
int n,m;
int dx[8] = {0,1,0,-1,-1,-1,1,1};
int dy[8] = {1,0,-1,0,-1,1,-1,1};
vector<char> ch[N];
deque<PII>q;
bool check(int x,int y){
	if(x < 1 || y < 1 || x > n || y > m) return false;
	for(int i = 0;i < 4;i ++){
		int fx = x + dx[i],fy = y + dy[i];
		if(fx >= 1 && fy >= 1 && fx <= n && fy <= m && ch[fx][fy] == '#') return false;
	}
	return true;
}
void init(){
	for(int i = 1;i <= n;i ++){
		dist[i].clear();
		pre[i].clear();
		ch[i].clear();
		for(int j = 0;j <= m;j ++){
			dist[i].push_back(INF);
			pre[i].push_back(0);
			ch[i].push_back('\0');
		}
	}
	q.clear();
}
int main(){
	int T; 
	cin >> T;
	while(T --){
		cin >> n >> m;
		init();
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= m;j ++) cin >> ch[i][j];	
		} 	
		for(int i = 1;i <= n;i ++){
			if(ch[i][1] == '#'){
				q.push_front({i,1});
				dist[i][1] = 0;
			}else if(check(i,1)){
				q.push_back({i,1});
				dist[i][1] = 1;
			}
		}
		while(!q.empty()){
			int x = q.front().first,y = q.front().second;
			q.pop_front();
			for(int i = 4;i < 8;i ++){
				int fx = x + dx[i],fy = y + dy[i];
				if(!check(fx,fy)) continue;
				int w = (ch[fx][fy] == '.');
				if(dist[x][y] + w < dist[fx][fy]){
					dist[fx][fy] = dist[x][y] + w;
					pre[fx][fy] = i;
					if(w) q.push_back({fx,fy});
					else q.push_front({fx,fy});
				}
			}
		}	
		int minn = INF,pos = -1;
		for(int i = 1;i <= n;i ++){
			if(dist[i][m] < minn){
				minn = dist[i][m];
				pos = i;
			} 
		} 
		if(minn >= INF){
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		int x = pos,y = m;
		while(1){
			ch[x][y] = '#';
			if(!pre[x][y]) break;
			int pres = pre[x][y];
			x -= dx[pres];
			y -= dy[pres];
		}
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= m;j ++) cout << ch[i][j];
			cout << "\n";
		}
	}
	return 0;
}