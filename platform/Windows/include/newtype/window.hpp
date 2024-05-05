#pragma once
#ifndef NEWTYPE_PLATFORM_WINDOW_HPP
#   define NEWTYPE_PLATFORM_WINDOW_HPP

#   include <newtype/window_base.hpp>

namespace newtype
{
    class NT_PLATFORM_API window : public window_base
    {
        HWND m_handle {};
        ATOM m_class {};
    public:
        window();

        window(window&) = delete;
        window& operator=(window&) = delete;
        ~window() override = default;

        void open() override;

        void close() override;

        void update_events() override;

        [[nodiscard]]
        bool is_open() const override;

        [[nodiscard]]
        std::string get_title() const override;

        void set_title(const std::string& _title) override;

        [[nodiscard]]
        std::tuple<int, int> get_position() const override;

        void set_position(std::tuple<int, int> _position) override;

        [[nodiscard]]
        std::tuple<int, int> get_size() const override;

        void set_size(std::tuple<int, int> _size) override;
    };
}

#endif //NEWTYPE_PLATFORM_WINDOW_HPP
