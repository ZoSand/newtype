#include <newtype/platform/pch.hpp>
#include <newtype/window.hpp>

namespace newtype
{
    std::unique_ptr<window_base> create_window()
    {
        return std::make_unique<window>();
    }

    window::window()
    {
        WNDCLASSEXA wcex = {0};

        wcex.cbSize = sizeof(WNDCLASSEXA);
        wcex.lpszClassName = "NTWindow";
        wcex.lpfnWndProc = DefWindowProcA;
        wcex.hInstance = GetModuleHandleA(nullptr);

        m_class = RegisterClassExA(&wcex);
        if (m_class == 0)
        {
            throw std::system_error((int)GetLastError(), std::system_category());
        }

        m_handle = CreateWindowExA(
                0,
                "NTWindow",
                "Newtype",
                WS_OVERLAPPEDWINDOW,
                CW_USEDEFAULT, CW_USEDEFAULT,
                CW_USEDEFAULT, CW_USEDEFAULT,
                nullptr,
                nullptr,
                GetModuleHandleA(nullptr),
                nullptr
        );
        if (m_handle == nullptr)
        {
            throw std::system_error((int)GetLastError(), std::system_category());
        }
    }

    void window::open()
    {
        if (m_handle == nullptr)
        {
            throw newtype::invalid_handle("Window handle is null");
        }

        ShowWindow(m_handle, SW_SHOW);
        UpdateWindow(m_handle);
    }

    void window::close()
    {
        if (m_handle == nullptr)
        {
            throw newtype::invalid_handle("Window handle is null");
        }

        DestroyWindow(m_handle);
        UnregisterClassA(
                (LPTSTR) ULONG_PTR(m_class),
                GetModuleHandleA(nullptr)
        );
    }

    void window::update_events()
    {
        MSG msg {};
        while (PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessageA(&msg);
        }
    }

    [[nodiscard]]
    bool window::is_open() const
    {
        return (m_handle != nullptr)
               && IsWindow(m_handle);
    }

    [[nodiscard]]
    std::string window::get_title() const
    {
        if (m_handle == nullptr)
        {
            throw newtype::invalid_handle("Window handle is null");
        }

        std::string title;

        if (int len = GetWindowTextLengthA(m_handle);  len != 0)
        {
            //being compliant with the "no new[]/delete[] calls" rule, we use vectors to get pointers (lol)
            std::vector<char> text(len + 1);

            if (GetWindowTextA(m_handle, text.data(), len + 1) == 0)
            {
                throw std::system_error((int) GetLastError(), std::system_category());
            }

            title = text.data();
        }

        return title;
    }

    void window::set_title(const std::string &_title)
    {
        if (m_handle == nullptr)
        {
            throw newtype::invalid_handle("Window handle is null");
        }

        SetWindowText(m_handle, _title.c_str());
    }

    [[nodiscard]]
    std::tuple<int, int> window::get_position() const
    {
        if (m_handle == nullptr)
        {
            throw newtype::invalid_handle("Window handle is null");
        }

        return {0, 0};
    }

    void window::set_position(std::tuple<int, int> _position)
    {
        if (m_handle == nullptr)
        {
            throw newtype::invalid_handle("Window handle is null");
        }

        NT_UNUSED_ARGUMENT(_position);
    }

    [[nodiscard]]
    std::tuple<int, int> window::get_size() const
    {
        return {0, 0};
    }

    void window::set_size(std::tuple<int, int> _size)
    {
        NT_UNUSED_ARGUMENT(_size);
    }
}
