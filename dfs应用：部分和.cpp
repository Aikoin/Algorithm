#include <iostream>
#include <cstring>
using namespace std;
#define MAX_N  1000

/* <���ֺ�����>
 * ��������a1��a2��...an���ж��Ƿ���Դ���ѡ����������ʹ���ǵĺ�ǡ��Ϊk��
 * ˼·��
 * ��a1��ʼ��˳�����ÿ�����ӻ򲻼ӣ���ȫ��n���������������ж����ǵĺ��ǲ���k��
 * �����㷨����:״̬��ת�ơ�
 */

//����
int a[MAX_N];
int n,k;

//�Ѿ���ǰi��õ��˺�sum��Ȼ�����i��֮��Ľ��з�֧
bool dfs(int i,int sum){
    //���ǰn�������ˣ��򷵻�sum�Ƿ���k���
    if(i==n) return sum == k;

    //������a[i]�����
    if(dfs(i+1,sum)) return true;

    //����a[i]�����
    if(dfs(i+1,sum+a[i])) return true;

    //�����Ƿ����a[i]�����ܴճ�k�ͷ���false
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
