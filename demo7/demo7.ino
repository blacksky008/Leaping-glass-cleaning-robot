#include <IRremote.h>
//红外引脚11
int RECV_PIN = 11;
//气缸左右引脚2，3
int zuo = 2;
int you = 3;
//气缸上下引脚4
int xi3 = 4;
//电机左右转引脚5，6，7
int xi2 = 5;
int shang = 6;
int qingjie=7;
int pin1 = 8;
//左右吸附引脚8
int pin2 = 10;
//中间吸附引脚9
int pin3 = 12;

//红外接受信号源

//左右气缸红外信号
long zuohong  = 0x00FFA25D;
long zuoyouting = 0xFF22DD;
long youhong = 0xFFE01F;
//上下气缸红外信号
long shanghong = 0xFF629D;
long xiahong = 0xFFA857;
//电机左右转红外信号
long zuoxuanhong = 0xFF6897;
long zuoyouxuanting = 0xFF02FD;
long youxuanhong = 0xFF9867;
//左右中吸附红外信号
long xikaihong2 = 0xFFE21D;
long xitinghong2 = 0xFFC23D;
long xikaihong3 = 0xFF906F;
long xitinghong3 = 0xFFB04F;

long qingkai = 0xFF30CF;
long qingguan =0xFF18E7 ;

long zong=0xFF4AB5;

long zongting=0xFF52AD;

//初始化红外源
IRrecv irrecv(RECV_PIN);
decode_results results;
//可去除，方便查看问题所在
void dump(decode_results *results) {
  int count = results->rawlen;
  if (results->decode_type == UNKNOWN) 
    {
     Serial.println("Could not decode message");
    } 
  else 
   {
    if (results->decode_type == NEC) 
      {
       Serial.print("Decoded NEC: ");
      } 
    else if (results->decode_type == SONY) 
      {
       Serial.print("Decoded SONY: ");
      } 
    else if (results->decode_type == RC5) 
      {
       Serial.print("Decoded RC5: ");
      } 
    else if (results->decode_type == RC6) 
      {
       Serial.print("Decoded RC6: ");
      }
     Serial.print(results->value, HEX);
     Serial.print(" (");
     Serial.print(results->bits, DEC);
     Serial.println(" bits)");
   }
     Serial.print("Raw (");
     Serial.print(count, DEC);
     Serial.print("): ");

  for (int i = 0; i < count; i++) 
     {
      if ((i % 2) == 1) {
      Serial.print(results->rawbuf[i]*USECPERTICK, DEC);
     } 
    else  
     {
      Serial.print(-(int)results->rawbuf[i]*USECPERTICK, DEC);
     }
    Serial.print(" ");
     }
      Serial.println("");
     }
//主函数
void setup()
 {
  //打开输出出入端
  pinMode(RECV_PIN, INPUT);   
  pinMode(zuo, OUTPUT);
  pinMode(you, OUTPUT);
  pinMode(shang, OUTPUT);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);  
  pinMode(pin3, OUTPUT); 
  pinMode(xi2, OUTPUT);
  pinMode(xi3, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(qingjie,OUTPUT);
  Serial.begin(9600);
//初始化
digitalWrite(zuo, HIGH);
digitalWrite(you, HIGH);
digitalWrite(shang, HIGH);
digitalWrite(pin1, HIGH);
digitalWrite(pin2, HIGH);
digitalWrite(pin3, HIGH);
digitalWrite(xi2, HIGH);
digitalWrite(xi3, HIGH);
digitalWrite(qingjie,HIGH);

//开始接受信号源
  irrecv.enableIRIn();
 }
