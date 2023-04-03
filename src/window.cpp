#include "headers/window.hpp"

#include <stdexcept>

namespace lve {
    Window::Window(int w, int h, std::string name) : width{w}, height{h}, windowName{name}{
        initWindow();
    }

    Window::~Window(){
        glfwDestroyWindow(window);

        glfwTerminate();
    }

    void Window::initWindow(){
        glfwInit();

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width, height, "Vulkan", nullptr, nullptr);
    }

    void Window::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface) {
        if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
            throw std::runtime_error("failed to create window surface");
        }
    }

    void Window::framebufferResizeCallback(GLFWwindow* window, int width, int height){
        auto windowLve = reinterpret_cast<Window *>(glfwGetWindowUserPointer(window));
        windowLve->frameBufferResized = true;
        windowLve->width = width;
        windowLve->height = height;
    }
}