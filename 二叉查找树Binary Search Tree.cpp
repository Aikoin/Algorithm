#include <iostream>
#include <set>
using namespace std;

//实现一个二叉搜索树

//表示节点的结构体
struct node
{
    int val;
    node *lch,*rch;
};

//插入x
node* insert(node *p,int x){
    if(p == NULL){
        node *q = new node;
        q->val = x;
        q->lch = q->rch = NULL;
        return q;
    }
    else if(x < p->val) p->lch = insert(p->lch,x);
    else p->rch = insert(p->rch,x);
    return p;  //已经存在，直接返回
}

//寻找x
bool find(node *p,int x){
    if(p == NULL) return false;
    else if(x == p->val) return true;
    else if(x < p->val) return find(p->lch,x);
    else return find(p->rch,x);
}

//删除x
node* remove(node *p,int x){
    if (p == NULL) return NULL;
    else if(x < p->val) p->lch = remove(p->lch,x);
    else if(x > p->val) p->rch = remove(p->rch,x);
    else{
        //无左提右
        if(p->lch == NULL){
            node *q = p->rch;
            delete p;
            return q;
        }
        //左无右提左
        else if(p->lch->rch == NULL){
            node *q = p->lch;
            q->rch = p->rch;
            delete p;
            return q;
        }
        //以上都不满足，提左子最大
        else{
            node *q;
            for(q = p->lch;q->rch->rch!=NULL;q = q->rch);
            node *r = q->rch;
            q->rch = r->lch;
            r->lch = p->lch;
            r->rch = p->rch;
            delete p;
            return r;
        }
    }
    //没有找到，直接返回
    return p;
}

int main()
{
    node *root = NULL;
    //插入数值
    root = insert(root,7);
    root = insert(root,2);
    root = insert(root,1);
    root = insert(root,5);
    root = insert(root,4);
    root = insert(root,15);
    root = insert(root,10);
    root = insert(root,17);
    root = insert(root,8);
    root = insert(root,11);
    root = insert(root,16);
    root = insert(root,19);

    //寻找数值10
    bool flag = find(root,10);
    cout<<flag<<endl;

    //插入新的数值
    root = insert(root,6);

    remove(root,15);           //删除数值15
    flag = find(root,15);      //寻找数值15
    cout<<flag<<endl;


    return 0;
}
