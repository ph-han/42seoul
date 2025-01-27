//
// Created by 한필호 on 11/2/23.
//

#include "phonebook.h"
#include <cstdio>

static std::string inputAndCheck(std::string msg) {
    const std::string space = " \t\n";
    std::string input = "";

    std::cin.sync();
    do {
        std::cout << msg;
        while (!getline(std::cin, input)) {
            std::clearerr(stdin);
            std::cin.clear();
            std::cout << "\n ** Input error! Retry. ** \n\n";
            std::cout << msg;
        }
        input.erase(0, input.find_first_not_of(space));
        input.erase(input.find_last_not_of(space) + 1);
        if (input.length() < 1)
            std::cout << "\n ** Enter letters! Retry. ** \n\n";
    } while (input.length() < 1);
    
    return input;
}

int main(void) {
    PhoneBook   phonebook;
    Contact     info;
    std::string cmd;
    std::string input = "";

    while (1) {
        cmd = inputAndCheck("\nInput command [ADD, SEARCH, EXIT] : ");
        if (!cmd.compare("ADD")) {
            input = inputAndCheck("-- 1. Input first name : ");
            info.setFirstname(input);
            input = inputAndCheck("-- 2. Input last name : ");
            info.setLastname(input);
            input = inputAndCheck("-- 3. Input nickname : ");
            info.setNickname(input);
            input = inputAndCheck("-- 4. Input phone : "); 
            info.setPhone(input);
            input = inputAndCheck("-- 5. Input darkest secret : ");
            info.setDarkestSecret(input);
            phonebook.add(info);
        } else if (!cmd.compare("SEARCH")) {
            if (phonebook.search_all()) {
                do {
                    input = inputAndCheck("\n-- Input index number : ");
                } while (!phonebook.search(input));
            }
        } else if (!cmd.compare("EXIT")) {
            break;
        } else {
            std::cout << "\n\n ** Wrong command! ** \n\n";
        }
    }
    return (0);
}
