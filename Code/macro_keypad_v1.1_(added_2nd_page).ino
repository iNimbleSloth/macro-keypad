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
bool sw1State = false;        // set initial sate of sw1 to false
bool sw2State = false;        // set initial state of sw2 to false
bool sw3State = false;        // set initial state of sw3 to false
bool sw4State = false;        // set initial state of sw4 to false
bool sw5State = false;      // set initial state of sw5 to false
bool sw6State = false;      // set initial state of sw6 to false
bool sw7State = false;        // set initial state of sw7 to false
bool page2Status = false;     // set initial state of Page 2 to false (this is a specical case used in toggle function of the button)
int currentSW7State;          // to keep track of the current state of button 7 (special case used in toggle function of the button)
int lastSW7State;             // to keep track of the last state of button 7 (special case used in toggle function of the button)


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
  
  // read in current states of the switches (specical case for SW7 as being used to toggle the state of CTRL)
  currentSW7State = digitalRead(sw7);
}

//Main program loop starts here.
void loop() {
  //Serial.println("Start of Loop ");
  
  lastSW7State = currentSW7State;       //save the last state of button 7
  currentSW7State = digitalRead(sw7);   //read in the current state of button 7

  //SW1
  // IF SW1 is pressed AND the sw1State status is false (i.e. not already pressed), then type text
  if (digitalRead(sw1) == LOW && sw1State == false)
  {
    if (page2Status != true)
    {
      //Serial.println("Page 1 Button 1");
      digitalWrite(led1, HIGH);
      sw1State = true;
      Keyboard.println("cLibrary ");
    }
    else
    {
      //Serial.println("Page 2 Button 1");
      digitalWrite(led1, HIGH);
      sw1State = true;
      //KEY PRESSES TO BE SIMULATED FOR PAGE 2 BUTTON 1 GOES HERE
      Keyboard.println("Academy ");
      
    }
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
    if (page2Status != true)
    {
      //Serial.println("Page 1 Button 2");
      digitalWrite(led2, HIGH);
      sw2State = true;
      Keyboard.println("Case ");
      Keyboard.println("Create cLibrary account and add username to contact in Salesforce.");
      Keyboard.println("Send through new technical contact lead.");
    }
     else
    {
      //Serial.println("Page 2 Button 2");
      digitalWrite(led2, HIGH);
      sw2State = true;
      Keyboard.println("Case ");
      Keyboard.println("Create academy account.");
      Keyboard.println("Send lead through to quote for training.");
    }
    delay(50);
  }
    
  // IF SW2 is released AND the sw2State status is true (i.e. button just released), then turn off the LED on the snip button (SW2/LED2)
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
    if (page2Status != true)
    {
      //Serial.println("Page 1 Button 3");
      digitalWrite(led3, HIGH);
      sw3State = true;
      Keyboard.println("Created cLibrary account and added username to contact in Salesforce.");
      Keyboard.println("Sent through new technical contact lead.");

      
    }
    else
    {
      //Serial.println("Page 2 Button 3");
      digitalWrite(led3, HIGH);
      sw3State = true;
      //KEY PRESSES TO BE SIMULATED FOR PAGE 2 BUTTON 3 GOES HERE
      Keyboard.println("Created academy account.");
      Keyboard.println("Sent lead through to quote for training.");
      
    }
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
    if (page2Status != true)
    {
      //Serial.println("Page 1 Button 4");
      digitalWrite(led4, HIGH);
      sw4State = true;
      Keyboard.println("New technical contact added to salesforce.");
    }
    else
    {
      //Serial.println("Page 2 Button 4");
      digitalWrite(led4, HIGH);
      sw4State = true;
      //KEY PRESSES TO BE SIMULATED FOR PAGE 2 BUTTON 5 GOES HERE
      Keyboard.println("One for Chloe. ");
      Keyboard.println("xxx signed up for an academy account. Please quote for training. ");
    }
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
  // IF SW5 is pressed and the sw5State status is false (i.e. not already pressed), then execute Windows COPY command
  if (digitalRead(sw5) == LOW && sw5State == false)
  {
    if (page2Status != true || true)  // FOR MY MACROPAD BUTTON 5 should do the same for both pages
    {
      //Serial.println("Page 1 Button 5");
      digitalWrite(led5, HIGH);
      sw5State = true;
      //Serial.println("Windows COPY command START");
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.write('c');
      Keyboard.release(KEY_LEFT_CTRL);
    }
    else
    {
      //Serial.println("Page 2 Button 5");
      digitalWrite(led5, HIGH);
      sw5State = true;
      //KEY PRESSES TO BE SIMULATED FOR PAGE 2 BUTTON 5 GOES HERE
    }
    delay(50);
  }
    
  // IF SW5 is released AND the sw5State status is true (i.e. button just released), then turn off the LED on the COPY button (SW5/LED5)
  if (digitalRead(sw5) == HIGH && sw5State == true)
  {
    digitalWrite(led5, LOW);
    sw5State = false;
    //Serial.println("Windows COPY command END");
    delay(50);
  }

  //SW6 
  // IF SW6 is pressed AND the sw6State status is false (i.e. not already pressed), then execute Windows PASTE command
  if (digitalRead(sw6) == LOW && sw6State == false)
  {
    if (page2Status != true || true)    // FOR MY MACROPAD BUTTON 6 should do the same for both pages
    {
      //Serial.println("Page 1 Button 6");
      digitalWrite(led6, HIGH);
      sw6State = true;
      //Serial.println("Windows PASTE command START");
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.write('v');
      Keyboard.release(KEY_LEFT_CTRL);
    }
    else
    {
      //Serial.println("Page 2 Button 6");
      digitalWrite(led6, HIGH);
      sw6State = true;
      //KEY PRESSES TO BE SIMULATED FOR PAGE 2 BUTTON 6 GOES HERE
    }
    delay(50);
  }
    
  // IF SW6 is released AND the sw6State status is true (i.e. button just released), then turn off the LED on SW6
  if (digitalRead(sw6) == HIGH && sw6State == true)
  {
    digitalWrite(led6, LOW);
    sw6State = false;
    delay(50);
  }

  

  //SW7 - Toggle between "PAGE 1 & PAGE 2"
  // SW7 is a special case as it is operating as a toggle mode. i.e. press and release to enable, followed by press and release to disable.
  // If the current state is ON and the previous state was OFF, then the button has been presse
  if (lastSW7State == HIGH && currentSW7State == LOW)
  {
    page2Status = !page2Status;         //toggle the state of the LED
    digitalWrite(led7, page2Status);    //toggle the state of the LED
    // IF the LED is ON then, PAGE 2 has been selected by the user
    if (page2Status == true)
    {
      // for debugging, notify to the serial console that Page 2 has been selected
      //Serial.println("Page 2 Selected");
    }
    // else the LED must be OFF so PAGE 1 has been selected
    else
    {
      // for debugging, notify to the serial console that Page 1 has been selected
      //Serial.println("Page 1 Selected");
    }
    delay(50);
  }

}
