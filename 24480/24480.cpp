#include <bits/stdc++.h>
using namespace std;
int N, M , R;
int u, r;
int visited[100005];
vector<int> graph[100005];


int dfs(int n, int cnt){
    if(!visited[n]){
        visited[n] = cnt;
        cnt++;
        sort(graph[n].rbegin(), graph[n].rend());
        for(int i = 0 ; i < graph[n].size(); i++){
            if(!visited[graph[n][i]]){
                cnt = dfs(graph[n][i],cnt);
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
        cin >> u >> r;
        graph[u].push_back(r);
        graph[r].push_back(u);
    }
    dfs(R,1);
    for(int i = 1; i <= N ; i++){
        cout << visited[i] << "\n";
    }

    return 0;
}