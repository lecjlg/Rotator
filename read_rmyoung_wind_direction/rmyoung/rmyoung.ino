void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {

                //read voltage from the rmyoung
                  int rmValue = analogRead(A3);
                  float rmvoltage = rmValue * (5.03 / 1023.0);
                  rmvoltage = rmvoltage * 72;
                  
  Serial.println(rmvoltage);
  


}
