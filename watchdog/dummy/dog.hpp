#if !defined WATCHDOG_DUMMY_DOG_HPP_INCLUDED
#define      WATCHDOG_DUMMY_DOG_HPP_INCLUDED

#include <iostream>

#include "./level.hpp"

namespace watchdog {

    template<level = level::info, class Source = std::ostream>
    class dog{
    public:

        dog(Source const& src = std::cerr)
        {}

        template<class... Args>
        void yelp(Args &&... args)
        {
        }

        template<class... Args>
        void bow(Args &&... args)
        {
        }

        template<class... Args>
        void woof(Args &&... args)
        {
        }
    };

} // namespace watchdog

#endif    // WATCHDOG_DOG_DUMMY_HPP_INCLUDED
