#include "cg_gl_error_checker.h"

#include <GLFW/glfw3.h>

int main() {
  GLFWwindow* window;
  const int width = 640, height = 480;
  CGcontext mainCgContext;

  /* Initialize the library */
  if (!glfwInit()) return -1;

  /* Create a windowed mode window and its OpenGL context */
  window = glfwCreateWindow(width, height, "Application", nullptr, nullptr);
  if (!window) {
    glfwTerminate();
    return -1;
  }

  /* Make the window's context current */
  glfwMakeContextCurrent(window);

  // Create Cg context
  CG_DEBUG(mainCgContext = cgCreateContext());
  CG_DEBUG(cgGLSetDebugMode(CG_TRUE)); // user OpenGL error checking

  /* Loop until the user closes the window */
  while (!glfwWindowShouldClose(window)) {
    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);

    /* Swap front and back buffers */
    glfwSwapBuffers(window);

    /* Poll for and process events */
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
