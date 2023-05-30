#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll N;
vector<pair<ll, ll>> v;
vector<pair<ll, ll>> q;
map<ll, ll> mp;
map<ll, ll> counting;
class segtree {
public:
	ll size;
	vector<ll> tree;
	vector<ll> lazy;
	segtree(ll num) {
		for (size = 1; size <= num; size *= 2);
		tree.resize(size * 2);
		lazy.resize(size * 2);
	}
	void updating(ll pos, ll val) {
		ll idx = pos + size - 1;
		tree[idx] += val;
		while (idx) {
			idx /= 2;
			tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
		}
	}
	ll update(ll pos, ll val, ll start, ll end, ll x, ll y) {
		if (lazy[pos] != 0) {
			tree[pos] += lazy[pos];
			if (pos < size) {
				lazy[pos * 2] += lazy[pos];
				lazy[pos * 2 + 1] += lazy[pos];
			}
			lazy[pos] = 0;
		}
		if (end < x || start > y) return tree[pos];
		if (start <= x && y <= end) {
			tree[pos] += val;
			if (pos < size) {
				lazy[pos * 2] += val;
				lazy[pos * 2 + 1] += val;
			}
			return tree[pos];
		}
		ll mid = (x + y) / 2;
		tree[pos] = max(update(pos * 2, val, start, end, x, mid), update(pos * 2 + 1, val, start, end, mid + 1, y));
		return tree[pos];
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (ll i = 1; i <= N; i++) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		v.push_back({ b,-1*i });
		v.push_back({ d,i });
		q.push_back({ d,b });
	}
	sort(v.begin(), v.end());
	ll tt = 0;
	ll pv = v[0].first;
    ll misss= 0;
	for (pair<ll, ll> iter : v) {
		if (mp.count(iter.first) == 0) {
			mp[iter.first] = 0;
		}
		
		if (pv != iter.first) {
			mp[pv] = tt;
			pv = iter.first;
            tt-=misss;
            misss= 0;
		}
		if (iter.second < 0) misss++;
		else tt++;
	}
	segtree tree(mp.size());
	ll cnt = 0;
	for (auto iter = mp.begin(); iter != mp.end(); iter++) {
		cnt++;
        counting[iter->first] = cnt;
		tree.updating(cnt, iter->second);
	}
	ll answer = 0;
    ll now = 0;
    vector<ll> mising;
    pv = v[0].first;
	for (pair<ll, ll> iter : v) {
        
        if(pv!= iter.first){
            answer = max(answer, tree.tree[1] + now);
            pv=iter.first;
            now-=mising.size();
            for(ll id : mising){
                ll sstart = counting[q[id-1].first];
                ll eend = counting[q[id-1].second];
                tree.update(1,1,sstart, eend, 1, tree.size);
            }
            mising.clear();
        }
        if(iter.second >0){
            ll sstart = counting[q[iter.second-1].first];
            ll eend = counting[q[iter.second-1].second];
            tree.update(1,-1,sstart, eend, 1, tree.size);
            now++;
        }
        if(iter.second<0){
            ll id = iter.second * -1;
            mising.push_back(id);
        }
	}
	cout << answer;
	return 0;
}