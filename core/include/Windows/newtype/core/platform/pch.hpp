#pragma once
#ifndef NEWTYPE_CORE_PLATFORM_PCH_HPP
#   define NEWTYPE_CORE_PLATFORM_PCH_HPP

#   include <exception>
#   include <stdexcept>
#   include <system_error>
#   include <vector>

#   include <windows.h>

#   include <newtype/core/platform/library.hpp>

namespace newtype
{
    struct invalid_handle : public std::logic_error
    {
        using logic_error::logic_error;
    };
}

#endif //NEWTYPE_CORE_PLATFORM_PCH_HPP
