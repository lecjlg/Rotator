int incomingByte = 0;   // for incoming serial data
int led = 13;
unsigned char sample_count = 0; // current sample number
int sum = 0;
float voltage = 0.0; 
float sensorDegrees;
float v_per_degree = 0.04; //in volts per degree


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
                  //voltage = voltage -1;
                  voltage = voltage * 14.45;
                  sensorDegrees = voltage / v_per_degree;
  Serial.println(sensorDegrees);
  
  

                //readvoltage();
                if (Serial.available() > 0) {
                int inByte = Serial.read();
                
                switch (inByte) {
                case '1':    
                Serial.println(sensorDegrees);
                Serial.println("Starting motor");
                digitalWrite(12, HIGH); //Establishes forward direction of Channel A
                digitalWrite(9, LOW);   //Disengage the Brake for Channel A
                analogWrite(3, 255);   //Spins the motor on Channel A at full speed
                break;
        
                case '0':  
                Serial.println(voltage);
                Serial.println(sensorDegrees);  
                Serial.println("Stopping motor");
                digitalWrite(9, HIGH);  //Engage the Brake for Channel A          
                break;

                case '3':
                Serial.println(sensorDegrees);    
                Serial.println("Motor backwards");
                digitalWrite(12, LOW);  //Establishes backward direction of Channel A 
                digitalWrite(9, LOW);   //Disengage the Brake for Channel A         
                analogWrite(3, 255);    //Spins the motor on Channel A at half speed
                break;
                                
                }
        }
}
