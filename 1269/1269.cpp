#include <bits/stdc++.h>
using namespace std;

int A;
int B;
unordered_set<int> s;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> A >> B;
    int ans = 0;
    for(int i = 0 ; i < A; i++){
        int a;
        cin >> a;
        s.insert(a);
    }
    int tmp = 0;
    for(int i = 0 ; i < B; i++){
        int a;
        cin >> a;
        auto iter = s.find(a);
        if(iter != s.end()) tmp++;
    }
    cout << A+B-(2*tmp);

    return 0;
}