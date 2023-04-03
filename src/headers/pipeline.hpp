#ifndef _H_PIPELINE_
#define _H_PIPELINE_

#include <vector>
#include <string>
#include "jachan_device.hpp"

namespace lve {
    struct  PipelineConfigInfo {};

    class Pipeline {
        public:
        Pipeline(JachanDevice& device, const std::string& vertFilepath, const std::string& fragFilepath, PipelineConfigInfo configInfo);
        ~Pipeline() {}

        Pipeline(const Pipeline& ) = delete;
        void operator=(const Pipeline&) = delete;

        static PipelineConfigInfo defaultPipeLineConfigInfo(uint32_t width, uint32_t height);

        private:
        static std::vector<char> readFile(const std::string& filepath);

        void createGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath, PipelineConfigInfo configInfo);

        void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);
        JachanDevice& jachanDevice;
        VkPipeline graphicsPipeline;
        VkShaderModule vertShaderModule;
        VkShaderModule fragShaderModule;
    };
}

#endif