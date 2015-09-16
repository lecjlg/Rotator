// number of analog samples to take per reading
#define NUM_SAMPLES 10


void readvoltage()  {

    // take a number of analog samples and add them up
    while (sample_count < NUM_SAMPLES) {
        sum += analogRead(A2);
        sample_count++;
        delay(100);
    }
    // calculate the voltage
    
    // use 5.0 for a 5.0V ADC reference voltage
    // 5.03V is the calibrated reference voltage
    voltage = ((float)sum / (float)NUM_SAMPLES * 5.03) / 1024.0;
    // send voltage for display on Serial Monitor
    // voltage multiplied by 11 when using voltage divider that
    // divides by 11. 11.132 is the calibrated voltage divide
    // value
    voltage = voltage * 11.175;
    sample_count = 0;
    sum = 0;
}


