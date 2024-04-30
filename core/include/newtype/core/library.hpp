#pragma once
#ifndef NEWTYPE_CORE_LIBRARY_HPP
#   define NEWTYPE_CORE_LIBRARY_HPP

#   if defined(NT_PLATFORM_WINDOWS)
#       define NT_CORE_API_IMPORT __declspec(dllimport)
#       define NT_CORE_API_EXPORT __declspec(dllexport)
#   else
#       error "platform not defined"
#   endif

#   if defined(NT_SHARED_LIBS)
#       if defined(NT_COMPILE_CORE)
#           define NT_CORE_API NT_CORE_API_EXPORT
#       else
#           define NT_CORE_API NT_CORE_API_IMPORT
#       endif
#   else
#       define NT_CORE_API
#   endif

#endif //NEWTYPE_CORE_LIBRARY_HPP