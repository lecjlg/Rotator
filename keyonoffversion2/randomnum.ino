int counter = 0;   //value for the counter will go between 0 and 30
long randNumber;  //define randon number
int sums = 0;     //running total of randon numbers
int moveval = 0;  //final value to read to move the rotator to


void randomnum() {

randNumber = random(259);  //define range for the random number

  if (counter  < 30) {  
       counter = counter +1;  //add one count to the counter
       sums = sums + randNumber; //add the randon number to the last value
       delay(1000); //count for a second before moving on
 
  } else {
    sums = sums / 30; //take the average of the 30 readings   
    moveval = sums; //assign the new avereaged value to the moveval variable
    Serial.print(" Averaged total is "); 
    Serial.println(moveval); //print out the the value to move the rotator to
    counter = 0; //reset the counter 
  }
}
