#include <bits/stdc++.h>
using namespace std;
int N;
int arr[10005];
int DP[10005][2];
vector<int> graph[10005];
int visited[10005];
vector<int> ans;
int answer;
int dfs(int num){
    if(visited[num]){
        for(int i = 0 ; i < graph[num].size(); i++){
            if(visited[graph[num][i]] == 0){
                visited[graph[num][i]] = 1;
                dfs(graph[num][i]);
                DP[num][0] += max(DP[graph[num][i]][1] ,DP[graph[num][i]][0]);
                DP[num][1] += DP[graph[num][i]][0];
            }
        }
    }
    return 0;
}



int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    for(int i = 1 ; i <= N; i++){
        cin >> arr[i];
        DP[i][1] = arr[i];
    }
    int u, v;
    for(int i = 0 ; i < N-1;i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    visited[1] = 1;
    dfs(1);
    answer = max(DP[1][0], DP[1][1]);
    cout << answer << "\n";
    return 0;
}