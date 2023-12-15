#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int main()
{
    std::ifstream       ifs;
    std::string         str;
    const std::string   numbers = "0123456789";
    int                 value = 0;

    ifs.open("input.txt", std::ios::in);
    if (!ifs)
    {
        std::cerr << "File couldn't be opened." << std::endl;
        return 1;
    }
    while (std::getline(ifs, str))
    {
        size_t first = str.find_first_of(numbers);
        size_t last = str.find_last_of(numbers);
        std::string line_value = std::string() + str.at(first) + str.at(last);
        value += std::stoi(line_value);
    }
    std::cout << "Sum of values : " << value << std::endl;
    ifs.close();
}