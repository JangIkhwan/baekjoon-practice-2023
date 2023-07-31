/*
23-07-31 21:20 ~ 

플로이드는 시간초과 가능성이 존재함

결국 다익스트라를 이용해서 각 학생이 X로 가는 시간을 따로 구해야 함

다익스트라의 시간복잡도는 V log E

예상 시간복잡도는 V^2 log E
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, X;
const int INF = 100001;

vector<pair<int, int>> graph[1001];
int dists[1001];
int returnTime[1001];

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	for (int i = 1; i <= N; i++) {
		dists[i] = INF;
	}
	dists[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (dists[now] < dist) continue;
		for (pair<int, int> edge : graph[now]) {
			int next = edge.first;
			int nextDist = dist + edge.second;
			if (nextDist < dists[next]) {
				dists[next] = nextDist;
				pq.push({ -nextDist, next });
			}
		}
	}
}

int main(void) {
	int s, e, t;
	scanf("%d %d %d", &N, &M, &X);
	for (int i = 1; i <= M; i++){
		scanf("%d %d %d", &s, &e, &t);
		graph[s].push_back({ e, t });
	}
	dijkstra(X);
	for (int i = 1; i <= N; i++) {
		returnTime[i] = dists[i];
	}
	int result = -1;
	for (int student = 1; student <= N; student++) {
		dijkstra(student);
		result = max(result, dists[X] + returnTime[student]);
	}
	printf("%d\n", result);
	return 0;
}
