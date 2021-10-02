void setup(){

}

// the loop function runs over and over again forever
void loop() {
    digitalWrite(30, LOW);   // turn the LED on (HIGH is the voltage level)
    delay(100);                       // wait for a second
    digitalWrite(30, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
    digitalWrite(17, LOW);   // turn the LED on (HIGH is the voltage level)
    delay(100);                       // wait for a second
    digitalWrite(17, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
}

