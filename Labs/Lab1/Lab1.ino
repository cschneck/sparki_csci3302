#include <Sparki.h> // include sparki library

void setup() {
  sparki.servo (SERVO_CENTER);
  sparki.clearLCD();
}

// /------^-----\
// |            |
// | 69  70  71 |
// | 68  64  67 |
// |  7  21   9 |
// | 22  25  13 |
// | 12  24  94 |
// |  8  28  90 |
// | 66  82  74 |
// \____________/


void moveLeftGran(int dist) {
  sparki.moveLeft(300);
  sparki.moveRight(200);
}

int readRemote() {
  int code = sparki.readIR();
   if (code != -1){
    sparki.print("Code received in function: ");
    sparki.println(code);
    return code;
   }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
   int code = sparki.readIR();

   if (code != -1){
    sparki.print("Received code: ");
    sparki.println(code);
   }

   switch(code){
    //Start program
    case 28:  sparki.moveLeft(); break;
    case 64:  sparki.moveStop(); break;
    case 24:  moveLeftInfinite(); break;
   }
  sparki.updateLCD();
}
