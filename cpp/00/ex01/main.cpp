//
// Created by 한필호 on 11/2/23.
//

#include "phonebook.h"

int main(void) {
    PhoneBook   phonebook;
    Contact     info;
    std::string cmd = "";
    std::string tmp = "";

    while (1) {
        std::cout << "Input command : ";
        if (!getline(std::cin, cmd)) {
            std::cout << "Input error! exit. \n"; break ;
        }
        if (!cmd.compare("ADD")) {
            std::cout << "-- 1. Input first name : ";
            if (!getline(std::cin, tmp)) {
                std::cout << "Input error! exit. \n"; break ;
            }
            info.set_firstname(tmp);
            std::cout << "-- 2. Input last name : ";
            if (!getline(std::cin, tmp)) {
                std::cout << "Input error! exit. \n";
                break;
            }
            info.set_lastname(tmp);
            std::cout << "-- 3. Input nickname : ";
            if (!getline(std::cin, tmp)) {
                std::cout << "Input error! exit. \n";
                break;
            }
            info.set_nickname(tmp);
            std::cout << "-- 4. Input phone : ";
            if (!getline(std::cin, tmp)) {
                std::cout << "Input error! exit. \n";
                break;
            }
            info.set_phone(tmp);
            std::cout << "-- 5. Input darkest secret : ";
            if (!getline(std::cin, tmp)) {
                std::cout << "Input error! exit. \n";
                break;
            }
            info.set_darkest_secret(tmp);
            phonebook.add(info);
        } else if (!cmd.compare("SEARCH")) {
            phonebook.search_all();
            std::cout << "-- Input index number : ";
            if (!getline(std::cin, tmp))
                std::cout << "Input error! exit. \n";
            phonebook.search(tmp);
        } else if (!cmd.compare("EXIT")) {
            break;
        } else {
            std::cout << "\n\n ** Wrong command! ** \n\n";
        }
    }
    return (0);
}
