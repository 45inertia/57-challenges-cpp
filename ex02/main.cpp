#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include <cstring>

int main() {
  // setting up GLFW window
  if (!glfwInit()) return 1;
  GLFWwindow* window = glfwCreateWindow(1280, 700, "ImGui Starter", nullptr, nullptr);
  glfwMakeContextCurrent(window);
  glfwSwapInterval(1); // enable vsync

  // setup ImGui
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 130");

  // application state
  char stringInput[128] = ""; 

  // main loop
  while(!glfwWindowShouldClose(window)) {
    glfwPollEvents(); // Takes pending input from the OS and fires the callbacks

    // start imgui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    // ui code starts here

    ImGui::ShowDemoWindow();

    ImGui::Begin("My First Window");

    ImGui::Text("Welcome to ImGui!");

    ImGui::InputTextWithHint("String Length", "Please Enter a string", stringInput, IM_COUNTOF(stringInput));
    ImGui::LabelText("Character Count", "%zu", std::strlen(stringInput));

    ImGui::End();
    
    // rendering the frame
    ImGui::Render();
    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(window);
  }

  // cleanup
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}
