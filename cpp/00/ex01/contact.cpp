//
// Created by 한필호 on 11/2/23.
//
#include "contact.h"

std::string Contact::get_firstname(void) {
    return (_firstname);
}

std::string Contact::get_lastname(void) {
    return (_lastname);
}

std::string Contact::get_nickname(void) {
    return (_nickname);
}

std::string Contact::get_phone(void) {
    return (_phone);
}

void Contact::set_first_name(std::string firstname) {
    _firstname = firstname;
}

void Contact::set_last_name(std::string lastname) {
    _lastname = lastname;
}

void Contact::set_nickname(std::string nickname) {
    _nickname = nickname;
}

void Contact::set_phone(std::string phone) {
    _phone = phone;
}