#include <bits/stdc++.h>
using namespace std;
int N, M;
int s, e;
vector<int> graph[505];
int visited[505];
int checking;
void dfs(int num){
    if(visited[num]){
        for(int i = 0 ; i < graph[num].size(); i++){
            int next = graph[num][i];
            if(!visited[next]){
                visited[next] = num;
                dfs(next);
            }
            else{
                if(next != visited[num]) checking = 1;
            }
        }
    }
    return;
}


int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int T = 0;
    while(1){
        T++;
        int ans = 0;
        checking = 0;
        fill(&visited[0], &visited[503], 0);
        for(int i = 0 ; i < 504; i++){
            graph[i].clear();
        }
        cin >> N >> M;
        if(N == 0 && M == 0) break;
        for(int i = 0 ; i < M ; i++){
            cin >> s >> e;
            graph[s].push_back(e);
            graph[e].push_back(s);
        }
        for(int i = 1; i <= N ; i++){
            checking = 0;
            if(visited[i] == 0){
                visited[i] = i;
                dfs(i);
                if(checking != 1){
                    ans++;
                }
            }
        }
        switch(ans){
            case 0: cout << "Case " << T << ": No trees.\n"; break;
            case 1: cout << "Case " << T << ": There is one tree.\n"; break;
            default : cout << "Case " << T << ": A forest of " << ans << " trees.\n"; break;
        }
    }
    return 0;
}