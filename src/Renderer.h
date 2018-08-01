#pragma once
#include<GL/glew.h>

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

#define ASSERT(x) if (!(x)) __builtin_trap();
#define GLCall(x) GLCLearError();\
    x;\
    ASSERT(GLLogCall(#x,__FILE__, __LINE__))

void GLCLearError();
bool GLLogCall(const char* function, const char* file , int line );

class Renderer{
    public : 
    void Draw(const VertexArray& va , const IndexBuffer& ib, const Shader& shader);
    void Clear() const;

};