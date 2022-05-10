#pragma once
#include <stdexcept>
#include <string>
class InternalException : public std::runtime_error {
public:
    InternalException(std::string message) : std::runtime_error(message) {}
    
};