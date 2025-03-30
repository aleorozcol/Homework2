#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Time {
    private:

        int hour, min, sec;
        bool am_or_pm;

        bool is_it_valid (int h, int m, int s);

        int modified_hour(int h);

        string is_it_am(bool am);

    public:

        Time (int h, int m, int s, bool am);
    
        void get_time();
    
        void get_time_24();
    
        void set_hour(int h);
        void set_min(int m);
        void set_sec(int s);
        void set_am_pm(bool am);
    
        int get_hour();
        int get_min();
        int get_sec();
};