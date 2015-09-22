int incomingByte = 0;   // for incoming serial data
int led = 13;
unsigned char sample_count = 0; // current sample number
int sum = 0;
float voltage = 0.0; 


void setup() {
  
  //Setup Channel A
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin
  pinMode(led, OUTPUT);
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
  delay(1000);
  Serial.println("Starting motor control script");
  Serial.println("Motor is now under your control");
  Serial.println("Please select 1 for cw and 3 for ccw and 0 to stop all movement");
 
}

void loop(){

                  //read voltage from the rotator
                  int sensorValue = analogRead(A2);
                  float voltage= sensorValue * (5.0 / 1023.0);
                  voltage = voltage * 11.06172839506173;
                  voltage = voltage / 0.0072222222222222;
                  Serial.println(voltage);
  

                //readvoltage();
                if (Serial.available() > 0) {
                int inByte = Serial.read();
                
                switch (inByte) {
                case '1':    
                Serial.println("motor clockwise");
                Serial.println(voltage);
                digitalWrite(12, HIGH); //Establishes forward direction of Channel A
                digitalWrite(9, LOW);   //Disengage the Brake for Channel A
                analogWrite(3, 255);   //Spins the motor on Channel A at full speed
                break;
        
                case '0':    
                Serial.println("Stopping motor");
                Serial.println(voltage);
                digitalWrite(9, HIGH);  //Engage the Brake for Channel A          
                break;

                case '3':    
                Serial.println("Motor counter clock");
                Serial.println(voltage);
                digitalWrite(12, LOW);  //Establishes backward direction of Channel A 
                digitalWrite(9, LOW);   //Disengage the Brake for Channel A         
                analogWrite(3, 255);    //Spins the motor on Channel A at half speed
                break;
                                
                }
        }
}
