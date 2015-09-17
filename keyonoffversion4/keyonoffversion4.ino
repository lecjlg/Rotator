int incomingByte = 0;   // for incoming serial data
int led = 13;
float sum = 0;                    // sum of samples taken
unsigned char sample_count = 0; // current sample number
float voltage = 0.0;            // calculated voltage
float moveval = 1;
float randNumber;
int counter = 0;   //value for the counter will go between 0 and 30
float sums = 0;     //running total of randon numbers
float tolerance = 0.05; //in volts

void setup() {
  
  //Setup Channel A
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin
  pinMode(led, OUTPUT);
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
  delay(2000);
  
 
}

void loop(){

                readvoltage();
                randomnum();
                Serial.print("Random number is now set at " );
                Serial.println(moveval);
                Serial.println(moveval - tolerance);
             
                        
                if (voltage < (moveval - tolerance))
                {
                    Serial.print("voltage from rotator is");
                    Serial.println(voltage);                                                          
                    Serial.println("turn clockwise");
                    digitalWrite(12, HIGH); //Establishes forward direction of Channel A
                    digitalWrite(9, LOW);   //Disengage the Brake for Channel A
                    analogWrite(3, 255);   //Spins the motor on Channel A at full speed
                    
                    
                }
                
                if (sq(voltage - moveval) < sq(tolerance))
                {
                 digitalWrite(9, HIGH);  //Engage the Brake for Channel A
                 Serial.println("Stopping motor"); 
                 delay(1000); 
                }
                                           
              
                if (voltage > (moveval + tolerance))
                {
                   Serial.print("voltage from rotator is");
                   Serial.println(voltage);                  
                   Serial.println("turn counter clockwise");
                   digitalWrite(12, LOW);  //Establishes backward direction of Channel A 
                   digitalWrite(9, LOW);   //Disengage the Brake for Channel A         
                   analogWrite(3, 255);    //Spins the motor on Channel A at half speed
                                            
                }

                
     
        }

