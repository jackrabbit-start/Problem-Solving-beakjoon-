#include <bits/stdc++.h>
using namespace std;
int N;
int arr[1000005];
vector<int> v;
deque<int> ans;
int checking[1000005];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >>N;
    for(int i = 0 ; i < N ; i++){
        cin >> arr[i];
    }
    for(int i = 0 ; i < N ; i++){
        auto iter = lower_bound(v.begin(), v.end(), arr[i]);
        if(iter == v.end()){ 
            v.push_back(arr[i]);
            checking[i] = v.size();
        } 
        else{
            v[iter-v.begin()] = arr[i];
            checking[i] = iter-v.begin()+1;
        }
    }
    cout << v.size() << "\n";
    int tmp = v.size();
    for(int i = N-1 ; i >= 0; i--){
        if(tmp == 0) break;
        if(checking[i] == tmp){
            ans.push_front(arr[i]);
            tmp--;
        }
    }
    for(int i = 0 ; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}