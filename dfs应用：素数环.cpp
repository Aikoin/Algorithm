//UVa524 ����������
//����һ��ȫ���еķ�������
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int a[20];
int isp[40];

bool is_prime(int n)  //�ж�n�Ƿ�Ϊ����
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
        for(int i=2;i<=n*2;++i) isp[i] = is_prime(i);  //�����������ӿ�����ж�
        for(int i=0;i<n;++i)
            a[i] = i+1;   //��һ������
        do{
            int ok = 1;
            for(int i=0;i<n;++i)
                if(!isp[a[i]+a[(i+1)%n]]){  //����������Ӳ�Ϊ���� ��0��Ԫ�����n-1��Ԫ������
                    ok = 0;
                    break;
                }
            if(ok){              //�жϺϷ���
                for(int i=0;i<n;++i){
                    if(i!=0) cout<<" ";
                    cout<<a[i];
                }
                cout<<endl;
            }
        }while(next_permutation(a+1,a+n));  //��1��ʼ���У�1��λ�ò��䣩
    }
    return 0;
}
//���к��֣���n=8��ʱ����Ѿ��е����ˣ����ܻᳬʱ��



//��������dfs���Ļ��ݷ���
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int a[20];
int isp[40];
int vis[20];

bool is_prime(int n)  //�ж�n�Ƿ�Ϊ����
{
    for(int i=2;i*i<=n;++i)
        if(n%i==0) return 0;
    return 1;
}

void dfs(int cur)  //cur:��ǰҪ���е������±��
{
    if(cur==n && isp[a[0]+a[n-1]]){  //�жϱ߽磬�����˲��Ե�һ���������һ����
        for(int i=0;i<n;++i){    //��ӡ����
            if(i!=0) cout<<" ";
            cout<<a[i];
        }
        cout<<endl;
    }
    for(int i=2;i<=n;++i)  //���Է���ÿ����i
        if(!vis[i] && isp[i+a[cur-1]]){  //����check������iû���ù���������ǰһ����֮��Ϊ����
            a[cur] =i;
            vis[i] = 1;   //���
            dfs(cur+1);
            vis[i] = 0;  //�����־
        }

}

int main()
{
    while(cin>>n){
        memset(vis,0,sizeof(vis));
        for(int i=2;i<=n*2;++i)
            isp[i] = is_prime(i);  //�����������ӿ�����ж�
        a[0] = 1;
        dfs(1);  //���±�Ϊ1������ʼ����
    }
    return 0;
}


//���ݷ�������-���Է����˺ܶ࣬��ʹn=18�ٶ�Ҳ����
