#include <iostream>
using namespace std;


int main()
{
//    int w[5][5]={{13},{11,8},{12,7,26},{6,14,15,8},{12,7,13,24,11}};
//    int A[5][5] = {0};
//    for(int i=0;i<5;i++)
//        A[4][i] = w[4][i];  //��Ͳ�״̬ȷ��
//    for(int i = 3; i>=0; --i){
//        for(int j = 0; j<=i; ++j){
//            A[i][j] = max(A[i+1][j],A[i+1][j+1])+w[i][j];  //״̬����
//        }
//    }
//    cout<<A[0][0]<<endl;

    int n;
    int w[10][10];
    int A[10][10]={0};
    cin>>n;  //�����м���
    for(int i=1;i<=n;i++)
        for(int j = 1;j<=i;j++)
            cin>>w[i][j];
    for(int i = 1;i<=n;i++)
        A[n][i] = w[n][i];
    for(int i=n-1;i>=1;i--)
        for(int j = 1;j<=i;++j)
            A[i][j] = max(A[i+1][j],A[i+1][j+1])+w[i][j];
    cout<<A[1][1]<<endl;

    return 0;
}


