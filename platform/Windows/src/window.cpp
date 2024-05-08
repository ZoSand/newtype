#include <newtype/platform/pch.hpp>
#include <newtype/window.hpp>

namespace newtype
{
    window::window()
    {
        WNDCLASSEXA wcex = {0};

        wcex.cbSize = sizeof(WNDCLASSEXA);
        wcex.lpszClassName = "NTWindow";
        wcex.lpfnWndProc = window::wnd_proc;
        wcex.style = CS_HREDRAW | CS_VREDRAW;
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
                this
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

    [[maybe_unused, nodiscard]]
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

    [[maybe_unused]]
    void window::set_title(const std::string &_title)
    {
        if (m_handle == nullptr)
        {
            throw newtype::invalid_handle("Window handle is null");
        }

        SetWindowText(m_handle, _title.c_str());
    }

    [[maybe_unused, nodiscard]]
    std::pair<int, int> window::get_position() const
    {
        if (m_handle == nullptr)
        {
            throw newtype::invalid_handle("Window handle is null");
        }

        RECT rect;
        GetWindowRect(m_handle, &rect);

        return {rect.left, rect.top};
    }

    [[maybe_unused]]
    void window::set_position(std::pair<int, int> _position)
    {
        if (m_handle == nullptr)
        {
            throw newtype::invalid_handle("Window handle is null");
        }

        NT_UNUSED_ARGUMENT(_position);
        SetWindowPos(m_handle, nullptr, _position.first, _position.second, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
    }

    [[maybe_unused, nodiscard]]
    std::pair<int, int> window::get_size() const
    {
        if (m_handle == nullptr)
        {
            throw newtype::invalid_handle("Window handle is null");
        }

        RECT rect;
        GetClientRect(m_handle, &rect);

        return {rect.right - rect.left, rect.bottom - rect.top };
    }

    [[maybe_unused]]
    void window::set_size(std::pair<int, int> _size)
    {
        if (m_handle == nullptr)
        {
            throw newtype::invalid_handle("Window handle is null");
        }

        RECT rect;
        GetWindowRect(m_handle, &rect);

        // save position before adjusting rect so it won't move
        POINT position {rect.left, rect.top};

        // adjusting so the size is of client area
        rect.right = rect.left + _size.first;
        rect.bottom = rect.top + _size.second;
        AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

        // move the window to new size and same position
        MoveWindow(m_handle, position.x, position.y, rect.right - rect.left, rect.bottom - rect.top, true);
    }

    LRESULT CALLBACK window::wnd_proc(HWND _hwnd, UINT _msg, WPARAM _wparam, LPARAM _lparam)
    {
        window* wnd;

        if (_msg == WM_CREATE)
        {
            wnd = static_cast<window*>(((LPCREATESTRUCTA)_lparam)->lpCreateParams);
            SetWindowLongPtrA(_hwnd, GWLP_USERDATA, (LONG_PTR)wnd);
        }
        else
        {
            wnd = static_cast<window*>((LPVOID)GetWindowLongPtrA(_hwnd, GWLP_USERDATA));
        }

        if (wnd == nullptr)
        {
            return DefWindowProcA(_hwnd, _msg, _wparam, _lparam);
        }

        switch (_msg)
        {
            case WM_DESTROY:
            {
                PostQuitMessage(0);
                break;
            }
            case WM_CLOSE:
            {
                wnd->close();
                break;
            }
            default:
            {
                return DefWindowProcA(_hwnd, _msg, _wparam, _lparam);
            }
        }

        return 0;
    }
}
