#include <iostream>
#include <set>
using namespace std;

//ʵ��һ������������

//��ʾ�ڵ�Ľṹ��
struct node
{
    int val;
    node *lch,*rch;
};

//����x
node* insert(node *p,int x){
    if(p == NULL){
        node *q = new node;
        q->val = x;
        q->lch = q->rch = NULL;
        return q;
    }
    else if(x < p->val) p->lch = insert(p->lch,x);
    else p->rch = insert(p->rch,x);
    return p;  //�Ѿ����ڣ�ֱ�ӷ���
}

//Ѱ��x
bool find(node *p,int x){
    if(p == NULL) return false;
    else if(x == p->val) return true;
    else if(x < p->val) return find(p->lch,x);
    else return find(p->rch,x);
}

//ɾ��x
node* remove(node *p,int x){
    if (p == NULL) return NULL;
    else if(x < p->val) p->lch = remove(p->lch,x);
    else if(x > p->val) p->rch = remove(p->rch,x);
    else{
        //��������
        if(p->lch == NULL){
            node *q = p->rch;
            delete p;
            return q;
        }
        //����������
        else if(p->lch->rch == NULL){
            node *q = p->lch;
            q->rch = p->rch;
            delete p;
            return q;
        }
        //���϶������㣬���������
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
    //û���ҵ���ֱ�ӷ���
    return p;
}

int main()
{
    node *root = NULL;
    //������ֵ
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

    //Ѱ����ֵ10
    bool flag = find(root,10);
    cout<<flag<<endl;

    //�����µ���ֵ
    root = insert(root,6);

    remove(root,15);           //ɾ����ֵ15
    flag = find(root,15);      //Ѱ����ֵ15
    cout<<flag<<endl;


    return 0;
}
