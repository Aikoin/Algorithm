//�㷨�� ��Dropping Balls��
����һ�� //ģ�⿪��
#include <iostream>
#include <string.h>
using namespace std;

const int maxd = 20;
int s[1<<maxd];  //���ڵ���Ϊ(2^20)-1

int main()
{
    int d,n;  //dΪҶ����ȣ�nΪС�����
    while (cin>>d>>n) {
        memset(s,0,sizeof(s));
        int k,m = (1<<d)-1;  //kΪ���ر�ţ�mΪ�ܽ����
        for(int i=0;i<n;i++){
            k = 1;
            while (1) {
                s[k] = !s[k];   //С��ÿ����һ�ο��ظı�һ��״̬
                k = s[k]?2*k:2*k+1;   // ���ݿ���״̬���������߻���������
                if(k>m) break;
            }
        }
        printf("%d\n",k/2);
    }

    return 0;
}



��������//ֱ��ģ�����һ��С��
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int d,n;  //dΪҶ����ȣ�nΪС�����
    while (cin>>d>>n) {
        int k = 1;
        for(int i=0;i<d-1;i++){   //ֻ���ж�d-1��
            if(n%2){    //nΪ����
                k = 2*k;     //����������
                n = (n+1)/2; //�����ǵڼ������ڸ�����������
            }
            else{     //nΪż��
                k = 2*k+1;   //����������
                n = n/2;     //�����ǵڼ������ڸ�����������
            }
        }
        printf("%d\n",k);
    }

    return 0;
}
