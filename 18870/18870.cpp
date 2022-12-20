#include <bits/stdc++.h>
using namespace std;


int N;
vector<int> v;
int arr[1000001]= {0,};
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        int a;
        cin >> a;
        arr[i] = a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end()); // unque는 중복 끝나고 난후 iterator 값 반환
    for(int i = 0 ; i < N ; i++){
        auto iter = lower_bound(v.begin(),v.end(),arr[i]);
        cout << iter-v.begin() << " ";
    }

    return 0;
}