#include <iostream>
#include <cstring>
using namespace std;

/* ��������  POJ 1321
 * ����Ͱ˻ʺ�֮ͬ�����ڰ˻ʺ��Ǵӵ�һ��һֱ�ҵ�����n�У��������������ĳһ�в������ӡ�
 * ��������dfs�����Ҫ����дһ������ѭ�����к��ж�Ҫ���ǵ������Ǽ���̶��С�
 * ����˵��ÿ���дӵ�x�п�ʼ�����ݺ󣬻����Դӵ�x+i�м������ã��Ӷ����ǵ��������
 */

int n,k;  
char map[10][10]; 
int visit[10];  
int ans = 0;

void dfs(int row,int cnt) //row:�� cnt:����������
{
    if(cnt == k+1){  //�жϱ߽�
        ans++;
        return;
    }
    for(int i= row;i<n;++i){  //��
        for(int j = 0;j<n;j++){  //ÿһ���n��״̬ ����ÿһ�ֿ���
            if(map[i][j]=='#'&&!visit[j]){  //����check����
                visit[j] = 1;   //���
                dfs(i+1,cnt+1);  //����һ�㣬����һ������
                visit[j] = 0;  //����
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
        dfs(0,1);  //�ӵ�0�㣬��ʼ�ŵ�һ������
        cout<<ans<<endl;
    }

    return 0;
}
