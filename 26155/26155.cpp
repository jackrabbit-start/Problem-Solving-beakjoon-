#include <bits/stdc++.h>
using namespace std;
int N, M, Q;
vector<tuple<double, int, int>> graph;
int arr[100002] = {0,};
vector<pair<double, int>> ans;
bool cmp(const pair<double, int> &a, const pair<double, int> &b)
{
    return a.second < b.second;
}
int find(int x) {
  if (arr[x] == x) {
      return x;
  } else {
      return arr[x] = find(arr[x]);
  }
}
void Union(int x, int y){
    x = find(x);
    y = find(y);
    if(x != y && N > 1){
        N--;
    }
    arr[y] = x;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> M;
    int a, b;
    double pro_s;
    for(int i = 1 ; i <= N ; i++){
        arr[i] = i;
    }
    for(int i = 0 ; i < M ; i++){
        cin >> a >> b >> pro_s;
        graph.emplace_back(pro_s,a,b);
    }
    sort(graph.rbegin(), graph.rend());
    cin >> Q;
    for(int i = 0; i < Q ; i++){
        cin >> pro_s;
        ans.push_back(make_pair(pro_s, i));
    }
    sort(ans.rbegin(), ans.rend());
    int t = 0;
    for(int i = 0 ; i < M ; i++){
        pro_s = get<0>(graph[i]);
        a = get<1>(graph[i]);
        b = get<2>(graph[i]);
        if(ans[t].first > pro_s){
            //cout << "(" << N  << "*" << t<<")";
            ans[t].first = N;
            t++;
            if(t == Q) break;
            i--;
            continue;
        }
        Union(a,b);
        
    }
    for(int i = t; i < Q; i++){
        ans[i].first = N;
    }
    sort(ans.begin(),ans.end(),cmp);
    for(int i = 0 ; i < Q ; i++){
        cout <<(int)(ans[i].first) << "\n";
    }
    

    return 0;
}