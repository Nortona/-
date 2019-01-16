#include <stdio.h>
#include <string.h>
 
int next[1000];
char str1[10000],str2[1000];
int cnt;
 
void get_next(int length2)
{
    int i = 0,j = -1;
    next[1] = 0;
    while (i<length2)
    {
        if(j == 0 || str2[i] == str2[j])
        {
            i++;
            j++;
            if (str2[i]!=str2[j])
                next[i] = j;
            else
                next[i] = next[j];
        }
        else
            j = next[j];
    }
}
 
int kmp(int length1,int length2)
{
    int i=0,j=0;
    get_next(length2);
    while(i<length1)
    {
        if(j==-1||str1[i]==str2[j])
        {
            ++i;
            ++j;
        }
        else
            j=next[j];
        if(j == length2)
        {
            cnt++;
            j = next[j];
        }
    }
}
 
int main()
{
    int n;
    int length1,length2;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        gets(str2);
        gets(str1);
        length1 = strlen(str1);
        length2 = strlen(str2);
        cnt = 0;
        kmp(length1,length2);
        printf("%d\n",cnt);
    }
    return 0;
}
