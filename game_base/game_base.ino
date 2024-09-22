#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define i2c_Address 0x3c

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define OLED_RESET -1     //   QT-PY / XIAO
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int leftBtn = 4;
const int rightBtn = 5;
const int selectBtn = 6;
const int backBtn = 7;

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

  display.drawBitmap(12, 24, bitmap, 12, 12, 1);
}

int getRandomNumber(int minVal, int maxVal) {
  return random(minVal, maxVal + 1);  // maxValue + 1 to include maxValue in the range
}
