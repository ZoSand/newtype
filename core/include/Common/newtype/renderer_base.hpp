#pragma once
#ifndef NEWTYPE_CORE_RENDERER_BASE_HPP
#   define NEWTYPE_CORE_RENDERER_BASE_HPP

#   include <newtype/window.hpp>

namespace newtype
{
    class NT_CORE_API renderer_base
    {
    public:
        using context = std::map<std::string, std::any>;

        virtual ~renderer_base() = default;

        //TODO: clear(color)
        virtual void clear() = 0;

        virtual void present() = 0;

    };
}

#endif