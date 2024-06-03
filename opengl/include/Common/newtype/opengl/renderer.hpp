#pragma once
#ifndef NEWTYPE_OPENGL_RENDERER_HPP
#   define NEWTYPE_OPENGL_RENDERER_HPP

#   include <newtype/core/renderer_base.hpp>

namespace newtype::opengl
{
    class NT_OPENGL_API renderer : public newtype::renderer_base
    {
    private:
        renderer_base::context m_ctx {};
    public:
        renderer();
        ~renderer() override;

        void clear() override;
        void present() override;
    };
}

#endif //NEWTYPE_OPENGL_RENDERER_HPP
