//
// Created by 한필호 on 11/1/23.
//

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include "contact.h"

class PhoneBook {
private:
    Contact _infos[8];
    int     _size;
public:
    PhoneBook ();
    void    add(Contact info);
    bool    search_all();
};

#endif //PHONEBOOK_H
