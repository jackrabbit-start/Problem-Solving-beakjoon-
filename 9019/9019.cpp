#include <bits/stdc++.h>
using namespace std;
int T;
int A, B;
int visited[10005];
int trace[10005][2];
deque<int> ans;

void bfs(int start){
    queue<int> q;
    visited[start] = 0;
    q.push(start);
    trace[start][0] = start;
    int tmp;
    while(!q.empty()){
        int now = q.front();
        if(now == B) return;
        q.pop();
        if(visited[(now*2)%10000] > visited[now]+1){
            visited[(now*2)%10000] = visited[now]+1;
            trace[(now*2)%10000][0] = now;
            trace[(now*2)%10000][1] = 'D';
            q.push((now*2)%10000);
        }
        tmp = now-1;
        if(tmp == -1) tmp = 9999;
        if(visited[tmp] > visited[now] + 1){
            visited[tmp] = visited[now] + 1;
            trace[tmp][0] = now;
            trace[tmp][1] = 'S'; 
            q.push(tmp);
        }
        tmp = now*10;
        tmp += tmp/10000;
        tmp %= 10000;
        if(visited[tmp] > visited[now] + 1){
            visited[tmp] = visited[now]+1;
            trace[tmp][0] = now;
            trace[tmp][1] = 'L'; 
            q.push(tmp);
        }
        tmp = now;
        tmp += (now%10)*10000;
        tmp /= 10;
        if(visited[tmp] > visited[now] + 1){
            visited[tmp] = visited[now] + 1;
            trace[tmp][0] = now;
            trace[tmp][1] = 'R'; 
            q.push(tmp);
        }
    }
}
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> T;
    while(T--){
        ans.clear();
        fill(&visited[0], &visited[10003], INT_MAX);
        fill(&trace[0][0], &trace[10003][1], 0);
        cin >> A >> B;
        bfs(A);
        int tmp = B;
        while(tmp != trace[tmp][0]){
            ans.push_front(trace[tmp][1]);
            tmp = trace[tmp][0];
        }
        for(int i = 0 ; i < ans.size(); i++){
            cout << char(ans[i]);
        }
        cout <<"\n";
    }
    return 0;
}