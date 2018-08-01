#include "VertexArray.h"
#include "Renderer.h"
#include "VertexBufferLayout.h"
VertexArray::VertexArray()
{
    GLCall(glGenVertexArrays(1, &m_RenderedID));
}
VertexArray::~VertexArray()
{
    GLCall(glDeleteVertexArrays(1, &m_RenderedID));
}

void VertexArray::AddBuffer(const VertexBuffer &vb, const VertexBufferLayout &layout)
{
    Bind();
    vb.Bind();
    const auto &elements = layout.getElements();
    unsigned int offset = 0;
    for (unsigned int i = 0; i < elements.size(); i++)
    {
        const auto &element = elements[i];
        GLCall(glEnableVertexAttribArray(i););
        GLCall(glVertexAttribPointer(i, element.count, element.type,
                                     element.normalized, layout.GetStride(), (const void *)offset)); // enable the vertex array !important
                                                                                                     //index, size(how many floats for 1 vertex), .., .., stride , position
        /* buffer gets linked to the vao in above code*/
        /* the index specifies the bond to vao (first parameter)*/
        offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
    }
}

void VertexArray::Bind() const
{
    GLCall(glBindVertexArray(m_RenderedID));

}
void VertexArray::Unbind() const
{
    GLCall(glBindVertexArray(0));
}
