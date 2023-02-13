#include <bits/stdc++.h>
using namespace std;
int N, M;
int indegree[50000];
int visited[50000];
vector<int> edge[50000];
vector<int> ans;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0 ; i < M ; i++){
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        indegree[b]++;
    }
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 1 ; i <= N; i++){
        if(indegree[i] == 0){
            visited[i] = 1;
            q.push(i);
            while(!q.empty()){
        int now = q.top();
        q.pop();
        ans.push_back(now);
        indegree[now]--;
        for(int i = 0 ; i < edge[now].size() ; i++){
            indegree[edge[now][i]]--;
            int next = edge[now][i];
            if(visited[next] == 0 && indegree[next] == 0){
                visited[next] = 1;
                q.push(next);
            }

            }
        }
        }
    }
    for(int i = 0 ; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}