#include <bits/stdc++.h>
using namespace std;
int N;
double a, b;
priority_queue<tuple<double ,double ,double ,double, double> , vector<tuple<double,double ,double ,double, double>> , greater<tuple<double ,double ,double ,double, double>>> edge;
vector<tuple<double ,double, int>> v;
map<pair<double ,double>, int> mp;
int arr[1005];

int Find(int x){
    if(arr[x] == x) return x;
    return arr[x] = Find(arr[x]);
}
int Union(int a, int b){
    int aa = Find(a);
    int bb = Find(b);
    if(aa!= bb){
        arr[aa] = bb;
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    for(int i = 0 ; i <= 1002; i++) arr[i] = i;
    for(int i = 0 ; i < N ; i++){
        cin >> a >> b;
        v.push_back(make_tuple(a, b, i+1));
        mp.emplace(make_pair(a, b), i+1);
    }
    for(int i = 0 ; i < v.size(); i++){
        for(int j = i+1 ; j < v.size(); j++){
            if(i!=j){
                double dis = pow(abs(get<0>(v[i]) - get<0>(v[j])),2) + pow(abs(get<1>(v[i]) - get<1>(v[j])),2); 
                edge.push(make_tuple(dis, get<0>(v[i]), get<1>(v[i]), get<0>(v[j]), get<1>(v[j])));
            }
        }
    }
    double ans = 0;
    int cnt = 0;
    while(cnt <= N && !edge.empty()){
        double dis = get<0>(edge.top());
        double nx = get<1>(edge.top());
        double ny = get<2>(edge.top());
        double nx_2 = get<3>(edge.top());
        double ny_2 = get<4>(edge.top());
        edge.pop();
        int tmp1 = mp.at({nx,ny});
        int tmp2 = mp.at({nx_2,ny_2});
        if(Find(tmp1) != Find(tmp2)){
            Union(tmp1, tmp2);
            cnt++;
            ans += sqrt(dis);
        }
    }
    cout<<fixed;
    cout.precision(2);
    cout << ans;
    
    return 0;
}