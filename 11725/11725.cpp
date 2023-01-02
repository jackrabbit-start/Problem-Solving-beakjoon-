#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> v[100004];
int visited[100004];
int answer[100004];
queue<int> q;
void bfs(){
    q.push(1);
    while(!q.empty()){
        int n = q.front();
        q.pop();
        visited[n] = 1;
        for(int i = 0 ; i < v[n].size(); i++){
            if(!visited[v[n][i]]){
            answer[v[n][i]] = n;
            q.push(v[n][i]);
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    int a, b;
    for(int i = 0 ; i < N-1 ; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs();
    for(int i = 2; i <= N ; i++){
        cout << answer[i]<< "\n";
    }

    return 0;
    
}