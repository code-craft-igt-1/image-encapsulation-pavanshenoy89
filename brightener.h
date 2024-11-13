#pragma once
#include "image.h"

class ImageBrightener {
 private:
    std::shared_ptr<Image> m_inputImage;
 public:
    explicit ImageBrightener(std::shared_ptr<Image> inputImage);
    int BrightenWholeImage();
};
