/*
  *
  * Udemy.com
  * Building an Arduino DC Voltmeter
  *
  */
 
 float vPow = 4.7;
 float r1 = 10000;
 float r2 = 10000;
 
 void setup() {
   Serial.begin(9600);
   
     

 }
 
 void loop() {
   float v = (analogRead(0) * vPow) / 1024.0;
   float v2 = v / (r2 / (r1 + r2));
   

   
   Serial.println(v2);
   delay(2000);
 }
