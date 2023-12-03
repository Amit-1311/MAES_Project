#define SW1 2
#define SW2 3
#define SW3 4
#define SW4 5

void setup() {
  Serial.begin(38400);
  pinMode(SW1,OUTPUT);
  pinMode(SW2,OUTPUT);
  pinMode(SW3,OUTPUT);
  pinMode(SW4,OUTPUT);
  digitalWrite(SW1,HIGH);
  digitalWrite(SW2,HIGH);
  /* If no name is given, default 'ESP32' is applied */
  /* If you want to give your own name to ESP32 Bluetooth device, then */
  /* specify the name as an argument Serial.begin("myESP32Bluetooth"); */

}

void loop() {
  String val;
  if (Serial.available())
  {
    val=Serial.readString();
    Serial.println(val);
    if(val=="11"){
      digitalWrite(SW1,LOW);
    }else if(val=="10"){
      digitalWrite(SW1,HIGH);
    }else if(val=="21"){
      digitalWrite(SW2,LOW);
    }else if(val=="20"){
      digitalWrite(SW2,HIGH);
    }else if(val=="31"){
      digitalWrite(SW3,LOW);
    }else if(val=="30"){
      digitalWrite(SW3,HIGH);
    }else if(val=="41"){
      digitalWrite(SW4,LOW);
    }else if(val=="40"){
      digitalWrite(SW4,HIGH);
    }
    
  }
}