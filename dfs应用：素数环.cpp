//UVa524 素数环问题
//先来一个全排列的方法试试
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int a[20];
int isp[40];

bool is_prime(int n)  //判断n是否为素数
{
    for(int i=2;i<=sqrt(n)+1;++i)
        if(n%i==0) return 0;
    return 1;
}

int main()
{
    int n;
    while(1){
        cin>>n;
        for(int i=2;i<=n*2;++i) isp[i] = is_prime(i);  //生成素数表，加快后续判断
        for(int i=0;i<n;++i)
            a[i] = i+1;   //第一个排列
        do{
            int ok = 1;
            for(int i=0;i<n;++i)
                if(!isp[a[i]+a[(i+1)%n]]){  //相邻整数相加不为素数 第0个元素与第n-1个元素相连
                    ok = 0;
                    break;
                }
            if(ok){              //判断合法性
                for(int i=0;i<n;++i){
                    if(i!=0) cout<<" ";
                    cout<<a[i];
                }
                cout<<endl;
            }
        }while(next_permutation(a+1,a+n));  //从1后开始排列（1的位置不变）
    }
    return 0;
}
//运行后发现，当n=8的时候就已经有点慢了，可能会超时。



//下面试试dfs求解的回溯法：
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int a[20];
int isp[40];
int vis[20];

bool is_prime(int n)  //判断n是否为素数
{
    for(int i=2;i*i<=n;++i)
        if(n%i==0) return 0;
    return 1;
}

void dfs(int cur)  //cur:当前要排列的数的下标号
{
    if(cur==n && isp[a[0]+a[n-1]]){  //判断边界，别忘了测试第一个数和最后一个数
        for(int i=0;i<n;++i){    //打印方案
            if(i!=0) cout<<" ";
            cout<<a[i];
        }
        cout<<endl;
    }
    for(int i=2;i<=n;++i)  //尝试放置每个数i
        if(!vis[i] && isp[i+a[cur-1]]){  //满足check条件：i没有用过，并且与前一个数之和为素数
            a[cur] =i;
            vis[i] = 1;   //标记
            dfs(cur+1);
            vis[i] = 0;  //清除标志
        }

}

int main()
{
    while(cin>>n){
        memset(vis,0,sizeof(vis));
        for(int i=2;i<=n*2;++i)
            isp[i] = is_prime(i);  //生成素数表，加快后续判断
        a[0] = 1;
        dfs(1);  //从下标为1的数开始搜索
    }
    return 0;
}


//回溯法比生成-测试法快了很多，即使n=18速度也不错
