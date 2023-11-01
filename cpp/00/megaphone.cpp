#include <iostream>

void to_upper(char &c) {
    c = std::toupper(static_cast<unsigned char>(c));
}

int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for (int i = 1; i < ac; i++)
    {
        std::string str = av[i];
        std::for_each(str.begin(), str.end(), to_upper);
        std::cout << str;
    }
    std::cout << '\n';
    return (0);
}