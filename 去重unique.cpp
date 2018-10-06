两种方法

n = unique(a,a+m+n)-a;    //返回去重后下标
        for(int i=0;i<n;i++){
            printf("%d ",a[i]);
        }

vector::iterator t = unique(a.begin(),a.end());  //去重 返回迭代器 指向去重后最后一个元素
a.erase(t,a.end());   //删去多余元素
for(t=a.begin();t!=a.end();t++){
    printf("%d ",*t);
}