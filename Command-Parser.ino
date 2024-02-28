// definitions for readability
#define GREEN 1
#define RED 2
#define YELLOW 3
#define ON 1
#define OFF 0
#define GREEN_LED_PIN 9
#define RED_LED_PIN 10
#define YELLOW_LED_PIN 11

bool greenLedState = OFF;
bool redLedState = OFF;
bool yellowLedState = OFF;
bool discoState = OFF;

void setup() {
    // setting up pin mode to output for the leds 
    pinMode(GREEN_LED_PIN, OUTPUT); 
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);

    // Serial communication setting
    Serial.begin(9600);

    Serial.println("Type HELP for avaliable Commands...");
}

void commandHelp(){
    Serial.println("Avaliable Commands:");
    Serial.println("GREEN LED ON - Switches the Green led mode to ON");
    Serial.println("GREEN LED OFF - Switches the Green led mode to OFF");
    Serial.println("RED LED ON - Switches the Red led mode to ON");
    Serial.println("RED LED OFF - Switches the Red led mode to OFF");
    Serial.println("YELLOW LED ON - Switches the Yellow led mode to ON");
    Serial.println("YELLOW LED OFF - Switches the Yellow led mode to OFF");
    Serial.println("DISCO MODE ON - Switches Disco mode to ON");
    Serial.println("DISCO MODE OFF - Switches Disco mode to OFF\n");
    return;
}
// Function to turn on 1 of 3 leds depending of choosen color
void turnOnLed(int color){

  discoState = OFF;

    switch(color){
        //Green
        case GREEN:
        {   

                digitalWrite(GREEN_LED_PIN, ON);
                Serial.println("GREEN LED IS ON!\n");
                greenLedState = ON;
        
            return;
        }
        case RED:
        {
  
                digitalWrite(RED_LED_PIN, ON);
                Serial.println("RED LED IS ON!\n");
                redLedState = ON;
            
            return;
        }
        case YELLOW:
        {
    
                digitalWrite(YELLOW_LED_PIN, ON);
                Serial.println("YELLOW LED IS ON!\n");
                yellowLedState = ON;
            
            return;
        }
    }
}

// Function to turn off led 1 of 3 leds depending of choosen color
void turnOffLed(int color){

        switch(color){
        //Green
        case GREEN:
        {
            if(!greenLedState){
                Serial.println("Green led is already OFF!\n");
                return;
            }else{
                digitalWrite(GREEN_LED_PIN, OFF);
                Serial.println("GREEN LED IS OFF!\n");
                greenLedState = OFF;
            }
            return;
        }
        case RED:
        {
            if(!redLedState){
                Serial.println("Red led is already OFF!\n");
                return;
            }else{
                digitalWrite(RED_LED_PIN, OFF);
                Serial.println("RED LED IS OFF!\n");
                redLedState = OFF;
            }
            return;
        }
        case YELLOW:
        {
            if(!yellowLedState){
                Serial.println("Yellow led is already OFF!\n");
                return;
            }else{
                digitalWrite(YELLOW_LED_PIN, OFF);
                Serial.println("YELLOW LED IS OFF!\n");
                yellowLedState = OFF;
            }
            return;
        }
    }
}

// Function to turn DiscoMode to either on or off
void discoMode(){

    if(greenLedState){
      digitalWrite(GREEN_LED_PIN, ON);
    }
    delay(100);
    if(redLedState){
    digitalWrite(RED_LED_PIN, ON);
    }
    if(greenLedState){
    digitalWrite(GREEN_LED_PIN, OFF);
    }
    delay(100);
    if(yellowLedState){
    digitalWrite(YELLOW_LED_PIN, ON);
    }
    if(redLedState){
    digitalWrite(RED_LED_PIN, OFF);
    }
    delay(100);
    if(yellowLedState){
    digitalWrite(YELLOW_LED_PIN, OFF);
    }
    return;
}

void loop() {

    if (Serial.available() > 0) { //Command Parser -->

        String input = Serial.readStringUntil('\n'); 

        if(input == "HELP" || input == "help"){

            commandHelp();

        }else if(input == "GREEN LED ON" || input == "green led on"){
            
            if(!discoState){
              turnOnLed(GREEN);
            }else if(greenLedState){
              Serial.println("Green led is already ON!\n");
            }else{
              greenLedState = ON;
            }
            

        }else if(input == "GREEN LED OFF" || input == "green led off"){

            turnOffLed(GREEN);

        }else if(input == "RED LED ON" || input == "red led on"){

            if(!discoState){
              turnOnLed(RED);
            }else if(redLedState){
              Serial.println("Red led is already ON!\n");
            }else{
              redLedState = ON;
            }

        }else if(input == "RED LED OFF" || input == "red led off"){

            turnOffLed(RED);

        }else if(input == "YELLOW LED ON" || input == "yellow led on"){

            if(!discoState){
              turnOnLed(YELLOW);
            }else if(yellowLedState){
              Serial.println("Yellow led is already ON!\n"); 
            }else{
              yellowLedState = ON;
            }

        }else if(input == "YELLOW LED OFF" || input == "yellow led off"){
            
            turnOffLed(YELLOW);

        }else if(input == "DISCO MODE ON" || input == "disco mode on"){
          
            greenLedState = ON;
            redLedState = ON;
            yellowLedState = ON;
            discoState = ON;
            Serial.println("DISCO MODE ON!\n");

        }else if(input == "DISCO MODE OFF" || input == "disco mode off"){

            discoState = OFF;
            Serial.println("DISCO MODE OFF!\n");

        }else {

            Serial.println("Invalid input!\n");

        }
    }// <--- Command Parser
    
    // using the already existing loop for the disco mode
    if(discoState){

        discoMode();
        
    }
}
