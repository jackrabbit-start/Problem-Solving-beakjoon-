#include <bits/stdc++.h>
using namespace std;
int T;
int N, M, t;
int g, h;
int s, e , w;
int start;
int input;
vector<pair<int, int>> graph[2020];
int dis1[2020];
int dis2[2020];
int dis3[2020];
vector<int> ans;

void Dijkstra(int starting, int* arr){
    arr[starting] = 0;
    priority_queue<tuple<int , int> , vector<tuple<int , int>> , greater<tuple<int , int>>> pq;
    pq.push({0, starting});
    while(!pq.empty()){
        int now = get<1>(pq.top());
        int now_dis = get<0>(pq.top());
        pq.pop();
        if(arr[now] < now_dis) continue;
        for(auto &iter : graph[now]){
            if(arr[iter.first] > iter.second + now_dis){
                arr[iter.first] = now_dis + iter.second;
                pq.push({now_dis + iter.second, iter.first});
            }
        }
    }

}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> T;
    while(T--){
        fill(dis1, dis1+2010, INT_MAX);
        fill(dis2, dis2+2010, INT_MAX);
        fill(dis3, dis3+2010, INT_MAX);
        ans.clear();
        for(int i = 0 ; i < 2010 ; i++){
            graph[i].clear();
        }
        cin >> N >> M >> t;
        cin >> start >> g >> h;
        for(int i = 0 ; i < M ; i++){
            cin >> s >> e >> w;
            graph[s].push_back({e,w});
            graph[e].push_back({s,w});
        }
        for(int i = 0 ; i < t; i++){
            cin >> input;
            ans.push_back(input);
        }
        Dijkstra(start, dis1);
        Dijkstra(g, dis2);
        Dijkstra(h, dis3);
        sort(ans.begin(), ans.end());
        for(auto &iter : ans){
            if(dis1[iter] == (dis1[g] + dis2[h] + dis3[iter]) || dis1[iter] == (dis1[h] + dis3[g] + dis2[iter])){
                cout << iter << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}