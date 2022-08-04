#include "HTTPClient.h" //Include library for HTTPClient
#include "Inkplate.h"   //Include Inkplate library to the sketch
#include "WiFi.h"       //Include library for WiFi

Inkplate display(INKPLATE_1BIT); // Create an object on Inkplate library and also set library into 1 Bit mode (BW)

const char ssid[] = "myssid";  // Your WiFi SSID
const char *password = "xxx"; // Your WiFi password

void setup()
{
    Serial.begin(9600);

    display.begin();        // Init Inkplate library (you should call this function ONLY ONCE)
    display.clearDisplay(); // Clear frame buffer of display
    display.display();      // Put clear image on display

    display.print("Connecting to WiFi...");
    display.partialUpdate();

    sleep(2);

    display.print("Hello World");
    display.partialUpdate();

    // Connect to the WiFi network.
    WiFi.mode(WIFI_MODE_STA);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        display.print(".");
        display.partialUpdate();
    }
    display.println("\nWiFi OK! Downloading...");
    display.partialUpdate();

    //    if (!display.drawImage("https://varipass.org/neowise_mono.bmp", 0, 0, false, true))
    //    {
    //        display.println("Image open error");
    //        display.display();
    //    }
    display.display();

    display.print("Hello World");
    display.partialUpdate();
}

void loop()
{
    // Nothing...
}