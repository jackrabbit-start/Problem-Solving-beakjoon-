#include <bits/stdc++.h>
using namespace std;


int N;
vector<int> v;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);    
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    for(int i = 0 ; i < N ; i++){
        cout << v[i]<<"\n";
    }
    return 0;
}// 내림차순은 rend rbegin 사용