int incomingByte = 0;   // for incoming serial data

void setup() {
  
  //Setup Channel A
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin
  
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
}

void loop(){


        // send data only when you receive data:
        if (Serial.available() > 1) {
                // read the incoming byte:
                incomingByte = Serial.read();

                // say what you got:
                Serial.print("Starting motor");
                //Motor A forward @ full speed
                digitalWrite(12, HIGH); //Establishes forward direction of Channel A
                digitalWrite(9, LOW);   //Disengage the Brake for Channel A
                analogWrite(3, 255);   //Spins the motor on Channel A at full speed
                Serial.println(incomingByte, DEC);
        } else 

                // send data only when you receive data:
        if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.read();
                // say what you got:
                Serial.print("Stopping Motor");
                //Motor A forward @ full speed
                digitalWrite(9, HIGH); //Establishes forward direction of Channel A
            
                Serial.println(incomingByte, DEC);
        }

  



}









