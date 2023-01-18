#include <bits/stdc++.h>
using namespace std;
int N, M;
int arr[105][105];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int visited[105][105];
vector<tuple<int ,int,int ,int>> v;
priority_queue<tuple<int , int ,int >> pq;
int jointset[100];
int dis[10][10];
int Find(int n){
    if(jointset[n]== n) return n;
    return jointset[n] = Find(jointset[n]);
}

void Union(int x, int y){
    int xx = Find(x);
    int yy = Find(y);
    if(xx != yy){
        jointset[xx] = yy;
    }
    return;
}

void bfs(int x, int y, int cnt){
    visited[x][y] = cnt;
    queue<pair<int ,int>> q;
    q.push({x,y});
    while(!q.empty()){
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4; i++){
            int next_x = nx+dx[i];
            int next_y = ny+dy[i];
            if(arr[next_x][next_y] == 1 && visited[next_x][next_y] == 0){
                visited[next_x][next_y] = cnt;
                q.push({next_x, next_y});
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    fill(&dis[0][0], &dis[9][9], INT_MAX);
    cin >> N >> M;
    int number_island = 2;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j<= M ; j++){
            cin >> arr[i][j];
        }
    }
    int cnt = 1;
    for(int i = 1; i <= N ;i++){
        for(int j = 1; j <= M ;j++){
            if(visited[i][j] == 0 && arr[i][j] == 1){
                bfs(i,j, cnt);
                cnt++;
            }
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j<= M ; j++){
            if(visited[i][j] != 0){
                int now = visited[i][j];
                for(int k = i+1; k <= N ; k++){
                    if(visited[k][j] == now) break;
                    if(visited[k][j] != 0){
                        if(k-i > 2){
                        dis[now][visited[k][j]] = min(k-i-1, dis[now][visited[k][j]]);
                        }
                        break;
                    }
                }
                for(int k = j+1; k <= M ; k++){
                    if(visited[i][k] == now) break;
                    if(visited[i][k] != 0 ){
                        if(k-j > 2){
                        dis[now][visited[i][k]] = min(k-j-1, dis[now][visited[i][k]]);
                        }
                        break;
                    }
                }
            }
        }
    }
    for(int i = 1 ; i < cnt; i++){
        jointset[i] = i;
        for(int j = 1 ; j < cnt ; j++){
            if(dis[i][j] != INT_MAX){
                pq.push(make_tuple(-1*dis[i][j], i, j));
            }
        }
    }
    int ans =0;
    int count = 0;
    while(!pq.empty()){
        int dis = -1* get<0>(pq.top());
        int a = get<1>(pq.top());
        int b = get<2>(pq.top());
        pq.pop();
        if(Find(a) != Find(b)){
            Union(a,b);
            ans += dis;
            count++;
        }
    }
    if(count != cnt-2) cout<< "-1";
    else cout << ans;
    return 0;
}