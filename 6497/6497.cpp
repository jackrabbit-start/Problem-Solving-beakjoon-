#include <bits/stdc++.h>
using namespace std;
int M, N;
int x, y, z;
int arr[200005];

int Find(int n){
    if(arr[n] == n) return n;
    return arr[n] = Find(arr[n]);
}

void Union(int a, int b){
    int aa = Find(a);
    int bb = Find(b);
    if(aa != bb){
        arr[aa] = bb;
    }
    return;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    while(1){
        priority_queue<tuple<int ,int ,int>> pq;
        cin >> M >> N;
        int sum = 0;
        if(M == 0 && N == 0) break;
        for(int i = 1; i <= M; i++){
            arr[i] = i;
        }
        for(int i = 0 ; i < N ; i++){
            cin >> x >> y >> z;
            sum += z;
            pq.push(make_tuple(-1*z, x+1, y+1));
        }
        int ans = 0;
        while(!pq.empty()){
            int dis = get<0>(pq.top());
            int xx = get<1>(pq.top());
            int yy = get<2>(pq.top());
            pq.pop();
            if(Find(xx) != Find(yy)){
                Union(xx,yy);
                ans += -1*dis;
            }
        }
        cout << sum - ans << "\n";
    }
    return 0;
}