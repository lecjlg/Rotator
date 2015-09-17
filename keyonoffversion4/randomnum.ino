void randomnum() {



randNumber = random(360);  //define range for the randon number
      
  
  if (counter  < 60) {  
       counter = counter +1;  //add one count to the counter
       sums = sums + randNumber; //add the randon number to the last value
       delay(1000); //count for a second before moving on
 
  } else {
    sums = sums / 60; //take the average of the 30 readings   
    moveval = sums; //assign the new avereaged value to the moveval variable
    //moveval is calculated by highest voltage from the rotator divided by 450 degrees the maximum it can rotate.
    moveval = moveval * 0.0099555555555556;
    counter = 0; //reset the counter
    Serial.print("Random number is now set at " );
    Serial.println(moveval);

  }
            

}
