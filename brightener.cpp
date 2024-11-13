#include "brightener.h"
#include <utility>

ImageBrightener::ImageBrightener(std::shared_ptr<Image> inputImage)
    : m_inputImage(std::move(inputImage)) {
}

int ImageBrightener::BrightenWholeImage() {
    int attenuatedPixelCount = 0;

    for (int x = 0; x < m_inputImage->GetRows(); x++) {
        for (int y = 0; y < m_inputImage->GetColumns(); y++) {
            int updatedPixelValue = IncreaseBrightness(m_inputImage->GetPixel(x, y), attenuatedPixelCount);
            m_inputImage->SetPixel(x, y, updatedPixelValue);
        }
    }

    return attenuatedPixelCount;
}

int ImageBrightener::IncreaseBrightness(int pixelValue, int& attenuatedPixelCount) {
    const int maxBrightness = 255;
    const int brightnessIncrement = 25;
    int updatedPixelValue = pixelValue + brightnessIncrement;
    if (updatedPixelValue > maxBrightness) {
        ++attenuatedPixelCount;
        updatedPixelValue = maxBrightness;
    }
    return updatedPixelValue;
}
