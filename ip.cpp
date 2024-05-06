#include <iostream>

int main()
{
    int age;
    std::string name;

    std::cin >> age; // input age + \n
    std::getline(std::cin >> std::ws, name); // eliminate whitespace before getting name input

    std::cout << "Hello " << name << ", you're " << age << " years old." << std::endl;

    return 0;
}
