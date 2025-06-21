/* 
 * SimpleOLED Library
 * Copyright (C) 2025 Jobit Joseph
 * Author: Jobit Joseph
 * Project: SimpleOLED Library
 *
 * Licensed under the MIT License
 * You may not use this file except in compliance with the License.
 * 
 * You may obtain a copy of the License at:
 * https://opensource.org/license/mit/
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software (the "Software") and associated documentation files, to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, subject to the following additional conditions:

 * 1. All copies or substantial portions must retain:  
 *    - The original copyright notice  
 *    - A prominent statement crediting the original author/creator  

 * 2. Modified versions must:  
 *    - Clearly mark the changes as their own  
 *    - Preserve all original credit notices
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "SimpleOLED.h"

// 5x7 font data (ASCII 32-126)
const uint8_t font5x7[][5] PROGMEM = {
  {0x00, 0x00, 0x00, 0x00, 0x00}, // Space
  {0x00, 0x00, 0x5F, 0x00, 0x00}, // !
  {0x00, 0x07, 0x00, 0x07, 0x00}, // "
  {0x14, 0x7F, 0x14, 0x7F, 0x14}, // #
  {0x24, 0x2A, 0x7F, 0x2A, 0x12}, // $
  {0x23, 0x13, 0x08, 0x64, 0x62}, // %
  {0x36, 0x49, 0x55, 0x22, 0x50}, // &
  {0x00, 0x05, 0x03, 0x00, 0x00}, // '
  {0x00, 0x1C, 0x22, 0x41, 0x00}, // (
  {0x00, 0x41, 0x22, 0x1C, 0x00}, // )
  {0x08, 0x2A, 0x1C, 0x2A, 0x08}, // *
  {0x08, 0x08, 0x3E, 0x08, 0x08}, // +
  {0x00, 0x50, 0x30, 0x00, 0x00}, // ,
  {0x08, 0x08, 0x08, 0x08, 0x08}, // -
  {0x00, 0x60, 0x60, 0x00, 0x00}, // .
  {0x20, 0x10, 0x08, 0x04, 0x02}, // /
  {0x3E, 0x51, 0x49, 0x45, 0x3E}, // 0
  {0x00, 0x42, 0x7F, 0x40, 0x00}, // 1
  {0x42, 0x61, 0x51, 0x49, 0x46}, // 2
  {0x21, 0x41, 0x45, 0x4B, 0x31}, // 3
  {0x18, 0x14, 0x12, 0x7F, 0x10}, // 4
  {0x27, 0x45, 0x45, 0x45, 0x39}, // 5
  {0x3C, 0x4A, 0x49, 0x49, 0x30}, // 6
  {0x01, 0x71, 0x09, 0x05, 0x03}, // 7
  {0x36, 0x49, 0x49, 0x49, 0x36}, // 8
  {0x06, 0x49, 0x49, 0x29, 0x1E}, // 9
  {0x00, 0x36, 0x36, 0x00, 0x00}, // :
  {0x00, 0x56, 0x36, 0x00, 0x00}, // ;
  {0x00, 0x08, 0x14, 0x22, 0x41}, // <
  {0x14, 0x14, 0x14, 0x14, 0x14}, // =
  {0x41, 0x22, 0x14, 0x08, 0x00}, // >
  {0x02, 0x01, 0x51, 0x09, 0x06}, // ?
  {0x32, 0x49, 0x79, 0x41, 0x3E}, // @
  {0x7E, 0x11, 0x11, 0x11, 0x7E}, // A
  {0x7F, 0x49, 0x49, 0x49, 0x36}, // B
  {0x3E, 0x41, 0x41, 0x41, 0x22}, // C
  {0x7F, 0x41, 0x41, 0x22, 0x1C}, // D
  {0x7F, 0x49, 0x49, 0x49, 0x41}, // E
  {0x7F, 0x09, 0x09, 0x01, 0x01}, // F
  {0x3E, 0x41, 0x41, 0x51, 0x32}, // G
  {0x7F, 0x08, 0x08, 0x08, 0x7F}, // H
  {0x00, 0x41, 0x7F, 0x41, 0x00}, // I
  {0x20, 0x40, 0x41, 0x3F, 0x01}, // J
  {0x7F, 0x08, 0x14, 0x22, 0x41}, // K
  {0x7F, 0x40, 0x40, 0x40, 0x40}, // L
  {0x7F, 0x02, 0x04, 0x02, 0x7F}, // M
  {0x7F, 0x04, 0x08, 0x10, 0x7F}, // N
  {0x3E, 0x41, 0x41, 0x41, 0x3E}, // O
  {0x7F, 0x09, 0x09, 0x09, 0x06}, // P
  {0x3E, 0x41, 0x51, 0x21, 0x5E}, // Q
  {0x7F, 0x09, 0x19, 0x29, 0x46}, // R
  {0x46, 0x49, 0x49, 0x49, 0x31}, // S
  {0x01, 0x01, 0x7F, 0x01, 0x01}, // T
  {0x3F, 0x40, 0x40, 0x40, 0x3F}, // U
  {0x1F, 0x20, 0x40, 0x20, 0x1F}, // V
  {0x7F, 0x20, 0x18, 0x20, 0x7F}, // W
  {0x63, 0x14, 0x08, 0x14, 0x63}, // X
  {0x03, 0x04, 0x78, 0x04, 0x03}, // Y
  {0x61, 0x51, 0x49, 0x45, 0x43}, // Z
  {0x00, 0x00, 0x7F, 0x41, 0x41}, // [
  {0x02, 0x04, 0x08, 0x10, 0x20}, // "\"
  {0x41, 0x41, 0x7F, 0x00, 0x00}, // ]
  {0x04, 0x02, 0x01, 0x02, 0x04}, // ^
  {0x40, 0x40, 0x40, 0x40, 0x40}, // _
  {0x00, 0x01, 0x02, 0x04, 0x00}, // `
  {0x20, 0x54, 0x54, 0x54, 0x78}, // a
  {0x7F, 0x48, 0x44, 0x44, 0x38}, // b
  {0x38, 0x44, 0x44, 0x44, 0x20}, // c
  {0x38, 0x44, 0x44, 0x48, 0x7F}, // d
  {0x38, 0x54, 0x54, 0x54, 0x18}, // e
  {0x08, 0x7E, 0x09, 0x01, 0x02}, // f
  {0x08, 0x14, 0x54, 0x54, 0x3C}, // g
  {0x7F, 0x08, 0x04, 0x04, 0x78}, // h
  {0x00, 0x44, 0x7D, 0x40, 0x00}, // i
  {0x20, 0x40, 0x44, 0x3D, 0x00}, // j
  {0x00, 0x7F, 0x10, 0x28, 0x44}, // k
  {0x00, 0x41, 0x7F, 0x40, 0x00}, // l
  {0x7C, 0x04, 0x18, 0x04, 0x78}, // m
  {0x7C, 0x08, 0x04, 0x04, 0x78}, // n
  {0x38, 0x44, 0x44, 0x44, 0x38}, // o
  {0x7C, 0x14, 0x14, 0x14, 0x08}, // p
  {0x08, 0x14, 0x14, 0x18, 0x7C}, // q
  {0x7C, 0x08, 0x04, 0x04, 0x08}, // r
  {0x48, 0x54, 0x54, 0x54, 0x20}, // s
  {0x04, 0x3F, 0x44, 0x40, 0x20}, // t
  {0x3C, 0x40, 0x40, 0x20, 0x7C}, // u
  {0x1C, 0x20, 0x40, 0x20, 0x1C}, // v
  {0x3C, 0x40, 0x30, 0x40, 0x3C}, // w
  {0x44, 0x28, 0x10, 0x28, 0x44}, // x
  {0x0C, 0x50, 0x50, 0x50, 0x3C}, // y
  {0x44, 0x64, 0x54, 0x4C, 0x44}, // z
  {0x00, 0x08, 0x36, 0x41, 0x00}, // {
  {0x00, 0x00, 0x7F, 0x00, 0x00}, // |
  {0x00, 0x41, 0x36, 0x08, 0x00}, // }
  {0x02, 0x01, 0x02, 0x04, 0x02}  // ~
};

SimpleOLED::SimpleOLED(uint8_t address, uint8_t width, uint8_t height) {
    _address = address;
    _width = width;
    _height = height;
    _pages = height / 8;
    _cursor_x = 0;
    _cursor_y = 0;
    _buffer = new uint8_t[_width * _pages];
}

SimpleOLED::~SimpleOLED() {
    delete[] _buffer;
}

void SimpleOLED::command(uint8_t cmd) {
    Wire.beginTransmission(_address);
    Wire.write(0x00); // Command mode
    Wire.write(cmd);
    Wire.endTransmission();
}

void SimpleOLED::sendData(uint8_t* data, uint16_t length) {
    for (uint16_t i = 0; i < length; i += 16) {
        Wire.beginTransmission(_address);
        Wire.write(0x40); // Data mode
        for (uint8_t j = 0; j < 16 && (i + j) < length; j++) {
            Wire.write(data[i + j]);
        }
        Wire.endTransmission();
    }
}

bool SimpleOLED::begin() {
    Wire.begin();
    Wire.setClock(400000); // Fast I2C
    
    command(0xAE); // Display off
    command(0xD5); // Set display clock
    command(0x80);
    command(0xA8); // Set multiplex ratio
    command(_height - 1);
    command(0xD3); // Set display offset
    command(0x00);
    command(0x40); // Set start line
    command(0x8D); // Charge pump
    command(0x14);
    command(0x20); // Memory mode
    command(0x00); // Horizontal addressing
    command(0xA1); // Segment remap
    command(0xC8); // COM scan direction
    command(0xDA); // COM pins
    command(_height == 64 ? 0x12 : 0x02);
    command(0x81); // Contrast
    command(0xCF);
    command(0xD9); // Pre-charge
    command(0xF1);
    command(0xDB); // VCOM detect
    command(0x40);
    command(0xA4); // Display all on resume
    command(0xA6); // Normal display
    command(0xAF); // Display on
    
    clear();
    return true;
}

void SimpleOLED::setAddress(uint8_t address) {
    _address = address;
}

void SimpleOLED::setSize(uint8_t width, uint8_t height) {
    delete[] _buffer;
    _width = width;
    _height = height;
    _pages = height / 8;
    _buffer = new uint8_t[_width * _pages];
}

void SimpleOLED::clear() {
    memset(_buffer, 0, _width * _pages);
}

void SimpleOLED::setPixel(uint8_t x, uint8_t y, uint8_t color) {
    if (x >= _width || y >= _height) return;
    
    uint16_t index = x + (y / 8) * _width;
    if (color) {
        _buffer[index] |= (1 << (y % 8));
    } else {
        _buffer[index] &= ~(1 << (y % 8));
    }
}

void SimpleOLED::clearPixel(uint8_t x, uint8_t y) {
    setPixel(x, y, 0);
}

uint8_t SimpleOLED::getPixel(uint8_t x, uint8_t y) {
    if (x >= _width || y >= _height) return 0;
    
    uint16_t index = x + (y / 8) * _width;
    return (_buffer[index] & (1 << (y % 8))) ? 1 : 0;
}

void SimpleOLED::drawLine(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t color) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;
    
    while (true) {
        setPixel(x0, y0, color);
        
        if (x0 == x1 && y0 == y1) break;
        
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

void SimpleOLED::drawHLine(uint8_t x, uint8_t y, uint8_t w, uint8_t color) {
    for (uint8_t i = 0; i < w; i++) {
        setPixel(x + i, y, color);
    }
}

void SimpleOLED::drawVLine(uint8_t x, uint8_t y, uint8_t h, uint8_t color) {
    for (uint8_t i = 0; i < h; i++) {
        setPixel(x, y + i, color);
    }
}

void SimpleOLED::drawRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t color) {
    drawHLine(x, y, w, color);         // Top
    drawHLine(x, y + h - 1, w, color); // Bottom
    drawVLine(x, y, h, color);         // Left
    drawVLine(x + w - 1, y, h, color); // Right
}

void SimpleOLED::fillRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t color) {
    for (uint8_t i = 0; i < h; i++) {
        drawHLine(x, y + i, w, color);
    }
}

void SimpleOLED::drawCircle(uint8_t x0, uint8_t y0, uint8_t r, uint8_t color) {
    int x = r;
    int y = 0;
    int err = 0;
    
    while (x >= y) {
        setPixel(x0 + x, y0 + y, color);
        setPixel(x0 + y, y0 + x, color);
        setPixel(x0 - y, y0 + x, color);
        setPixel(x0 - x, y0 + y, color);
        setPixel(x0 - x, y0 - y, color);
        setPixel(x0 - y, y0 - x, color);
        setPixel(x0 + y, y0 - x, color);
        setPixel(x0 + x, y0 - y, color);
        
        if (err <= 0) {
            y += 1;
            err += 2*y + 1;
        }
        if (err > 0) {
            x -= 1;
            err -= 2*x + 1;
        }
    }
}

void SimpleOLED::drawBitmap(uint8_t x, uint8_t y, const uint8_t* bitmap, uint8_t w, uint8_t h, uint8_t color) {
    for (uint8_t row = 0; row < h; row++) {
        for (uint8_t col = 0; col < w; col++) {
            uint8_t byte_index = (row * ((w + 7) / 8)) + (col / 8);
            uint8_t bit_index = 7 - (col % 8);
            
            if (pgm_read_byte(&bitmap[byte_index]) & (1 << bit_index)) {
                setPixel(x + col, y + row, color);
            }
        }
    }
}

void SimpleOLED::drawXBM(uint8_t x, uint8_t y, const uint8_t* xbm, uint8_t w, uint8_t h, uint8_t color) {
    for (uint8_t row = 0; row < h; row++) {
        for (uint8_t col = 0; col < w; col++) {
            uint8_t byte_index = (row * ((w + 7) / 8)) + (col / 8);
            uint8_t bit_index = col % 8;
            
            if (pgm_read_byte(&xbm[byte_index]) & (1 << bit_index)) {
                setPixel(x + col, y + row, color);
            }
        }
    }
}

void SimpleOLED::setCursor(uint8_t x, uint8_t y) {
    _cursor_x = x;
    _cursor_y = y;
}

void SimpleOLED::drawChar(uint8_t x, uint8_t y, char c, uint8_t color) {
    if (c < 32 || c > 126) c = 32; // Replace invalid chars with space
    
    uint8_t char_index = c - 32;
    
    for (uint8_t i = 0; i < 5; i++) {
        uint8_t column = pgm_read_byte(&font5x7[char_index][i]);
        for (uint8_t j = 0; j < 7; j++) {
            if (column & (1 << j)) {
                setPixel(x + i, y + j, color);
            }
        }
    }
}

void SimpleOLED::print(const char* str) {
    while (*str) {
        if (*str == '\n') {
            _cursor_x = 0;
            _cursor_y += 8;
        } else {
            drawChar(_cursor_x, _cursor_y, *str, 1);
            _cursor_x += 6; // 5 pixels + 1 space
            if (_cursor_x >= _width) {
                _cursor_x = 0;
                _cursor_y += 8;
            }
        }
        str++;
    }
}

void SimpleOLED::println(const char* str) {
    print(str);
    _cursor_x = 0;
    _cursor_y += 8;
}

void SimpleOLED::print(int value) {
    char buffer[12];
    itoa(value, buffer, 10);
    print(buffer);
}

void SimpleOLED::println(int value) {
    print(value);
    _cursor_x = 0;
    _cursor_y += 8;
}

void SimpleOLED::print(float value, int decimals) {
    char buffer[20];
    dtostrf(value, 0, decimals, buffer);
    print(buffer);
}

void SimpleOLED::println(float value, int decimals) {
    print(value, decimals);
    _cursor_x = 0;
    _cursor_y += 8;
}

// Text functions with position
void SimpleOLED::print(uint8_t x, uint8_t y, const char* str) {
    setCursor(x, y);
    print(str);
}

void SimpleOLED::println(uint8_t x, uint8_t y, const char* str) {
    setCursor(x, y);
    println(str);
}

void SimpleOLED::print(uint8_t x, uint8_t y, int value) {
    setCursor(x, y);
    print(value);
}

void SimpleOLED::println(uint8_t x, uint8_t y, int value) {
    setCursor(x, y);
    println(value);
}

void SimpleOLED::print(uint8_t x, uint8_t y, float value, int decimals) {
    setCursor(x, y);
    print(value, decimals);
}

void SimpleOLED::println(uint8_t x, uint8_t y, float value, int decimals) {
    setCursor(x, y);
    println(value, decimals);
}

void SimpleOLED::display() {
    command(0x21); // Column address
    command(0x00); // Start column
    command(_width - 1); // End column
    command(0x22); // Page address
    command(0x00); // Start page
    command(_pages - 1); // End page
    
    sendData(_buffer, _width * _pages);
}