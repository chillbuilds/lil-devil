//activities 
// - store
// - park
// - 

const int leftBtn = 2;
const int rightBtn = 3;
const int centerBtn = 4;
const int systemDelay = 500;

unsigned long previousHungerMillis = 0;
unsigned long previousPooMillis = 0;
// const unsigned long interval = 6 * 3600UL * 1000UL; // 6 hours in milliseconds
unsigned long hungerInterval = 4000UL;
unsigned long pooInterval = 2000UL;
unsigned long hapinessInterval = 3000UL;

const int optionsLength = 5;
String options[optionsLength] = {"feed", "poo", "play", "doctor", "stats"};
int currentOption = 0;

int leftButtonState = 0;
int rightButtonState = 0;
int centerButtonState = 0;

int hunger = 1;
int poo = 1;
int happiness = 5;
int health = 5;

void setup() {
  Serial.begin(9600);
  pinMode(leftBtn, INPUT_PULLUP);
  pinMode(rightBtn, INPUT_PULLUP);
  pinMode(centerBtn, INPUT_PULLUP);
}

void loop() {
  leftButtonState = digitalRead(leftBtn);
  rightButtonState = digitalRead(rightBtn);
  centerButtonState = digitalRead(centerBtn);

  if(leftButtonState == LOW){
    currentOption--;
    if(currentOption < 0){
      currentOption = 4;  
    }
    delay(systemDelay);
    Serial.print("current option: ");
    Serial.println(options[currentOption]);
  }

  if(rightButtonState == LOW){
    currentOption++;
    if(currentOption > optionsLength-1){
      currentOption = 0;
    }
    delay(systemDelay);
    Serial.print("current option: ");
    Serial.println(options[currentOption]);
  }

  if(centerButtonState == LOW){
    delay(systemDelay);
    Serial.print("selected: ");
     Serial.println(options[currentOption]);
  }
  
  unsigned long currentMillis = millis();

  if(currentMillis - previousHungerMillis >= hungerInterval){
    previousHungerMillis = currentMillis; // Reset the timer

  if(hunger < 5){
      hunger++;
    }
    if(hunger >= 5){
      // Serial.println("feed this bitch");
    }
    // Serial.print("hunger: ");
    // Serial.println(hunger);
  }

  if(currentMillis - previousPooMillis >= pooInterval){
    previousPooMillis = currentMillis; // Reset the timer

    if(poo < 5){
      poo++;
    }
    if(poo >= 5){
      // Serial.println("he shid");
      poo = 1;
    }
    // Serial.print("poo: ");
    // Serial.println(poo);
  }

  
}
