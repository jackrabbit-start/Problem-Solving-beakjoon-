#include <bits/stdc++.h>
using namespace std;
int N, M, V;
int u,v;
vector<int> graph[1010];
int visited_bfs[1010];
int visited_dfs[1010];
queue<int> q;

int dfs(int n, int cnt){
    if(!visited_dfs[n]){
        cout << n<< " ";
        visited_dfs[n]= cnt;
        cnt++;
        for(int i = 0 ; i < graph[n].size(); i++){
            if(!visited_dfs[graph[n][i]]){
                cnt = dfs(graph[n][i],cnt);
            }
        }
    }
    return cnt;
}

void bfs(int n){
    int cnt = 0;
    q.push(n);
    while(!q.empty()){
        int num = q.front();
        q.pop();
        if(visited_bfs[num]) continue;
        cnt++;
        visited_bfs[num] = cnt;
        cout << num <<" ";
        for(int i = 0 ; i < graph[num].size(); i++){
            int nxt = graph[num][i];
            if(!visited_bfs[nxt]){
                q.push(nxt);
            }
        }
    }
}


int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> M >> V;
    for(int i = 0 ; i < M ; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 1; i <=N; i++){
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(V,1);
    cout << "\n";
    bfs(V);
    return 0;
}