#pragma once
#include <cstdint>
#include <memory>

class Image {
 public:
    Image(uint16_t rows, uint16_t columns);
    ~Image();
    uint8_t GetPixel(uint16_t x, uint16_t y) const;
    void SetPixel(uint16_t x, uint16_t y, uint8_t value);
    bool Validate() const;

    uint16_t GetRows() const { return m_rows; }
    uint16_t GetColumns() const { return m_columns; }

 private:
    const uint16_t m_rows;
    const uint16_t m_columns;
    std::unique_ptr<uint8_t[]> pixels;  // max 1k x 1k image
    static const uint16_t MAX_ROW_COLUMN = 1024;
};
