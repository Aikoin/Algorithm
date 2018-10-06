#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a[5],tag = 0;
    while(~scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3])){
        if(!a[0]&&!a[1]&&!a[2]&&!a[3]) break;
        if(tag)
            printf("\n");
        tag = 1;
        int flag = 1,t;
        do{
            if(a[0]==0) continue;
            if(flag){
                printf("%d%d%d%d",a[0],a[1],a[2],a[3]);
                flag = 0;
            }
            else if(t==a[0])
                printf(" %d%d%d%d",a[0],a[1],a[2],a[3]);
            else
                printf("\n%d%d%d%d",a[0],a[1],a[2],a[3]);
            t = a[0];
        }while(next_permutation(a,a+4));
        printf("\n");
    }

}
