#include <stdio.h> 
#include <string.h>

const int MAXN = 110000 + 10;
char s[MAXN * 2];
int p[MAXN * 2];

int min(int a, int b) {
	if (a < b) return a;
	return b;
}

int main() {
	while (scanf ("%s", s) != EOF) {
		int len = strlen(s), id = 0, max_len = 0;
		for (int i = len; i >= 0; i--) {
			s[i + i + 2] = s[i];
			s[i + i + 1] = '#';
		}
		s[0] = '*';
		for (int i = 2; i < 2 * len + 1; i++) {
			if (p[id] + id > i) p[i] = min(p[2 * id - i], p[id] + id - i);
			else p[i] = 1;
			while (s[i - p[i]] == s[i + p[i]]) ++p[i];
			if (id + p[id] < i + p[i]) id = i;
			if (max_len < p[i]) max_len = p[i];
		}
		printf ("%d\n", max_len - 1);
	}
	return 0;
}
