//c, Aron Ayub.
// Open Source Project.

#include <ESP8266WiFi.h>
#include "AdafruitIO_WiFi.h"

#include <DHT.h>

// Replace with your network credentials
//const char* ssid = "Super";
//const char* password = "SuperIntel@..";

// DHT sensor pin
const int dhtPin = D5;

// Initialize DHT sensor
DHT dht(dhtPin, DHT22);


//
//#define WIFI_SSID       "xxxxxxxxxxxxxx"
//#define WIFI_PASS       "xxxxxx"



#define WIFI_SSID       "xxxxxxxxx"
#define WIFI_PASS       "xxxxxxxxxxxxxxxxx"


#define IO_USERNAME    "xxxxxxxxxxxxxxxxxxx"
#define IO_KEY         "xxxxxxxxxxx"


// Connect to Wi-Fi and Adafruit IO handel
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

// Create a feed object that allows us to send data to
AdafruitIO_Feed * firedetector = io.feed("temperature");
AdafruitIO_Feed * smoke = io.feed("humidity");

const int sensor_pin = A0;
const int buzzer = 14;
const int led = 15;
int smokeA0 = 12;

// Input value range
int sensorValueMin = 0;   // Minimum sensor value
int sensorValueMax = 1023;  // Maximum sensor value

// Output range (percentage)
int outputMin = 0;    // Minimum output value (0%)
int outputMax = 100;  // Maximum output value (100%)

int smokie;
int percentage;
//delay func
unsigned long previousTime = 0;
unsigned long delayTime = 60000; //define time interval, milli secs


void setup()
{
  // Enable the serial port so we can see updates
  Serial.begin(115200);
  pinMode(sensor_pin, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(smokeA0, INPUT);

  // Connect to Adafruit IO
  io.connect();

  // wait for a connection
  while (io.status() < AIO_CONNECTED)
  {
    delay(1000);
    Serial.println("*************");
    Serial.println("******Connecting to Wi-Fid******");

  }
  Serial.println("Connected to WiFi");
  // Initialize DHT sensor
  dht.begin();

}

void loop()
{
  
  sensor();

}

void sensor() {
  // Always keep this at the top of your main loop
  // While not confirmed, this implies that the Adafruit IO library is not event-driven
  // This means you should refrain from using infinite loops
  io.run();




  // Read temperature and humidity from DHT sensor
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Check if any reads failed
  if (isnan(temperature) || isnan(humidity))
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }



  // Print the percentage value

  if (millis() - previousTime >= delayTime) {

    firedetector->save(temperature);
    smoke->save(humidity);

    // Print temperature and humidity
  Serial.print("Temperature Sent is: ");
  Serial.print(temperature);
  Serial.print(" °C\t");
  Serial.print("Humidity Sent is: ");
  Serial.print(humidity);
  Serial.println(" %");
//  delay(1000);
   
    previousTime = millis();
  }
}