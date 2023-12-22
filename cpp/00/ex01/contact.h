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
    std::string _darkestSecret;
public:
    void           setFirstname(std::string firstname);
    void           setLastname(std::string lastname);
    void           setNickname(std::string nickname);
    void           setPhone(std::string phone);
    void           setDarkestSecret(std::string secret);
    const std::string&    getFirstname(void) const;
    const std::string&    getLastname(void) const;
    const std::string&    getNickname(void) const;
    const std::string&    getPhone(void) const;
    const std::string&    getDarkestSecret(void) const;
};

#endif //CONTACT_H
