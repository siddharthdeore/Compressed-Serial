void DecodeString()
{
  if (c == '#')
  {
    c = Serial.read();
    s1 = "";
    s2 = "";
    s3 = "";
    s4 = "";
    while (c != '$' && s4.length() < 2 && (c >= '0') && (c <= 'o'))
    {
      if (s1.length() < 2)
        s1 = s1 + c;
      else if (s2.length() < 2)
        s2 = s2 + c;
      else if (s3.length() < 2)
        s3 = s3 + c;
      else if (s4.length() < 2)
        s4 = s4 + c;
      c = Serial.read();
    }

    if (s1.length() == 2 && s2.length() == 2)
    {
      s1.toCharArray(Str1, s1.length() + 1);
      s2.toCharArray(Str2, s2.length() + 1);
      s3.toCharArray(Str3, s3.length() + 1);
      s4.toCharArray(Str4, s4.length() + 1);

      X = String2Dec(Str1) % 4096;
      Y = String2Dec(Str2) % 4096;
      Z = String2Dec(Str3) % 4096;
      Buttons = String2Dec(Str4) % 4096;
      packetCount++;
#ifdef debug
      Serial.print(packetCount);
      Serial.print(" #");
      Serial.print(s1);
      Serial.print(s2);
      Serial.print(s3);
      Serial.print(s4);
      Serial.print("$ X=");
      Serial.print(X);
      Serial.print(" Y=");
      Serial.print(Y);
      Serial.print(" ");
      Serial.print(" Z=");
      Serial.print(Z);
      Serial.print(" ");
      Serial.println(Buttons, BIN);
      //        Serial.print(" ");
      //        Serial.println(buttons[2]);
      //        Serial.println((Buttons & 1<<0)!=0);
      delay(5);
#endif
    }
  }
}
/* Funcction to convert base 64 string to its decimal equivalen*/
int String2Dec(char *s)
{
  int x = 0;
  for (;;)
  {
    char chu = *s;
    if (chu >= '0')
    {
      x = x * 64 + (chu - '0');
    }
    else break;
    s++;
  }
  return x;
}