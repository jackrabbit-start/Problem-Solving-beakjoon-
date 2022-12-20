#include <bits/stdc++.h>
using namespace std;


int N;
vector<tuple<int,int>> v;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        int x_pos, y_pos;
        cin >> x_pos >> y_pos;
        v.push_back(make_tuple(x_pos, y_pos)); //튜플 사용법
    }
    sort(v.begin(), v.end());
    for(int i = 0 ; i < N ; i++){
        cout << get<0>(v[i]) << " " << get<1>(v[i]) << "\n"; // 튜플 출력방법
    }

    return 0;
}