#include <iostream>
#include <cstring>
using namespace std;
#define MAX_N  1000

/* <部分和问题>
 * 给定整数a1、a2、...an，判断是否可以从中选出若干数，使它们的和恰好为k。
 * 思路：
 * 从a1开始按顺序决定每个数加或不加，在全部n个数都决定后，再判断它们的和是不是k。
 * 搜索算法核心:状态的转移。
 */

//输入
int a[MAX_N];
int n,k;

//已经从前i项得到了和sum，然后对于i项之后的进行分支
bool dfs(int i,int sum){
    //如果前n项都计算过了，则返回sum是否与k相等
    if(i==n) return sum == k;

    //不加上a[i]的情况
    if(dfs(i+1,sum)) return true;

    //加上a[i]的情况
    if(dfs(i+1,sum+a[i])) return true;

    //无论是否加上a[i]都不能凑成k就返回false
    return false;
}

void solve()
{
    if(dfs(0,0)) printf("Yes\n");
    else printf("No\n");
}

int main()
{
    while(cin>>n){
        for(int i=0;i<n;++i)
            cin>>a[i];
        cin>>k;
        solve();
    }

    return 0;
}
