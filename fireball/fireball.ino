#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define i2c_Address 0x3c

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define OLED_RESET -1     //   QT-PY / XIAO
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const unsigned char fireball_bar [] PROGMEM = {
	// 62x11px
	0x00, 0x00, 0x00, 0x55, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2a, 0xa0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x55, 0x50, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xea, 0xbf, 0xff, 0xff, 0xf8, 
	0x80, 0x00, 0x00, 0x55, 0x50, 0x00, 0x00, 0x08, 0x88, 0x42, 0x10, 0xaa, 0xa8, 0x42, 0x10, 0x88, 
	0x80, 0x00, 0x00, 0x55, 0x50, 0x00, 0x00, 0x08, 0xff, 0xff, 0xff, 0xea, 0xbf, 0xff, 0xff, 0xf8, 
	0x00, 0x00, 0x00, 0x55, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2a, 0xa0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x55, 0x50, 0x00, 0x00, 0x00
};
const unsigned char devil_head[] PROGMEM = {
  // 48x17px
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00,
  0x00, 0x20, 0x78, 0x00, 0x00, 0x00, 0x00, 0x60, 0x7c, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x7e, 0x00,
  0x00, 0x00, 0x01, 0xe0, 0x7f, 0x00, 0x00, 0x00, 0x07, 0xe0, 0x3f, 0x80, 0xff, 0xff, 0x0f, 0xe0,
  0x3f, 0xe7, 0xff, 0xff, 0xff, 0xc0, 0x1f, 0xff, 0x00, 0x01, 0xff, 0xc0, 0x1f, 0xf8, 0x00, 0x00,
  0x7f, 0x80, 0x1f, 0xc0, 0x00, 0x00, 0x1f, 0x80, 0x1e, 0x00, 0x00, 0x00, 0x07, 0x80, 0x38, 0x00,
  0x00, 0x00, 0x03, 0x80, 0x70, 0x00, 0x00, 0x00, 0x01, 0x80, 0xe0, 0x00, 0x00, 0x00, 0x00, 0xc0,
  0xc0, 0x00, 0x00, 0x00, 0x00, 0xc0
};
const unsigned char bird [] PROGMEM = {
	// 16x16px
	0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x2f, 0x00, 0x7c, 0x00, 0xfc, 0x01, 0xfc, 0x07, 0xf8, 
	0x0f, 0xf8, 0x1f, 0xf0, 0x3f, 0xe0, 0xf1, 0x40, 0xc1, 0x60, 0x01, 0xa0, 0x00, 0x00, 0x00, 0x00
};
const unsigned char fireball_0 [] PROGMEM = {
	// 16x16px
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x20, 0x0c, 0x30, 0x14, 0x68, 0x24, 0x48, 
	0x63, 0x88, 0x40, 0x08, 0x40, 0x08, 0x20, 0x08, 0x20, 0x10, 0x10, 0x10, 0x08, 0x20, 0x0f, 0xc0
};
const unsigned char fireball_1 [] PROGMEM = {
	// 16x16px
	0x00, 0x00, 0x00, 0x00, 0x0c, 0x80, 0x09, 0x80, 0x01, 0x60, 0x06, 0x10, 0x08, 0x10, 0x08, 0x10, 
	0x10, 0x10, 0x10, 0x08, 0x10, 0x08, 0x10, 0x10, 0x10, 0x10, 0x08, 0x20, 0x0c, 0x40, 0x03, 0x80
};
const unsigned char fireball_2 [] PROGMEM = {
	// 16x16px
	0x18, 0x40, 0x08, 0xc0, 0x00, 0xa0, 0x00, 0xa0, 0x01, 0x20, 0x01, 0x20, 0x02, 0x10, 0x02, 0x10, 
	0x02, 0x10, 0x04, 0x10, 0x04, 0x10, 0x04, 0x10, 0x02, 0x20, 0x02, 0x20, 0x01, 0x40, 0x00, 0x80
};
const unsigned char fireball_3 [] PROGMEM = {
	// 16x16px
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x20, 0x00, 0x50, 0x00, 0x50, 0x00, 0x50, 
	0x02, 0x90, 0x05, 0x10, 0x08, 0x10, 0x08, 0x10, 0x08, 0x20, 0x04, 0x20, 0x03, 0x40, 0x00, 0x80
};

unsigned long previousAnimationMillis = 0;
const int animationDelay = 16;
int currentFrame = 0;

unsigned long previousGameMillis = 0;
int gameDelay = 2000;

