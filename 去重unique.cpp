���ַ���

n = unique(a,a+m+n)-a;    //����ȥ�غ��±�
        for(int i=0;i<n;i++){
            printf("%d ",a[i]);
        }

vector::iterator t = unique(a.begin(),a.end());  //ȥ�� ���ص����� ָ��ȥ�غ����һ��Ԫ��
a.erase(t,a.end());   //ɾȥ����Ԫ��
for(t=a.begin();t!=a.end();t++){
    printf("%d ",*t);
}