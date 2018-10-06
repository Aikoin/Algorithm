#include <iostream>
#include <cstring>
using namespace std;

/* 棋盘问题  POJ 1321
 * 本题和八皇后不同之处在于八皇后是从第一行一直找到最后第n行，但是这题可以在某一行不放棋子。
 * 于是我们dfs里面就要考虑写一个二重循环，行和列都要考虑到，我们假设固定行。
 * 就是说，每次行从第x行开始，回溯后，还可以从第x+i行继续调用，从而考虑到所有情况
 */

int n,k;  
char map[10][10]; 
int visit[10];  
int ans = 0;

void dfs(int row,int cnt) //row:行 cnt:放置棋子数
{
    if(cnt == k+1){  //判断边界
        ans++;
        return;
    }
    for(int i= row;i<n;++i){  //层
        for(int j = 0;j<n;j++){  //每一层的n个状态 尝试每一种可能
            if(map[i][j]=='#'&&!visit[j]){  //满足check条件
                visit[j] = 1;   //标记
                dfs(i+1,cnt+1);  //到下一层，放下一个棋子
                visit[j] = 0;  //回溯
            }
        }
    }
    return;
}

int main()
{
    while (cin>>n>>k) {
        if(n==-1&&k==-1) break;
        for(int i =0;i<n;++i)
            for(int j=0;j<n;++j)
                cin>>map[i][j];

        ans = 0;
        memset(visit,0,sizeof(visit));
        dfs(0,1);  //从第0层，开始放第一颗棋子
        cout<<ans<<endl;
    }

    return 0;
}
