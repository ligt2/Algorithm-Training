#include<bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
using i128 = __int128;
using namespace std;
const int N = 1005;
char a[N][N];
int dist[N][N];
bool flag[N][N];
int n;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

void bfs(int x, int y) {
	queue<pair<int,int>> st;
	flag[x][y]=true;
	st.push({x, y});
	while(st.size()) {
		int fi=st.front().first, se=st.front().second;
		for(int i=0;i<4;i++) {
			int xx=fi+dx[i],yy=se+dy[i];
			if(xx<1||xx>n||yy<1||yy>n) continue;
			if(flag[xx][yy]) continue;
			if(a[xx][yy]=='1')	continue;
			flag[xx][yy]=true;
			dist[xx][yy]=dist[fi][se]+1;
			st.push({xx,yy});
		}
		st.pop();
	}

}

void solve() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			cin>>a[i][j];
		}
	}
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	bfs(x1, y1);
	cout<<dist[x2][y2];

}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);	
	int _=1;
	//cin>>_;
	while(_ --){
		solve();
	} 
}