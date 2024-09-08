//activities 
// - store
// - park
// - 

unsigned long previousHungerMillis = 0;
unsigned long previousPooMillis = 0;
// const unsigned long interval = 6 * 3600UL * 1000UL; // 6 hours in milliseconds
unsigned long hungerInterval = 4000UL;
unsigned long pooInterval = 2000UL;
unsigned long hapinessInterval = 3000UL;

int buttonState = 0;

int hunger = 1;
int poo = 1;
int happiness = 5;
int health = 5;

//timing to decriment stats

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(2);

  if(buttonState == LOW){
    Serial.println("fed");
    hunger--;
    hunger--;
    if(hunger < 1){
      hunger = 1;
    }
    delay(1000);
  }
  
  unsigned long currentMillis = millis();

  if(currentMillis - previousHungerMillis >= hungerInterval){
    previousHungerMillis = currentMillis; // Reset the timer

  if(hunger < 5){
      hunger++;
    }
    if(hunger >= 5){
      Serial.println("feed this bitch");
    }
    Serial.print("hunger: ");
    Serial.println(hunger);
  }

  if(currentMillis - previousPooMillis >= pooInterval){
    previousPooMillis = currentMillis; // Reset the timer

    if(poo < 5){
      poo++;
    }
    if(poo >= 5){
      Serial.println("he shid");
      poo = 1;
    }
    Serial.print("poo: ");
    Serial.println(poo);
  }

  
}
