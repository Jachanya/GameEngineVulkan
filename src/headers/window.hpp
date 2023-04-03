#ifndef _H_WINDOW_
#define _H_WINDOW_

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace lve {
    class Window {
        public:
        Window(int w, int h, std::string name);
        ~Window();

        bool shouldClose() { return glfwWindowShouldClose(window); }
        VkExtent2D getExtent() {return {static_cast<uint32_t>(width), static_cast<uint32_t>(height)};  }
        bool wasWindowResized() { return frameBufferResized; }
        void resetWindowResizedFlag() { frameBufferResized = false; }
        GLFWwindow* getGLFWwindow() const { return window; }
        void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);

        private:
        static void framebufferResizeCallback(GLFWwindow* window, int width, int height);
        void initWindow();

        int width;
        int height;
        bool frameBufferResized = false;

        std::string windowName;
        GLFWwindow *window;
    };
};

#endif