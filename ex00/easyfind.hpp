#pragma once

#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <exception>

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::list;
using std::vector;

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);

    if (it == container.end())
        throw std::runtime_error("Error: The requested element was not found!");

    return it;
}
