#include <bits/stdc++.h>
using namespace std;
int N, K;
int visited[300010];
queue<int> q;

void bfs(int start){
    q.push(start);
    visited[start] = 1;
    while(!q.empty()){
        int n = q.front();
        q.pop();
        if(n<=100000 && !visited[n+1]){
            visited[n+1] = visited[n]+1;
            q.push(n+1);
        }
        if(n<=50000 && !visited[2*n]){
            visited[2*n] = visited[n]+1;
            q.push(2*n);
        }
        if(n > 0 && !visited[n-1]){
            visited[n-1] = visited[n]+1;
            q.push(n-1);
        }
    }

}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> K;
    bfs(N);
    cout << visited[K]-1;

    return 0;
}