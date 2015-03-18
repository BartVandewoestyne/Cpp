#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> readit(const std::string& ifile)
{
    std::ifstream ifs(ifile);
    std::string line;
    std::vector<std::string> v;
    while (std::getline(ifs, line))
    {
        v.push_back(line);
    }
    return v;
}

int main()
{
    std::vector<std::string> vs;
    vs = readit(std::string("text.txt"));
    for (const auto& e : vs)
    {
        std::cout << e << std::endl;
    }
}
