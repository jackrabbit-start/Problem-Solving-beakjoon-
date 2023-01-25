#include <bits/stdc++.h>
using namespace std;
int N;
int u, v;
vector<int> graph[1000002];
int visited[1000005];
int DP[1000005];
int ans;
int dfs(int num){
    if(visited[num]){
        int checking = 0;
        for(int i = 0 ; i < graph[num].size(); i++){
            int nxt = graph[num][i];
            if(!visited[nxt]){
                visited[nxt] = 1;
                dfs(nxt);
                if(DP[nxt] == 0) checking = 1;
            }
        }
        if(checking) {DP[num] = 1; ans++;}
    }
    return 0;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    for(int i = 0 ; i < N-1; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    visited[1] = 1;
    dfs(1);
    cout << ans;
    return 0;
}