#include "easyfind.hpp"

template <typename T>
void tryFind(T &container, int value)
{
    try
    {
        typename T::iterator it = easyfind(container, value);
        cout << "Found Element: " << *it << endl;
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
        return 1;
    }
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    vector<int> vec(arr, arr + 5);

    arr[0] = 100;

    cout << "-------------------- arr[0] -------------------" << endl;
    cout << arr[0] << endl;

    cout << "-------------------- vec[0] -------------------" << endl;
    cout << vec[0] << endl;

    cout << "-------------------- VEC -------------------" << endl;

    tryFind(vec, 30);
    tryFind(vec, 100);

    list<int> lst;
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(25);
    lst.push_back(35);
    lst.push_back(45);

    cout << "-------------------- LST -------------------" << endl;

    tryFind(lst, 25);
    tryFind(lst, 999);

    return 0;
}
