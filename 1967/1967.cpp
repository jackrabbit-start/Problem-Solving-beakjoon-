#include <bits/stdc++.h>
using namespace std;
int V;
int s, e, w;
vector<pair<int ,int>> graph[100005];
int visited[100005][2];
int maxing;
int max_num;

void bfs(int start, int idx){
    queue<int> q;
    visited[start][idx] = 0;
    q.push(start);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = 0 ; i < graph[now].size(); i++){
            int nxt = graph[now][i].first;
            int dis = graph[now][i].second;
            if(visited[nxt][idx] == -1 ){
                visited[nxt][idx] = visited[now][idx] + dis;
                if(visited[nxt][idx] > maxing){
                    maxing = visited[nxt][idx];
                    max_num = nxt;
                }
                q.push(nxt);
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> V;
    fill(&visited[0][0], &visited[100003][1], -1);
    for(int i = 1 ; i < V; i++){
        cin >> s >> e >> w;
        graph[s].push_back(make_pair(e, w));
        graph[e].push_back(make_pair(s, w));
    }
    bfs(1, 0);
    maxing = 0;
    bfs(max_num, 1);
    cout << maxing;
    return 0;
}