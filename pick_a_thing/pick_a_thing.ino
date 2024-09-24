#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define i2c_Address 0x3c

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define OLED_RESET -1     //   QT-PY / XIAO
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const unsigned char box [] PROGMEM = {
	// 17x16px
	0x3f, 0xff, 0x80, 0x40, 0x81, 0x80, 0x81, 0x02, 0x80, 0xff, 0xfe, 0x80, 0x87, 0xc2, 0x80, 0x88, 
	0x22, 0x80, 0x93, 0x92, 0x80, 0xa4, 0x4a, 0x80, 0xa4, 0x4a, 0x80, 0xa0, 0x8a, 0x80, 0xa1, 0x0a, 
	0x80, 0xa0, 0x0a, 0x80, 0x91, 0x12, 0x80, 0x88, 0x22, 0x80, 0x87, 0xc3, 0x00, 0xff, 0xfe, 0x00
};

const int leftBtn = 0;
const int backBtn = 1;
const int selectBtn = 2;
const int rightBtn = 3;

unsigned long previousAnimationMillis = 0;
const int animationDelay = 85;
int currentFrame = 0;

void setup() {
  randomSeed(analogRead(0));

  Serial.begin(9600);

  pinMode(leftBtn, INPUT_PULLUP);
  pinMode(rightBtn, INPUT_PULLUP);
  pinMode(selectBtn, INPUT_PULLUP);
  pinMode(backBtn, INPUT_PULLUP);

  delay(500);                        // wait for the OLED to power up
  display.begin(i2c_Address, true);  // Address 0x3C default
  display.setContrast(0);            // dim display
  display.setRotation(1);
  display.setTextColor(SH110X_WHITE);
  display.setTextSize(1);

  display.clearDisplay();
  display.display();

}

void loop() {

  renderGame();

  unsigned long animationMillis = millis();

  if (animationMillis - previousAnimationMillis >= animationDelay) {
    previousAnimationMillis = animationMillis;  // reset timer

    currentFrame++;
  }

}

void renderGame() {
  display.clearDisplay();

  display.drawBitmap(12, 24, box, 17, 16, 1);

  display.display();
}

int getRandomNumber(int minVal, int maxVal) {
  return random(minVal, maxVal + 1);  // maxValue + 1 to include maxValue in the range
}
