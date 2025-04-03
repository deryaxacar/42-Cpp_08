#pragma once

#include <stack>
#include <iostream>
#include <iterator>

using std::cout;
using std::endl;
using std::stack;

template <typename T>
class MutantStack : public stack<T>
{
public:
    MutantStack() {}

    MutantStack(const MutantStack &other) : stack<T>(other) {}

    MutantStack &operator=(const MutantStack &other)
    {
        if (this != &other)
            stack<T>::operator=(other);
        return *this;
    }

    ~MutantStack() {}

    typedef typename stack<T>::container_type::iterator iterator;

    iterator begin() { return stack<T>::c.begin(); }
    iterator end() { return stack<T>::c.end(); }


};
