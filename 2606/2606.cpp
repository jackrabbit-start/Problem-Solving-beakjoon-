#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> graph[105];
int visited[105];
int u, v;
queue<int> q;
void bfs(int n){
    q.push(n);
    while(!q.empty()){
        int num = q.front();
        q.pop();
        if(visited[num]) continue;
        visited[num] = 1;
        for(int i = 0 ; i < graph[num].size(); i++){
            int nxt = graph[num][i];
            if(!visited[nxt]){
                q.push(nxt);
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0 ; i < M ; i++){
        cin >> u >> v;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    bfs(1);
    int ans = 0;
    for(int i = 1; i <= N ; i++){
        if(visited[i]) ans++;
    }
    cout << ans-1;
    return 0;
}