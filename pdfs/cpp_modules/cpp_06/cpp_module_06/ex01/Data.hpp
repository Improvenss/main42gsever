#ifndef DATA_HPP
#define DATA_HPP

#include <string>

typedef struct 
{
    std::string name;
    std::string department;
    std::string job;
    int age;
    bool isActive;
} Data;

uintptr_t serialize(Data* data);
Data* deserialize(uintptr_t raw);

#endif