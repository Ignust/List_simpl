#include <iostream>
#include"list.hpp"

using namespace std;

int main()
{
    List<int> mlist;
    mlist.push_back(1);
    mlist.push_back(2);
    mlist.push_back(3);
    cout << "size = " << mlist.getSize() << endl;
    cout << " [] = " << mlist[2] << endl;

    mlist.pop_Front();
    mlist.pop_Front();
    mlist.pop_Front();
    cout << "size = " << mlist.getSize() << endl;
    mlist.pop_Front();
    mlist.pop_Front();
    mlist.push_back(1);
    mlist.push_back(2);
    mlist.push_back(3);
    cout << "size = " << mlist.getSize() << endl;
    mlist.erase(1);
    cout << "size = " << mlist.getSize() << endl;

    List<int>::iterator(mlist.begin());

    return 0;
}
