#include <bits/stdc++.h>
using namespace std;
int N, M, R;
int u,v;
int visited[100005];
vector<int> graph[100005];

int dfs(int start, int cnt){
    if(!visited[start]){
        visited[start] = cnt;
        cnt += 1;
        sort(graph[start].begin(), graph[start].end());
        for(int i = 0 ; i < graph[start].size(); i++){
            if(!visited[graph[start][i]]){
                cnt = dfs(graph[start][i], cnt);
            }
        }
    }
    return cnt;
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
    dfs(R, 1);
    for(int i = 1 ; i <= N ; i++){
        cout << visited[i] << "\n";
    }
    return 0;
}