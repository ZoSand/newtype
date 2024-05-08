#include <newtype/core/pch.hpp>
#include <newtype/window_base.hpp>

namespace newtype
{
    namespace
    {
        create_window_handler handler;
    }

    create_window_handler set_window_create_handler(create_window_handler _handler)
    {
        handler = std::move(_handler);
        return handler;
    }

    create_window_handler get_create_window_handler()
    {
        return handler;
    }
}