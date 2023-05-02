 /*  Macro Keypad
  by iNimbleSloth.com
  April 2023
*/
#include <Keyboard.h>
#include <Mouse.h>

//Create names for I/O; SW for input switches & led for LEDs in the switches.
//The Number is the Arduino pin out NOT the PCB pinout!!
int sw1 = 2;
int sw2 = 3;
int sw3 = 4;
int sw4 = 5;
int sw5 = 6;
int sw6 = 7;
int sw7 = 8;
int led1 = 9;
int led2 = 10;
int led3 = 16;
int led4 = 14;
int led5 = 15;
int led6 = 18;
int led7 = 19;

// variables to keep strack of button states
bool copyState = false;       // set initial state of Copy to false, i.e copy key not held down
bool pasteState = false;      // set initial state of paste to false, i.e copy key not held down
bool sw1State = false;        // set initial sate of sw1 to false
bool sw2State = false;        // set initial sate of sw2 to false
bool sw3State = false;        // set initial sate of sw3 to false
bool sw4State = false;        // set initial sate of sw4 to false
//bool sw5State = false;        // set initial sate of sw5 to false
//bool sw6State = false;        // set initial sate of sw6 to false
bool sw7State = false;        // set initial sate of sw7 to false

void setup() {

  Serial.begin(9600);           //serial output used for debugging (not required for release version)

  //setup I/O; SW inputs with internal pull up resistor. LEDs as outputs.
  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);
  pinMode(sw3, INPUT_PULLUP);
  pinMode(sw4, INPUT_PULLUP);
  pinMode(sw5, INPUT_PULLUP);
  pinMode(sw6, INPUT_PULLUP);
  pinMode(sw7, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
}

//Main program loop starts here.
void loop() {
  //Serial.println("Start of Loop ");

  //SW1
  // IF SW1 is pressed AND the sw1State status is false (i.e. not already pressed), then type text
  if (digitalRead(sw1) == LOW && sw1State == false)
  {
    digitalWrite(led1, HIGH);
    sw1State = true;
    Keyboard.println("Case ");
    Keyboard.println("Create cLibrary acount and add username to contact in Salesforce.");
    Keyboard.println("Send through new technical contact lead.");
    delay(50);
  }
    
  // IF SW1 is released AND the sw3State status is true (i.e. button just released), then turn off the LED on the  button (SW1/LED1)
  if (digitalRead(sw1) == HIGH && sw1State == true)
  {
    digitalWrite(led1, LOW);
    sw1State = false;
    delay(50);
  }
    
  //SW2
  // IF SW2 is pressed AND the sw4State status is false (i.e. not already pressed), then type text
  if (digitalRead(sw2) == LOW && sw2State == false)
  {
    digitalWrite(led2, HIGH);
    sw2State = true;
    Keyboard.println("Created cLibrary acount and added username to contact in Salesforce.");
    Keyboard.println("Sent through new technical contact lead.");
    delay(50);
  }
    
  // IF SW4 is released AND the sw2State status is true (i.e. button just released), then turn off the LED on the snip button (SW2/LED2)
  if (digitalRead(sw2) == HIGH && sw2State == true)
  {
    digitalWrite(led2, LOW);
    sw2State = false;
    delay(50);
  }

  //SW3
  // IF SW3 is pressed and the sw5State status is false (i.e. not already pressed), then press type text
  if (digitalRead(sw3) == LOW && sw3State == false)
  {
    digitalWrite(led3, HIGH);
    sw3State = true;
    Keyboard.println("Case ");
    Keyboard.println("Create academy account.");
    Keyboard.println("Send lead through to quote for training.");
    delay(50);
  }
    
  // IF SW3 is released AND the snipeState status is true (i.e. button just released), then turn off the LED on the snip button (SW5/LED5)
  if (digitalRead(sw3) == HIGH && sw3State == true)
  {
    digitalWrite(led3, LOW);
    sw3State = false;
    delay(50);
  }

  //SW4 
  // IF SW4 is pressed and the sw4State status is false (i.e. not already pressed), then press type text
  if (digitalRead(sw4) == LOW && sw4State == false)
  {
    digitalWrite(led4, HIGH);
    sw4State = true;
    Keyboard.println("Created academy account.");
    Keyboard.println("Sent lead through to quote for training.");
    delay(50);
  }
    
  // IF SW4 is released AND the snipeState status is true (i.e. button just released), then turn off the LED on the snip button (SW4/LED4)
  if (digitalRead(sw4) == HIGH && sw4State == true)
  {
    digitalWrite(led4, LOW);
    sw4State = false;
    delay(50);
  }
    
  //SW5
  // IF SW5 is pressed and the copyState status is false (i.e. not already pressed), then execute Windows COPY command
  if (digitalRead(sw5) == LOW && copyState == false)
  {
    digitalWrite(led5, HIGH);
    copyState = true;
    Serial.println("Windows COPY command START");
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.write('c');
    Keyboard.release(KEY_LEFT_CTRL);
    delay(50);
  }
    
  // IF SW5 is released AND the copyState status is true (i.e. button just released), then turn off the LED on the COPY button (SW5/LED5)
  if (digitalRead(sw5) == HIGH && copyState == true)
  {
    digitalWrite(led5, LOW);
    copyState = false;
    Serial.println("Windows COPY command END");
    delay(50);
  }

  //SW6 
  // IF SW6 is pressed AND the pasteState status is false (i.e. not already pressed), then execute Windows PASTE command
  if (digitalRead(sw6) == LOW && pasteState == false)
  {
    digitalWrite(led6, HIGH);
    pasteState = true;
    Serial.println("Windows PASTE command START");
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.write('v');
    Keyboard.release(KEY_LEFT_CTRL);
    delay(50);
  }
    
  // IF SW6 is released AND the pasteState status is true (i.e. button just released), then turn off the LED on the PASTE button (SW3/LED3)
  if (digitalRead(sw6) == HIGH && pasteState == true)
  {
    digitalWrite(led6, LOW);
    pasteState = false;
    Serial.println("Windows PASTE command END");
    delay(50);
  }

  // IF SW7 is pressed and the sw7State status is false (i.e. not already pressed), then press execuste Windows DESKTOP command
  if (digitalRead(sw7) == LOW && sw7State == false)
  {
    digitalWrite(led7, HIGH);
    sw7State = true;
    Serial.println("Windows Desktop command START");
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.write('d');
    Keyboard.release(KEY_LEFT_GUI);
    delay(50);
  }

  // IF SW7 is NOT pressed and the rightClick status is true (i.e. the button has just been released), then release the right mouse button
  if(digitalRead(sw7) == HIGH && sw7State == true)
  {
    digitalWrite(led7, LOW);
    sw7State = false;
    delay(50);
  }

}
