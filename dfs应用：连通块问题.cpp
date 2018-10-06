#include <iostream>
using namespace std;
#define MAX_N 100
#define MAX_M 100

/* 连通块搜索问题 <Lake Counting> (POJ No.2386)   / <Oil Deposits> (POJ 1562)
 * 有一个大小为NxM的园子，雨后积起了水。八连通的积水被认为是连接在一起的。请求出园子里总共有多少水洼？（w表示积水，.表示没有积水)
 * 思路：
 * 从任意'w'开始，不停的把邻接的部分用'.'代替。1次dfs后与初始的这个w连接的所有w就被替换成了'.'
 * 因此直到图中不再存在w为止，总共进行dfs的次数就是答案了。8个方向对应了8种状态转移，每个格子作为dfs的参数至多被调用一次。
 */

//输入
int N,M;
char field[MAX_N][MAX_M+1];

//现在位置(x,y)
void dfs(int x,int y){
    //将现在所在位置替换为.
    field[x][y] = '.';

    //循环遍历移动的8个方向
    for(int dx = -1; dx <= 1; dx++){
        for(int dy = -1; dy <=1; dy++){
            //向x方向移动dx，向y方向移动dy，移动后的结果为(nx,ny)
            int nx = x + dx, ny = y + dy;
            //判断(nx,ny)是不是在园子内，以及是否有积水
            if(nx>=0 && nx<N && ny>=0 && ny<M && field[nx][ny] == 'W') dfs(nx,ny);
        }
    }
    return;
}

void solve(){
    int res = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(field[i][j] == 'W'){
                // 从有W的地方开始dfs
                dfs(i,j);
                res++;
            }
        }
    }
    printf("%d\n",res);
}


int main()
{
    cin>>N>>M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin>>field[i][j];
    solve();

    return 0;
}
