#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define i2c_Address 0x3c

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define OLED_RESET -1     //   QT-PY / XIAO
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const unsigned char banner [] PROGMEM = {
	// 64x16px
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xa0, 0xb0, 0x68, 0x2c, 0x1a, 0x0b, 0x06, 0x82, 
	0x4e, 0x67, 0x33, 0x99, 0xcc, 0xe6, 0x73, 0x39, 0x9f, 0x0f, 0x87, 0xc3, 0xe1, 0xf0, 0xf8, 0x7c, 
	0xb1, 0x98, 0xcc, 0x66, 0x33, 0x19, 0x8c, 0xc6, 0xb1, 0x98, 0xcc, 0x66, 0x33, 0x19, 0x8c, 0xc6, 
	0xb1, 0x98, 0xcc, 0x66, 0x33, 0x19, 0x8c, 0xc6, 0x87, 0x03, 0x81, 0xc0, 0xe0, 0x70, 0x38, 0x1c, 
	0xce, 0x67, 0x33, 0x99, 0xcc, 0xe6, 0x73, 0x39, 0xec, 0xb6, 0x6b, 0x2d, 0x9a, 0xcb, 0x66, 0xb2, 
	0x61, 0x50, 0xd8, 0x54, 0x36, 0x15, 0x0d, 0x85, 0xad, 0xb6, 0xab, 0x6d, 0xaa, 0xdb, 0x6a, 0xb6, 
	0x6d, 0x56, 0xdb, 0x55, 0xb6, 0xd5, 0x6d, 0xb5, 0xa1, 0xb0, 0xa8, 0x6c, 0x2a, 0x1b, 0x0a, 0x86, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
const unsigned char devil_head [] PROGMEM = {
  // 48x17px
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 
	0x00, 0x20, 0x78, 0x00, 0x00, 0x00, 0x00, 0x60, 0x7c, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x7e, 0x00, 
	0x00, 0x00, 0x01, 0xe0, 0x7f, 0x00, 0x00, 0x00, 0x07, 0xe0, 0x3f, 0x80, 0xff, 0xff, 0x0f, 0xe0, 
	0x3f, 0xe7, 0xff, 0xff, 0xff, 0xc0, 0x1f, 0xff, 0x00, 0x01, 0xff, 0xc0, 0x1f, 0xf8, 0x00, 0x00, 
	0x7f, 0x80, 0x1f, 0xc0, 0x00, 0x00, 0x1f, 0x80, 0x1e, 0x00, 0x00, 0x00, 0x07, 0x80, 0x38, 0x00, 
	0x00, 0x00, 0x03, 0x80, 0x70, 0x00, 0x00, 0x00, 0x01, 0x80, 0xe0, 0x00, 0x00, 0x00, 0x00, 0xc0, 
	0xc0, 0x00, 0x00, 0x00, 0x00, 0xc0
};
const unsigned char table [] PROGMEM = {
	// 64x32px
	0x20, 0x00, 0x0e, 0x00, 0x00, 0xe0, 0x00, 0x0f, 0x20, 0x00, 0x04, 0x00, 0x00, 0x40, 0x00, 0x07, 
	0x20, 0x00, 0x0a, 0x00, 0x00, 0xa0, 0x00, 0x0b, 0x20, 0x00, 0x04, 0x00, 0x00, 0x40, 0x00, 0x05, 
	0x40, 0x00, 0x0a, 0x00, 0x00, 0xa0, 0x00, 0x0d, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 
	0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x19, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x49, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 
	0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x09, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x09, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0b, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 
	0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 
	0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0
};
const unsigned char box [] PROGMEM = {
	// 17x16px
	0x3f, 0xff, 0x80, 0x40, 0x81, 0x80, 0x81, 0x02, 0x80, 0xff, 0xfe, 0x80, 0x87, 0xc2, 0x80, 0x88, 
	0x22, 0x80, 0x93, 0x92, 0x80, 0xa4, 0x4a, 0x80, 0xa4, 0x4a, 0x80, 0xa0, 0x8a, 0x80, 0xa1, 0x0a, 
	0x80, 0xa0, 0x0a, 0x80, 0x91, 0x12, 0x80, 0x88, 0x22, 0x80, 0x87, 0xc3, 0x00, 0xff, 0xfe, 0x00
};
const unsigned char box_open_0 [] PROGMEM = {
// 26x24px
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x80, 0x00, 
	0x00, 0x15, 0x40, 0x00, 0x00, 0x2a, 0x20, 0x00, 0x00, 0x51, 0x10, 0x00, 0x00, 0xa0, 0x88, 0x00, 
	0x01, 0x40, 0x44, 0x00, 0x02, 0x80, 0x2c, 0x00, 0x05, 0x00, 0x14, 0x00, 0x07, 0xff, 0xf4, 0x00, 
	0x04, 0x3e, 0x14, 0x00, 0x04, 0x41, 0x14, 0x00, 0x04, 0x9c, 0x94, 0x00, 0x05, 0x22, 0x54, 0x00, 
	0x05, 0x22, 0x54, 0x00, 0x05, 0x04, 0x54, 0x00, 0x05, 0x08, 0x54, 0x00, 0x05, 0x00, 0x54, 0x00, 
	0x04, 0x88, 0x94, 0x00, 0x04, 0x41, 0x14, 0x00, 0x04, 0x3e, 0x18, 0x00, 0x07, 0xff, 0xf0, 0x00
};
const unsigned char box_open_1 [] PROGMEM = {
// 26x24px
  0x04, 0x00, 0x04, 0x00, 0x06, 0x00, 0x0c, 0x00, 0x05, 0x00, 0x14, 0x00, 0x05, 0x00, 0x14, 0x00, 
	0x05, 0x00, 0x14, 0x00, 0x05, 0x00, 0x14, 0x00, 0x05, 0x00, 0x14, 0x00, 0x05, 0x00, 0x14, 0x00, 
	0x05, 0x00, 0x14, 0x00, 0x05, 0x00, 0x1c, 0x00, 0x05, 0x00, 0x14, 0x00, 0x07, 0xff, 0xf4, 0x00, 
	0x04, 0x3e, 0x14, 0x00, 0x04, 0x41, 0x14, 0x00, 0x04, 0x9c, 0x94, 0x00, 0x05, 0x22, 0x54, 0x00, 
	0x05, 0x22, 0x54, 0x00, 0x05, 0x04, 0x54, 0x00, 0x05, 0x08, 0x54, 0x00, 0x05, 0x00, 0x54, 0x00, 
	0x04, 0x88, 0x94, 0x00, 0x04, 0x41, 0x14, 0x00, 0x04, 0x3e, 0x18, 0x00, 0x07, 0xff, 0xf0, 0x00
};
const unsigned char box_open_2 [] PROGMEM = {
// 26x24px
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x40, 0x00, 0x00, 0x40, 0xa0, 0x00, 0x00, 0x80, 0x50, 0x00, 0x01, 0x40, 0x28, 0x00, 0x02, 0x80, 
	0x14, 0x00, 0x05, 0x00, 0x0a, 0x00, 0x0a, 0x00, 0x05, 0x00, 0x14, 0x00, 0x07, 0xff, 0xf4, 0x00, 
	0x04, 0x3e, 0x14, 0x00, 0x04, 0x41, 0x14, 0x00, 0x04, 0x9c, 0x94, 0x00, 0x05, 0x22, 0x54, 0x00, 
	0x05, 0x22, 0x54, 0x00, 0x05, 0x04, 0x54, 0x00, 0x05, 0x08, 0x54, 0x00, 0x05, 0x00, 0x54, 0x00, 
	0x04, 0x88, 0x94, 0x00, 0x04, 0x41, 0x14, 0x00, 0x04, 0x3e, 0x18, 0x00, 0x07, 0xff, 0xf0, 0x00
};
const unsigned char win_0 [] PROGMEM = {
  // 12x12px
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x03, 0xc0, 0x07, 0xc0, 0x07, 0xc0
};
const unsigned char win_1 [] PROGMEM = {
  // 12x12px
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x07, 0xc0, 
	0x07, 0xc0, 0x01, 0xc0, 0x21, 0xc0, 0x21, 0xc0
};
const unsigned char win_2 [] PROGMEM = {
  // 12x12px
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x07, 0xc0, 0x07, 0xc0, 0x01, 0xc0, 0x21, 0xc0, 
	0x21, 0xc0, 0xf9, 0xc0, 0x21, 0xc0, 0x21, 0xc0
};
const unsigned char win_3 [] PROGMEM = {
  // 12x12px
	0x03, 0xc0, 0x07, 0xc0, 0x07, 0xc0, 0x01, 0xc0, 0x21, 0xc0, 0x21, 0xc0, 0xf9, 0xc0, 0x21, 0xc0, 
	0x21, 0xc0, 0x01, 0xc0, 0x03, 0xe0, 0x07, 0xf0
};
const unsigned char win_4 [] PROGMEM = {
  // 12x12px
	0x01, 0x40, 0x02, 0x80, 0x05, 0x40, 0x00, 0x80, 0x01, 0x40, 0x20, 0x80, 0x51, 0x40, 0x20, 0x80, 
	0x01, 0x40, 0x00, 0x80, 0x01, 0x40, 0x02, 0xa0
};
const unsigned char win_5 [] PROGMEM = {
  // 12x12px
	0x01, 0x40, 0x00, 0x00, 0x05, 0x40, 0x00, 0x00, 0x01, 0x40, 0x00, 0x00, 0x41, 0x40, 0x20, 0x00, 
	0x01, 0x40, 0x00, 0x00, 0x01, 0x40, 0x00, 0x00
};
const unsigned char win_6 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x40, 0x00, 0x00, 0x80, 
	0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00
};
const unsigned char lose_0 [] PROGMEM = {
  // 12x12px
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xc0, 0x01, 0xe0, 0x03, 0x30
};
const unsigned char lose_1 [] PROGMEM = {
  // 12x12px
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x01, 0xe0, 
	0x03, 0x30, 0x03, 0x30, 0x23, 0x30, 0x23, 0x30
};
const unsigned char lose_2 [] PROGMEM = {
  // 12x12px
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x01, 0xe0, 0x03, 0x30, 0x03, 0x30, 0x23, 0x30, 
	0x23, 0x30, 0xfb, 0x30, 0x23, 0x30, 0x23, 0x30
};
const unsigned char lose_3 [] PROGMEM = {
  // 12x12px
	0x00, 0xc0, 0x01, 0xe0, 0x03, 0x30, 0x03, 0x30, 0x23, 0x30, 0x23, 0x30, 0xfb, 0x30, 0x23, 0x30, 
	0x23, 0x30, 0x03, 0x30, 0x01, 0xe0, 0x00, 0xc0
};
const unsigned char lose_4 [] PROGMEM = {
  // 12x12px
	0x00, 0x00, 0x00, 0xe0, 0x01, 0x10, 0x02, 0x20, 0x01, 0x10, 0x22, 0x20, 0x51, 0x10, 0x22, 0x20, 
	0x01, 0x10, 0x02, 0x20, 0x01, 0xc0, 0x00, 0x00
};
const unsigned char lose_5 [] PROGMEM = {
  // 12x12px
	0x00, 0x00, 0x00, 0xa0, 0x01, 0x10, 0x02, 0x20, 0x00, 0x10, 0x02, 0x20, 0x40, 0x10, 0x22, 0x20, 
	0x00, 0x10, 0x02, 0x20, 0x01, 0x40, 0x00, 0x00
};
const unsigned char lose_6 [] PROGMEM = {
  // 12x12px
	0x00, 0x00, 0x00, 0x20, 0x01, 0x00, 0x00, 0x00, 0x00, 0x10, 0x02, 0x00, 0x40, 0x00, 0x00, 0x00, 
	0x00, 0x10, 0x02, 0x00, 0x00, 0x40, 0x00, 0x00
};
const unsigned char top_select [] PROGMEM = {
	// 7x6px
	0x38, 0x38, 0xfe, 0x7c, 0x38, 0x10
};
const unsigned char bottom_select [] PROGMEM = {
	// 11x3px
	0xff, 0xe0, 0x00, 0x00, 0x3f, 0x80
};

