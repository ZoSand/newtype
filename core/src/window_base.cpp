#include <newtype/core/pch.hpp>
#include <newtype/window_base.hpp>

namespace newtype
{
    struct handlers
    {
        static inline create_window_handler s_create_handler;
    };

    create_window_handler set_create_window_handler(create_window_handler _handler)
    {
        create_window_handler old = handlers::s_create_handler;
        handlers::s_create_handler = std::move(_handler);
        return old;
    }

    create_window_handler get_create_window_handler()
    {
        return handlers::s_create_handler;
    }
}