#pragma once
#ifndef NEWTYPE_PLATFORM_WINDOW_HPP
#   define NEWTYPE_PLATFORM_WINDOW_HPP

#   include <newtype/window_base.hpp>

namespace newtype
{
    class NT_CORE_API window : public window_base
    {
        HWND m_handle {};
        ATOM m_class {};

        static LRESULT CALLBACK wnd_proc(HWND _hwnd, UINT _msg, WPARAM _wparam, LPARAM _lparam);
    public:
        window();

        window(window&) = delete;
        window& operator=(window&) = delete;
        ~window() override = default;

        void* get_native_handle() const override;

        void open() override;

        void close() override;

        void update_events() override;

        [[nodiscard]]
        bool is_open() const override;

        [[maybe_unused, nodiscard]]
        std::string get_title() const override;
        [[maybe_unused]]
        void set_title(const std::string& _title) override;

        [[maybe_unused, nodiscard]]
        std::pair<int, int> get_position() const override;
        [[maybe_unused]]
        void set_position(std::pair<int, int> _position) override;

        [[maybe_unused, nodiscard]]
        std::pair<int, int> get_size() const override;
        [[maybe_unused]]
        void set_size(std::pair<int, int> _size) override;
    };
}

#endif //NEWTYPE_PLATFORM_WINDOW_HPP
