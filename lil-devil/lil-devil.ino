//activities 
// - store
// - park
// - 

const int leftBtn = 4;
const int rightBtn = 5;
const int selectBtn = 6;
const int backBtn = 7;
const int systemDelay = 200;

unsigned long previoushungerLvlMillis = 0;
unsigned long previouspooLvlMillis = 0;
unsigned long hungerLvlInterval = 4000UL;
unsigned long pooLvlInterval = 2000UL;
unsigned long hapinessInterval = 3000UL;
unsigned long btnHoldDuration = 2000UL;

const int optionsLength = 5;
String options[optionsLength] = {"feed", "poo", "play", "doctor", "stats"};
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
    }
    Serial.println("pressed back");
    delay(systemDelay);
  }

  if(leftButtonState == LOW && atHome == true){
    currentOption--;
    if(currentOption < 0){
      currentOption = 4;  
    }
    Serial.print("current option: ");
    Serial.println(options[currentOption]);
    delay(systemDelay);
  }

  if(rightButtonState == LOW && atHome == true){
    currentOption++;
    if(currentOption > optionsLength-1){
      currentOption = 0;
    }
    Serial.print("current option: ");
    Serial.println(options[currentOption]);
    delay(systemDelay);
  }

  if(selectButtonState == LOW && atHome == true){
    Serial.print("selected: ");
    Serial.println(options[currentOption]);
    String selectedOption = options[currentOption];
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
