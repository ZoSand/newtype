#include <newtype/core/pch.hpp>
#include <newtype/application_base.hpp>

#include <iostream>

namespace newtype
{
    application_base::application_base()
    {
        create_window_handler hnd_create = get_create_window_handler();
        if (hnd_create == nullptr)
        {
            throw std::bad_function_call();
        }
        m_wnd = hnd_create();
    }

    application_base::~application_base()
    = default;

    void application_base::close(int _exit_code)
    {
        m_exit_code = _exit_code;
        m_wnd->close();
    }

    [[maybe_unused]]
    void application_base::set_renderer(renderer_base *_renderer)
    {
        m_rnd.reset(_renderer);
    }

    [[maybe_unused, nodiscard]]
    renderer_base *application_base::get_renderer()
    {
        return m_rnd.get();
    }

    [[maybe_unused, nodiscard]]
    window_base *application_base::get_window() const
    {
        return m_wnd.get();
    }

    [[maybe_unused, nodiscard]]
    std::string application_base::get_window_title() const
    {
        return m_wnd->get_title();
    }

    [[maybe_unused]]
    void application_base::set_window_title(const std::string &_title)
    {
        m_wnd->set_title(_title);
    }

    [[maybe_unused, nodiscard]]
    std::pair<int, int> application_base::get_window_position() const
    {
        return m_wnd->get_position();
    }

    [[maybe_unused]]
    void application_base::set_window_position(std::pair<int, int> _position)
    {
        m_wnd->set_position(_position);
    }

    [[maybe_unused, nodiscard]]
    std::pair<int, int> application_base::get_window_size() const
    {
        return m_wnd->get_size();
    }

    [[maybe_unused]]
    void application_base::set_window_size(std::pair<int, int> _size)
    {
        m_wnd->set_size(_size);
    }

    int application_base::run()
    {
        m_wnd->open();

        while (m_wnd->is_open())
        {
            m_wnd->update_events();
        }

        m_wnd->close();

        return m_exit_code;
    }
}