
const int light1_pin = 11, light2_pin = 12;
const int button1_pin = 2, button2_pin = 8; 

void light1(){
  static int toggle = 1 ; 
  digitalWrite(light1_pin, toggle);
  toggle = !toggle;
}

// PORT B ISR function
ISR (PCINT0_vect){
  static int toggle = 1 ;
  // the ISR will be entered twice, we just need one toggle, so add if statment just for rising edge case
  if(digitalRead(button2_pin)) {
    digitalWrite(light2_pin, toggle);
    toggle = !toggle;
    Serial.println("Entered");
  }
}

void setup() {
  //================PINMODE================
  
  pinMode(light1_pin, OUTPUT);
  pinMode(light2_pin, OUTPUT);
  pinMode(button1_pin, INPUT_PULLUP);
  pinMode(button2_pin, INPUT_PULLUP);

  //================Interrupt================

  PCICR = 0X1;  // Enable PORT B
  PCMSK0 = 0X1; // Enable pin D8 ;


  attachInterrupt(digitalPinToInterrupt(button1_pin), light1, FALLING); // Connect pin2 in the hardware way

  Serial.begin(9600);
}

void loop() {

}
