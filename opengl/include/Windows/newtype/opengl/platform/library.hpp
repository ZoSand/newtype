#pragma once
#ifndef NEWTYPE_OPENGL_PLATFORM_LIBRARY_HPP
#   define NEWTYPE_OPENGL_PLATFORM_LIBRARY_HPP

#   if defined(NT_PLATFORM_WINDOWS)
#       define NT_OPENGL_API_IMPORT __declspec(dllimport)
#       define NT_OPENGL_API_EXPORT __declspec(dllexport)
#   else
#       error "platform should be Windows"
#   endif

#   if defined(NT_SHARED_LIBS)
#       if defined(NT_COMPILE_OPENGL)
#           define NT_OPENGL_API NT_OPENGL_API_EXPORT
#       else
#           define NT_OPENGL_API NT_OPENGL_API_IMPORT
#       endif
#   else
#       define NT_OPENGL_API
#   endif

#endif //NEWTYPE_OPENGL_PLATFORM_LIBRARY_HPP