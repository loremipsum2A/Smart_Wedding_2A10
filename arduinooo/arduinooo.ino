int led_pin=13;
int analog_pin=A0;
char data;
void setup() {

Serial.begin(9600);

pinMode(led_pin, OUTPUT);

}

void loop() {

int temp;

temp=analogRead(analog_pin);

if(temp>512)

{

Serial.write('1');

}

else

{

Serial.write('5');

digitalWrite(led_pin,LOW);

delay(1000);

}
data=Serial.read();

if(data=='0')
{
digitalWrite(led_pin,HIGH);
delay(1000);
digitalWrite(led_pin,LOW);
delay(1000);
}

}
