#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>
#include <iterator>

class Span
{
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;
public:
    Span();
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    // Member functions
    void addNumber(int number);
    template <typename Iterator>
    void addNumber(Iterator begin, Iterator end);

    int shortestSpan() const;
    int longestSpan() const;

    // Exception classes
    class SpanFullException : public std::exception
    {
        const char* what() const throw()
        {
            return "Span is already full";
        }
    };

    class NotEnoughElementsException : public std::exception
    {
        const char* what() const throw()
        {
            return "Not enough elements to calculate span";
        }
    };
};

#include "Span.tpp"

#endif