#pragma once
#ifndef NEWTYPE_PLATFORM_LIBRARY_HPP
#   define NEWTYPE_PLATFORM_LIBRARY_HPP

#   if defined(NT_PLATFORM_WINDOWS)
#       define NT_PLATFORM_API_IMPORT __declspec(dllimport)
#       define NT_PLATFORM_API_EXPORT __declspec(dllexport)
#   else
#       error "platform not defined"
#   endif

#   if defined(NT_SHARED_LIBS)
#       if defined(NT_COMPILE_PLATFORM)
#           define NT_PLATFORM_API NT_PLATFORM_API_EXPORT
#       else
#           define NT_PLATFORM_API NT_PLATFORM_API_IMPORT
#       endif
#   else
#       define NT_PLATFORM_API
#   endif

#endif //NEWTYPE_PLATFORM_LIBRARY_HPP