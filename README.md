# Mini-Weather-Station-Adafruit
 Adafruit Mini weather station 

 Requirements 
 1. ESP8266 Dev board
 2. DHT sensor.
 3. Power Source.
 4. [Adafruit Account.][def2]

**Circuit Diagram is as Below**

 - [Navigate and download the code.][def]
 - Configure the Adafruit Account
 - Take the right parameters from Adafruit 
```
#define WIFI_SSID       "xxxxxxxxx"
#define WIFI_PASS       "xxxxxxxxxxxxxxxxx"

#define IO_USERNAME    "xxxxxxxxxxxxxxxxxxx"
#define IO_KEY         "xxxxxxxxxxx"

```

**Change the feeds name as below**
- Replace Fed1 and Fed2.
```
AdafruitIO_Feed * firedetector = io.feed("fed1");
AdafruitIO_Feed * smoke = io.feed("fed1");
```
- **To change the Frequency of Sending data**
- Change the block below, time is in milli-secs

```
unsigned long delayTime = 60000; //define time interval, milli secs
```
 - Edit Arduino Code and get it running.
    - Remember to copy feeds name.



[def]: https://github.com/AronAyub/Mini-Weather-Station-Adafruit/blob/main/mini-weather.ino
[def2]: https://io.adafruit.com/