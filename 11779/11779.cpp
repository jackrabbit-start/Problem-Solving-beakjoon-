#include <bits/stdc++.h>
using namespace std;
int N, M;
int visited[1005];
int trace[1005];
vector<pair<int, int>> graph[1004];
int s, e, w;
int start, ending;
priority_queue<tuple<int, int, int> , vector<tuple<int, int, int>>, greater<tuple<int ,int, int>>> pq;
deque<int> ans;

int Dijkstra(int start_n){
    trace[start_n] = start_n;
    pq.push({0, start_n, start_n});
    while(!pq.empty()){
        int now = get<1>(pq.top());
        int dis = get<0>(pq.top());
        int past = get<2>(pq.top());
        pq.pop();
        if(visited[now] != INT_MAX) continue;
        visited[now] = dis;
        trace[now] = past;
        for(int i = 0 ; i < graph[now].size(); i++){
            int nxt = graph[now][i].first;
            int ndis = graph[now][i].second;
            if(visited[nxt] == INT_MAX){
                pq.push(make_tuple( ndis + visited[now] , nxt , now));
            }
        }
    }
    return 0;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> M;
    fill(&visited[0] , &visited[1003], INT_MAX);
    fill(&trace[0] , &trace[1003], -1);
    for(int i = 0 ; i < M; i++){
        cin >> s >> e >> w;
        graph[s].push_back(make_pair(e,w));
    }
    cin >> start >> ending;
    Dijkstra(start);
    int tmp = ending;
    
    while(tmp != trace[tmp]){
        ans.push_front(tmp);
        tmp = trace[tmp];
    }
    ans.push_front(start);
    cout << visited[ending] << "\n";
    cout << ans.size() << "\n";
    for(int i = 0 ; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}