#include <gems.h>

#include <iostream>
#include <memory>
#include <vector>

namespace gems
{
    Diamond::Diamond()
        : lifespan(FOREVER)
    {}

    Diamond::Diamond(const Diamond &d)
        : lifespan(d.lifespan)
    {}

    TimeOrder Diamond::get_lifespan()
    {
        return this->lifespan;
    }

#ifndef I_GOT_A_MAIN
    extern "C" int main(int argc, char **argv)
    {
        int n = 10;
        if(argc > 1) {
            if(std::string(argv[1]) == "-h") {
                std::cerr << "Usage:" << std::endl;
                std::cerr << "\t" << argv[0] << " [N]" << std::endl;
                std::cerr << std::endl;
                std::cerr << "Options:" << std::endl;
                std::cerr << "\tN\t\tNumber of diamonds [default: 10]";
                std::cerr << std::endl;
                return 0;
            }
            n = std::atoi(argv[1]);
        }

        std::vector<std::unique_ptr<Diamond>> bling(n);
        for(int i = 0; i < n; i++) {
            bling[i] = std::unique_ptr<Diamond>(new Diamond());
        }

        int is_forever = 0;
        for(auto &d : bling) {
            is_forever += int(d->get_lifespan() == FOREVER);
        }

        if(is_forever == n) {
            std::cout << n << " diamonds are forever" << std::endl;
        }
        else {
            std::cout << "Looks ike cubic zirconium to me" << std::endl;
        }

        return 0;
    }
#endif
}
