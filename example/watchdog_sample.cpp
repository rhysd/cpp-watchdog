#include <iostream>

#include "../watchdog/watchdog.hpp"

struct klass{
    int i, j;
    klass(int i_, int j_) : i(i_), j(j_){}
};

std::ostream &operator<<(std::ostream &o, klass k)
{
    o << k.i * k.j;
    return o;
}

int main()
{
    // specify log level
    // it may be convenient if a dog is defined in global field
    watchdog::dog<watchdog::level::warning> dog(std::cerr);

    dog.yelp("this is information message."); // this message is not logged because of log level
    dog.bow("this is warning message!");
    dog.woof("this ie error message!!");

    int foo = 1;
    char bar = 'a';
    klass baz(2, 3);

    dog.bow("functions are variadic, like this", foo, bar, baz); // 'functions are variadic, like this 1 a 6' is logged

    // you can add filter (not implemented)
    dog.add_filter("filter name", [](std::string const& s){ return true; });

    // you can add message mapper (not implemented)
    dog.add_mapper("mapper name", [](std::string const& s){ return s + "!!!"; });

    return 0;
}
