//
// Created by 한필호 on 11/1/23.
//

#include "phonebook.h"

PhoneBook::PhoneBook() : _infos{}, _size{0} {
}

void PhoneBook::add(Contact info) {
    if (_size >= 7)
        _size %= 7;
    _infos[_size++] = info;
}

void PhoneBook::search() {

}

