#include <iostream>
using namespace std;
#define MAX_N 100
#define MAX_M 100

/* ��ͨ���������� <Lake Counting> (POJ No.2386)   / <Oil Deposits> (POJ 1562)
 * ��һ����СΪNxM��԰�ӣ���������ˮ������ͨ�Ļ�ˮ����Ϊ��������һ��ġ������԰�����ܹ��ж���ˮ�ݣ���w��ʾ��ˮ��.��ʾû�л�ˮ)
 * ˼·��
 * ������'w'��ʼ����ͣ�İ��ڽӵĲ�����'.'���档1��dfs�����ʼ�����w���ӵ�����w�ͱ��滻����'.'
 * ���ֱ��ͼ�в��ٴ���wΪֹ���ܹ�����dfs�Ĵ������Ǵ��ˡ�8�������Ӧ��8��״̬ת�ƣ�ÿ��������Ϊdfs�Ĳ������౻����һ�Ρ�
 */

//����
int N,M;
char field[MAX_N][MAX_M+1];

//����λ��(x,y)
void dfs(int x,int y){
    //����������λ���滻Ϊ.
    field[x][y] = '.';

    //ѭ�������ƶ���8������
    for(int dx = -1; dx <= 1; dx++){
        for(int dy = -1; dy <=1; dy++){
            //��x�����ƶ�dx����y�����ƶ�dy���ƶ���Ľ��Ϊ(nx,ny)
            int nx = x + dx, ny = y + dy;
            //�ж�(nx,ny)�ǲ�����԰���ڣ��Լ��Ƿ��л�ˮ
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
                // ����W�ĵط���ʼdfs
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
