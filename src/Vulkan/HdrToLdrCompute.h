#pragma once

#include "Context.h"
#include "Image.h"

class HdrToLdrCompute {
public:
    HdrToLdrCompute(Context& context, uint32_t width, uint32_t height, vk::ImageView inputImageView);
    ~HdrToLdrCompute();
    HdrToLdrCompute(const HdrToLdrCompute&) = delete;
    HdrToLdrCompute& operator=(const HdrToLdrCompute&) = delete;
    HdrToLdrCompute(HdrToLdrCompute&&) = delete;
    HdrToLdrCompute& operator=(HdrToLdrCompute&&) = delete;
    
    void dispatch(vk::CommandBuffer commandBuffer, uint32_t x, uint32_t y, uint32_t z);
    Image outputImage;
private:
    vk::UniqueDescriptorSet descriptorSet;
    vk::UniquePipeline pipeline;
    vk::UniquePipelineLayout pipelineLayout;
    vk::UniqueDescriptorSetLayout descriptorSetLayout;
    vk::UniqueShaderModule shaderModule;
};