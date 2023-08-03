/*
23-08-03 20:39 ~ 21:23 

기억할 점
- sort 함수로 구조체를 정렬하고 싶으면 cmp 함수를 작성해야 함
- 구조체를 내림차순으로 정렬하고 싶으면 cmp(a, b) { return a < b } 로 작성해야 함
- sort 함수로 배열을 정렬할 때 sort(배열의 시작, 배열의 시작 + 배열의 크기, cmp)로 호출해야 함
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class DisjointSet {
	int parent[100001];
public:
	DisjointSet() {
		for (int i = 1; i <= 100000; i++) {
			parent[i] = i;
		}
	}
	int find(int i) {
		if (parent[i] == i) {
			return i;
		}
		return parent[i] = find(parent[i]);
	}
	void merge(int i, int j) {
		int u = find(i);
		int v = find(j);
		if (u != v) {
			parent[u] = v;
		}
	}
};

struct Edge {
	int start, end, weight;
};

bool compare(const Edge& a, const Edge& b) { 
	return a.weight < b.weight; // 오름차순 정렬
}

int N, M;
Edge edgeList[1000001];
DisjointSet set;

int Kruskal() {
	int ret = 0;
	int edgeCount = 0;
	int maxWeight = -1;
	for (int i = 1; i <= M; i++) {
		int start = edgeList[i].start;
		int end = edgeList[i].end;
		int weight = edgeList[i].weight;
		if (set.find(start) != set.find(end)) {
			set.merge(start, end);
			ret += weight;
			//printf("start: %d / end: %d / weight : %d\n", start, end, weight);
			maxWeight = max(maxWeight, weight);
			edgeCount += 1;
			if (edgeCount == N - 1) {
				ret -= maxWeight;
				break;
			}
		}
	}
	return ret;
}

int main(void) {
	int a, b, c;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		edgeList[i].start = a;
		edgeList[i].end = b;
		edgeList[i].weight = c;
	}
	sort(edgeList + 1, edgeList + M + 1, compare); // 배열을 정렬할 때 인자에 주의
	/*for (int i = 1; i <= M; i++) {
		printf("%d\n", edgeList[i].weight);
	}*/
	printf("%d", Kruskal());
	return 0;
}