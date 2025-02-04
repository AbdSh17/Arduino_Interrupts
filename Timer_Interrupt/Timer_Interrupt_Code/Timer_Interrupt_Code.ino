/*
  Arduino Timer Interrupt Flash Demo
  timer-int-flash.ino
  Flash LED using Timer1

  DroneBot Workshop 2022
  https://dronebotworkshop.com
*/

// Define the LED pin
#define ledPin 12

// Define timer compare match register value


ISR(TIMER1_COMPA_vect)
// Interrupt Service Routine for compare mode
{
  
  // Write opposite value to LED
  digitalWrite(ledPin, digitalRead(ledPin) ^ 1);
}

void setup()
{
  // Set LED as output
  pinMode(ledPin, OUTPUT);

  // Disable all interrupts
  noInterrupts();

  // Initialize Timer1
  TCCR1A = 0;
  TCCR1B = 0;

  // Set timer1_compare_match to the correct compare match register value

  // Set prescaler to 256
  TCCR1B = (1 << WGM12) | (1 << CS12); // CTC Mode, Prescaler 256
  OCR1A = 187499; // Correct compare match value for 3s delay

  // Enable timer interrupt for compare mode
  TIMSK1 |= (1 << OCIE1A); // = 1

  // Enable all interrupts
  interrupts();
}

void loop()
{

}