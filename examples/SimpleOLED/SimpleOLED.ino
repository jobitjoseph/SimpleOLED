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

// Create display
SimpleOLED display(0x3C, 128, 64);

// Sample 16x16 bitmap (heart icon)
const uint8_t heart_bitmap[] PROGMEM = {
  0x00, 0x00, 0x38, 0x7c, 0xfe, 0xfe, 0xfe, 0xff, 
  0xff, 0xfe, 0xfe, 0xfe, 0x7c, 0x38, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f, 
  0x1f, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00
};

// Sample XBM format image (8x8 smiley)
const uint8_t smiley_xbm[] PROGMEM = {
  0x3c, 0x42, 0xa5, 0x81, 0xa5, 0x99, 0x42, 0x3c
};

void setup() {
    display.begin();
    
    // Demo different features
    demoGraphics();
    delay(2000);
    
    demoImages();
    delay(2000);
    
    demoText();
}

void demoGraphics() {
    display.clear();
    
    // Draw shapes
    display.drawRect(10, 10, 30, 20, 1);
    display.fillRect(50, 15, 20, 10, 1);
    display.drawCircle(100, 20, 15, 1);
    
    // Draw lines
    display.drawLine(0, 40, 127, 40, 1);
    display.drawVLine(64, 45, 15, 1);
    
    display.display();
}

void demoImages() {
    display.clear();
    
    // Draw bitmap images
    display.drawBitmap(20, 10, heart_bitmap, 16, 16, 1);
    display.drawBitmap(50, 10, heart_bitmap, 16, 16, 1);
    
    // Draw XBM image
    display.drawXBM(90, 15, smiley_xbm, 8, 8, 1);
    
    display.setCursor(0, 35);
    display.println("Bitmap Images!");
    
    display.display();
}

void demoText() {
    display.clear();
    
    // Traditional way with setCursor
    display.setCursor(0, 0);
    display.println("Traditional:");
    
    // New way with x,y parameters
    display.print(0, 16, "At position:");
    display.print(80, 16, "(80,16)");
    
    display.println(0, 32, "Integer:");
    display.println(60, 32, 42);
    
    display.print(0, 48, "Float: ");
    display.print(42, 48, 3.14159, 2);
    
    display.display();
}

void loop() {
    // Animation loop
    static int frame = 0;
    
    display.clear();
    display.setCursor(0, 0);
    display.print("Frame: ");
    display.println(frame);
    
    // Animated circle
    int x = 64 + 30 * cos(frame * 0.1);
    int y = 32 + 15 * sin(frame * 0.1);
    display.drawCircle(x, y, 5, 1);
    
    display.display();
    frame++;
    delay(50);
}
