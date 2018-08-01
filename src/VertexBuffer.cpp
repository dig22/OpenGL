#include "VertexBuffer.h"
#include "Renderer.h"

VertexBuffer::VertexBuffer(const void *data, unsigned int size) //size is always in bytes
{   
    GLCall(glGenBuffers(1, &m_RendererID));                                                              //Generate a memory space in GPU and return ID
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));                                                 //Select a buffer as array buffer (Bind here to display)
    GLCall(glBufferData(GL_ARRAY_BUFFER, size, data /*Array*/, GL_STATIC_DRAW)); //put data with size in bytes
      

}
VertexBuffer::~VertexBuffer()
{
    GLCall(glDeleteBuffers(1,&m_RendererID));
}

void  VertexBuffer::Bind() const
{
     GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));         
}
void VertexBuffer::Unbind() const
{
      GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));         
}
