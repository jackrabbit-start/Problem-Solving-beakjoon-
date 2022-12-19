#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int input;
    int avg_ans = 0;
    for(int i = 0 ; i < 5; i++){
        cin >> input;
        avg_ans += input;
        v.push_back(input);
    }
    sort(v.begin(),v.end());
    cout << avg_ans/5 << "\n" << v[2];
    return 0;
}// 2:43초 예제는 돌려보고 제출하기