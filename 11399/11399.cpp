#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> v;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    int a;
    for(int i = 0 ; i < N ; i++){
        cin >>a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i = 0 ; i < v.size(); i++){
        ans += (N-i)*v[i];
    }
    cout << ans;

    return 0;
}