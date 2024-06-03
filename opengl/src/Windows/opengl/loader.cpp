#include <newtype/opengl/common/pch.hpp>
#include <newtype/opengl/loader.hpp>

namespace newtype::opengl
{
    bool load_gl_api()
    {
        return true;
    }

    renderer_base::context init_context(newtype::window_base* _wnd)
    {
        renderer_base::context ctx;
        HWND handle = (HWND)_wnd->get_native_handle();

        if (!handle)
        {
            throw newtype::invalid_handle("Invalid Handle passed creating context");
        }

        HDC dc = GetDC(handle);
        PIXELFORMATDESCRIPTOR pfd = {};
        pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
        pfd.nVersion = 1;
        pfd.dwFlags =
                PFD_DRAW_TO_WINDOW |
                PFD_SUPPORT_OPENGL |
                PFD_DOUBLEBUFFER;
        pfd.iPixelType = PFD_TYPE_RGBA;
        pfd.cColorBits = 32;

        int pixelFormat = ChoosePixelFormat(dc, &pfd);
        SetPixelFormat(dc, pixelFormat, &pfd);

        HGLRC glrc = wglCreateContext(dc);
        wglMakeCurrent(dc, glrc);

        if (!dc || !glrc)
        {
            //TODO: opengl exception
            throw;
        }

        ctx["DC"] = dc;
        ctx["HGLRC"] = glrc;

        return ctx;
    }

    void make_context_current(renderer_base::context _ctx)
    {
        HDC dc;
        HGLRC glrc;
        try
        {
            dc = std::any_cast<HDC>(_ctx["DC"]);
            glrc = std::any_cast<HGLRC>(_ctx["HGLRC"]);
        }
        catch (const std::bad_any_cast& _e)
        {
            //TODO: opengl exceptions
            throw _e;
        }

        wglMakeCurrent(dc, glrc);
    }

    void swap_buffers(renderer_base::context _ctx)
    {
        HDC dc;
        HGLRC glrc;
        try
        {
            dc = std::any_cast<HDC>(_ctx["DC"]);
            glrc = std::any_cast<HGLRC>(_ctx["HGLRC"]);
        }
        catch (const std::bad_any_cast& _e)
        {
            //TODO: opengl exceptions
            throw _e;
        }

        wglMakeCurrent(dc, glrc);
        SwapBuffers(dc);
    }

    void remove_context(renderer_base::context _ctx)
    {
        HGLRC glrc;
        try
        {
            glrc = std::any_cast<HGLRC>(_ctx["HGLRC"]);
        }
        catch (const std::bad_any_cast& _e)
        {
            //TODO: opengl exceptions
            throw _e;
        }

        wglDeleteContext(glrc);
        _ctx.clear();
    }
}