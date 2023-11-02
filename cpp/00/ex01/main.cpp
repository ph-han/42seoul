//
// Created by 한필호 on 11/2/23.
//

#include <iostream>
#include <string>
#include "phonebook.h"

int main(void) {
    std::string cmd;
    std::string tmp;
    PhoneBook   phoneBook;
    Contact     info;

    while (1) {
        std::cout << "Input command : ";
        getline(std::cin, cmd);
        if (cmd.empty())
            break ;
        if (!cmd.compare("ADD"))
        {
            std::cout << "Input firstname : ";
            getline(std::cin, tmp);
            if (tmp.empty())
                break ;
            info.set_firstname(tmp);
            std::cout << "Input lastname : ";
            getline(std::cin, tmp);
            if (tmp.empty())
                break ;
            info.set_lastname(tmp);
            std::cout << "Input nickname : ";
            getline(std::cin, tmp);
            if (tmp.empty())
                break ;
            info.set_nickname(tmp);
            std::cout << "Input phone : ";
            getline(std::cin, tmp);
            if (tmp.empty())
                break ;
            info.set_phone(tmp);
            phoneBook.add(info);
            std::cout << "Add successfully!!\n\n";
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
