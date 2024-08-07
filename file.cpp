#include <ESP8266WiFi.h>
//#include <ESP8266Firebase.h>
//#define REFERENCE_URL "https://smartliving-4b210-default-rtdb.firebaseio.com/"
//#define FIREBASE_AUTH "RwcIlszjgfsQmCmZ7sA6OGKOJd860f607Ka2WMPI"
#define WIFI_SSID "DESKTOP_94TAEO1"
#define WIFI_PASSWORD "qwertyuiop"
WiFiServer server(5005);
//Firebase firebase(REFERENCE_URL);
void setup() {
 Serial.begin(115200);
 delay(100);
 //LED OUTPUT MODE
 pinMode(D0, OUTPUT);
 pinMode(D1, OUTPUT);
 pinMode(D2, OUTPUT);
 pinMode(D3, OUTPUT);
 digitalWrite(D0, HIGH);
 digitalWrite(D1, HIGH);
 digitalWrite(D2, HIGH);
 digitalWrite(D3, HIGH);
 Serial.println();
 Serial.print("Connecting to ");
 Serial.println(WIFI_SSID);
 WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
 while (WiFi.status() != WL_CONNECTED) {
 delay(500);
 Serial.print(".");
 }
 Serial.println("");
 Serial.println("WiFi connected");
 Serial.print("IP address: ");
 Serial.println(WiFi.localIP());
 server.begin();
 Serial.println("Server started");

}
void loop() {
 WiFiClient client = server.available();
 if (client) {
 Serial.println("Client connected");
 while (client.connected()) {
 if (client.available() > 0) {
 char data = client.read();
 if (data == 'A') {
 digitalWrite(D0, LOW);
 }
 else if (data == 'B') {
 digitalWrite(D0, HIGH);
 }
 else if (data == 'C') {
 digitalWrite(D1, LOW);
 }
 else if (data == 'D') {
 digitalWrite(D1, HIGH);
 }
 else if (data == 'E') {
 digitalWrite(D2, LOW);
 }
else if (data == 'F') {
 digitalWrite(D2, HIGH);
 }

 else if (data == 'G') {
 digitalWrite(D3, LOW);
 }
 else if (data == 'H') {
 digitalWrite(D3, HIGH);
 }
 }
 }
 client.stop();
 Serial.println("Client disconnected");
 }
}
