#include <bits/stdc++.h>
using namespace std;
int input;
int root;
int graph[1000003][2];
int visited[1000003];
vector<int> arr;

void make_tree(int num){
    int tmp = root;
    while(1){
    if(tmp > num){
        if(graph[tmp][0] == 0){
            graph[tmp][0] = num;
            break;
        }
        else{
            tmp = graph[tmp][0];
        }
    }
    else{
        if(graph[tmp][1] == 0){
            graph[tmp][1] = num;
            break;
        }
        else{
            tmp = graph[tmp][1];
        }
    }
    }
}

void dfs(int num){
    if(visited[num] == -1){
        visited[num] = 1;
        int left = graph[num][0];
        int right = graph[num][1];
        if(left != 0 && visited[left] == -1){
            dfs(left);
        }
        if(right != 0 && visited[right] == -1){
            dfs(right);
        }
        cout << num << "\n";
    }
    return;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    fill(&visited[0], &visited[1000002], -1);
    while(cin >> input){
        if(root == 0) root = input;
        arr.push_back(input);
    }
    for(int i = 1 ; i < arr.size(); i++){
        make_tree(arr[i]);
    }
    dfs(root);
    return 0;
}