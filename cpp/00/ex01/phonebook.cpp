//
// Created by 한필호 on 11/1/23.
//

#include "phonebook.h"

PhoneBook::PhoneBook() : _infos(), _size(0){}

void PhoneBook::printInfo(const std::string& contactInfo) {
    std::string skip = "...";
    std::string tmp = contactInfo;

    if (tmp.length() > 10)
        std::cout << std::left << std::setw(10) << tmp.replace(7, tmp.length(), skip);
    else
        std::cout << std::left << std::setw(10) << tmp;
    std::cout << "|";
}

void PhoneBook::add(Contact info) {
    _infos[_size++ % 8] = info;
}

bool PhoneBook::search_all() {
    std::cout << "\n⌈";
    std::cout << std::left << std::setw(10) << "index";
    std::cout << "|";
    std::cout << std::left << std::setw(10) << "firstname";
    std::cout << "|";
    std::cout << std::left << std::setw(10) <<  "lastname";
    std::cout << "|";
    std::cout << std::left << std::setw(10) << "nickname";
    std::cout << "⌉";
    std::cout << "\n";
    if (_size == 0)
    {
        std::cout << "|";
        std::cout << "                 " << "No contact";
        std::cout << "                " << "|";
        std::cout << "\n";
        return false;
    }
    for (int idx = 0; idx < 8; idx++)
    {
        if (idx >= _size) break;
        std::cout << "|";
        std::cout << std::left << std::setw(10) << idx;
        std::cout << "|";
        printInfo(_infos[idx].getFirstname());
        printInfo(_infos[idx].getLastname());
        printInfo(_infos[idx].getNickname());
        std::cout << "\n";
    }
    return true;
}

bool PhoneBook::search(std::string idx) {
    Contact info;
    int index = 0;

    index = idx[0] - '0';
    if (idx.length() >= 2 || index >= _size || index >= (8))
    {
        std::cout << "\n ** Wrong index! ** \n";
        return false;
    }
    info = _infos[index];
    std::cout << "\n-------------------------------------------\n";
    std::cout << "First name : " << info.getFirstname() << "\n";
    std::cout << "Last name : " << info.getLastname() << "\n";
    std::cout << "Nick name : " << info.getNickname() << "\n";
    std::cout << "Phone : " << info.getPhone() << "\n";
    std::cout << "-------------------------------------------\n";
    return true;
}

