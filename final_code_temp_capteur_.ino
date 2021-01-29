#include <SimpleDHT.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
// pour DHT22, 
//      VCC: 5V 
//      GND: GND
//      DATA: pin digital 2
int pinDHT22 = 2;

SimpleDHT22 dht22(pinDHT22);
LiquidCrystal_I2C lcd(0x27,20,4);
void setup() {
  Serial.begin(9600);// defini la vitesse du bus I2C
  lcd.init();//initialise le lcD
  lcd.backlight();//initialise le retro eclerage 
}   

void loop() {
  Serial.println("=================================");
  Serial.println("Sample DHT22...");
  float temperature = 0;
  float humidity = 0;
 
  
  
  int err = SimpleDHTErrSuccess;
  if ((err = dht22.read2(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT22 failed, err="); Serial.print(SimpleDHTErrCode(err));
    Serial.print(","); Serial.println(SimpleDHTErrDuration(err)); delay(2000);
    return;
  }
  
  Serial.print("Sample OK: ");
  Serial.print((float)temperature); Serial.print(" *C, ");
  Serial.print((float)humidity); Serial.println(" RH%");
   lcd.setCursor(0,0);
   lcd.print("Temperature:");
   lcd.setCursor(12,0);
  lcd.print((float)temperature);
  lcd.setCursor(0,1);
  lcd.print("humidite : ");
  lcd.print((float)humidity);
  
  // definit le delais pour recommencé le programme donc il definit aussi le delais entre les messure 
  delay(1000);
}
