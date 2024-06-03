#pragma once
#ifndef NEWTYPE_OPENGL_LOADER_HPP
#   define NEWTYPE_OPENGL_LOADER_HPP

#include <newtype/core/window_base.hpp>
#include <newtype/core/renderer_base.hpp>

namespace newtype::opengl
{
    bool NT_OPENGL_API load_gl_api();

    renderer_base::context NT_OPENGL_API init_context(newtype::window_base* _wnd);
    void NT_OPENGL_API make_context_current(renderer_base::context _ctx);
    void NT_OPENGL_API swap_buffers(renderer_base::context _ctx);
    void NT_OPENGL_API remove_context(renderer_base::context _ctx);
}

#endif //NEWTYPE_OPENGL_LOADER_HPP
