#include <iostream>
#include <cstring>
using namespace std;

//������n���ַ�Ҫ���У����������ηŵ�n��������
//��Ҫ��������Ƿ�Ϊ�գ����л���ʲô�ַ��������ǷŽ�����ǡ�
//����һ��Ҫ�ָ���ʼ״̬������n+1������ʱ��һ�������Ѿ�����

char a[12];
char b[12];
int vis[12];
int n;

void dfs(int s)
{
    if(s == n+1){  //�жϱ߽�
        for(int i=1;i<=n;++i)
            cout<<b[i];
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;++i){  //����ÿһ�����
        if(!vis[i]){  //check����
            vis[i] = 1;  //���
            b[s] = a[i];
            dfs(s+1);  //��������
            vis[i] = 0; //���ݣ����ѷ��ʱ�����

            while(a[i]==a[i+1]) i++;  //ȥ��
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
