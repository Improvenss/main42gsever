/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:31:14 by cyalniz           #+#    #+#             */
/*   Updated: 2023/01/06 14:40:35 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>
#include "Data.hpp"


int main(){
    Data data;

    data.name = "Cagri";
    data.department = "Software";
    data.job = "Software Developer";
    data.age = 27;
    data.isActive = true;

	std::cout << "Name: " << data.name << std::endl;
	std::cout << "Department: " << data.department << std::endl;
	std::cout << "Job: " << data.job << std::endl;
	std::cout << "Age: " << data.age << std::endl;
	std::cout << "IsActive: " << data.isActive << std::endl;

    std::cout << std::endl << std::endl;
    uintptr_t	serialize_input = serialize(&data);
	Data*		deserialize_output = deserialize(serialize_input);

    std::cout << "Name: " << deserialize_output->name << std::endl;
	std::cout << "Department: " << deserialize_output->department << std::endl;
	std::cout << "Job: " << deserialize_output->job << std::endl;
	std::cout << "Age: " << deserialize_output->age << std::endl;
	std::cout << "IsActive: " << deserialize_output->isActive << std::endl;


    int value = 0x12345678;
    int* value_ptr = &value;
    char* char_ptr = reinterpret_cast<char*>(value_ptr);
    std::cout<<*value_ptr<<std::endl;
    //std::cout<<char_ptr<<std::endl;


    *value_ptr = 12;
    std::cout<<*value_ptr<<std::endl;

    //char_ptr = reinterpret_cast<char*>(123);
    //std::cout<<*char_ptr<<std::endl;


}