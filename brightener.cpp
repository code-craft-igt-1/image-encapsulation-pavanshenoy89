#include "brightener.h"
#include <utility>

ImageBrightener::ImageBrightener(std::shared_ptr<Image> inputImage)
    : m_inputImage(std::move(inputImage)) {
}

int ImageBrightener::BrightenWholeImage() {
    // For brightening, we add a certain grayscale (25) to every pixel.
    // While brightening, some pixels may cross the max brightness. They are
    // called 'attenuated' pixels
    int attenuatedPixelCount = 0;
    for (int x = 0; x < m_inputImage->GetRows(); x++) {
        for (int y = 0; y < m_inputImage->GetColumns(); y++) {
            if (m_inputImage->GetPixel(x, y) > (255 - 25)) {
                ++attenuatedPixelCount;
                m_inputImage->SetPixel(x, y, 255);
            } else {
                m_inputImage->SetPixel(x, y, m_inputImage->GetPixel(x, y) + 25);
            }
        }
    }
    return attenuatedPixelCount;
}
