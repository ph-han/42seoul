//
// Created by 한필호 on 11/1/23.
//

#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {
private:
    std::string _firstname;
    std::string _lastname;
    std::string _nickname;
    std::string _phone;
    std::string _darkest_secret;
public:
    void           set_firstname(std::string firstname);
    void           set_lastname(std::string lastname);
    void           set_nickname(std::string nickname);
    void           set_phone(std::string phone);
    void           set_darkest_secret(std::string secret);
    std::string    get_firstname(void);
    std::string    get_lastname(void);
    std::string    get_nickname(void);
    std::string    get_phone(void);
    std::string    get_darkest_secret(void);
};

#endif //CONTACT_H
