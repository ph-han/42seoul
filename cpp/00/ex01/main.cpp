//
// Created by 한필호 on 11/2/23.
//

#include <iostream>
#include <string>
#include "phonebook.h"

int main(void) {
    std::string cmd;
    std::string tmp;
    PhoneBook   phoneBook{};
    Contact     info;

    while (1) {
        getline(cin, cmd);
        if (!cmd.compare("ADD"))
        {
            std::cout << "Input firstname : "
            getline(cin, tmp);
            info.set_firstname(tmp);
            std::cout << "Input lastname : "
            getline(cin, tmp);
            info.set_lastname(tmp);
            std::cout << "Input nickname : "
            getline(cin, tmp);
            info.set_nickname(tmp);
            std::cout << "Input phone : "
            getline(cin, tmp);
            info.set_phone(tmp);
            phoneBook.add(info);
        }
        else if (!cmd.compare("SEARCH"))
        {

        }
        else if (!cmd.compare("EXIT"))
            break;
        else
            std::cout << "Wrong command!\n";
    }
}