//延时信号
int on = 0;
unsigned long last = millis();
//循环体
void loop() 
{
  if (irrecv.decode(&results)) 
   {
    if (millis() - last > 250) 
      {
       on = !on;
       digitalWrite(13, on ? HIGH : LOW);
       dump(&results);
      }
   if (results.value == zuohong )
   {
digitalWrite(zuo, HIGH);
digitalWrite(you, LOW);
digitalWrite(shang, HIGH);
digitalWrite(pin1, HIGH);
digitalWrite(pin2, HIGH);
digitalWrite(pin3, HIGH);
digitalWrite(xi2, LOW);
digitalWrite(xi3, HIGH);
delay(5000);
digitalWrite(zuo, HIGH);
digitalWrite(you, HIGH);
digitalWrite(shang, LOW);
digitalWrite(pin1, HIGH);
digitalWrite(pin2, HIGH);
digitalWrite(pin3, HIGH);
digitalWrite(xi2, LOW);
digitalWrite(xi3, LOW);
//digitalWrite(qingjie,HIGH);
delay(3000);
digitalWrite(zuo, HIGH);
digitalWrite(you, HIGH);
digitalWrite(shang, LOW);
digitalWrite(pin1, HIGH);
digitalWrite(pin2, HIGH);
digitalWrite(pin3, HIGH);
digitalWrite(xi2, HIGH);
digitalWrite(xi3, LOW);
//digitalWrite(qingjie,HIGH);
delay(2000);
digitalWrite(zuo, LOW);
digitalWrite(you, HIGH);
digitalWrite(shang, LOW);
digitalWrite(pin1, HIGH);
digitalWrite(pin2, HIGH);
digitalWrite(pin3, HIGH);
digitalWrite(xi2, HIGH);
digitalWrite(xi3, LOW);
//digitalWrite(qingjie,HIGH);
delay(3000);
digitalWrite(zuo, LOW);
digitalWrite(you, HIGH);
digitalWrite(shang, HIGH);
digitalWrite(pin1, HIGH);
digitalWrite(pin2, HIGH);
digitalWrite(pin3, HIGH);
digitalWrite(xi2, LOW);
digitalWrite(xi3, LOW);
//digitalWrite(qingjie,HIGH);
delay(2000);
digitalWrite(zuo, LOW);
digitalWrite(you, HIGH);
digitalWrite(shang, HIGH);
digitalWrite(pin1, HIGH);
digitalWrite(pin2, HIGH);
digitalWrite(pin3, HIGH);
digitalWrite(xi2, LOW);
digitalWrite(xi3, HIGH);
//digitalWrite(qingjie,HIGH);
}

   if (results.value == youhong )
   {
digitalWrite(zuo, LOW);
digitalWrite(you, HIGH);
digitalWrite(shang, HIGH);
digitalWrite(pin1, HIGH);
digitalWrite(pin2, HIGH);
digitalWrite(pin3, HIGH);
digitalWrite(xi2, LOW);
digitalWrite(xi3, HIGH);

delay(5000);
digitalWrite(zuo, HIGH);
digitalWrite(you, HIGH);
digitalWrite(shang, LOW);
digitalWrite(pin1, HIGH);
digitalWrite(pin2, HIGH);
digitalWrite(pin3, HIGH);
digitalWrite(xi2, LOW);
digitalWrite(xi3, LOW);
//digitalWrite(qingjie,HIGH);
delay(3000);
digitalWrite(zuo, HIGH);
digitalWrite(you, HIGH);
digitalWrite(shang, LOW);
digitalWrite(pin1, HIGH);
digitalWrite(pin2, HIGH);
digitalWrite(pin3, HIGH);
digitalWrite(xi2, HIGH);
digitalWrite(xi3, LOW);
//digitalWrite(qingjie,HIGH);
delay(2000);
digitalWrite(zuo, HIGH);
digitalWrite(you, LOW);
digitalWrite(shang, LOW);
digitalWrite(pin1, HIGH);
digitalWrite(pin2, HIGH);
digitalWrite(pin3, HIGH);
digitalWrite(xi2, HIGH);
digitalWrite(xi3, LOW);
//digitalWrite(qingjie,HIGH);
delay(3000);
digitalWrite(zuo, HIGH);
digitalWrite(you, LOW);
digitalWrite(shang, HIGH);
digitalWrite(pin1, HIGH);
digitalWrite(pin2, HIGH);
digitalWrite(pin3, HIGH);
digitalWrite(xi2, LOW);
digitalWrite(xi3, LOW);
delay(2000);
digitalWrite(zuo, HIGH);
digitalWrite(you, LOW);
digitalWrite(shang, HIGH);
digitalWrite(pin1, HIGH);
digitalWrite(pin2, HIGH);
digitalWrite(pin3, HIGH);
digitalWrite(xi2, LOW);
digitalWrite(xi3, HIGH);
//digitalWrite(qingjie,HIGH);
}
//形态1
 if (results.value == xikaihong2 )
 {
digitalWrite(shang, HIGH);
digitalWrite(pin1, HIGH);
digitalWrite(pin2, HIGH);
digitalWrite(pin3, HIGH);
digitalWrite(xi2, LOW);
digitalWrite(xi3, LOW);
delay(2000);
digitalWrite(shang, HIGH);
digitalWrite(pin1, HIGH);
digitalWrite(pin2, HIGH);
digitalWrite(pin3, HIGH);
digitalWrite(xi2, LOW);
digitalWrite(xi3, HIGH);
 }
//形态2
if (results.value == zuoyouting )
{
digitalWrite(zuo, HIGH);
digitalWrite(you, HIGH);
digitalWrite(shang, LOW);
digitalWrite(pin1, HIGH);
digitalWrite(pin2, HIGH);
digitalWrite(pin3, HIGH);
digitalWrite(xi2, LOW);
digitalWrite(xi3, LOW);
delay(2000);
digitalWrite(zuo, HIGH);
digitalWrite(you, HIGH);
digitalWrite(shang, LOW);
digitalWrite(pin1, HIGH);
digitalWrite(pin2, HIGH);
digitalWrite(pin3, HIGH);
digitalWrite(xi2, HIGH);
digitalWrite(xi3, LOW);
}
 //右转  
   if (results.value == youxuanhong )
       {digitalWrite(pin1, LOW);
       digitalWrite(pin2, HIGH);
       digitalWrite(pin3, HIGH);
    //   digitalWrite(zuo, HIGH);
      // digitalWrite(you, LOW);
 //      digitalWrite(shang, HIGH);
   //    digitalWrite(xi2, LOW);
     //  digitalWrite(xi3, HIGH);
 //      digitalWrite(qingjie,HIGH);
       }
//左转    
   if (results.value ==zuoxuanhong  )
     { digitalWrite(pin1, LOW); 
       digitalWrite(pin2, LOW);
       digitalWrite(pin3, LOW);
   //    digitalWrite(zuo, HIGH);
     //  digitalWrite(you, LOW);
     //  digitalWrite(shang, HIGH);
     //  digitalWrite(xi2, LOW);
     //  digitalWrite(xi3, HIGH);
       //digitalWrite(qingjie,HIGH);
     }
     //停
 if (results.value == zuoyouxuanting )  {
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, HIGH);}


    if (results.value == zongting )  
   {

      digitalWrite(xi3, LOW);

  }     
   if (results.value == qingkai )  
       digitalWrite(qingjie, LOW);

  if (results.value == qingguan )  
       digitalWrite(qingjie, HIGH);
    last = millis();      
    irrecv.resume(); // Receive the next value
  }
}



