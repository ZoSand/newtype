#include <newtype/core/pch.hpp>
#include <newtype/application_base.hpp>

namespace newtype
{
    application_base::application_base()
    {
        m_wnd = create_window();
    }

    application_base::~application_base()
        = default;

    [[maybe_unused, nodiscard]]
    std::string application_base::get_window_title() const
    {
        return m_wnd->get_title();
    }

    [[maybe_unused]]
    void application_base::set_window_title(const std::string& _title)
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

        return 0;
    }
}