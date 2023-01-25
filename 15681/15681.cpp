#include <bits/stdc++.h>
using namespace std;
int N, R , Q;
int u, v;
vector<int> graph[100005];
int visited[100005];
int numbers[100005];
int dfs(int num){
    if(visited[num]){
        numbers[num] = 1;
        for(int i = 0 ; i < graph[num].size() ; i++){
            if(visited[graph[num][i]] == 0){
                visited[graph[num][i]] = 1;
                numbers[num] += dfs(graph[num][i]);
            }
        }
    }
    return numbers[num];
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> R >> Q;
    for(int i = 1 ; i < N ; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    visited[R] = 1;
    dfs(R);
    int input;
    for(int i = 0 ; i < Q; i++){
        cin >> input;
        cout << numbers[input] <<"\n";
    }
    return 0;
}