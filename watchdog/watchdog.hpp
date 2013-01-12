#if !defined WATCHDOG_WATCHDOG_HPP_INCLUDED
#define      WATCHDOG_WATCHDOG_HPP_INCLUDED

#ifdef WATCHDOG_NO_DOGS
#   include "./dummy/level.hpp"
#   include "./dummy/dog.hpp"
#else
#   include "./level.hpp"
#   include "./dog.hpp"
#endif // #ifdef WATCHDOG_NO_DOGS

#endif    // WATCHDOG_WATCHDOG_HPP_INCLUDED
