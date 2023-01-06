#include <bits/stdc++.h>
using namespace std;
int N, M, R;
int u , v;
vector<int> graph[100005];
int visited[100005];
queue<int> q;
int bfs(int n){
    int cnt = 1;
    q.push(n);
    visited[n] = 1;
    while(!q.empty()){
        int num = q.front();
        q.pop();
        for(int i = 0 ; i < graph[num].size(); i++){
            int tmp = graph[num][i];
            if(!visited[tmp]){
                cnt++;
                q.push(tmp);
                visited[tmp] = cnt;
            }
        }
    }
    return 0;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> M >> R;
    for(int i = 0 ; i < M ; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 1; i <= N ; i++){
        sort(graph[i].begin(), graph[i].end());
    }
    bfs(R);
    for(int i = 1; i <= N ; i++){
        cout << visited[i] << "\n";
    }
    return 0;
}