# Dogs are watching your C++ code!

This is library for logging in C++.

## Example

```cpp
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
    auto dog = watchdog::dog(std::cout, watchdog::level::warning);

    dog.yelp("this is information message."); // this message is not logged because of log level
    dog.bow("this is warning message!");
    dog.woof("this ie error message!!");

    int foo = 1;
    char bar = 'a';
    klass baz(2, 3);

    dog.bowwow("functions are variadic, like this", foo, bar, baz); // 'functions are variadic, like this 1 a 6' is logged

    // you can add filter
    dog.add_filter("filter name", [](std::string const& s){ return true; });

    // you can add message mapper
    dog.add_mapper("mapper name", [](std::string const& s){ return s + "!!!"; });

    return 0;
}
```

#License

MIT License.

    Copyright (c) 2013 rhysd

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
    of the Software, and to permit persons to whom the Software is furnished to do so,
    subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
    INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
    PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
    LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
    TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR
    THE USE OR OTHER DEALINGS IN THE SOFTWARE.
