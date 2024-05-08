#pragma once
#ifndef NEWTYPE_CORE_APPLICATION_BASE_HPP
#   define NEWTYPE_CORE_APPLICATION_BASE_HPP

#   include <newtype/window_base.hpp>

namespace newtype
{
    class NT_CORE_API application_base
    {
        std::unique_ptr<window_base> m_wnd;
    public:
        application_base();
        virtual ~application_base();

        int run();

        [[maybe_unused, nodiscard]]
        std::string get_window_title() const;
        [[maybe_unused]]
        void set_window_title(const std::string& _title);

        [[maybe_unused, nodiscard]]
        std::pair<int, int> get_window_position() const;
        [[maybe_unused]]
        void set_window_position(std::pair<int, int> _position);

        [[maybe_unused, nodiscard]]
        std::pair<int, int> get_window_size() const;
        [[maybe_unused]]
        void set_window_size(std::pair<int, int> _size);
    };

    namespace application
    {
        template <std::derived_from<application_base> app_t>
        int run()
        {
            std::unique_ptr<application_base> app = std::make_unique<app_t>();
            return app->run();
        }
    }
}

#endif //NEWTYPE_CORE_APPLICATION_BASE_HPP
