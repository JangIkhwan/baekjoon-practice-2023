/*
23-07-30 21:18 ~ 22:03

1차 시도 : 성공

- 그래프 상에서 해당 노드로 도달할 수 있는 노드의 수와 
해당 노드에서 시작해서 도달할 수 있는 노드의 수가 N - 1개면 
순위를 알 수 있음

생각해볼 점
- 플로이드 워셜로 풀 수 있을까?
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
vector<int> graph[501];
bool visited[501];

int lowCount[501];
int highCount[501];

void bfs(int start) {
	queue<int> qu;
	qu.push(start);
	visited[start] = true;
	while (!qu.empty()) {
		int now = qu.front();
		qu.pop();
		for (int next : graph[now]) {
			if (!visited[next]) {
				qu.push(next);
				visited[next] = true;
				lowCount[next] += 1;
				highCount[start] += 1;
			}
		}
	}
}

int main(void) {
	int a, b;
	int result;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
	}
	for (int start = 1; start <= N; start++) {
		bfs(start);
		memset(visited, 0, sizeof(visited));
	}
	result = 0;
	for (int node = 1; node <= N; node++) {
		if (lowCount[node] + highCount[node] == N - 1) {
			result += 1;
		}
	}
	printf("%d\n", result);
	return 0;
}
