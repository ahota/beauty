#include <string>

namespace flowers
{
    class Rose {
    public:
        Rose(std::string name="rose");
        Rose(const Rose &r);
        std::string get_name();
        bool is_sweet_smelling();
        bool has_thorn();
    private:
        std::string name;
        bool thorn;
    };

#ifndef I_GOT_A_MAIN
        extern "C" int main(int argc, char **argv);
#endif
}
