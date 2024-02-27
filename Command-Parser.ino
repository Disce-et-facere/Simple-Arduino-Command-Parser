// definitions for readability
#define GREEN 1
#define RED 2
#define YELLOW 3
#define ON 1
#define OFF 0
#define GREEN_LED_PIN 9
#define RED_LED_PIN 10
#define YELLOW_LED_PIN 11

bool greenLedState = false;
bool redLedState = false;
bool yellowLedState = false;
bool discoState = false;

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
        case 1:
        {
            if(greenLedState){
                Serial.println("Green led is already ON!\n");
                return;
            }else{
                digitalWrite(GREEN_LED_PIN, ON);
                Serial.println("GREEN LED IS ON!\n");
                greenLedState = ON;
            }
            return;
        }
        case 2:
        {
            if(redLedState){
                Serial.println("Red led is already ON!\n");
                return;
            }else{
                digitalWrite(RED_LED_PIN, ON);
                Serial.println("RED LED IS ON!\n");
                redLedState = ON;
            }
            return;
        }
        case 3:
        {
            if(yellowLedState){
                Serial.println("Yellow led is already ON!\n");
                return;
            }else{
                digitalWrite(YELLOW_LED_PIN, ON);
                Serial.println("YELLOW LED IS ON!\n");
                yellowLedState = ON;
            }
            return;
        }
    }

}

// Function to turn off led 1 of 3 leds depending of choosen color
void turnOffLed(int color){

        switch(color){
        //Green
        case 1:
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
        case 2:
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
        case 3:
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

    digitalWrite(GREEN_LED_PIN, ON);
    delay(100);
    digitalWrite(RED_LED_PIN, ON);
    digitalWrite(GREEN_LED_PIN, OFF);
    delay(100);
    digitalWrite(YELLOW_LED_PIN, ON);
    digitalWrite(RED_LED_PIN, OFF);
    delay(100);
    digitalWrite(YELLOW_LED_PIN, OFF);

    return;
}

void loop() {

    if (Serial.available() > 0) { //Command Parser with options -->

        String input = Serial.readStringUntil('\n'); 

        if(input == "HELP" || input == "help"){

            commandHelp();

        }else if(input == "GREEN LED ON" || input == "green led on"){

            turnOnLed(GREEN);

        }else if(input == "GREEN LED OFF" || input == "green led off"){

            turnOffLed(GREEN);

        }else if(input == "RED LED ON" || input == "red led on"){

            turnOnLed(RED);

        }else if(input == "RED LED OFF" || input == "red led off"){

            turnOffLed(RED);

        }else if(input == "YELLOW LED ON" || input == "yellow led on"){

            turnOnLed(YELLOW);

        }else if(input == "YELLOW LED OFF" || input == "yellow led off"){
            
            turnOffLed(YELLOW);

        }else if(input == "DISCO MODE ON" || input == "disco mode on"){
            greenLedState = OFF;
            redLedState = OFF;
            yellowLedState = OFF;
            discoState = ON;
            Serial.println("DISCO MODE ON!\n");

        }else if(input == "DISCO MODE OFF" || input == "disco mode off"){

            discoState = OFF;
            Serial.println("DISCO MODE OFF!\n");

        }else {

            Serial.println("Invalid input!\n");

        }// <--- Command Parser with options


    // using the already existing loop for the disco mode
    }

    if(discoState){

        discoMode();
        
    }
}