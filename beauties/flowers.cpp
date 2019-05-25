#include <flowers.h>

#ifndef I_GOT_A_MAIN
#include <cstdlib>
#include <iostream>
#include <memory>
#include <vector>
#endif

namespace flowers
{
    Rose::Rose(std::string name)
        : name(name), thorn(true)
    {}

    Rose::Rose(const Rose &r)
        : name(r.name), thorn(true)
    {}

    std::string Rose::get_name()
    {
        return this->name;
    }

    bool Rose::is_sweet_smelling()
    {
        return true;
    }

    bool Rose::has_thorn()
    {
        return this->thorn;
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
                std::cerr << "\tN\t\tNumber of roses [default: 10]";
                std::cerr << std::endl;
                return 0;
            }
            n = std::atoi(argv[1]);
        }

        std::unique_ptr<Rose> r1(new Rose());
        std::unique_ptr<Rose> r2(new Rose("Montague"));

        std::cout << "A rose named " << r1->get_name() << " "
            << (r1->is_sweet_smelling() ? "smells " : "does not smell ")
            << "sweet" << std::endl;

        std::cout << "A rose named " << r2->get_name() << " "
            << (r2->is_sweet_smelling() ? "smells " : "does not smell ")
            << "sweet" << std::endl;

        std::vector<std::unique_ptr<Rose>> bush(n);
        for(int i = 0; i < n; i++) {
            bush[i] = std::unique_ptr<Rose>(new Rose());
        }

        int thorns = 0;
        for(auto &r : bush) {
            thorns += int(r->has_thorn());
        }

        if(thorns == n) {
            std::cout << "Every rose (out of " << n
                << ") has its thorn" << std::endl;
        }
        else {
            std::cout << "Bret Michaels was wrong" << std::endl;
        }

        return 0;
    }
#endif
}
