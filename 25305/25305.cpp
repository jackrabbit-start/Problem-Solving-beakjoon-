#include <bits/stdc++.h>
using namespace std;

int N;
int K;
vector<int> v;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> K;
    int input;
    for(int i = 0 ; i < N ; i++){
        cin >> input;
        v.push_back(input);
    }
    sort(v.rbegin(),v.rend());
    cout << v[K-1];


    return 0;
} // 2분 40초