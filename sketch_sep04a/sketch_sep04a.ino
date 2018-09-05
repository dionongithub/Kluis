#include <Keypad.h>
#define beep A2
#define red 11
#define green 10

String pass = "1999";
String input = "";
bool unlocked = false;


const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
  pinMode(green, OUTPUT);                      //green light
  pinMode(red, OUTPUT);                      //red light
  pinMode(12, OUTPUT);                      //lock
  pinMode(beep, OUTPUT);
}

void loop(){
  char key = keypad.getKey();
  String keyS = (String) key;

  if (key != NO_KEY){

    if (keyS == "*"){
      Serial.println("Cleared!");
      input = "";
      
    }else if(keyS == "#"){

      if (input == pass){                     //right pass
        unlocked = true;
        
      }else{                                  //false pass
        
        Serial.println("Wrong Pass!");
        digitalWrite(red, HIGH);
        digitalWrite(beep, HIGH);
        delay(1000);
        digitalWrite(beep, LOW);
        delay(1000);
        digitalWrite(red, LOW);
        input = "";
        
      }
    
    }else{
    
      input += keyS;
      Serial.println(input);

      if(pass == input){
        
        Serial.println("Unlocked!");
        digitalWrite(green, HIGH);
        digitalWrite(12, HIGH);
        digitalWrite(beep, HIGH);
        delay(50);
        digitalWrite(beep, LOW);
        delay(50);
        digitalWrite(beep, HIGH);
        delay(50);
        digitalWrite(beep, LOW);
        delay(50);
        digitalWrite(beep, HIGH);
        delay(50);
        digitalWrite(beep, LOW);
        delay(2750);
        unlocked = false;
        Serial.println("Locked!");
        digitalWrite(green, LOW);
        digitalWrite(12, LOW);
        input = "";
      }
      
    }

    if(unlocked){

        Serial.println("Unlocked!");
        digitalWrite(green, HIGH);
        digitalWrite(12, HIGH);
        digitalWrite(beep, HIGH);
        delay(50);
        digitalWrite(beep, LOW);
        delay(50);
        digitalWrite(beep, HIGH);
        delay(50);
        digitalWrite(beep, LOW);
        delay(50);
        digitalWrite(beep, HIGH);
        delay(50);
        digitalWrite(beep, LOW);
        delay(2750);
        unlocked = false;
        Serial.println("Locked!");
        digitalWrite(green, LOW);
        digitalWrite(12, LOW);
        input = "";
    }
    
  }
}
