void randomnum() {



randNumber = random(360);  //define range for the randon number
      
  
  if (counter  < 30) {  
       counter = counter +1;  //add one count to the counter
       sums = sums + randNumber; //add the randon number to the last value
       delay(1000); //count for a second before moving on
 
  } else {
    sums = sums / 30; //take the average of the 30 readings   
    moveval = sums; //assign the new avereaged value to the moveval variable
    moveval = moveval * 0.01241666;
    counter = 0; //reset the counter 

  }
            

}
