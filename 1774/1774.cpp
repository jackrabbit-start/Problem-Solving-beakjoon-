#include <bits/stdc++.h>
using namespace std;
int N, M;
int arr[1005];
vector<pair<double ,double>> v;
priority_queue<tuple<double, int, int>> edge;
double x,y;
int xx, yy;
int Find(int n){
    if(arr[n] == n) return n;
    return arr[n] = Find(arr[n]);
}
int Union(int a, int b){
    int aa = Find(a);
    int bb = Find(b);
    if(aa != bb){
        arr[aa] = bb;
        return 1;
    }
    return 0;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1 ; i <= N; i++){
        cin >> x >> y;
        v.push_back(make_pair(x,y));
        arr[i] = i;
    }
    for(int i = 0 ; i < M ; i++){
        cin >> xx >> yy;
        Union(xx,yy);
    }
    for(int i = 0 ; i< v.size(); i++){
        for(int j = i+1; j < v.size(); j++){
            double dis = pow(abs(v[i].first - v[j].first), 2) + pow(abs(v[i].second - v[j].second), 2);
            edge.push(make_tuple(-1*dis, i+1,j+1));
        }
    }
    double ans = 0;
    while(!edge.empty()){
        double dis = -1*get<0>(edge.top());
        int nx = get<1>(edge.top());
        int ny = get<2>(edge.top());
        edge.pop();
        if(Find(nx) != Find(ny)){
            Union(nx,ny);
            ans += sqrt(dis);
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << ans;
    return 0;
}