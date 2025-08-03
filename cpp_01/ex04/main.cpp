#include <iostream>
#include <string>
#include <fstream>

bool validate_args(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cout << "Usage: ./loser file_name.txt s1 s2\n";
        return false;
    }
    if (argv[1][0] == '\0') 
    {
        std::cout << "Second argument (file name) is empty.\n";
        return false;
    }
    if (argv[2][0] == '\0') 
    {
        std::cout << "Third argument (s1) must not be empty.\n";
        return false;
    }
    if (argv[3][0] == '\0') 
    {
        std::cout << "Forth argument (s2) must not be empty.\n";
        return false;
    }
    return true;
}


std::string replace_by_line(const std::string& line, const std::string& s1, const std::string& s2)
{
    std::string result;
    size_t i = 0;
    while (i < line.size()) 
    {
        size_t position = line.find(s1, i);
        if (position == std::string::npos) 
        {
            result += line.substr(i);
            break;
        }
        result += line.substr(i, position - i);
        result += s2;
        i = position + s1.size();
    }
    return result;
}

bool processFile(const char* filename, const std::string& s1, const std::string& s2, std::string& rebuilt)
{
    std::ifstream infile(filename); //read
    if (!infile) {
        std::cout << "Failed to open file for reading: "<< filename << "\n";
        return false;
    }

    std::string line;
    rebuilt.clear();
    while (std::getline(infile, line))
    {
        rebuilt+= replace_by_line(line, s1, s2);
        rebuilt+= '\n';
    }
    return true;
}
bool writeFile(const char* filename, const std::string& content)
{
    std::ofstream outfile(filename);
    if (!outfile) 
    {
        std::cout << "Failed to open file for writing: "<< filename << "\n";
        return false;
    }
    outfile << content;
    return true;
}

int main(int argc, char *argv[])
{
    if (!validate_args(argc, argv))
        return 1;
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::string rebuilt;

    if (!processFile(argv[1], s1, s2, rebuilt))
        return 1;

    if (!writeFile(argv[1], rebuilt))
        return 1;
    return 0;
}


