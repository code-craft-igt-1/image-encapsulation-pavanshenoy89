#include "./brightener.h"
#include <utility>

ImageBrightener::ImageBrightener(std::shared_ptr<Image> inputImage)
    : m_inputImage(std::move(inputImage)), attenuatedPixelCount(0) {
}

void ImageBrightener::BrightenWholeImage() {
    for (int x = 0; x < m_inputImage->GetRows(); x++) {
        for (int y = 0; y < m_inputImage->GetColumns(); y++) {
            int updatedPixelValue = IncreaseBrightness(
                                    m_inputImage->GetPixel(x, y));
            m_inputImage->SetPixel(x, y, updatedPixelValue);
        }
    }
}

uint16_t ImageBrightener::GetAttenuatedCount() const {
    return attenuatedPixelCount;
}

int ImageBrightener::IncreaseBrightness(int pixelValue) {
    const int maxBrightness = 255;
    const int brightnessIncrement = 25;
    int updatedPixelValue = pixelValue + brightnessIncrement;
    if (updatedPixelValue > maxBrightness) {
        updatedPixelValue = maxBrightness;
        attenuatedPixelCount++;
    }
    return updatedPixelValue;
}
