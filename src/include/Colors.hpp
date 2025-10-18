// colors.hpp
#pragma once
#include <string>

namespace color {
    // Standard text colors
    inline constexpr const char* reset       = "\033[0m";
    inline constexpr const char* black       = "\033[30m";
    inline constexpr const char* red         = "\033[31m";
    inline constexpr const char* green       = "\033[32m";
    inline constexpr const char* yellow      = "\033[33m";
    inline constexpr const char* blue        = "\033[34m";
    inline constexpr const char* magenta     = "\033[35m";
    inline constexpr const char* cyan        = "\033[36m";
    inline constexpr const char* white       = "\033[37m";

    // Bright variants
    inline constexpr const char* bright_black   = "\033[90m";
    inline constexpr const char* bright_red     = "\033[91m";
    inline constexpr const char* bright_green   = "\033[92m";
    inline constexpr const char* bright_yellow  = "\033[93m";
    inline constexpr const char* bright_blue    = "\033[94m";
    inline constexpr const char* bright_magenta = "\033[95m";
    inline constexpr const char* bright_cyan    = "\033[96m";
    inline constexpr const char* bright_white   = "\033[97m";

    // Background colors
    inline constexpr const char* bg_black   = "\033[40m";
    inline constexpr const char* bg_red     = "\033[41m";
    inline constexpr const char* bg_green   = "\033[42m";
    inline constexpr const char* bg_yellow  = "\033[43m";
    inline constexpr const char* bg_blue    = "\033[44m";
    inline constexpr const char* bg_magenta = "\033[45m";
    inline constexpr const char* bg_cyan    = "\033[46m";
    inline constexpr const char* bg_white   = "\033[47m";
}

