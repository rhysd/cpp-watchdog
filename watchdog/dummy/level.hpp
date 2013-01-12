#if !defined WATCH_DOG_DUMMY_LEVEL_HPP_INCLUDED
#define      WATCH_DOG_DUMMY_LEVEL_HPP_INCLUDED

namespace watchdog {
    enum class level {
        info = 0,
        warning,
        error
    };
} // namespace watchdog

#endif    // WATCH_DOG_DUMMY_LEVEL_HPP_INCLUDED
