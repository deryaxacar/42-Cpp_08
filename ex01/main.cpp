#include "Span.hpp"

int main()
{
    try
    {
        Span sp(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        cout << "-------------------- SP 5 -------------------" << endl;
        cout << "Shortest distance: " << sp.shortestSpan() << endl;
        cout << "Longest distance: " << sp.longestSpan() << endl;

        sp.addNumber(99);
    }
    catch (const exception &e)
    {
        cout << "--------------------- ERR --------------------" << endl;
        cerr << e.what() << endl;
        return 1;
    }

    try
    {
        Span sp(10000);
        vector<int> values(10000);

        for (unsigned int i = 0; i < values.size(); i++)
            values[i] = i;

        sp.addNumbers(values.begin(), values.end());

        cout << "------------------ SP 10.000 ----------------" << endl;
        cout << "Shortest distance in 10000 element span: " << sp.shortestSpan() << endl;
        cout << "Longest distance in 10000 element span: " << sp.longestSpan() << endl;
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}
