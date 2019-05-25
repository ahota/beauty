namespace gems
{
    enum TimeOrder {
        SECONDS = 0,
        MINUTES = 10,
        HOURS = 20,
        DAYS = 30,
        WEEKS = 40,
        MONTHS = 50,
        YEARS = 60,
        DECADES = 70,
        CENTURIES = 80,
        MILLENIA = 90,
        EONS = 100,
        FOREVER = 1000
    };

    class Diamond {
    public:
        Diamond();
        Diamond(const Diamond &d);
        TimeOrder get_lifespan();
    private:
        TimeOrder lifespan;
    };

#ifndef I_GOT_A_MAIN
    extern "C" int main(int argc, char **argv);
#endif
}
