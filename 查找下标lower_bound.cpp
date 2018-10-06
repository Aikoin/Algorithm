#include <iostream>
#include <algorithm>
using namespace std;

#define N 10005

int main()
{
    int a[N];
    int n,q,val,num=0;
    while(~scanf("%d%d",&n,&q)&&n&&q)
    {
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        printf("CASE# %d:\n",++num);
        while(q--){
            scanf("%d",&val);
            int key = lower_bound(a,a+n,val)-a;
            if(a[key]==val)
                printf("%d found at %d\n",val,key+1);
            else
                printf("%d not found\n",val);
        }
    }
}