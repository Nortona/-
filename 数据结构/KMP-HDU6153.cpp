//给出两个字符串a,b，求b串所有后缀在a中出现次数与后缀长度乘积之和
#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 1e6;
const int mod = 1e9 + 7;
int nextt[MAX + 10];
char s1[MAX + 10];
char s2[MAX + 10];
long long num[MAX + 10];
int t,len1,len2;
void getnext()
{
    int p=0, k = -1;
    nextt[0] = -1;
    while (p < len2)
    {
        if (k == -1 || s2[p] == s2[k])
        {    
                    p++;k++;
                     nextt[p] =k;
                }
        else k = nextt[k];
    }
}
void kmp()
{
    getnext();
    int i = 0, j = 0;
    while (i < len1)
    {
        if(j==-1||s1[i]==s2[j])
        {i++; j++;}
        else j = nextt[j];
        num[j]++;
        if (j == len2) j = nextt[j];
    }
}
int main()
{
    cin >> t;
    while (t--)
    {
        memset(num,0, sizeof(num));
        cin >> s1;
        cin >> s2;
        len1 = strlen(s1);
        len2 = strlen(s2);
        reverse(s1, s1 + len1);
        reverse(s2, s2 + len2);
        kmp();
        long long ans = 0;
        for (int i = len2; i > 0; i--)
        {                
            num[nextt[i]] += num[i];
            ans = (ans + i*num[i]) % mod;
        }
            printf("%d\n", ans);
    }
    return 0;
}
