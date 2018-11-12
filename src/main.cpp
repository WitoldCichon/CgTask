#include "shader.h"
#include "texture.h"

#include <GLFW/glfw3.h>

int main() {
  GLFWwindow* window;
  const int windowWidth = 640, windowHeight = 480;
  CGcontext mainCgContext;

  /* Initialize the library */
  if (!glfwInit()) return -1;

  /* Create a windowed mode window and its OpenGL context */
  window = glfwCreateWindow(windowWidth, windowHeight, "Application", nullptr,
                            nullptr);
  if (!window) {
    glfwTerminate();
    return -1;
  }

  /* Make the window's context current */
  glfwMakeContextCurrent(window);

  // Create Cg context
  CG_DEBUG(mainCgContext = cgCreateContext());
  CG_DEBUG(cgGLSetDebugMode(CG_TRUE));  // user OpenGL error checking

  // Create vertex shader
  Shader vertexShader(mainCgContext, {"../resources/shaders/vertex_shader.cg",
                                      "main_function", CG_GL_VERTEX});
  Shader fragmentShader(mainCgContext,
                        {"../resources/shaders/fragment_shader.cg",
                         "main_function", CG_GL_FRAGMENT});

  // Create texture from the file
  Texture text("../resources/textures/parrot.jpeg", 1);

  /* Loop until the user closes the window */
  while (!glfwWindowShouldClose(window)) {
    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);

    vertexShader.bind();
    fragmentShader.bind();

    CG_DEBUG(glBegin(GL_QUADS));
    glTexCoord2d(0, 0);
    glVertex2f(-1.0f, -1.0f);
    glTexCoord2d(1, 0);
    glVertex2f(1.0f, -1.0f);
    glTexCoord2d(1, 1);
    glVertex2f(1.0f, 1.0f);
    glTexCoord2d(0, 1);
    glVertex2f(-1.0f, 1.0f);
    glEnd();

    vertexShader.unbind();
    fragmentShader.unbind();

    /* Swap front and back buffers */
    glfwSwapBuffers(window);

    /* Poll for and process events */
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
