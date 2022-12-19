#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int N;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    int input;
    for(int i = 0 ; i < N ; i++){
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(),v.end());
    for(int i = 0 ; i < N ; i++){
        cout << v[i] << "\n";
    }

    return 0;
} // 1분 58초