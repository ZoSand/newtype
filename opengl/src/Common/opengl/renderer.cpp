#include <newtype/opengl/common/pch.hpp>
#include <newtype/opengl/renderer.hpp>
#include <newtype/opengl/loader.hpp>

#include <newtype/core/application_base.hpp>

#include <gl/gl.h>

namespace newtype::opengl
{
    bool gl_loaded = load_gl_api();

    renderer::renderer()
    {
        m_ctx = init_context(newtype::application_base::get()->get_window());
    };

    renderer::~renderer()
    {
        remove_context(m_ctx);
    };

    void renderer::clear()
    {
        if (!gl_loaded)
        {
            //TODO: opengl exception
            throw;
        }
        make_context_current(m_ctx);
        glClearColor(0, .33f, .33f,  1);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void renderer::present()
    {
        if (!gl_loaded)
        {
            //TODO: opengl exception
            throw;
        }
        make_context_current(m_ctx);
        swap_buffers(m_ctx);
    }
}