#define debug 0

//String format #XYZZBB;
//X  varies from  0 to  o ie 0 to 64
//Y  varies from  0 to  o ie 0 to 64
//ZZ varies from 00 to oo ie 0 to 4096
//BB varies from 00 to oo Buttons value 12 bit binary ie 1111 1111 1111

//#oo oo oo oo oo oo oo oo;

String s1, s2, s3, s4;
char Str1[3] = "X";
char Str2[3] = "Y";
char Str3[3] = "Z";
char Str4[3] = "B";
char c;
int Buttons; //Digital Buttons
int x = 4095;
int y = 4095;
int z = 4095;
int btn = 0;
int la = 4095;
int lo = 4095;
int al = 4095;

int X, Y, Z; //Analog
boolean buttons[10];
boolean flag = 0;

uint32_t packetCount = 0, last_sent = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("Ready");
}
void loop() {
  if (Serial.available())
  {
    c = Serial.read();
    if (c == '*') flag = 1;
    if (c == '+') flag = 0;
    DecodeString();
  }
  if (flag)
  {
    if (millis() - last_sent >= 200)
    {
      sendPacket();
      last_sent = millis();
    }
  }
  //  updateVariables();
}
void updateVariables()
{
  x = 0;
  y = 0;
  z = 0;
}