const int leftBtn = 0;
const int backBtn = 1;
const int selectBtn = 2;
const int rightBtn = 3;

const int birdFrames = 48;

int birdStartPos = 50;
int birdEndPos = 50;

int previousBirdX = 0;
int previousBirdY = 0;

unsigned long previousSystemDelayMillis = 0;
int systemDelayInterval = 300;
bool btnCooldown = false;

bool gameSetup = false;
bool rightSide = false;
bool hit = false;

int currentFireFrame = 0;

void setup() {

  randomSeed(analogRead(0));
  birdStartPos = getRandomNumber(30, 80);
  delay(20);
  birdEndPos = getRandomNumber(30, 80);

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

  delay(3000);
  
}

void loop() {

  renderFireball();

  unsigned long systemDelayMillis = millis();
  unsigned long animationMillis = millis();
  unsigned long gameMillis = millis();

  if (systemDelayMillis - previousSystemDelayMillis >= systemDelayInterval) {
    previousSystemDelayMillis = systemDelayMillis;  // reset the timer

    btnCooldown = false;
  }
  
  if (animationMillis - previousAnimationMillis >= animationDelay) {
    previousAnimationMillis = animationMillis;  // reset the timer

    currentFrame++;
    currentFireFrame++;
    if (currentFrame >= birdFrames) {      

      rightSide = !rightSide;

      currentFrame = 0;
      birdStartPos = birdEndPos;
      birdEndPos = getRandomNumber(30, 90);
    }

    if (currentFireFrame >= 16) {
      currentFireFrame = 0;
    }
    
  }

  if (gameMillis - previousGameMillis >= gameDelay) {
    previousGameMillis = gameMillis;  // Reset the timer

    if(hit){
      hit = false;
      currentFrame = 0;
      birdStartPos = getRandomNumber(30, 90);
      delay(10);
      birdEndPos = getRandomNumber(30, 90);
    }
  }

  if(digitalRead(selectBtn) == LOW && btnCooldown == false && gameSetup == true){
    btnCooldown = true;
    previousSystemDelayMillis = systemDelayMillis;

    if(currentFrame >= 10 && currentFrame <= 14){
      hit = true;
      previousGameMillis = gameMillis;
    }
    if(currentFrame >= 34 && currentFrame <= 38){
      hit = true;
      previousGameMillis = gameMillis;
    }
  }
}

void renderFireball() {

  if(gameSetup == false){
    birdStartPos = getRandomNumber(30, 90);
    delay(10);
    birdEndPos = getRandomNumber(30, 90);

    gameSetup = true;
  }

  int offset = birdStartPos - birdEndPos;
  float offsetAmount = (float)offset / birdFrames;

  display.clearDisplay();

  display.drawBitmap(2, 10, fireball_bar, 62, 11, 1);
  display.drawBitmap(10, 108, devil_head, 48, 17, 1);

  float yPos = birdStartPos + (offsetAmount * ((float)currentFrame + 1) * -1);

  const unsigned char* fireball_frames[] = { fireball_0, fireball_0, fireball_0, fireball_0, fireball_1, fireball_1, fireball_1, fireball_1, fireball_2, fireball_2, fireball_2, fireball_2, fireball_3, fireball_3, fireball_3, fireball_3 };

  if(hit){
    display.drawBitmap(previousBirdX, previousBirdY, fireball_frames[currentFireFrame], 16, 16, 1);
  }else{

    if (currentFrame < birdFrames/2) {
      display.drawRect(((currentFrame * 2.6) + 2), 10, 2, 11, SH110X_WHITE);
    }else{
      display.drawRect(((opposite(currentFrame) * 2.6) + 2), 10, 2, 11, SH110X_WHITE);
    }

    if (rightSide) {
      previousBirdX = 48 - currentFrame;
      previousBirdY = round(yPos);
      display.drawBitmap((48 - currentFrame), round(yPos), bird, 16, 16, 1);
    } else {
      previousBirdX = currentFrame;
      previousBirdY = round(yPos);
      display.drawBitmap(currentFrame, round(yPos), bird, 16, 16, 1);
    }
  }

  // display.drawBitmap(24, 100, fireball_frames[currentFireFrame], 16, 16, 1);

  display.display();
}

int opposite(int x) {
  if (x < 0 || x > 47) {
    return -1; // Return -1 for out of range
  }
  return 47 - x;
}

int getRandomNumber(int minVal, int maxVal) {
  return random(minVal, maxVal + 1);  // maxValue + 1 to include maxValue in the range
}