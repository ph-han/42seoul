//
// Created by 한필호 on 11/2/23.
//
#include "contact.h"

const std::string& Contact::getFirstname(void) const{
    return (_firstname);
}

const std::string &Contact::getLastname(void) const
{
    return (_lastname);
}

const std::string &Contact::getNickname(void) const
{
    return (_nickname);
}

const std::string &Contact::getPhone(void) const {
    return (_phone);
}

const std::string &Contact::getDarkestSecret(void) const {
    return (_darkestSecret);
}

void Contact::setFirstname(std::string firstname) {
    _firstname = firstname;
}

void Contact::setLastname(std::string lastname) {
    _lastname = lastname;
}

void Contact::setNickname(std::string nickname) {
    _nickname = nickname;
}

void Contact::setPhone(std::string phone) {
    _phone = phone;
}

void Contact::setDarkestSecret(std::string secret) {
    _darkestSecret = secret;
}
