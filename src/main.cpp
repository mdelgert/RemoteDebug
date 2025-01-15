#include <WiFi.h>
#include <RemoteDebug.h>
#include "Secure.h"

// RemoteDebug instance
RemoteDebug Debug;

void setup()
{
    // Initialize Serial Monitor
    Serial.begin(115200);
    delay(100);

    // Connect to WiFi
    Serial.println("Connecting to WiFi...");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nConnected to WiFi!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

    // Initialize RemoteDebug
    Debug.begin("ESP32_Debug");     // Set a friendly name for debugging
    Debug.setResetCmdEnabled(true); // Allow the reset command
    Debug.showTime(true);           // Show time in debug messages
    Debug.showProfiler(true);       // Enable profiler to measure execution time
    Debug.println("RemoteDebug initialized!");
}

void loop()
{
    // Handle RemoteDebug
    Debug.handle();

    debugI("Remote Debug Version: %s", REMOTEDEBUG_VERSION);

    // Example debug messages
    Debug.println("* This is a message of println");
    Debug.printf("* This is a message of printf: %d\n", 123);
    debugV("* This is a message of debug level VERBOSE");
    debugD("* This is a message of debug level DEBUG");
    debugI("* This is a message of debug level INFO");
    debugW("* This is a message of debug level WARNING");
    debugE("* This is a message of debug level ERROR");

    delay(3000);
}
