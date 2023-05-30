#include <bits/stdc++.h>
using namespace std;
int V, E;
vector<int> graph[10010];
int visited[10010];
int finished[10010];
stack<int> st;
vector<set<int>> ans;
int id;

int dfs(int now){
    visited[now] = ++id;
    st.push(now);
    int result = visited[now];
    for(int nxt : graph[now]){
        if(visited[nxt] == 0) result = min(result, dfs(nxt));
        else if(finished[nxt] == 0) result = min(result, visited[nxt]);
    }
    if(result == visited[now]){
        set<int> answer;
        while(!st.empty()){
            int tmp = st.top();
            st.pop();
            finished[tmp] = 1;
            answer.insert(tmp);
            if(tmp == now) break;
        }
        ans.push_back(answer);
    }
    return result;
}


int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> V >> E;
    for(int i = 0 ; i < E; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    for(int i = 1; i <= V ; i++){
        if(visited[i] == 0) dfs(i);
    }
    cout << ans.size() << "\n";
    sort(ans.begin(), ans.end());
    for(int i = 0 ; i < ans.size(); i++){
        for(auto iter = ans[i].begin() ; iter != ans[i].end(); iter++){
            cout << *iter << " ";
        }
        cout << "-1\n";
    }
    return 0;
}