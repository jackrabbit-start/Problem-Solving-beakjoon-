#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
ll N, T;
vector<pair<ll, ll>> v;

class segtree{
    public :
    ll size;
    vector<ll> tree;
    segtree(ll num){
        for(size = 1; size <= num; size *= 2);
        tree.resize(size*2);
    }
    void update(ll pos){
        ll idx = pos + size - 1;
        tree[idx]++;
        idx /= 2;
        while(idx){
            tree[idx] = tree[2*idx] + tree[2*idx+1];
            idx/=2;
        }
    }
    ll sum(ll start, ll end, ll pos, ll from, ll to){
        if(end < from || to < start) return 0;
        if(start <= from && end >= to) return tree[pos];
        ll mid = (from + to)/2;
        return sum(start, end, pos*2, from, mid) + sum(start, end, pos*2+1, mid+1, to);
    }

};

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> T;
    while(T--){
        cin >> N;
        v.clear();
        segtree tree(N);
        for(int i = 0 ; i < N; i++){
            ll a, b;
            cin >> a >> b;
            v.push_back({a,b});
        }
        sort(v.begin(), v.end(), [](P &a, P &b){
            return a.second < b.second;
        });
        ll arr[80000];
        ll nums = 1;
        ll answer = 0;
        for(int i = 0; i < N ; i++){
            if(i!=0 &&v[i-1].second != v[i].second) nums++;
            arr[i] = nums;
        }
        for(int i = 0 ; i < N ; i++){
            v[i].second = arr[i];
        }
        sort(v.begin(), v.end(), [](P &a, P &b){
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });
        ll nowp = v[0].first;
        for(int i = 0 ; i < N ; i++){
            //cout << "(" << v[i].first << " " << v[i].second << ") ";
            answer += tree.sum(v[i].second , nums , 1, 1, tree.size);
            tree.update(v[i].second);
        }
        cout << answer << "\n";

    }
    return 0;
}