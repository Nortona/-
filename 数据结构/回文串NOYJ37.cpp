//NOYJ37
// 给一个字符串，求它最少需要添加几个字符变为回文串。
#include <stdio.h> 
#include <algorithm>
#include <string.h>

using namespace std;

int dp[1000][1000];

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int n; scanf ("%d", &n);
	while (n --) {
		char s_1[1000], s_2[1000];
		scanf ("%s", s_1 + 1);
		int len = strlen(s_1 + 1);
		int ans = 1;
		for (int i = len; i >= 1; i--)
			s_2[ans++] = s_1[i];
		printf ("%s\n%s\n", s_1+1, s_2+1);
		s_2[len + 1] = '\0';
		memset (dp, 0, sizeof(dp));
		int len_1 = strlen(s_1 + 1), len_2 = strlen(s_2 + 1);
		for (int i = 1; i <= len_1; i++) {
			for (int j = 1; j <= len_2; j++) {
				if (s_1[i] == s_2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
				else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		printf ("%d\n",len - dp[len_1][len_2]);
	}
	return 0;
}


