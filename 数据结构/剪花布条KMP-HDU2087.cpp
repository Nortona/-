#include<cstdio>
#include<cstring>
using namespace std;

char a[1005];
char b[1005];
int lena,lenb;
int next[1005];

void getnext()
{
    int i=0,k=-1;
    next[0]=-1;
    while(i<lenb)
    {
        if(k==-1||b[i]==b[k])
        {
            i++;
            k++;
            next[i]=k;
        }
        else    k=next[k];
    }
}
int KMP()
{
    getnext();
    int i=0,j=0;
    int cnt=0;
    while(i<lena)
    {
        if(j==-1||a[i]==b[j])
        {
            i++;
            j++;
        }
        else    j=next[j];
        if(j==lenb)
        {
            cnt++;
            j=0;//若两个不同的匹配没有交集则j=0,若存在交集则j=next[j]; 
        }
    }
    return cnt;
}
int main()
{
    while(scanf("%s",a)!=EOF)
    {
        if(*a=='#')    break;
        scanf("%s",b);
        lena=strlen(a);
        lenb=strlen(b);    
        printf("%d\n",KMP());
    }
   
    return 0;
}
