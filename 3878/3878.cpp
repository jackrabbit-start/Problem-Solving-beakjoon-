	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	typedef long double lld;
	ll T;
	ll N, M;
	typedef struct Point {
		ll x, y;
		bool operator < (Point &a) {
			if (a.x == x) return y < a.y;
			return x < a.x;
		}
		bool operator == (Point &a) {
			if (a.x == x && a.y == y) return true;
			return false;
		}
	}Point;
	vector<Point> v1;
	vector<Point> v2;
	ll CCW(Point &a, Point &b, Point &c) {
		return a.x*b.y + b.x*c.y + a.y*c.x - a.x*c.y - b.y*c.x - a.y*b.x;
	}
	ll distance(Point &a, Point &b) {
		return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
	}
	bool compare1(Point &a, Point &b) {
		Point p = v1[0];
		ll tmp = CCW(p, a, b);
		if (tmp == 0) return distance(p, a) < distance(p, b);
		return tmp > 0;
	}
	bool compare2(Point &a, Point &b) {
		Point p = v2[0];
		ll tmp = CCW(p, a, b);
		if (tmp == 0) return distance(p, a) < distance(p, b);
		return tmp > 0;
	}
	int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
		cin >> T;
		while (T--) {
			v1.clear();
			v2.clear();
			cin >> N >> M;
			for (ll i = 0; i < N; i++) {
				ll a, b;
				cin >> a >> b;
				v1.push_back({ a,b });
			}
			for (ll i = 0; i < M; i++) {
				ll a, b;
				cin >> a >> b;
				v2.push_back({ a,b });
			}
			if (N == 0 || M == 0) {	
				cout << "YES\n";
				continue;
			}
			if (N == 1 && M == 1) {
				cout << "YES\n";
				continue;
			}
			if (N > 1) {
				sort(v1.begin(), v1.end(), [](Point &a, Point &b) {
					if (a.y == b.y) return a.x < b.x;
					return a.y < b.y;
					});
				sort(v1.begin() + 1, v1.end(), compare1);
			}
			if (M > 1) {
				sort(v2.begin(), v2.end(), [](Point &a, Point &b) {
					if (a.y == b.y) return a.x < b.x;
					return a.y < b.y;
					});
				sort(v2.begin() + 1, v2.end(), compare2);
			}
			ll isok = 1;
			deque<ll> st1;
			deque<ll> st2;
			st1.push_back(0);
			if (N != 1)st1.push_back(1);
			for (ll i = 2; i < N; i++) {
				ll tmp = st1.back();
				st1.pop_back();
				while (st1.size() > 0 && CCW(v1[st1.back()], v1[tmp], v1[i]) <= 0) {
					tmp = st1.back();
					st1.pop_back();
				}
				st1.push_back(tmp);
				st1.push_back(i);
			}

			st2.push_back(0);
			if (M != 1)st2.push_back(1);
			for (ll i = 2; i < M; i++) {
				ll tmp = st2.back();
				st2.pop_back();
				while (st2.size() > 0 && CCW(v2[st2.back()], v2[tmp], v2[i]) <= 0) {
					tmp = st2.back();
					st2.pop_back();
				}
				st2.push_back(tmp);
				st2.push_back(i);
			}

			if (st1.size() > 2) {
				for (ll j = 0; j < v2.size(); j++) {
					ll tmp = 1;
					for (ll i = 0; i < st1.size(); i++) {
						if (CCW(v1[st1[i%st1.size()]], v1[st1[(i + 1) % st1.size()]], v2[j]) < 0) {
							tmp = 0;
						}
					}
					if (tmp) isok = 0;
				}
			}
			if (st2.size() > 2) {
				for (ll j = 0; j < v1.size(); j++) {
					ll tmp = 1;
					for (ll i = 0; i < st2.size(); i++) {
						if (CCW(v2[st2[i%st2.size()]], v2[st2[(i + 1) % st2.size()]], v1[j]) < 0) {
							tmp = 0;
						}
					}
					if (tmp) isok = 0;
				}
			}
				for (ll i = 0; i < st1.size(); i++) {
					for (ll j = 0; j < st2.size(); j++) {
						Point A1 = v1[st1[i]];
						Point A2 = v1[st1[(i + 1) % st1.size()]];
						Point B1 = v2[st2[j]];
						Point B2 = v2[st2[(j + 1) % st2.size()]];
						//cout << " (" << CCW(A1, A2, B1)*CCW(A1, A2, B2)  << " " << CCW(B1, B2, A1)*CCW(B1, B2, A2) << ")";
						if (CCW(A1, A2, B1)*CCW(A1, A2, B2) == 0  &&  CCW(B1, B2, A1)*CCW(B1, B2, A2) == 0) {
							if (A1 < A2) {
								if (B1 < B2) {
									if (A1 < B2 && B1 < A2) isok = 0;
								}
								else {
									if (A1 < B1 && B2 < A2) isok = 0;
								}
							}
							else {
								if (B1 < B2) {
									if (A2 < B2 && B1 < A1) isok = 0;
								}
								else {
									if (A2 < B1 && B2 < A1) isok = 0;
								}
							}
						}
						else if (CCW(A1, A2, B2) * CCW(A1, A2, B1) <= 0 && CCW(B1, B2, A1) * CCW(B1, B2, A2) <= 0) isok = 0;
					}
				}
			if (isok) cout << "YES\n";
			else cout << "NO\n";
		}
		return 0;
	}