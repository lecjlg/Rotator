void inputdest() {
   if (Serial.available() > 0) {
                int inByte = Serial.read();
                
                switch (inByte) {
                case '0':    
                Serial.println("Destination 180 degrees");
                break;
        
                case '1':    
                Serial.println("Destination 90 degrees");
                break;

                }
   
   }

}
