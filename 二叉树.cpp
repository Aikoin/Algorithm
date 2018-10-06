//算法题 【Dropping Balls】
【法一】 //模拟开关
#include <iostream>
#include <string.h>
using namespace std;

const int maxd = 20;
int s[1<<maxd];  //最大节点数为(2^20)-1

int main()
{
    int d,n;  //d为叶子深度，n为小球个数
    while (cin>>d>>n) {
        memset(s,0,sizeof(s));
        int k,m = (1<<d)-1;  //k为开关编号，m为总结点数
        for(int i=0;i<n;i++){
            k = 1;
            while (1) {
                s[k] = !s[k];   //小球每掉落一次开关改变一次状态
                k = s[k]?2*k:2*k+1;   // 根据开关状态决定向左走还是向右走
                if(k>m) break;
            }
        }
        printf("%d\n",k/2);
    }

    return 0;
}



【法二】//直接模拟最后一个小球
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int d,n;  //d为叶子深度，n为小球个数
    while (cin>>d>>n) {
        int k = 1;
        for(int i=0;i<d-1;i++){   //只需判断d-1层
            if(n%2){    //n为奇数
                k = 2*k;     //进入左子树
                n = (n+1)/2; //计算是第几个落在根的左子树里
            }
            else{     //n为偶数
                k = 2*k+1;   //进入右子树
                n = n/2;     //计算是第几个落在根的右子树里
            }
        }
        printf("%d\n",k);
    }

    return 0;
}
