#define I_GOT_A_MAIN // enforce only the below main function
                     // and also receive blessings for this
                     // code from Positive K
#include <flowers.h>
#include <gems.h>

#include <iostream>

int main(int argc, char **argv)
{
    int n = 10;
    if(argc > 1) {
        if(std::string(argv[1]) == "-h") {
            std::cerr << "Usage:" << std::endl;
            std::cerr << "\t" << argv[0] << " [N]" << std::endl;
            std::cerr << std::endl;
            std::cerr << "Options:" << std::endl;
            std::cerr << "\tN\t\tNumber of items to measure [default: 10]";
            std::cerr << std::endl;
            return 0;
        }
        n = std::atoi(argv[1]);
    }

    int size_rose = sizeof(flowers::Rose);
    int size_diamond = sizeof(gems::Diamond);

    if(n == 1) {
        std::cout << n << " rose weighs " << size_rose * n << " bytes";
    }
    else {
        std::cout << n << " roses weigh " << size_rose * n << " bytes";
    }
    std::cout << std::endl;

    if(n == 1) {
        std::cout << n << " diamond weighs " << size_diamond * n << " bytes";
    }
    else {
        std::cout << n << " diamonds weigh " << size_diamond * n << " bytes";
    }
    std::cout << std::endl;

    return 0;
}
