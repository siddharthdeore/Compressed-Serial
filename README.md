# Compressed Serial
An aprroach to send and receive data though UART communication. Compressed String For faster and relible Serial Communication.
String format #XYZZBB;<br>
X  varies from  0 to  o ie 0 to 64<br>
Y  varies from  0 to  o ie 0 to 64<br>
Z varies from 00 to oo ie 0 to 4095<br>
Button value varies from 00 to oo Buttons value is 12 bit binary ie 1111 1111 1111 so 12 digital values can be sent at a time.
