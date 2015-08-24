void motorcontrol() {
// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *myMotor = AFMS.getMotor(1);

//AFMS.begin();  // create with the default frequency 1.6KHz


  uint8_t i;
  myMotor->run(RELEASE);
  myMotor->run(FORWARD);
  myMotor->setSpeed(0);  


}
