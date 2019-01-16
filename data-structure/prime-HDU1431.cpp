#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10000000;

bool  Is_Prime[MAXN];

int ans[800];

int Get_Prime() {
	memset(Is_Prime, true, sizeof(Is_Prime));
	for (int i = 2; i < MAXN; i++) {
		if (Is_Prime[i]) {
			for (int j = i + i; j < MAXN; j += i)
				Is_Prime[j] = false;
		}
	}
}

int Pal_Num(int n) {
	int sum = 0, m = n;
	while (m) {
		sum = sum * 10 + m % 10;
		m /= 10;
	}
	if (sum == n) return true;
	else return false;
} 
int main() {
	Get_Prime();
	int k = 0;
	for (int i = 2; i < MAXN; i++) {
		if (Is_Prime[i] && Pal_Num(i))
			ans[k++] = i;
	}
	int a, b;
	while (scanf ("%d %d", &a, &b)) {
		for (int i = 0; i <= k; i++) {
			if (ans[i] <= b && ans[i] >= a)
				cout << ans[i] << endl;
			if (ans[i] > b) break;
		}
		cout << endl;
	}
	return 0;
}
