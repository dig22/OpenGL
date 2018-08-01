#include "IndexBuffer.h"
#include "Renderer.h"
IndexBuffer::IndexBuffer(const unsigned int* data,unsigned int count ) // count element count
    :m_Count(count)
{   

    ASSERT(sizeof(unsigned int) == sizeof(GLuint));

    GLCall(glGenBuffers(1, &m_RendererID));                                                              //Generate a memory space in GPU and return ID
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));                                                 //Select a buffer as array buffer (Bind here to display)
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data /*Array*/, GL_STATIC_DRAW)); //put data with size in bytes
      

}
IndexBuffer::~IndexBuffer()
{
    GLCall(glDeleteBuffers(1,&m_RendererID));
}

void IndexBuffer::Bind() const
{
      GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));         
}
void IndexBuffer::Unbind() const
{
      GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));         
}
