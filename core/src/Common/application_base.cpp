#include <newtype/pch.hpp>
#include <newtype/application_base.hpp>

#include <iostream>
#include <utility>

namespace newtype
{
    application_base* application_base::s_instance;

    application_base::application_base()
    {
        s_instance = this;
        m_wnd = create_window();
    }

    application_base::~application_base()
    = default;

    void application_base::close(int _exit_code)
    {
        m_exit_code = _exit_code;
        m_wnd->close();
    }

    [[maybe_unused]]
    void application_base::set_renderer(std::unique_ptr<renderer_base> _renderer)
    {
        m_rnd = std::move(_renderer);
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
            m_rnd->clear();
            m_rnd->present();
        }

        m_wnd->close();

        return m_exit_code;
    }

    [[nodiscard]]
    application_base* application_base::get()
    {
        return s_instance;
    }
}