//
// Created by 한필호 on 11/1/23.
//

#include "phonebook.h"

PhoneBook::PhoneBook() : _infos(), _size(0){}

void PhoneBook::add(Contact info) {
    _infos[_size++ % 8] = info;
}

void PhoneBook::search_all() {
    std::cout << std::left << std::setw(10) << "index";
    std::cout << "|";
    std::cout << std::left << std::setw(10) << "firstname";
    std::cout << "|";
    std::cout << std::left << std::setw(10) <<  "lastname";
    std::cout << "|";
    std::cout << std::left << std::setw(10) << "phone";
    std::cout << "|";
    std::cout << "\n";
    std::string skip = "...";
    std::string tmp;

    for (int idx = 0; idx < 8; idx++)
    {
        if (idx >= _size) break;
        std::cout << std::left << std::setw(10) << idx;
        std::cout << "|";

        tmp = _infos[idx].get_firstname();
        if (tmp.length() > 10)
            std::cout << std::left << std::setw(10) << tmp.replace(7, tmp.length(), skip);
        else
            std::cout << std::left << std::setw(10) << tmp;
        std::cout << "|";

        tmp = _infos[idx].get_lastname();
        if (tmp.length() > 10)
            std::cout << std::left << std::setw(10) << tmp.replace(7, tmp.length(), skip);
        else
            std::cout << std::left << std::setw(10) << tmp;
        std::cout << "|";

        tmp = _infos[idx].get_phone();
        if (tmp.length() > 10)
            std::cout << std::left << std::setw(10) << tmp.replace(7, tmp.length(), skip);
        else
            std::cout << std::left << std::setw(10) << tmp;
        std::cout << "|";

        std::cout << "\n";
    }
}

void PhoneBook::search(std::string idx) {
    Contact info;
    int index = 0;

    if (idx.length() >= 2)
    {
        std::cout << "Wrong idx\n";
        return;
    }
    index = idx[0] - '0';
    if (index >= _size || index >= (8))
    {
        std::cout << "Wrong idx\n";
        return;
    }
    info = _infos[index];
    std::cout << "First name : " << info.get_firstname() << "\n";
    std::cout << "Last name : " << info.get_lastname() << "\n";
    std::cout << "Nick name : " << info.get_nickname() << "\n";
    std::cout << "Phone : " << info.get_phone() << "\n";
}

