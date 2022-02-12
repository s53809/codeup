#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct Node {
	vector<int> adjNode;
	int adjGetsu = 0;
	bool visited = false;
};

int v, n;
vector<Node> x;
vector<int> ans;

int BFS(int N) {
	priority_queue<int, vector<int>, greater<int>> qu;
	qu.push(N);
	while (!qu.empty()) {
		int Num = qu.top();
		qu.pop();
		x[Num].visited = true;
		ans.push_back(Num);
		int length = x[Num].adjNode.size();
		for (int i = 0; i < length; i++) {
			if (x[x[Num].adjNode[i]].visited) return -1;
			x[x[Num].adjNode[i]].adjGetsu--;
			if (x[x[Num].adjNode[i]].adjGetsu == 0) qu.push(x[Num].adjNode[i]);
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> v >> n;

	x.resize(v + 1);

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		x[a].adjNode.push_back(b);
		x[b].adjGetsu++;
	}
	for (int i = 1; i <= v; i++) {
		if (x[i].adjGetsu == 0) {
			int panstar = BFS(i);
			if (panstar == -1) {
				cout << "-1";
			}
			break;
		}
	}
	bool isAllVisited = true;
	for (int i = 1; i <= v; i++) {
		if (x[i].visited == false) {
			isAllVisited = false;
		}
	}
	if (!isAllVisited) {
		cout << "-1\n";
	}
	else {
		int ansLength = ans.size();
		for (int i = 0; i < ansLength; i++) {
			cout << ans[i] << '\n';
		}
	}
}