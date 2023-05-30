#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll N, M;
vector<ll> v[100100];
ll id= 0;
vector<pair<ll , ll>> euler(100100);

ll dfs(ll now, ll parent){
    euler[now].first = ++id;
    for(ll nxt : v[now]){
        if(nxt == parent) continue;
        dfs(nxt, now);
    }
    euler[now].second = id;
    return 0;
}

class segtree{
public:
    vector<ll> tree;
    vector<ll> lazy;
    ll size;
    segtree(ll num){
        for(size = 1 ; size <= num;size*=2);
        tree.resize(size*2);
        lazy.resize(size*2);
    }
    ll update(ll pos, ll val, ll start, ll end, ll x , ll y){
        if(start > end) return 0;
        if(lazy[pos]){
            if(lazy[pos] == -1) tree[pos] = 0;
            else tree[pos] = lazy[pos] * (y-x+1);
            if(pos < size){
                lazy[pos*2] = lazy[pos];
                lazy[pos*2+1] = lazy[pos];
            }
            lazy[pos] = 0;
        }
        if(end < x || y < start) return tree[pos];
        if(start <= x && y <= end){
            tree[pos] = val*(y-x+1);
            if(val == 0) val = -1;
            if(pos < size){
                lazy[pos*2] = val;
                lazy[pos*2+1] = val;
                
            }
            return tree[pos];
        }
        ll mid = (x+y)/2;
        tree[pos] = update(pos*2, val, start, end, x, mid) + update(pos*2+1,val, start, end, mid+1, y);
        return tree[pos];
    }

    ll cal_sum(ll pos, ll start, ll end, ll x , ll y){
        if(start > end) return 0;
        if(lazy[pos]){
            if(lazy[pos] == -1) tree[pos] = 0;
            else tree[pos] = lazy[pos] * (y-x+1);
            if(pos < size){
                lazy[pos*2] = lazy[pos];
                lazy[pos*2+1] = lazy[pos];
            }
            lazy[pos] = 0;
        }
        if(end < x || y < start) return 0;
        if(start <= x && y <= end){
            return tree[pos];
        }
        ll mid = (x+y)/2;
        return cal_sum(pos*2, start, end, x, mid) + cal_sum(pos*2+1, start, end, mid+1, y);
    }
};


int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    for(ll i = 1 ; i <= N ; i++){
        ll input;
        cin >> input;
        v[input].push_back(i);
    }
    dfs(1,0);
    segtree tree(N);
    tree.update(1,1,1 , id, 1,tree.size);
    cin >> M;
    while(M--){
        ll input, a;
        cin >> input >> a;
        if(input == 1){
            tree.update(1,1,euler[a].first+1 , euler[a].second, 1,tree.size);
        }
        else if (input == 2){
            tree.update(1,0,euler[a].first+1 , euler[a].second, 1,tree.size);
        }
        else{
            cout << tree.cal_sum(1,euler[a].first +1, euler[a].second,1,tree.size) << "\n";
        }
    }

    return 0;
}