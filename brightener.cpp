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
    int rows = m_inputImage->GetRows();
    int columns = m_inputImage->GetColumns();
    for (int x = 0; x < rows; x++) {
        for (int y = 0; y < columns; y++) {
            int pixel_value = m_inputImage->GetPixel(x, y);
            if (pixel_value > (255 - 25)) {
                ++attenuatedPixelCount;
                m_inputImage->SetPixel(x, y, 255);
            } else {
                m_inputImage->SetPixel(x, y, pixel_value + 25);
            }
        }
    }
    return attenuatedPixelCount;
}
