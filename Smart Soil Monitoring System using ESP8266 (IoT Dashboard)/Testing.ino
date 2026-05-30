#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Set up your WI-FI credential
const char* ssid = "***********"
const char* password = "***********";

ESP8266WebServer server(80);

int soilPin = A0;

void handleRoot() {

  int soilValue = analogRead(soilPin);

  int percent = map(soilValue, 1023, 0, 0, 100);

  if (percent < 0) percent = 0;
  if (percent > 100) percent = 100;

  String status;
  String color;

  if (percent < 40) {
    status = "DRY SOIL";
    color = "#ff3b3b";
  }
  else {
    status = "WET SOIL";
    color = "#00ff88";
  }

  String page = "";

  page += "<!DOCTYPE html><html>";

  page += "<head>";

  page += "<meta name='viewport' content='width=device-width, initial-scale=1.0'>";

  page += "<meta http-equiv='refresh' content='1'>";

  page += "<title>Smart Soil Dashboard</title>";

  page += "<style>";

  page += "body{";
  page += "background:#0f172a;";
  page += "font-family:Arial;";
  page += "color:white;";
  page += "text-align:center;";
  page += "}";

  page += ".card{";
  page += "background:#1e293b;";
  page += "width:90%;";
  page += "max-width:400px;";
  page += "margin:40px auto;";
  page += "padding:25px;";
  page += "border-radius:20px;";
  page += "box-shadow:0px 0px 20px black;";
  page += "}";

  page += ".circle{";
  page += "width:120px;";
  page += "height:120px;";
  page += "border-radius:50%;";
  page += "margin:auto;";
  page += "line-height:120px;";
  page += "font-size:28px;";
  page += "font-weight:bold;";
  page += "background:";
  page += color;
  page += ";";
  page += "color:black;";
  page += "animation:pulse 1s infinite;";
  page += "}";

  page += "@keyframes pulse{";
  page += "0%{transform:scale(1);}";
  page += "50%{transform:scale(1.08);}";
  page += "100%{transform:scale(1);}";
  page += "}";

  page += ".bar{";
  page += "width:100%;";
  page += "background:#334155;";
  page += "border-radius:20px;";
  page += "overflow:hidden;";
  page += "margin-top:20px;";
  page += "}";

  page += ".fill{";
  page += "height:30px;";
  page += "width:";
  page += percent;
  page += "%;";
  page += "background:";
  page += color;
  page += ";";
  page += "}";

  page += "</style>";

  page += "</head>";

  page += "<body>";

  page += "<div class='card'>";

  page += "<h1>SMART SOIL MONITOR</h1>";

  page += "<h3>Live IoT Dashboard</h3>";

  page += "<div class='circle'>";
  page += percent;
  page += "%";
  page += "</div>";

  page += "<h2 style='color:";
  page += color;
  page += ";'>";
  page += status;
  page += "</h2>";

  page += "<p>Raw Sensor Value: ";
  page += soilValue;
  page += "</p>";

  page += "<div class='bar'>";
  page += "<div class='fill'></div>";
  page += "</div>";

  page += "</div>";

  page += "</body></html>";

  server.send(200, "text/html", page);
}

void setup() {

  Serial.begin(115200);

  WiFi.begin(ssid, password);

  Serial.println("Connecting...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Esp8266 connected to ");
  Serial.println(ssid);

  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);

  server.begin();

  Serial.println("Dashboard Started");
}

void loop() {

  server.handleClient();
}