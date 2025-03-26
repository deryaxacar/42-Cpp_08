#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span &other)
{
    *this = other;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        this->_maxSize = other._maxSize;
        this->_numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
    if (_numbers.size() >= _maxSize)
        throw overflow_error("Error: Span capacity exceeded!");
    _numbers.push_back(number);
}

void Span::addNumbers(vector<int>::iterator begin, vector<int>::iterator end)
{
    if (_numbers.size() + std::distance(begin, end) > _maxSize)
        throw overflow_error("Error: over capacity!");
    _numbers.insert(_numbers.end(), begin, end);
}

int Span::shortestSpan()
{
    if (_numbers.size() < 2)
        throw logic_error("Error: At least two elements are required!");

    vector<int> sortedNumbers(_numbers);
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    int minSpan = sortedNumbers[1] - sortedNumbers[0];
    for (unsigned int i = 1; i < sortedNumbers.size() - 1; i++)
    {
        int span = sortedNumbers[i + 1] - sortedNumbers[i];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan()
{
    if (_numbers.size() < 2)
        throw logic_error("Error: At least two elements are required!");

    int minElement = *std::min_element(_numbers.begin(), _numbers.end());
    int maxElement = *std::max_element(_numbers.begin(), _numbers.end());

    return maxElement - minElement;
}