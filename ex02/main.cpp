#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    cout << "Top: " << mstack.top() << endl;

    mstack.pop();

    cout << "Size: " << mstack.size() << endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    cout << "Stack elements: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << "Size: " << mstack.size() << endl;

    return 0;
}