const int leftBtn = 0;
const int backBtn = 1;
const int selectBtn = 2;
const int rightBtn = 3;

unsigned long previousAnimationMillis = 0;
const int animationDelay = 85;
int currentFrame = 0;

unsigned long previousSystemDelayMillis = 0;
int systemDelayInterval = 300;
bool btnCooldown = false;

int boxState[3] = {0, 0, 0};
int selectedBox = 0;

int currentBoxFrame = 0;
bool opened = false;

int currentEndFrame = 0;

void setup() {
  randomSeed(analogRead(0));

  Serial.begin(9600);
  while (!Serial);

  int opt_0[3] = { 0, 1, 2 };
  int opt_1[3] = { 1, 0, 2 };
  int opt_2[3] = { 1, 2, 0 };
  int opt_3[3] = { 0, 2, 1 };
  int opt_4[3] = { 2, 1, 0 };
  int opt_5[3] = { 2, 0, 1 };

  int* boxOptions[6] = { opt_0, opt_1, opt_2, opt_3, opt_4, opt_5 };
  int* randomState = boxOptions[random(0, 6)];

  boxState[0] = randomState[0];
  boxState[1] = randomState[1];
  boxState[2] = randomState[2];

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
  unsigned long systemDelayMillis = millis();

  if (systemDelayMillis - previousSystemDelayMillis >= systemDelayInterval) {
    previousSystemDelayMillis = systemDelayMillis;  // reset the timer

    btnCooldown = false;
  }

  if (animationMillis - previousAnimationMillis >= animationDelay) {
    previousAnimationMillis = animationMillis;  // reset timer

    if(opened && currentBoxFrame <= 4){
      currentBoxFrame++;
    }

    if(opened && currentBoxFrame >= 5 && currentEndFrame >= 14){
      delay(1000);
      currentEndFrame = 0;
      currentBoxFrame = 0;
      opened = false;
    }

    if(opened && currentBoxFrame >= 5 && currentEndFrame <= 13){
      currentEndFrame++;
    }

    currentFrame++;
    if(currentFrame >= 8){
      currentFrame = 0;
    }
  }

  if(digitalRead(leftBtn) == LOW && btnCooldown == false && opened == false){
    btnCooldown = true;
    previousSystemDelayMillis = systemDelayMillis;
    selectedBox--;
  }
  if(digitalRead(rightBtn) == LOW && btnCooldown == false && opened == false){
    btnCooldown = true;
    previousSystemDelayMillis = systemDelayMillis;
    selectedBox++;
  }
  if(digitalRead(selectBtn) == LOW && btnCooldown == false && opened == false){
    opened = true;
    btnCooldown = true;
    previousSystemDelayMillis = systemDelayMillis;
  }

}

