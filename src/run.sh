rm ./run
clang++-6.0 -o run Application.cpp \
 IndexBuffer.cpp \
 Renderer.cpp \
 VertexArray.cpp \
 VertexBuffer.cpp \
 Shader.cpp \
 Texture.cpp \
 ./tests/TestClearColor.cpp \
 ./tests/Test.cpp \
 ./vendor/stb_image/stb_image.so \
./vendor/imgui/objects/*.o  \
-lglfw -lGLEW -lGL -lm -g
./run
