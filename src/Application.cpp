//docs.GL for reference
//gl degub msg callback in opengl 4.3 above
//unsigned ints instead of GLints;

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <alloca.h>
#include <fstream>
#include <string>
#include <sstream>

#include "Renderer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "VertexBufferLayout.h"
#include "Shader.h"
#include "Texture.h"

#include "vendor/glm/glm.hpp"
#include "vendor/glm/gtc/matrix_transform.hpp"
#include "vendor/imgui/imgui.h"
#include "vendor/imgui/imgui_impl_glfw.h"
#include "vendor/imgui/imgui_impl_opengl3.h"

#include "tests/TestClearColor.h"

int main(void)
{
    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /*Its possible to change OpenGL version with glfwWindowHint()*/
    /* glfwWindowHint() also allows changing compatiblity or core profiles*/

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(960, 540, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /*Cap fps*/
    glfwSwapInterval(1);

    glewExperimental = GL_TRUE; //for vao currently

    if (glewInit() != GLEW_OK) //after context
        std::cout << "Error!" << std::endl;

    std::cout << glGetString(GL_VERSION) << std::endl;
    {
      

        GLCall(glEnable(GL_BLEND)); //ENable Blending aplha channels
        GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

        Renderer renderer;
        /* GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));*/
        /*GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));*/

        ImGui::CreateContext(); //IMGUI
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init();
        ImGui::StyleColorsDark();

        test::Test* currentTest= nullptr;
        test::TestMenu* testMenu = new test::TestMenu(currentTest);
        currentTest = testMenu;

        testMenu->RegisterTest<test::TestClearColor>("Clear Color");
       
        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            /* Render here */
            GLCall(glClearColor(0.0f,0.0f,0.0f,1.0f));
            renderer.Clear();


            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            if(currentTest  ){
                currentTest->OnUpdate(0.0f);
                currentTest->OnRender();
                ImGui::Begin("Test");
                if(currentTest != testMenu && ImGui::Button("<-")){
                    delete currentTest;
                    currentTest =testMenu;
                }
                currentTest->OnImGuiRender();
                ImGui::End();
            }

    
            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            /*Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
        }

        //delete vb ib before
        delete currentTest;
        if(currentTest!=testMenu){
            delete testMenu;
        }
    }

    

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}