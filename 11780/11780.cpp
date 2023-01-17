#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int N, M;
ll s, e, w;
ll arr[105][105];
ll trace[105][105];
deque<int> ans;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    cin >> M;
    fill(&arr[0][0], &arr[103][103], INT_MAX);
    for(int i = 0 ; i < M ; i++){
        cin >> s >> e >> w;
        arr[s][e] = min(w, arr[s][e]);
    }
    for(int i = 1; i <= N ; i++){
        for( ll j =1 ; j <= N ; j++){
            trace[i][j] = j;
        }
    }
    for(int k = 1; k <= N ; k++){
        for(int i = 1; i <= N ; i++){
            for(int j = 1; j <= N ; j++){
                if(i == j) continue;
                if(arr[i][k] + arr[k][j] < arr[i][j]){
                    arr[i][j] = arr[i][k] + arr[k][j];
                    trace[i][j] = trace[i][k];
                }
                else arr[i][j] = arr[i][j];
            }
        }
    }
    for(int i = 1; i <= N ; i++){
        for( int j =1 ; j <= N ; j++){
            if(arr[i][j] == INT_MAX) cout << "0 ";
            else cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    for(int i = 1; i <= N ; i++){
        for( int j =1 ; j <= N ; j++){
            if(arr[i][j] == INT_MAX) cout << "0\n";
            else{
                int tmp = i;
                ans.clear();
                ans.push_back(tmp);
                while(trace[tmp][j] != j){
                    tmp = trace[tmp][j];
                    ans.push_back(tmp);
                }
                ans.push_back(j);
                cout << ans.size() << " ";
                for(int k = 0 ; k < ans.size(); k++){
                    cout << ans[k] << " ";
                }
                cout << "\n";
            }
        }

    }
    return 0;
}