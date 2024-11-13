#include "brightener.h"
#include <utility>

ImageBrightener::ImageBrightener(std::shared_ptr<Image> inputImage)
    : m_inputImage(std::move(inputImage)) {
}

int ImageBrightener::BrightenWholeImage() {
    int attenuatedPixelCount = 0;
    int rows = m_inputImage->GetRows();
    int columns = m_inputImage->GetColumns();
    const int maxBrightness = 255;
    const int brightnessIncrement = 25;

    for (int x = 0; x < rows; x++) {
        for (int y = 0; y < columns; y++) {
            int pixelValue = m_inputImage->GetPixel(x, y);
            if (pixelValue > (maxBrightness - brightnessIncrement)) {
                ++attenuatedPixelCount;
                m_inputImage->SetPixel(x, y, maxBrightness);
            } else {
                m_inputImage->SetPixel(x, y, pixelValue + brightnessIncrement);
            }
        }
    }
    return attenuatedPixelCount;
}
