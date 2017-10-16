#include <avr/sleep.h>

#define DRV5033_PIN 0
#define LED_PIN 1

volatile bool state = false;

ISR(PCINT0_vect)
{
	state = !digitalRead(DRV5033_PIN);
}

void setup()
{
	ADCSRA &= ~_BV(ADEN);
	GIMSK |= (1 << PCIE);
	PCMSK |= (1 << DRV5033_PIN);
	pinMode(LED_PIN, OUTPUT);
	pinMode(DRV5033_PIN, INPUT);
}

void loop()
{
	digitalWrite(LED_PIN, state? HIGH:LOW);
}
