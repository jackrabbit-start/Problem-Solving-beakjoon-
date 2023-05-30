#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double lld;
ll N;

typedef struct Point {
	ll x, y;
	ll id;

	bool operator == (Point &a) {
		if (a.x == x && a.y == y) return 1;
		return 0;
	}
    bool operator < (Point &a){
        if(x == a.x) return y < a.y;
        return x< a.x;
    }
};
vector<Point> v;
vector<Point> arr;
Point start;
pair<lld, lld> final;
Point fine;
Point to;
Point sot;
pair<lld, lld> inter;
ll isch[300100];

ll CCW(Point &a, Point &b, Point &c) {
	return a.x*b.y + b.x*c.y + a.y*c.x - a.x*c.y - b.y*c.x - a.y*b.x;
}
ll distance(Point &a, Point &b) {
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}
bool compare(Point &a, Point &b) {
	ll tmp = CCW(sot, a, b);
	if (tmp == 0) return distance(sot, a) < distance(sot, b);
	return tmp > 0;
}
bool com(Point &a, Point &b) {
	if (a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}


pair<lld, lld> find_point(Point &cc, Point &dd) {
    pair<lld, lld> a = make_pair((lld)dd.x, (lld)dd.y);
    pair<lld, lld> b = make_pair((lld)to.x, (lld)to.y);
    pair<lld, lld> c = make_pair((lld)start.x, (lld)start.y);
    pair<lld, lld> d = make_pair((lld)cc.x, (lld)cc.y);
	pair<lld, lld> res;
	//cout << "<" << a.x << " " << a.y << " " << b.x << " " << b.y << " " << c.x << " " << c.y << " " << d.x << " " << d.y << ">";
	if (dd.x == to.x) {
        lld t = d.second-c.second;
        lld t1 = d.first-c.first;
        lld t2 = a.first-c.first;
        lld t3 = c.second;
        lld m2 = t / t1;
		res.first = a.first;
		res.second = m2 *t2 + t3;
	}
	else if (start.x == cc.x) {
        lld t = b.second-a.second;
        lld t1 = b.first - a.first;
        lld t2 = c.first-a.first;
        lld t3 = a.second;
        lld m1 = t/t1;
		res.first = c.first;
		res.second = m1 * (t2) + t3;
	}
	else {
        lld t = b.second-a.second;
        lld t1 = b.first-a.first;
        lld t2 = c.first-a.first;
        lld t3 = a.second;


        lld m1 = (b.second - a.second) / (b.first -a.first);
        lld m2 = (d.second - c.second) / (d.first - c.first);

		lld p = m1 * a.first - m2 * c.first +c.second - a.second;
		lld xx = p / (m1 - m2);
		res.first = xx;
		res.second = m1 * (xx -a.first) +a.second;
	}
	//cout << "<" << res.x << " " << res.y << " >";
	return res;
}
bool checking(Point &a, Point &b) {
	if (CCW(start, a, to) < 0) return false;
	if (CCW(a, b, to) < 0) return false;
	if (CCW(b, start, to) < 0) return false;
	return true;
}
lld find_divide(pair<lld, lld> &a, pair<lld, lld> &b, pair<lld, lld> &c) {
	lld p1 = c.first - a.first;
	lld p2 = b.first - a.first;
	lld res = 1.0;
	return p1 / p2;
	//cout << "<" << a.x << " " << b.x << " " << c.x  << " " << a.x-b.x<< ">";
}
lld find_divide_same(pair<lld, lld> &a, pair<lld, lld> &b, pair<lld, lld> &c) {
	lld p1 = c.second - a.second;
	lld p2 = b.second - a.second;
	lld res = 1.0;
	return p1 / p2;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	cin >> start.x >> start.y;
    start.id= 0;
	v.push_back(start);
	arr.push_back(start);
	for (int i = 1; i <= N; i++) {
		ll x, y;
		cin >> x >> y;
		v.push_back({ x, y, i});
		arr.push_back({ x,y, i});
	}
	cin >> to.x >> to.y;
    if(N==0){
        if(start.x == to.x && start.y == to.y) cout << "YES\n";
        else cout << "NO";
        return 0;
    }
	sort(v.begin(), v.end(), com);
	sot= v[0];
	sort(v.begin()+1, v.end(), compare);
	deque<ll> st;
	st.push_back(0);
    st.push_back(1);
	for (ll i = 2; i <= N; i++) {
		ll tmp = st.back();
		st.pop_back();
		while (st.size() > 0 && CCW(v[st.back()], v[tmp], v[i]) <= 0) {
			tmp = st.back();
			st.pop_back();
		}
		st.push_back(tmp);
		st.push_back(i);
	}
    cout << fixed;
    cout.precision(16);

    if(st.size()==2 && v[st[0]].x == v[st[1]].x && v[st[0]].y == v[st[1]].y){
        if(v[st[0]].x == to.x && v[st[0]].y==to.y){
            cout << "YES\n";
            for(ll i = 1; i < N ; i++){
                cout << (lld)0 << "\n"; 
            }
             cout << (lld) 1 << "\n";
        }
        else cout << "NO\n";
        return 0;
    }
    else if(st.size() == 2){
        if(CCW(v[st[0]], v[st[1]] , to) != 0) cout << "NO\n";
        else{
            Point A = v[st[0]];
            Point B = v[st[1]];
            if(A.id > B.id){
                Point jk = A;
                A = B;
                B = jk;
            }
            //cout << "<" << A.x << " " << A.y << " " <<B.x << " " << B.y << ">";  
            if(A==to){
                cout << "YES\n";
                isch[A.id] = 3;
            }
            else if(B== to){
                cout << "YES\n";
                isch[B.id] = 3;
            }
            else{
            if(A < B){
                if(A < to && to < B) cout << "YES\n";
                else {cout << "NO\n"; return 0;}
            }
            else{
                if(B < to && to < A) cout << "YES\n";
                else{cout << "NO\n"; return 0;}
            }
            isch[A.id] = 2;
            isch[B.id]= 2;
            }
            ll tt = 0;
            Point from;
            if(isch[0]== 2){tt++; from = start;}
            for(ll i = 1; i <= N ; i++){
                if(isch[i] == 2){
                    if(tt == 0){
                        from = arr[i];
                        tt++;
                        cout << (lld)1 << "\n";
                    }
                    else{
                        pair<lld, lld> t1 = make_pair((lld)from.x, (lld)from.y);
                        pair<lld, lld> t2 = make_pair((lld)to.x, (lld)to.y);
                        pair<lld, lld> t3 = make_pair((lld)arr[i].x, (lld)arr[i].y);
                        if(from.x == arr[i].x){
                            cout << find_divide_same(t1,t3,t2) << "\n";
                        }
                        else{
                            cout << find_divide(t1,t3,t2) << "\n";
                        }
                    }
                }
                else if(isch[i] == 3){
                    cout << (lld)1 << "\n";
                }
                else cout << (lld)0 << "\n";
            }
        }
        return 0;
    }

    ll isok = 1;
    for (ll i = 0; i < st.size(); i++) {
		isch[v[st[i]].id] = 1;
 		if (CCW(v[st[i%st.size()]], v[st[(i + 1) % st.size()]], to) < 0) {
			isok = 0;
		}
    }
    if (isok == 1) {
		cout << "YES\n";
		cout << fixed;
		cout.precision(16);
        Point xx;
        Point yy;
        for (ll i = 0; i < st.size(); i++) {
            if(checking(v[st[i]] , v[st[(i+1)%st.size()]])){
                xx = v[st[i]];
                yy = v[st[(i+1)%st.size()]];
            }
		}
        if(xx.id > yy.id){
            Point tmp = xx;
            xx = yy;
            yy = tmp;
        }
        if(xx == to || yy == to){
            if(xx==to) isch[xx.id] = 3;
            if(yy==to) isch[yy.id] = 3;
            for(ll i = 1; i <= N ; i++){
                if(isch[i] == 3) cout << (lld)1 <<"\n";
                else cout << (lld)0 <<"\n";
            }
        }
        else{
        if(xx.id != 0) inter = find_point(xx, yy);
        else inter = make_pair((lld)xx.x , (lld)xx.y);
        for(ll i = 1; i <= N ; i++){
            if(xx.id == i){
                pair<lld, lld> t1 = make_pair((lld)start.x , (lld)start.y);
                pair<lld, lld> t2 = make_pair((lld)xx.x , (lld)xx.y);
                if(xx.x == start.x){
				    cout << find_divide_same(t1, t2, inter) << "\n";
                }
                else{
                    cout << find_divide(t1,t2,inter) << "\n";
                }
            }
            else if(yy.id == i){
                pair<lld, lld> t1 = make_pair((lld)yy.x , (lld)yy.y);
                pair<lld, lld> t2 = make_pair((lld)to.x , (lld)to.y);
                if(to.x == yy.x){
				    cout << find_divide_same(inter, t1, t2) << "\n";
                }
                else{
                    cout << find_divide(inter,t1,t2) << "\n";
                }
            }
            else cout << (lld)0 <<"\n";
        }
        }
    }
	else cout << "NO";
	return 0;
}