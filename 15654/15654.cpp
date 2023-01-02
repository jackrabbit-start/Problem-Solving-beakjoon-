#include <bits/stdc++.h>
using namespace std;
int N;
int M;
int arr[10];
vector<pair<int, int>> dq;
vector<int> answer;

int backtracking(int cnt){
    if(cnt == M){ 
        for(int i = 0 ; i < answer.size(); i++){
            cout << answer[i] << " ";
        }
        cout << "\n";
        return 1;
    }
    for(int i = 0 ; i < N ; i++){
        if(dq[i].second== 0){
            dq[i].second = 1;
            answer.push_back(dq[i].first);
            backtracking(cnt+1);
            answer.pop_back();
            dq[i].second = 0;
        }   
    }
    return 1;

}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> M;
    int input;
    for(int i = 0 ; i < N ; i++){
        cin >> input;
        dq.push_back(make_pair(input, 0));
    }
    sort(dq.begin(), dq.end());
    backtracking(0);

    return 0;
    
}