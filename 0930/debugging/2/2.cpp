#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int N;
int K;

struct Node {
	int num;
	int idx;
};
Node line[11];
int cnt = 0;
Node comb[100][11];
int used[11];

void find(int numidx, int level) {
	if (level == 4) {
		cnt++;
		//cout << "here" << endl;
		return;
	}

	used[numidx] = 1;

	for (int i = 0; i < N; i++) {
		if (used[i]) continue;
		//cout << "here2" << endl;
		if (abs(line[numidx].num - line[i].num) > K || abs(line[numidx].num - line[i].num) == 0) continue;

		//cout << "here3" << endl;

		used[i] = 1;
		find(i, level + 1);
		used[i] = 0;
	}
}

int main() {
	freopen("input.txt", "r", stdin);

	memset(line, 0, sizeof(line));
	memset(comb, 0, sizeof(comb));
	memset(used, 0, sizeof(used));

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		Node tmp;
		cin >> tmp.num;

		tmp = { tmp.num, i };
		line[i] = tmp;
	}

	/*for (int i = 0; i < N; i++) {
		cout << line[i].idx << ": " << line[i].num << endl;
	}*/
	/*int order = 0;

	for (int i = 0; i < N; i++) {
		comb[order][i] = line[i];

		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			comb[order][j] = 

			for (int d = 0; d < N; d++) {
				if (j == d || i == d) continue;

				for (int t = 0; t < N; t++) {
					if (i == t || j == t || d == t) continue;
				}
			}
		}

	}*/

	//find(line[0].idx, 1);

	for (int i = 0; i < N; i++) {
		memset(used, 0, sizeof(used));
		find(line[i].idx, 1);
	}

	cout << cnt << endl;
}