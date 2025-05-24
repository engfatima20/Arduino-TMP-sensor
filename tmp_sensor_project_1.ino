#include <LiquidCrystal_I2C.h>
//المكتبه دي بتستدعي Wire.hاوتوماتيك مش بنحتاج نكتبها وبتستخدمها عشان تتواصل مع الشاشه عن طريق بروتوكول I2C
// SDA,SCL دول بيتوصلو على بنات ثابته طالما بستخدم UNO (A4,A5) ال Wire.h بتعرفهم اوتوماتيك
#define tmppin A1
#define buzzerpin 13
#define ledpin 12
float threshold;

LiquidCrystal_I2C lcd(32, 16, 2); //object بنعرف فيه الشاشه (type, columns,rows)

void setup() {
  // بنجهز الشاشه 
  lcd.begin(16,2); //بنقول ان الشاشه فيها كام خانه وكام سطر
  lcd.init();   //بنجهز الشاشه عشان تشتغل وتفهم الاوامر اللي هنديهالها
  lcd.backlight();
  lcd.clear();
  
  pinMode(buzzerpin, OUTPUT);
  pinMode(ledpin, OUTPUT);
}

void loop() {
  threshold = analogRead(tmppin); //  الرقم بيكون قيمته 0 : 1023 
  float voltage =   threshold * (5.0 / 1024.0); 
  float temperatureC = (voltage -0.5) * 100; // 1V = 100درجه 
  
 // lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Temperature: ");
  lcd.setCursor(4, 1);
  lcd.print(temperatureC);
  lcd.print(" C");
  
  if(temperatureC >=35)
  {
	digitalWrite(ledpin, HIGH);
  }  else {
    digitalWrite(ledpin, LOW);
       }
  if (temperatureC >=40)
  {
    digitalWrite(buzzerpin, HIGH);
  }else {
    digitalWrite(buzzerpin, LOW);
  }
    
          delay(1000);
   

                 }