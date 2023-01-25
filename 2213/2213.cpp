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

void tracking(int num, int tmp){
    if(visited[num]){
        int includ;
        if(tmp == 0){
            includ = 1;
        }
        else if(tmp == 1 && DP[num][1] > DP[num][0]){
            includ = 0;
            ans.push_back(num);
        }
        else{
            includ = 1;
        }
        for(int i = 0 ; i < graph[num].size(); i++){
            if(visited[graph[num][i]] == 0){
                visited[graph[num][i]] = 1;
                tracking(graph[num][i], includ);
            }
        }
    }
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
    fill(&visited[0], &visited[10004],0);
    visited[1]=1;
    if(DP[1][1] > DP[1][0]) tracking(1,1);
    else tracking(1,0);
    answer = max(DP[1][0], DP[1][1]);
    cout << answer << "\n";
    sort(ans.begin(), ans.end());
    for(int i = 0 ; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}