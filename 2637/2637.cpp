#include <bits/stdc++.h>
using namespace std;
long long int N;
long long int M;
long long int x,y,k;
vector<pair<long long int, long long int>> v[105];
vector<long long int> ans;
long long int arr[105];
long long int depth[105];

void bfs(long long int start){
    queue<long long int> q;
    q.push(start);
    arr[N]= 1;
    while(!q.empty()){
        long long int target = q.front();
        q.pop();
        if(v[target].size() == 0) ans.push_back(target);
        for(long long int i = 0 ; i < v[target].size(); i++){
            long long int tt = v[target][i].first;
            long long int tc = v[target][i].second;
            arr[tt] += arr[target]*tc;
            depth[tt]--;
            if(depth[tt] == 0)q.push(tt);
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    cin >> M;
    for(long long int i = 0 ; i < M ; i++){
        cin >> x >> y >> k;
        v[x].push_back(make_pair(y,k));
        depth[y]++;
    }
    bfs(N);
    sort(ans.begin(), ans.end());
    for(long long int i = 0; i < ans.size() ; i++){
        cout << ans[i] << " " << arr[ans[i]] << "\n";
    }

    return 0;
}