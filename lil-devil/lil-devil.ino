#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define i2c_Address 0x3c

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1   //   QT-PY / XIAO
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define icon_height 12
#define icon_width  12
static const unsigned char PROGMEM food_icon[] =
{ B00000000, B00000000,
  B00000000, B00000000,
  B00000000, B00000000,
  B00011111, B10000000,
  B00100000, B01000000,
  B01000000, B00100000,
  B01111111, B11100000,
  B00111111, B11000000,
  B00111111, B11000000,
  B01000000, B00100000,
  B01111111, B11100000,
  B00000000, B00000000,
};
static const unsigned char PROGMEM poo_icon[] =
{ B00000000, B00000000,
  B00000001, B00000000,
  B00000011, B00000000,
  B00001111, B00000000,
  B00001001, B00000000,
  B00011111, B10000000,
  B00100000, B01000000,
  B00111111, B11000000,
  B01000000, B00100000,
  B01000000, B00100000,
  B00111111, B11000000,
  B00000000, B00000000,
};
static const unsigned char PROGMEM play_icon[] =
{ B00000000, B00000000,
  B00110000, B00000000,
  B01001000, B00000000,
  B01001000, B00000000,
  B00110011, B10000000,
  B01001100, B01000000,
  B01001010, B10100000,
  B01001000, B00100000,
  B01001000, B10100000,
  B01001100, B01000000,
  B00110011, B10000000,
  B00000000, B00000000,
};
static const unsigned char PROGMEM doctor_icon[] =
{ B00000000, B00000000,
  B01100011, B00000000,
  B01000001, B00000000,
  B01000001, B00000000,
  B01000001, B00000000,
  B00100010, B00000000,
  B00011100, B00000000,
  B00001000, B11000000,
  B00001001, B00100000,
  B00000101, B00100000,
  B00000011, B11000000,
  B00000000, B00000000,
};
static const unsigned char PROGMEM stats_icon[] =
{ B00000000, B00000000,
  B00000000, B11000000,
  B00000000, B11000000,
  B00000110, B11000000,
  B00000110, B11000000,
  B00110110, B11000000,
  B00110110, B11000000,
  B00110110, B11000000,
  B00110110, B11000000,
  B01111111, B11100000,
  B01111111, B11100000,
  B00000000, B00000000,
};
static const unsigned char PROGMEM clock_icon[] =
{ B00000000, B00000000,
  B00001111, B00000000,//1
  B00110100, B11000000,//2
  B00100100, B01000000,//3
  B01000101, B00100000,//4
  B01000110, B00100000,//5
  B01000100, B00100000,//6
  B01000000, B00100000,//7
  B00100000, B01000000,//8
  B00110000, B11000000,//9
  B00001111, B00000000,//10
  B00000000, B00000000,
};
const unsigned char devil [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf0, 0x00, 0x00, 0x1f, 0xfc, 0x00, 0x00, 0x78, 0x0f, 0x00, 
  0x00, 0xe0, 0x03, 0x80, 0x01, 0xc0, 0x01, 0xc0, 0x03, 0x80, 0x00, 0xe0, 0x03, 0x1e, 0x00, 0x60, 
  0x06, 0x21, 0x00, 0x30, 0x06, 0x40, 0x80, 0x30, 0x0c, 0x40, 0x8e, 0x18, 0x0c, 0x40, 0x91, 0x18, 
  0x0c, 0x40, 0x91, 0x18, 0x0c, 0x21, 0x11, 0x18, 0x0c, 0x1e, 0x0e, 0x18, 0x0c, 0x00, 0x00, 0x18, 
  0x0c, 0x00, 0x00, 0x18, 0x06, 0x00, 0x00, 0x30, 0x06, 0x00, 0x00, 0x30, 0x03, 0x0f, 0xe0, 0x60, 
  0x03, 0x83, 0x80, 0xe0, 0x01, 0xc0, 0x01, 0xc0, 0x00, 0xe0, 0x03, 0x80, 0x00, 0x78, 0x0f, 0x00, 
  0x00, 0x1f, 0xfc, 0x00, 0x00, 0x07, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
const unsigned char left_icon [] PROGMEM = {
  // 4x8
  0x10, 0x20, 0x40, 0x80, 0x80, 0x40, 0x20, 0x10
};
const unsigned char right_icon [] PROGMEM = {
  // 4x8
  0x80, 0x40, 0x20, 0x10, 0x10, 0x20, 0x40, 0x80
};
const unsigned char statBarLg [] PROGMEM = {
  // 56 x 8
  0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xc0, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x06, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x80, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x02, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x0c, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc
};
const unsigned char statLgFull [] PROGMEM = {
  // 9x4
  0x7f, 0x00, 0xff, 0x80, 0xff, 0x80, 0x7f, 0x00
};
const unsigned char statLgEmpty [] PROGMEM = {
  // 9x4
  0x7f, 0x00, 0x80, 0x80, 0x80, 0x80, 0x7f, 0x00
};
const unsigned char pizza [] PROGMEM = {
  // 32x32
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0x80, 
  0x07, 0xfe, 0x00, 0x40, 0x04, 0x00, 0x00, 0x40, 0x08, 0x00, 0x00, 0x20, 0x0f, 0xff, 0xff, 0xc0, 
  0x04, 0x00, 0x00, 0x40, 0x02, 0x38, 0x00, 0x80, 0x02, 0x44, 0x00, 0x80, 0x01, 0x44, 0x01, 0x00, 
  0x01, 0x44, 0x39, 0x00, 0x00, 0xb8, 0x45, 0x00, 0x00, 0x80, 0x46, 0x00, 0x00, 0x40, 0x46, 0x00, 
  0x00, 0x40, 0x3c, 0x00, 0x00, 0x23, 0x84, 0x00, 0x00, 0x24, 0x44, 0x00, 0x00, 0x14, 0x48, 0x00, 
  0x00, 0x14, 0x48, 0x00, 0x00, 0x0b, 0x90, 0x00, 0x00, 0x08, 0x10, 0x00, 0x00, 0x04, 0x20, 0x00, 
  0x00, 0x04, 0x20, 0x00, 0x00, 0x02, 0x20, 0x00, 0x00, 0x02, 0x40, 0x00, 0x00, 0x01, 0x40, 0x00, 
  0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const int leftBtn = 4;
const int rightBtn = 5;
const int selectBtn = 6;
const int backBtn = 7;
const int systemDelay = 150;

unsigned long previoushungerLvlMillis = 0;
unsigned long previouspooLvlMillis = 0;
unsigned long hungerLvlInterval = 4000UL;
unsigned long pooLvlInterval = 2000UL;
unsigned long hapinessInterval = 3000UL;

const int optionsLength = 6;
String options[optionsLength] = {"feed", "poo", "play", "doctor", "stats", "time"};
int currentOption = 0;
bool atHome = true;

int leftButtonState = 0;
int rightButtonState = 0;
int selectButtonState = 0;
int backButtonState = 0;

int hungerLvl = 1;
int pooLvl = 1;
int happinessLvl = 5;
int healthLvl = 5;

void setup() {
  Serial.begin(9600);
  pinMode(leftBtn, INPUT_PULLUP);
  pinMode(rightBtn, INPUT_PULLUP);
  pinMode(selectBtn, INPUT_PULLUP);
  pinMode(backBtn, INPUT_PULLUP);

  delay(250); // wait for the OLED to power up
  display.begin(i2c_Address, true); // Address 0x3C default
  display.setContrast (0); // dim display
  display.setRotation(1);

  display.clearDisplay();
  renderHome();
}

void loop() {
  leftButtonState = digitalRead(leftBtn);
  rightButtonState = digitalRead(rightBtn);
  selectButtonState = digitalRead(selectBtn);
  backButtonState = digitalRead(backBtn);

  if(backButtonState == LOW){
    if(atHome == false){
      atHome = true;
      Serial.println("returned home");
      updateIcons();
    }
    Serial.println("pressed back");
    delay(systemDelay);
  }

  if(leftButtonState == LOW && atHome == true){
    currentOption--;
    if(currentOption < 0){
      currentOption = optionsLength-1;  
    }
    updateIcons();
    delay(systemDelay);
  }

  if(rightButtonState == LOW && atHome == true){
    currentOption++;
    if(currentOption > optionsLength-1){
      currentOption = 0;
    }
    updateIcons();
    delay(systemDelay);
  }

  if(selectButtonState == LOW && atHome == true){
    Serial.print("selected: ");
    Serial.println(options[currentOption]);
    String selectedOption = options[currentOption];
    display.clearDisplay();
    display.display();
    if(selectedOption == "feed"){
      atHome = false;
      feed();
    }
    if(selectedOption == "poo"){
      atHome = false;
      poo();
    }
    if(selectedOption == "play"){
      atHome = false;
      play();
    }
    if(selectedOption == "doctor"){
      atHome = false;
      doctor();
    }
    if(selectedOption == "stats"){
      atHome = false;
      stats();
    }
    if(selectedOption == "time"){
      atHome = false;
      setTime();
    }
    Serial.print("at home: ");
    Serial.println(atHome);
    delay(systemDelay);
  }
  
  unsigned long currentMillis = millis();

  if(currentMillis - previoushungerLvlMillis >= hungerLvlInterval){
    previoushungerLvlMillis = currentMillis; // Reset the timer

  if(hungerLvl < 5){
      hungerLvl++;
    }
    if(hungerLvl >= 5){
      // Serial.println("feed this bitch");
    }
    // Serial.print("hungerLvl: ");
    // Serial.println(hungerLvl);
  }

  if(currentMillis - previouspooLvlMillis >= pooLvlInterval){
    previouspooLvlMillis = currentMillis; // Reset the timer

    if(pooLvl < 5){
      pooLvl++;
    }
    if(pooLvl >= 5){
      // Serial.println("he shid");
      pooLvl = 1;
    }
    // Serial.print("pooLvl: ");
    // Serial.println(pooLvl);
  }

  
}

void feed() {
  display.clearDisplay();
  display.drawBitmap(16, 46,  pizza, 32, 32, 1);
  
  display.setTextSize(1);
  display.setCursor(14 , 8);
  display.setTextColor(SH110X_WHITE);
  display.print("hunger");

  display.drawBitmap(4, 22,  statBarLg, 56, 8, 1);
  display.drawBitmap(7, 24,  statLgFull, 9, 4, 1);
  display.drawBitmap(17, 24,  statLgFull, 9, 4, 1);
  display.drawBitmap(27, 24,  statLgFull, 9, 4, 1);
  display.drawBitmap(37, 24,  statLgEmpty, 9, 4, 1);
  display.drawBitmap(47, 24,  statLgEmpty, 9, 4, 1);

  display.drawBitmap(4, 60,  left_icon, 4, 8, 1);
  display.drawBitmap(54, 60,  right_icon, 4, 8, 1);
  
  display.setCursor(16 , 94);
  display.print("pizza");

  display.setCursor(24 , 108);
  display.print("+2");
  
  display.display();
  // select food:
  // - pear
  // - cookie
  // - pizza
  // - steak
}

void poo(){
  // lower poo variable
  // animation of water washing over screen
  // remove poo from home screen if present
  // return home
}

void play(){
  // 
}

void doctor(){
}

void stats(){
  // show stats
  // hunger, poo, happiness, health lvls
  // set time
  // reset pet
}

void setTime(){
  
}

void renderHome(){
  display.clearDisplay();
  drawLilDevil();
  updateIcons();  
}

// xpos and ypos are rect origin point
void updateIcons(){
  drawIcons();
  if(options[currentOption] == "feed"){
    drawIconSelector(3, 16);
  }
  if(options[currentOption] == "poo"){
    drawIconSelector(19, 16);
  }
  if(options[currentOption] == "play"){
    drawIconSelector(34, 16);
  }
  if(options[currentOption] == "doctor"){
    drawIconSelector(52, 16);
  }
  if(options[currentOption] == "stats"){
     drawIconSelector(3, 124); 
  }
  if(options[currentOption] == "time"){
     drawIconSelector(50, 124); 
  }
}

void drawLilDevil(){
//  display.drawBitmap(24, 48,  devil, 32, 32, 1);
//  display.display();
//  delay(1);
}

void drawIcons(){
  display.clearDisplay();
  display.drawBitmap(14 , 48,  devil, 32, 32, 1);
  display.drawBitmap(2, 4,  food_icon, 12, 12, 1);
  display.drawBitmap(18, 4,  poo_icon, 12, 12, 1);
  display.drawBitmap(33, 4,  play_icon, 12, 12, 1);
  display.drawBitmap(51, 4,  doctor_icon, 12, 12, 1);
  display.drawBitmap(2, 112,  stats_icon, 12, 12, 1);
  display.drawBitmap(49, 112,  clock_icon, 12, 12, 1);
  display.display();
  delay(1);
}

void drawIconSelector(int xPos, int yPos) {
  display.drawRect(xPos, yPos, 10, 2, SH110X_WHITE);
  display.display();
  delay(1);
}
