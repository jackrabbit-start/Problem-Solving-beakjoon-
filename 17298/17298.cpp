#include <bits/stdc++.h>
using namespace std;
int N;
int arr[1000003];
int ans[1000003];
deque<pair<int, int>> dq;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    for(int i = 1 ; i <= N ; i++){
        cin >> arr[i];
        ans[i] = -1;
    }
    for(int i = 1 ; i <= N ; i++){
        if(dq.empty()) dq.push_back(make_pair(arr[i], i));
        else{
            while(!dq.empty()&& dq.back().first < arr[i]){
                //cout << "(" << dq.back().first << " " << arr[i] << ")";
                ans[dq.back().second] = arr[i];
                dq.pop_back();
            }
            dq.push_back(make_pair(arr[i], i));
        }
        
    }
    for(int i = 1; i <= N ; i++){
        cout << ans[i] << " ";
    }
    return 0;
}