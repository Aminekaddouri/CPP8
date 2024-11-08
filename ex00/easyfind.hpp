#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <exception>

// Custom exception class for better error handling
class NotFoundException : public std::exception
{
public:
    const char* what() const throw()
    {
        return "Element not found in the container";
    }
};

template <typename T>
typename T::iterator easyfind(T& container, int toFind)
{
    // use std::find to search for the integer in the container
    typename T::iterator it = std::find(container.begin(), container.end(), toFind);

    // check if element was not found
    if (it == container.end())
        throw NotFoundException();
    return(it);
}

#endif