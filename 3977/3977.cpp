#include <bits/stdc++.h>
using namespace std;
int T;
int N, M;
vector<int> graph[100010];
int visited[100010];
int sccID[100010];
int sccindegree[100010];
int vID;
deque<int> st;
int scccnt = 1;

int dfs(int now){
    visited[now] = ++vID;
    st.push_front(now);
    int result = visited[now];
    for(int nxt : graph[now]){
        if(visited[nxt] == -1) result = min(result, dfs(nxt));
        else if(sccID[nxt] == -1) result = min(result, visited[nxt]);
    }
    if(result == visited[now]){
        while(!st.empty()){
            int tmp = st.front();
            st.pop_front();
            sccID[tmp] = scccnt;
            if(tmp == now) break;
        }
        scccnt++;
    }
    return result;
}


int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> T;
    while(T--){
        scccnt = 1;
        vID = 0;
        memset(visited, -1, sizeof(visited));
        memset(sccID, -1, sizeof(sccID));
        memset(sccindegree, 0, sizeof(sccindegree));
        st.clear();
        for(int i = 0 ; i <= N ; i++){
            graph[i].clear();
        }
        cin >> N >> M;
        for(int i = 0 ; i < M ; i++){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
        }
        for(int i = 0 ; i  < N ; i++){
            if(visited[i] == -1) dfs(i);
        }
        for(int i = 0; i < N ; i++){
            for(int to : graph[i]){
                if(sccID[i] != sccID[to]){
                    sccindegree[sccID[to]]++;
                }
            }
        }
        int ans = 0;
        int ansscc;
        for(int i = 1; i < scccnt; i++){
            if(sccindegree[i] == 0){
                ans++;
                ansscc = i;
            }
        }
        if(ans != 1){
            cout << "Confused\n";
        }
        else{
            vector<int> answer;
            for(int i = 0 ; i < N ; i++){
                if(sccID[i] == ansscc){
                    answer.push_back(i);
                }
            }
            sort(answer.begin(), answer.end());
            for(int i = 0 ; i < answer.size(); i++){
                cout << answer[i] << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}