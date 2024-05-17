#pragma once
#ifndef NEWTYPE_CORE_APPLICATION_BASE_HPP
#   define NEWTYPE_CORE_APPLICATION_BASE_HPP

#   include <newtype/window_base.hpp>
#   include <newtype/renderer_base.hpp>

namespace newtype
{
    class NT_CORE_API application_base
    {
        std::unique_ptr<window_base> m_wnd;
        std::unique_ptr<renderer_base> m_rnd;

        int m_exit_code {};
    public:
        application_base();
        virtual ~application_base();

        int run();

        [[maybe_unused]]
        void close(int exit_code = 0);

        [[maybe_unused]]
        void set_renderer(renderer_base* _renderer);
        [[maybe_unused, nodiscard]]
        renderer_base* get_renderer();

        [[maybe_unused, nodiscard]]
        newtype::window_base* get_window() const;

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
