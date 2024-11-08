#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return (*this);
}

Span::~Span() {}

// Adds a single number
void Span::addNumber(int number)
{
    if (_numbers.size() >= _maxSize)
        throw SpanFullException();
    _numbers.push_back(number);
}

// Finds the shortest span
int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw NotEnoughElementsException();
    
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    int minSpan = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size() - 1; i++)
    {
        int span = sorted[i + 1] - sorted[i];
        if (span < minSpan)
            minSpan = span;
    }
    return (minSpan);
}

// Finds the longest span
int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw NotEnoughElementsException();
    int minElement = *std::min_element(_numbers.begin(), _numbers.end());
    int maxElement = *std::max_element(_numbers.begin(), _numbers.end());
    return (maxElement - minElement);
}