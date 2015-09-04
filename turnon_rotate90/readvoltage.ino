  void readvoltage() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):

  float deg = sensorValue * 0.35190658;
  float voltage = sensorValue * (5 / 1023.0);
  // print out the value you read:
  delay(600);
  //Serial.print ("rotate to ");
  //rial.print(deg );
  //rial.print(" ° current voltage is ");
  //Serial.print(voltage );
  //Serial.println(" v");
  Serial.println(voltage);

}
