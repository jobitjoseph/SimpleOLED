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
#ifndef SIMPLEOLED_H
#define SIMPLEOLED_H

#include <Arduino.h>
#include <Wire.h>

class SimpleOLED {
private:
    uint8_t _address;
    uint8_t _width;
    uint8_t _height;
    uint8_t _pages;
    uint8_t* _buffer;
    uint8_t _cursor_x;
    uint8_t _cursor_y;
    
    void command(uint8_t cmd);
    void sendData(uint8_t* data, uint16_t length);

public:
    SimpleOLED(uint8_t address = 0x3C, uint8_t width = 128, uint8_t height = 64);
    ~SimpleOLED();
    
    // Display control
    bool begin();
    void display();
    void clear();
    void setAddress(uint8_t address);
    void setSize(uint8_t width, uint8_t height);
    
    // Pixel operations
    void setPixel(uint8_t x, uint8_t y, uint8_t color = 1);
    void clearPixel(uint8_t x, uint8_t y);
    uint8_t getPixel(uint8_t x, uint8_t y);
    
    // Drawing functions
    void drawLine(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t color = 1);
    void drawHLine(uint8_t x, uint8_t y, uint8_t w, uint8_t color = 1);
    void drawVLine(uint8_t x, uint8_t y, uint8_t h, uint8_t color = 1);
    void drawRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t color = 1);
    void fillRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t color = 1);
    void drawCircle(uint8_t x0, uint8_t y0, uint8_t r, uint8_t color = 1);
    
    // Image functions
    void drawBitmap(uint8_t x, uint8_t y, const uint8_t* bitmap, uint8_t w, uint8_t h, uint8_t color = 1);
    void drawXBM(uint8_t x, uint8_t y, const uint8_t* xbm, uint8_t w, uint8_t h, uint8_t color = 1);
    
    // Text functions
    void setCursor(uint8_t x, uint8_t y);
    void print(const char* str);
    void println(const char* str);
    void print(int value);
    void println(int value);
    void print(float value, int decimals = 2);
    void println(float value, int decimals = 2);
    void drawChar(uint8_t x, uint8_t y, char c, uint8_t color = 1);
    
    // Text functions with position
    void print(uint8_t x, uint8_t y, const char* str);
    void println(uint8_t x, uint8_t y, const char* str);
    void print(uint8_t x, uint8_t y, int value);
    void println(uint8_t x, uint8_t y, int value);
    void print(uint8_t x, uint8_t y, float value, int decimals = 2);
    void println(uint8_t x, uint8_t y, float value, int decimals = 2);
    
    // Utility
    uint8_t getWidth() { return _width; }
    uint8_t getHeight() { return _height; }
};

#endif