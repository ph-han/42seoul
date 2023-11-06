//
// Created by 한필호 on 11/1/23.
//

#include "phonebook.h"

PhoneBook::PhoneBook() : _infos(), _size(0){}

void PhoneBook::add(Contact info) {
    if (_size >= 7)
        _size %= 7;
    _infos[_size++] = info;
}

bool PhoneBook::search_all() {
    std::cout.width(10);
    std::cout << "index | ";
    std::cout.width(10);
    std::cout << "firstname | ";
    std::cout.width(10);
    std::cout << "lastname | ";
    std::cout.width(10);
    std::cout << "phone\n";
    for (int i = 0; i < _size; i++)
    {
        std::cout.width(10);
        std::cout << i;
        std::cout.width(10);
        std::cout << _infos[i].get_firstname();
        std::cout.width(10);
        std::cout << _infos[i].get_lastname();
        std::cout.width(10);
        std::cout << _infos[i].get_phone() << "\n";
    }
    return (false);
}

