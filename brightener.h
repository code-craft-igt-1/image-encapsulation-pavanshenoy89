#pragma once
#include <memory>
#include "./image.h"

class ImageBrightener {
 public:
    explicit ImageBrightener(std::shared_ptr<Image> inputImage);
    void BrightenWholeImage();
    uint16_t GetAttenuatedCount() const;

 private:
    int IncreaseBrightness(int pixelValue);

 private:
    std::shared_ptr<Image> m_inputImage;
    uint16_t attenuatedPixelCount;
};
