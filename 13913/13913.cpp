#include <bits/stdc++.h>
using namespace std;
int N, K;
int visited[100005];
int trace[100005];
deque<int> v;
queue<int> q;
void bfs(int start){
    visited[start] = 0;
    trace[start] = start;
    q.push(start);
    while(!q.empty()){
        int now = q.front();
        if(now == K) return;
        q.pop();
        if(now+1 <= 100000 && visited[now+1] > visited[now] + 1 ){
            trace[now+1] = now;
            visited[now+1] = visited[now] + 1;
            q.push(now+1);
        }
        if(now-1 >= 0 && visited[now-1] > visited[now] + 1 ){
            trace[now-1] = now;
            visited[now-1] = visited[now] + 1;
            q.push(now-1);
        }
        if(2*now <= 100000 && visited[now*2] > visited[now] + 1 ){
            trace[now*2] = now;
            visited[now*2] = visited[now] + 1;
            q.push(now*2);
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> K;
    fill(&visited[0], &visited[100003], INT_MAX);
    fill(&trace[0], &trace[100003], -1);
    bfs(N);
    int ans = visited[K];
    cout << ans << "\n";
    int tmp = K;
    while(tmp != trace[tmp]){
        v.push_front(tmp);
        tmp = trace[tmp];
    }
    v.push_front(N);
    for(int i = 0 ; i < v.size(); i++){
        cout << v[i] << " ";
    }
    return 0;
}