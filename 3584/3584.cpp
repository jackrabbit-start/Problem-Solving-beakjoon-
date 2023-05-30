#include<bits/stdc++.h>
using namespace std;
int T;
int N;
int depth[10005];
int arr[10005][20];
vector<int> graph[10005];
int maxlevel;
int dfs(int now, int parent) {
	depth[now] = depth[parent] + 1;
	arr[now][0] = parent;
	for (int i = 1; i <= maxlevel; i++) {
		int tmp = arr[now][i - 1];
		arr[now][i] = arr[tmp][i-1];
	}
	for (int i = 0; i < graph[now].size(); i++) {
		int nxt = graph[now][i];
		if (nxt != parent) {
			dfs(nxt, now);
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		memset(depth, 0, sizeof(depth));
		fill(&arr[0][0], &arr[10003][18], 0);
		for (int i = 1; i <= N; i++) {
			graph[i].clear();
		}
		cin >> N;
		for (int i = 1; i < N; i++) {
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			depth[v]++;
		}
		maxlevel = (int)floor(log2(N));
		int rootnd = -1;
		for (int i = 1; i <= N; i++) {
			if (depth[i] == 0) rootnd = i;
			depth[i] = 0;
		}
		dfs(rootnd, 0);
		int a, b;
		cin >> a >> b;
		if (depth[a] != depth[b]) {
			if (depth[a] > depth[b]) swap(a, b);
			for (int i = maxlevel; i >= 0; i--) {
				if (depth[a] <= depth[arr[b][i]]) {
					b = arr[b][i];
				}
			}
		}
		int ans = a;
		if (a != b) {
			for (int i = maxlevel; i >= 0; i--) {
				if (arr[a][i] != arr[b][i]) {
					a = arr[a][i];
					b = arr[b][i];
				}
				ans = arr[a][i];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}