#include <iostream>
#include <cstring>
using namespace std;

//假设有n个字符要排列，把他们依次放到n个箱子中
//先要检查箱子是否为空，手中还有什么字符，把他们放进并标记。
//放完一次要恢复初始状态，当到n+1个箱子时，一次排列已经结束

char a[12];
char b[12];
int vis[12];
int n;

void dfs(int s)
{
    if(s == n+1){  //判断边界
        for(int i=1;i<=n;++i)
            cout<<b[i];
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;++i){  //遍历每一种情况
        if(!vis[i]){  //check满足
            vis[i] = 1;  //标记
            b[s] = a[i];
            dfs(s+1);  //继续搜索
            vis[i] = 0; //回溯，将已访问标记清除

            while(a[i]==a[i+1]) i++;  //去重
        }
    }
    return;
}


int main()
{
    memset(a,0,sizeof(a));
    memset(vis,0,sizeof(vis));
    cin>>a+1;
    n = strlen(a+1);
    dfs(1);
}
