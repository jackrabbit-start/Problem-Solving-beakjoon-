#include <bits/stdc++.h>
using namespace std;
int N;
char s, le, ri;
int visited[105];
vector<int> midvisit;
vector<int> lastvisit;
vector<int> graph[105];

int dfs(int num, int cnt){
    if(visited[num] == -1){
        visited[num] = cnt;
        cout << char(num+'A');
        cnt++;
        for(int i = 0 ; i < graph[num].size(); i++){
            if(i == 1) midvisit.push_back(num);
            if(graph[num][i] != '.' && visited[graph[num][i] - 'A'] == -1){
                dfs(graph[num][i] - 'A', cnt+1);                
            }
        }
        lastvisit.push_back(num);
    }
    return 0;
}


int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    fill(&visited[0] , &visited[101], -1);
    for(int i = 0 ; i < N ; i++){
        cin >> s >> le >> ri;
        graph[s-'A'].push_back(le);
        graph[s-'A'].push_back(ri);
    }
    dfs(0 , 1);
    cout << "\n";
    for(int i = 0 ; i < midvisit.size(); i++){
        cout << char(midvisit[i] + 'A');
    }
    cout << "\n";
    for(int i = 0 ; i < lastvisit.size(); i++){
        cout << char(lastvisit[i] + 'A');
    }
    return 0;
}