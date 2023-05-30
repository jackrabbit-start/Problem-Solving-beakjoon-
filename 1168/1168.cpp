#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll N, K;

class segtree{
    public:
    ll size;
    vector<ll> tree;
    segtree(int num){
        for(size = 1; size < num; size*=2);
        tree.resize(2*size);
    }
    void update(ll target, ll val){
        ll idx = target + size - 1;
        tree[idx] = val;
        while(idx){
            idx /= 2;
            tree[idx] = tree[idx*2] + tree[idx*2 +1];
        }
    }
    ll find_t(ll pos, ll val){
        while(pos < size){
            if(tree[pos*2] < val){
                val -= tree[pos*2];
                pos = pos*2 +1;
            }
            else{
                pos = pos*2;
            }
        }
        return pos;
    }

};

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> K;
    segtree tree(N);
    ll total = K;
    for(int i = 1 ; i <= N ; i++){
        tree.update(i,1);
    }
    K--;
    cout << "<";
    for(int i = 0 ; i < N ; i++){
        total = total % (N-i);
        if(total == 0) total = N-i;
        ll res = tree.find_t(1, total);
        if(i != N-1)cout<<res-tree.size+1 << ", ";
        else cout << res - tree.size+1;
        tree.update(res-tree.size+1,0);
        total += K;
    }
    cout << ">";
    return 0;
}