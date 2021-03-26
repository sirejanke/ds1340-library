// Set date and time using a DS1340 RTC connected via I2C

// Hi my Name is Martin Janke and i hope enjoy the implementation of the ds1340 for the RTClib from Adafruit Industries
//   
// Connect SCL (Hardware scl of your Board)
// Connect SDA  (Hardware sda of your Board)
// Date and time functions using a DS1340 RTC connected via I2C and Wire lib
#include "RTClib.h"

RTC_DS1340 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup () {
  Serial.begin(115200);



  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  }
//enabletricklecharger4kdiode(); 4k resistor with diode
 // enabletricklecharger4knodiode(); 4k resistor with no diode
//rtc.enabletricklecharger2knodiode(); // 2k resistor with no diode
//rtc.enabletricklecharger2kdiode(); // // 2k resistor with  diode
 //rtc.enabletricklecharger250nodiode(); // 250ohm resistor with no diode do not use with vcc over 3,6v
 rtc.enabletricklecharger250diode(); // // 250ohm resistor with  diode do not use with vcc over 3,6v
  //rtc.disabletricklecharger();  // disable tricklecharger
  // rtc.enableFTout(); enable ft out 
  rtc.disableFTout(); //  disable ft out 


  // When time needs to be re-set on a previously configured device, the
  // following line sets the RTC to the date & time this sketch was compiled
   //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  // This line sets the RTC with an explicit date & time, for example to set
  // January 21, 2014 at 3am you would call:
   rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
}

void loop () {
    DateTime now = rtc.now();

    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();


}
