#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Define OLED display SPI pins
#define OLED_MOSI   11  // Hardware SPI MOSI
#define OLED_CLK    13  // Hardware SPI SCK
#define OLED_DC     8   // Data/Command
#define OLED_CS     10  // Chip select
#define OLED_RESET  9

// Initialize display
Adafruit_SSD1306 display(128, 64, &SPI, OLED_DC, OLED_RESET, OLED_CS);

void setup() {
    Serial.begin(9600);

    // Initialize the OLED display
    if (!display.begin(SSD1306_SWITCHCAPVCC)) {
        Serial.println(F("SSD1306 initialization failed!"));
        while (true) {
          //blink LED to indicate error
          digitalWrite(LED_BUILTIN, HIGH);
          delay(500);
          digitalWrite(LED_BUILTIN, LOW);
          delay(500);
        }

    }

    display.clearDisplay(); // Clear display
    display.setTextSize(2); // Text size
    display.setTextColor(WHITE); // Set text color
    display.setCursor(10, 20); // Move cursor
    display.println("Hello TI!"); // Print line
    display.display(); // Show the message on the display
}

void loop() {
    // Nothing here, just displaying "Hello TI!"
}
