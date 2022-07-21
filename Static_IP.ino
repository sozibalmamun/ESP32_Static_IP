#include <WiFi.h>
// Set your Static IP address
IPAddress local_IP(192, 168, 1, 111);
// Set your Gateway IP address
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 0, 0);
IPAddress primaryDNS(8, 8, 8, 8);
IPAddress secondaryDNS(8, 8, 4, 4);

#define ssid "your_ssid"
#define pass "your_pass"


void setup() {
  Serial.begin(9600);
  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
    Serial.println("STA Failed to configure");
  }

  Serial.print("Connecting");
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
    Serial.print(".");
  }
  Serial.println("Connected");
}

void loop() {
  Serial.println(WiFi.localIP());
  delay(3000);
}
