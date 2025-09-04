# SimpleOLED Library
![License](https://img.shields.io/badge/License-MIT-blue.svg)
![Platforms](https://img.shields.io/badge/Platforms-ESP32%20%7C%20ESP8266%20%7C%20Arduino%20Uno%20R4%20WiFi%20%7C%20RPi%20Pico%20W%20%7C%20Arduino-green)
![Version](https://img.shields.io/badge/Version-1.0.0-brightgreen)

A lightweight, feature-rich Arduino library for SSD1306 OLED displays that uses only the Wire library. Perfect for projects requiring minimal memory usage and no external dependencies.

<p align="center">
  <a href="https://www.paypal.com/paypalme/jobitjoseph">
    <img src="https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif" alt="Donate with PayPal" />
  </a>
</p>

## Features

- ✅ **Wire Library Only** - No heavy graphics libraries required
- ✅ **Multiple Display Sizes** - Supports 128x64 and 128x32 displays
- ✅ **Configurable I2C Address** - Works with 0x3C and 0x3D addresses
- ✅ **Text Rendering** - Built-in 5x7 font with position control
- ✅ **Graphics Functions** - Lines, rectangles, circles, pixels
- ✅ **Image Support** - Bitmap and XBM format images
- ✅ **Memory Efficient** - Optimized for Arduino Uno and similar boards
- ✅ **Easy to Use** - Simple, intuitive API

## Installation

### Arduino IDE
#### Method 1: Arduino Library Manager (Recommended)
1. **Open Arduino IDE**
2. **Navigate to Library Manager**
   ```
   Tools → Manage Libraries... (or Ctrl+Shift+I)
   ```
3. **Search for GeoLinker**
   - Type "GeoLinker" in the search box
   - Install version 1.0.2
4. Include with `#include <SimpleOLED.h>`

#### Method : Manual Installation
1. Download the library files
2. Place in `Arduino/libraries/SimpleOLED/`
3. Restart Arduino IDE
4. Include with `#include <SimpleOLED.h>`

### PlatformIO
Add to your `platformio.ini`:
```ini
lib_deps = 
    SimpleOLED
```

## Quick Start

```cpp
#include <SimpleOLED.h>

SimpleOLED display;  // Default: 0x3C, 128x64

void setup() {
    display.begin();
    display.clear();
    display.println(0, 0, "Hello World!");
    display.display();
}

void loop() {
    // Your code here
}
```

## Hardware Connections

| OLED Pin | Arduino Uno | ESP32 | ESP8266 |
|----------|-------------|-------|---------|
| VCC      | 3.3V/5V     | 3.3V  | 3.3V    |
| GND      | GND         | GND   | GND     |
| SDA      | A4          | 21    | D2      |
| SCL      | A5          | 22    | D1      |

## API Reference

### Display Control
- `begin()` - Initialize display
- `display()` - Update screen with buffer
- `clear()` - Clear display buffer
- `setSize(width, height)` - Set display dimensions
- `setAddress(address)` - Set I2C address

### Text Functions
- `print(text)` / `println(text)` - Print at cursor
- `print(x, y, text)` / `println(x, y, text)` - Print at position
- `setCursor(x, y)` - Set text cursor position

### Graphics Functions
- `setPixel(x, y, color)` - Set individual pixel
- `drawLine(x0, y0, x1, y1)` - Draw line
- `drawRect(x, y, w, h)` - Draw rectangle outline
- `fillRect(x, y, w, h)` - Draw filled rectangle
- `drawCircle(x, y, radius)` - Draw circle

### Image Functions
- `drawBitmap(x, y, bitmap, w, h)` - Draw bitmap image
- `drawXBM(x, y, xbm, w, h)` - Draw XBM format image

## Examples

### Basic Text
```cpp
display.clear();
display.println(0, 0, "Temperature:");
display.print(0, 16, "Value: ");
display.print(50, 16, 25.6, 1);
display.println(80, 16, " C");
display.display();
```

### Graphics
```cpp
display.clear();
display.drawRect(10, 10, 50, 30, 1);
display.drawCircle(80, 25, 15, 1);
display.drawLine(0, 50, 127, 50, 1);
display.display();
```

### Multiple Display Sizes
```cpp
// For 128x32 display
SimpleOLED display(0x3C, 128, 32);

// For different I2C address
SimpleOLED display(0x3D, 128, 64);
```

## License

MIT License - Feel free to use in personal and commercial projects.

**Copyright (C) 2025 Jobit Joseph, Semicon Media Pvt Ltd (Circuit Digest)**

## 👨‍💻 Author

**Jobit Joseph** 

## 🔄 Version History
- **v1.0.1** - Current release
- Bug Fix
- **v1.0.0** - Initial release

---
