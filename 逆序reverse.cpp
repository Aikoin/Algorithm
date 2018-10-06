#include <iostream>
#include <vector>
using namespace std;

template <class BidirectionalIterator>
void reverse (BidirectionalIterator first, BidirectionalIterator last)
{
    while ((first!=last)&&(first!=--last)) {
        iter_swap(first,last);
        ++first;
    }
}

int main()
{
    vector<int> a;
    for(int i=0;i<10;++i)
        a.push_back(i);
    reverse(a.begin(),a.end());
    for(vector<int>::iterator t = a.begin();t!=a.end();++t)
        cout<<*t<<" ";
    cout<<endl;

    return 0;
}