void renderGame() {

  const unsigned char* box_frames[6] = { box_open_0, box_open_0, box_open_1, box_open_1, box_open_2, box_open_2 };
  const unsigned char* win_frames[15] = { win_0, win_1, win_2, win_3, win_3, win_3, win_3, win_3, win_3, win_3, win_3, win_3, win_4, win_5, win_6 };
  const unsigned char* lose_frames[15] = { lose_0, lose_1, lose_2, lose_3, lose_3, lose_3, lose_3, lose_3, lose_3, lose_3, lose_3, lose_3, lose_4, lose_5, lose_6 };
  const unsigned char plusYPositions[15] = { 35, 35, 35, 35, 33, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31 };


  selectedBox = (selectedBox + 3) % 3; // loop between the 3 selected boxes

  display.clearDisplay();

  display.drawBitmap(0, 4, banner, 64, 16, 1);
  display.drawBitmap(0, 110, banner, 64, 16, 1);
  display.drawBitmap(1, 5, table, 64, 32, 1);
  display.drawBitmap(10, 93, devil_head, 48, 17, 1);

  int selectYPositions[8] = { 36, 36, 34, 34, 33, 33, 34, 34 };

  if(opened){
    if(selectedBox == 0){
      if(boxState[selectedBox] == 0 && currentBoxFrame >= 5 && currentEndFrame <= 13){
        display.drawBitmap(6, plusYPositions[currentEndFrame], lose_frames[currentEndFrame], 12, 12, 1);
      }
      if(boxState[selectedBox] == 1 && currentBoxFrame >= 5 && currentEndFrame <= 13){
        display.drawBitmap(6, plusYPositions[currentEndFrame], win_frames[currentEndFrame], 12, 12, 1);
      }
      if(boxState[selectedBox] == 2 && currentBoxFrame >= 5 && currentEndFrame <= 13){
        display.drawBitmap(6, plusYPositions[currentEndFrame], win_frames[currentEndFrame], 12, 12, 1);
      }

      display.drawBitmap(-1, 36, box_frames[currentBoxFrame], 26, 24, 1);
      display.drawBitmap(24, 44, box, 17, 16, 1);
      display.drawBitmap(44, 44, box, 17, 16, 1);

    }
    if(selectedBox == 1){
      if(boxState[selectedBox] == 0 && currentBoxFrame >= 5 && currentEndFrame <= 13){
        display.drawBitmap(26, plusYPositions[currentEndFrame], lose_frames[currentEndFrame], 12, 12, 1);
      }
      if(boxState[selectedBox] == 1 && currentBoxFrame >= 5 && currentEndFrame <= 13){
        display.drawBitmap(26, plusYPositions[currentEndFrame], win_frames[currentEndFrame], 12, 12, 1);
      }
      if(boxState[selectedBox] == 2 && currentBoxFrame >= 5 && currentEndFrame <= 13){
        display.drawBitmap(26, plusYPositions[currentEndFrame], win_frames[currentEndFrame], 12, 12, 1);
      }

      display.drawBitmap(4, 44, box, 17, 16, 1);
      display.drawBitmap(19, 36, box_frames[currentBoxFrame], 26, 24, 1);
      display.drawBitmap(44, 44, box, 17, 16, 1);

    }
    if(selectedBox == 2){
      if(boxState[selectedBox] == 0 && currentBoxFrame >= 5 && currentEndFrame <= 13){
        display.drawBitmap(46, plusYPositions[currentEndFrame], lose_frames[currentEndFrame], 12, 12, 1);
      }
      if(boxState[selectedBox] == 1 && currentBoxFrame >= 5 && currentEndFrame <= 13){
        display.drawBitmap(46, plusYPositions[currentEndFrame], win_frames[currentEndFrame], 12, 12, 1);
      }
      if(boxState[selectedBox] == 2 && currentBoxFrame >= 5 && currentEndFrame <= 13){
        display.drawBitmap(46, plusYPositions[currentEndFrame], win_frames[currentEndFrame], 12, 12, 1);
      }
      
      display.drawBitmap(4, 44, box, 17, 16, 1);
      display.drawBitmap(24, 44, box, 17, 16, 1);
      display.drawBitmap(39, 36, box_frames[currentBoxFrame], 26, 24, 1);

    }
  }else{

    display.drawBitmap(4, 44, box, 17, 16, 1);
    display.drawBitmap(24, 44, box, 17, 16, 1);
    display.drawBitmap(44, 44, box, 17, 16, 1);
    if(selectedBox == 0){
      display.drawBitmap(9, selectYPositions[currentFrame], top_select, 7, 6, 1);
      // display.drawBitmap(7, 62, bottom_select, 11, 3, 1);
    }
    if(selectedBox == 1){
      display.drawBitmap(29, selectYPositions[currentFrame], top_select, 7, 6, 1);
      // display.drawBitmap(27, 62, bottom_select, 11, 3, 1);
    }
    if(selectedBox == 2){
      display.drawBitmap(49, selectYPositions[currentFrame], top_select, 7, 6, 1);
      // display.drawBitmap(47, 62, bottom_select, 11, 3, 1);
    }
  }

  display.display();
}
