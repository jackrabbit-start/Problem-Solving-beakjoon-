#include <bits/stdc++.h>
using namespace std;
int T;
int N;
int M;
int last_year[505];
int edge[505][505];
int indegree[505];
vector<int> ans;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> T;
    while(T--){
        ans.clear();
        memset(indegree, 0 , sizeof(indegree));
        memset(edge, 0 , sizeof(edge));
        memset(last_year, 0 , sizeof(last_year));
        cin >> N;
        for(int i = 0 ; i < N ; i++){
            int input;
            cin >> input;
            last_year[i] = input;
            indegree[input] = i;
        }
        for(int i = 0 ; i < N ; i++){
            for(int j = i+1 ; j < N ; j++){
                edge[last_year[i]][last_year[j]] = 1;
            }
        }
        cin >> M;
        for(int i = 0 ; i < M ; i++){
            int a, b;
            cin >> a >> b;
            if(edge[a][b] == 1){
                edge[a][b] = 0;
                edge[b][a] = 1;
                indegree[b]--;
                indegree[a]++;
            }
            else {
                edge[a][b] = 1;
                edge[b][a] = 0;
                indegree[a]--;
                indegree[b]++;
            }
        }
        queue<int> q;
        for(int i = 1 ; i <= N ; i++){
            if(indegree[i] == 0) q.push(i);
        } 
        int cnt = 0;
        while(cnt++ < N){
            if(q.empty()){cout << "IMPOSSIBLE\n"; break;}
            if(q.size() > 1){ cout << "? "; break;}
            int now = q.front();
            ans.push_back(now);
            q.pop();
            indegree[now]--;
            for(int i  = 1 ; i <= N ; i++){
                if(edge[now][i] == 1) indegree[i]--;
                if(indegree[i] == 0) q.push(i);
            }
        }
        if(ans.size() == N){
            for(int i = 0 ; i < ans.size(); i++){
                cout << ans[i] << " ";
            }
        }
    }
    return 0;
}