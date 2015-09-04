int incomingByte = 0;   // for incoming serial data
int led = 13;


void setup() {
  
  //Setup Channel A
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin
  pinMode(led, OUTPUT);
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
  delay(1000);
  Serial.println("Starting motor control script");

  Serial.println("resetting rotator to 0 degrees");
  digitalWrite(led, HIGH); // turn on led while the rotator moves
  digitalWrite(12, HIGH); //Establishes forward direction of Channel A
  digitalWrite(9, LOW);   //Disengage the Brake for Channel A
  analogWrite(3, 255);   //Spins the motor on Channel A at full speed
  delay(14000);
  digitalWrite(led, LOW); // turn off led when the rotator stops
  Serial.println("Motor is now under your control");
  Serial.println("Please select 1 for cw and 3 for ccw and 0 to stop all movement");
 
}

void loop(){



             
                Serial.println("Turning motor to 90 degrees ");
                digitalWrite(12, LOW); //Establishes forward direction of Channel A
                digitalWrite(9, LOW);   //Disengage the Brake for Channel A
                analogWrite(3, 255);   //Spins the motor on Channel A at full speed
                digitalWrite(led, HIGH); // turn on led while the rotator moves
                delay(34000);
                
                Serial.println("Stopping motor");
                digitalWrite(9, HIGH);  //Engage the Brake for Channel A 
                digitalWrite(led, LOW); // turn off led when the rotator stops
                delay(30000000);
           
}
  










