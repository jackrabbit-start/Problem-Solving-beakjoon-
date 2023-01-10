#include <bits/stdc++.h>
using namespace std;
int N, M;
int A, B, C;
vector<tuple<int ,int ,int>> edge;
int dis[800];

int Bellman_ford(int start){
    dis[start] = 0;
    for(int i = 0 ; i <= N ; i++){
        for(int j = 0 ; j < M ; j++){
            int now = get<0>(edge[j]);
            int next = get<1>(edge[j]);
            int weight = get<2>(edge[j]);
            if(dis[now] != INT_MAX && dis[next] > dis[now] + weight){
                dis[next] = dis[now] + weight;
                if(dis[next] < -100000000) return 1; // bellman_ford 는 무한대로 내려갈때 값이 너무 작아질 수 있으므로 해둔 장치 (나올수 있는 가장 작은 값 = -6000만)
                if(i == N) return 1;
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
    fill(dis, dis+600 , INT_MAX);
    for(int i = 0 ; i < M ; i++){
        cin >> A >> B >> C;
        edge.push_back({A, B, C});
    }
    if(Bellman_ford(1)){
        cout << -1;
    }
    else{
        for(int i = 2; i<= N ;i++){
            if(dis[i] != INT_MAX) cout << dis[i] << "\n";
            else cout << "-1\n";
        }
    }
    return 0;
}