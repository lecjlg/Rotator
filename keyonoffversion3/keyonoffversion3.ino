int incomingByte = 0;   // for incoming serial data
int led = 13;
int sum = 0;                    // sum of samples taken
unsigned char sample_count = 0; // current sample number
float voltage = 0.0;            // calculated voltage
float moveval = 1;
int randNumber;

void setup() {
  
  //Setup Channel A
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin
  pinMode(led, OUTPUT);
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
  delay(1000);


 
}

void loop(){

                readvoltage();
                randomnum();
                if ( voltage < randNumber * 0.01241666)
                {
                    Serial.println(voltage);
                    Serial.println(randNumber);
                    Serial.println(randNumber * 0.01241666);
                    Serial.println("turn clockwise");
                    //digitalWrite(12, HIGH); //Establishes forward direction of Channel A
                    //digitalWrite(9, LOW);   //Disengage the Brake for Channel A
                    //analogWrite(3, 255);   //Spins the motor on Channel A at full speed
                                           
                }
                else
                {
                   Serial.println(voltage);                    
                   Serial.println(randNumber * 0.01241666);
                   Serial.println("turn counter clockwise");
                   //digitalWrite(12, LOW);  //Establishes backward direction of Channel A 
                   //digitalWrite(9, LOW);   //Disengage the Brake for Channel A         
                   //analogWrite(3, 255);    //Spins the motor on Channel A at half speed
                  

                       
                }

                
     
        }

