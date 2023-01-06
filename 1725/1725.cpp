#include <bits/stdc++.h>
using namespace std;

int N;
int arr[100005];
deque<pair<int, int>> dq; // 높이 , 길이
int answer = 0;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    for(int i = 1 ; i <= N ; i++){
        cin >> arr[i];
        answer = max(answer, arr[i]);
    }
    for(int i = N ; i > 0 ; i--){
        if(arr[i] <= arr[i+1]){
            int length = N-i+1;
            while(!dq.empty() && dq.back().first >= arr[i]){
                length = dq.back().second;
                dq.pop_back();
            }
            dq.push_back(make_pair(arr[i],length));
        }
        else{
            dq.push_back(make_pair(arr[i], 1));
        }
        for(int j = 0 ; j < dq.size(); j++){
            answer = max(answer , dq[j].first*dq[j].second);
            dq[j].second++;
        }
    }
    cout << answer;

    return 0;
}