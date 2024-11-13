#pragma once
#include <memory>
#include "./image.h"

class ImageBrightener {
  public:
    explicit ImageBrightener(std::shared_ptr<Image> inputImage);
    int BrightenWholeImage();

  private:
    int IncreaseBrightness(int pixelValue, int* attenuatedPixelCount);

  private:
    std::shared_ptr<Image> m_inputImage;
};
