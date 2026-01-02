// #include<bits/stdc++.h>
// using ll = long long;
// using ull = unsigned long long;
// using u128 = unsigned __int128;
// using i128 = __int128;
// using namespace std;
// const int N = 40;
// int a[N][N];
// bool flag[N][N];
// int n;
// int dx[]={-1,1,0,0};
// int dy[]={0,0,-1,1};
// int cnt=2,cur=2;
// bool f[1000];

// void bfs(int x, int y) {
//     flag[x][y]=true;
//     queue<pair<int,int>> st;
//     if(x==1||x==n|| y==1||y==n) f[cnt]=true;
//     st.push({x, y});
//     while(st.size()) {
//         int x=st.front().first, y=st.front().second;
//         st.pop();
//         for(int i=0;i<4;i++) {
//             int xx=x+dx[i],yy=y+dy[i];
//             if(xx<1||xx>n||yy<1||yy>n)  continue;
//             if(flag[xx][yy])    continue;
//             if(a[xx][yy]==1)  continue;
//             flag[xx][yy]=true;
//             if(xx==1||xx==n|| yy==1||yy==n) f[cnt]=true;
//             st.push({xx, yy});
//         }
//     }

// }

// void bfs2(int x, int y) {
//     flag[x][y]=true;
//     a[x][y] = f[cur] ? 0 : 2;
//     queue<pair<int,int>> st;
//     st.push({x, y});
//     while(st.size()) {
//         int x=st.front().first, y=st.front().second;
//         st.pop();
//         for(int i=0;i<4;i++) {
//             int xx=x+dx[i],yy=y+dy[i];
//             if(xx<1||xx>n||yy<1||yy>n)  continue;
//             if(flag[xx][yy])    continue;
//             if(a[xx][yy]==1)  continue;
//             flag[xx][yy]=true;
//             a[xx][yy]=a[x][y];
//             st.push({xx, yy});
//         }
//     }

// }


// void solve() {
//     cin>>n;
//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=n;j++) {
//             cin>>a[i][j];
//         }
//     }   
//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=n;j++) {
//             if(a[i][j]==0&&!flag[i][j]) {
//                 bfs(i, j);
//                 cnt++;
//             } 
//         }
//     } 
//     //问题：不是到当前的0格子属于哪个连通块,
//     //第一次得到状态，第二次再走一遍bfs，实在难以描述不规则的连通标记
//     memset(flag, false, sizeof flag);
//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=n;j++) {
//             if(a[i][j]==0 &&!flag[i][j]) {
//                 bfs2(i, j);
//                 cur++; 
//             } 
//         }
//     } 

//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=n;j++) {
//             cout<<a[i][j]<<" ";
//         }
//         cout<<"\n";
//     }


// }

// signed main() {
// 	cin.tie(nullptr)->sync_with_stdio(false);	
// 	int _=1;
// 	//cin>>_;
// 	while(_ --){
// 		solve();
// 	} 
// }

#include<bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
using i128 = __int128;
using namespace std;
const int N = 40;
int a[N][N];
bool flag[N][N];
int n;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int cnt=2,cur=2;
bool f[1000];
void bfs(int x, int y) {
    flag[x][y]=true;
    queue<pair<int,int>> st;
    if(x==1||x==n|| y==1||y==n) f[cnt]=true;
    st.push({x, y});
    while(st.size()) {
        int x=st.front().first, y=st.front().second;
        st.pop();
        for(int i=0;i<4;i++) {
            int xx=x+dx[i],yy=y+dy[i];
            if(xx<1||xx>n||yy<1||yy>n)  continue;
            if(flag[xx][yy])    continue;
            if(a[xx][yy]==1)  continue;
            flag[xx][yy]=true;
            if(xx==1||xx==n|| yy==1||yy==n) f[cnt]=true;
            st.push({xx, yy});
        }
    }
}
void bfs2(int x, int y) {
    flag[x][y]=true;
    f[cur]==true? a[x][y]=0:a[x][y]=2;
    //赋值方式的三元表达式写错了，对于要被赋值的式子应该提前放到开头
    //a[x][y]=f[cur]?0:2;
    queue<pair<int,int>> st;
    st.push({x, y});
    while(st.size()) {
        int x=st.front().first, y=st.front().second;
        st.pop();
        for(int i=0;i<4;i++) {
            int xx=x+dx[i],yy=y+dy[i];
            if(xx<1||xx>n||yy<1||yy>n)  continue;
            if(flag[xx][yy])    continue;
            if(a[xx][yy]==1)  continue;
            flag[xx][yy]=true;
            a[xx][yy]=a[x][y];
            st.push({xx, yy});
        }
    }
}

void solve() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin>>a[i][j];
        }
    }   
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(a[i][j]==0&&!flag[i][j]) {
                bfs(i, j);
            } 
            cnt++;
        }
    } 
    //问题：不是到当前的0格子属于哪个连通块,
    //第一次得到状态，第二次再走一遍bfs，实在难以描述不规则的连通标记
    memset(flag, false, sizeof flag);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(a[i][j]==0 &&!flag[i][j]) {
                bfs2(i, j);
            } 
           cur++; 
        }
    } 
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}
signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);   
    int _=1;
    //cin>>_;
    while(_ --){
        solve();
    } 
}
