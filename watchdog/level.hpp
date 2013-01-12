#if !defined WATCHDOG_LEVEL_HPP_INCLUDED
#define      WATCHDOG_LEVEL_HPP_INCLUDED

namespace watchdog {
    enum class level {
        info = 0,
        warning,
        error
    };
} // namespace watchdog
#endif    // WATCHDOG_LEVEL_HPP_INCLUDED
