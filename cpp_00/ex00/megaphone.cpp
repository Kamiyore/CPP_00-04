# include <iostream>
# include <cctype>

int main(int argc, char *argv[])
{
    int i = 1;
    if(argc < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        while(argv[i])
         {
            for(int j = 0; argv[i][j]; j++)
                std ::cout << (char)toupper(argv[i][j]); 
           i++; 
         }
    }
    std::cout << std::endl;
    return 0;
}
