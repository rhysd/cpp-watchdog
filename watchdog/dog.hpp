#if !defined WATCHDOG_DOG_HPP_INCLUDED
#define      WATCHDOG_DOG_HPP_INCLUDED

#include <iostream>

#include "./level.hpp"

namespace watchdog {

    template<level Level = level::info, class Source = std::ostream>
    class dog{
    public:
        std::ostream mouse;

        dog(Source const& src = std::cerr)
            : mouse(src) {}

        template<class... Args>
        void yelp(Args &&... args)
        {
            bark<level::info>(std::forward<Args>(args)...);
        }

        template<class... Args>
        void bow(Args &&... args)
        {
            bark<level::warning>(std::forward<Args>(args)...);
        }

        template<class... Args>
        void woof(Args &&... args)
        {
            bark<level::error>(std::forward<Args>(args)...);
        }

    private:
        template<level L, class... Args>
        void bark(Args &&... args)
        {
            if(static_cast<int>(Level) <= static_cast<int>(L)){
                bark_impl(std::forward<Args>(args)...);
                mouse << std::endl;
            }
        }

        template<class Arg>
        void bark_impl(Arg && arg)
        {
            mouse << arg << ' ';
        }

        template<class Head, class... Tail>
        void bark_impl(Head && head, Tail &&... tail)
        {
            mouse << head << ' ';
            bark_impl(std::forward<Tail>(tail)...);
        }
    };

} // namespace watchdog

#endif    // WATCHDOG_DOG_HPP_INCLUDED
