#include "headers/pipeline.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>

namespace lve {
    Pipeline::Pipeline(JachanDevice& device, const std::string& vertFilepath, const std::string& fragFilepath, PipelineConfigInfo configInfo)
    : jachanDevice{device}
    {
        createGraphicsPipeline(vertFilepath, fragFilepath, configInfo);
    }
    std::vector<char> Pipeline::readFile(const std::string& filepath){
        std::ifstream file(filepath, std::ios::ate | std::ios::binary);
        if(!file.is_open()) {
            throw std::runtime_error("failed to open file: " + filepath);
        }

        size_t fileSize = static_cast<size_t>(file.tellg());
        std::vector<char> buffer(fileSize);

        file.seekg(0);
        file.read(buffer.data(), fileSize);

        file.close();
        return buffer;
    }
    void Pipeline::createGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath, PipelineConfigInfo configInfo){
        auto vertCode = readFile(vertFilepath);
        auto fragCode = readFile(fragFilepath);

        std::cout << "Vertex shader code size " << vertCode.size() << std::endl;
        std::cout << "Vertex shader code size " << fragCode.size() << std::endl;
    }

    void Pipeline::createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule){
        VkShaderModuleCreateInfo createInfo;
        createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        createInfo.codeSize = code.size();
        createInfo.pCode = reinterpret_cast<const uint32_t *>(code.data());

        if( vkCreateShaderModule(jachanDevice.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS){
            throw std::runtime_error("Failed to create shader module");
        }
    }

    PipelineConfigInfo Pipeline::defaultPipeLineConfigInfo(uint32_t width, uint32_t height) {
        PipelineConfigInfo configInfo{};
        return configInfo;
    }
}