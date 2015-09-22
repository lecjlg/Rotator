#define LMSIZE 60

int incomingByte = 0;   // for incoming serial data
int led = 13;
float samples = 0;                    // sum of samples taken
unsigned char sample_count = 0; // current sample number
float voltage = 0.0;            // calculated voltage
float rmvoltage = 1;
float rmDegrees;
int counter = 0;   //value for the counter will go between 0 and 30
float tolerance = 2; //degrees
int sensorValues[60];
float sensorDegrees;
float v_per_degree = 0.04; //in volts per degree
int i =0; //loop variable

void setup() {
  
  //Setup Channel A
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin
  pinMode(led, OUTPUT);
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
  delay(2000);
  
 
}

void loop(){

                  //read voltage from the rotator
                  int sensorValue = analogRead(A2);
                  
                  //sensorValue=sensorValue/60;
                  
                  float voltage= sensorValue * ( 5.0 / 1023.0);
                  voltage = voltage * 14.45;
                  sensorDegrees = voltage / v_per_degree;
                                
                  //read voltage from the rmyoung
                  int rmIn = analogRead(A3);
                  long rmValue = runningAverage(rmIn);
                  rmDegrees = rmVoltToDeg(rmValue);
                  
                  Serial.println("RM Young\t RM Young(avg)\tSensor");
                  Serial.print( rmVoltToDeg(rmIn));
                  Serial.print("\t\t\t");
                  Serial.print(rmDegrees);
                  Serial.print("\t");
                  Serial.println( sensorDegrees);                             
                        
                if (sensorDegrees < (rmDegrees - tolerance))
                {
                      
                    Serial.println("turn clockwise");
                    digitalWrite(12, HIGH); //Establishes forward direction of Channel A
                    digitalWrite(9, LOW);   //Disengage the Brake for Channel A
                    analogWrite(3, 255);   //Spins the motor on Channel A at full speed
                    delay(1000);
                    
                }
                
                if (sq(sensorDegrees - rmDegrees) < sq(tolerance))
                {
                 digitalWrite(9, HIGH);  //Engage the Brake for Channel A
                 Serial.println("Stopping motor"); 
                 delay(1000); 
                }
                                           
              
                if (sensorDegrees > (rmDegrees + tolerance))
                {
                    Serial.println("turn anticlockwise");
                    digitalWrite(12, LOW);  //Establishes backward direction of Channel A 
                    digitalWrite(9, LOW);   //Disengage the Brake for Channel A         
                    analogWrite(3, 255);    //Spins the motor on Channel A at half speed
                    delay(1000);
                                            
                }

                
     
        }
long runningAverage(int M)
{
  static int LM[LMSIZE];      // LastMeasurements
  static byte index = 0;
  static long sum = 0;
  static byte count = 0;

  // keep sum updated to improve speed.
  sum -= LM[index];
  LM[index] = M;
  sum += LM[index];
  index = (index+1) % LMSIZE;
  if (count < LMSIZE) count++;
  Serial.println(index);

  return sum / count;
}

float rmVoltToDeg(int rmVal)
{
  float rmvoltage = rmVal * (5.03 / 1023.0);
  return rmvoltage * 72.0;
}



