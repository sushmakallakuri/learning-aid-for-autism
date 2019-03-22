

#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 20, 4);

// it is a calculator  which helps  students suffering from autism to perform single digit calculations
//bs is state of row one buttons
//bs1 states of operations
// bs2 states of row two buttons
//state1-state of equal steate 2-state of reset
//a- first digit,b-second digit
int bs[]={0,0,0,0,0,0,0,0,0,0};
int bs1[]={0,0,0,0};
int bs2[]={0,0,0,0,0,0,0,0,0,0};
int state1=0,state2=0;
int a,bb,e,f,c,i,neg,dot,d,f1=0,f2=0,f3=0;
char str[1];
float h;
char ch[25]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y'};
int b[10],l[10],b1[4],l1[4],b2[10],l2[10],l3[10],l4[10];
int equal,reset;
char x;
//l,b set of first row leds and buttons
//l1,b1 set of leds and buttons for operations
//l2,b2 set of row2 leds and buttons
//l3,l4 - set of output leds 

void setup() {
  // pins declaration start

b2[0]=13;
b2[1]=12;
b2[2]=11;
b2[3]=10;
b2[4]=9;
b2[5]=8;
b2[6]=7;
b2[7]=6;
b2[8]=5;
b2[9]=4;
neg=40;
equal=A3;
b1[0]=A1;
b1[1]=A2;
b1[2]=A0;
b1[3]=A4;
reset=A7;
dot=44;


b[0]=A5;
b[1]=A6;//A6
b[2]=28;
b[3]=30;
b[4]=17;
b[5]=16;
b[6]=15;
b[7]=14;
b[8]=2;//2
b[9]=3;

l3[0]=43;
l3[1]=45;
l3[2]=47;
l3[3]=49;
l3[4]=51;
l3[5]=53;
l3[6]=52;
l3[7]=50;
l3[8]=48;
l3[9]=46;


//l1[0]=44;
//l1[1]=46;


l4[0]=41;
l4[1]=39;
l4[2]=37;
l4[3]=35;
l4[4]=33;
l4[5]=31;
l4[6]=29;
l4[7]=27;
l4[8]=25;
l4[9]=23;
// pins declaration ends
for(int i=0;i<10;i++)
pinMode(b[i],INPUT);


for(int i=0;i<10;i++)
pinMode(b2[i],INPUT);

for(int i=0;i<10;i++)
pinMode(l3[i],OUTPUT);


for(int i=0;i<10;i++)
pinMode(l4[i],OUTPUT);

for(int i=0;i<10;i++)
pinMode(l3[i],OUTPUT);

pinMode(dot,OUTPUT);
pinMode(neg,OUTPUT);

for(int i=0;i<4;i++)
pinMode(b1[i],INPUT);

pinMode(equal,INPUT);
pinMode(reset,INPUT);
  Serial.begin(9600);
  Serial1.begin(9600);
  lcd.begin();
      lcd.print("Lets calculate!");
  // Turn on the blacklight and print a message.
  lcd.backlight();
 
  
}


void loop() {
  for( i=0;i<10;i++)
  {
bs[i]=digitalRead(b[i]);
delay(20);
if(bs[i]==HIGH)
{
//digitalWrite(l3[i],HIGH);
lcd.setCursor(0,0);
lcd.print("First number : ");
//lcd.print();
//Serial.println("buton1 presed");

a=i;
lcd.print(a);
//Serial1.print("first number is\r");
Serial1.println(a);
Serial.print("\r");
delay(20);
x = ch[i];


 Serial.write(x); 

 

}

  }



for(i=0;i<4;i++)
{
bs1[i]=digitalRead(b1[i]);
delay(10);
if(bs1[i]==HIGH)
{
c=i;
x=ch[10+i];

 
 Serial.write(x); 


lcd.setCursor(0,1);
lcd.print("Operation : ");

//Serial.println("buton2 presed");
//Serial1.print("operation selected is\r");

delay(10);
if(c==0){
Serial1.println("add");
Serial.print("\r");
delay(10);
lcd.print("+");
}
else if(c==1){
Serial1.println("subtract");
Serial.print("\r");
delay(10);
lcd.print("-");
}
else if(c==2){
Serial1.println("multiply");
Serial.print("\r");
delay(10);
lcd.print("*");
}
else if(c==3){
Serial1.println("divide");
Serial.print("\r");  
delay(10);
lcd.print("/"); 
}                                     
}}


for( i=0;i<10;i++)
  {
bs2[i]=digitalRead(b2[i]);
delay(10);
if(bs2[i]==HIGH)
  {
    delay(25);
    bs2[i]=digitalRead(b2[i]);
    if(bs2[i]==HIGH)
  {//Serial.println(i);
//digitalWrite(l4[i],HIGH);
bb=i;
x=ch[14+i];
 
Serial.write(x); 



//Serial.println(bb);
lcd.setCursor(0,2);
lcd.print("Second number: ");
lcd.print(bb);
//Serial.println("buton3 presed");
//Serial1.print("second value is");

Serial1.println(bb);
Serial.print("\r");
delay(10);
//Serial.println(b[i]);
//Serial.println(b[7]);
//Serial.println(flag);
  } }}


state1=digitalRead(equal);
delay(10);
if(state1==HIGH)
{ delay(25);
 state1=digitalRead(equal);
 if(state1==HIGH)
{
  
switch(c){
  case 0:
  {
    d=a+bb;
  //Serial1.print("sum is\r");
  
  Serial1.println(d);
  Serial.print("\r");
  delay(10);
  lcd.setCursor(0,3);
 
lcd.print("Sum of number:");
lcd.print(d);
  e=d/10;
f=d%10;


digitalWrite(l3[e],HIGH);

digitalWrite(l4[f],HIGH);
  
break;

  }

case 1:
  {
    d=a-bb;
  //Serial1.print("difference is\r");
 
  Serial1.println(d);
  Serial.print("\r");
   delay(10);
  lcd.setCursor(0,3);
lcd.print("Difference:");


if(d<0)
{
  d=-d;
  digitalWrite(neg,HIGH);
  lcd.print("-");
 
}

lcd.print(d);

  e=d/10;
f=d%10;


digitalWrite(l3[e],HIGH);

digitalWrite(l4[f],HIGH);
break;
  }

case 2:
  {
    d=a*bb;
 // Serial1.print("product is\r");

  Serial1.println(d);
  Serial.print("\r");
    delay(10);
  lcd.setCursor(0,3);
  
lcd.print("Product :");
lcd.print(d);
  
  e=d/10;
f=d%10;


digitalWrite(l3[e],HIGH);

digitalWrite(l4[f],HIGH);
break;
  }
case 3:
  {
    h=(float)a/bb;
//  Serial1.print("quotient is\r");
  
  digitalWrite(dot,HIGH);
  Serial1.println(h);
  Serial.print("\r");
  delay(10);
    lcd.setCursor(0,3);
 
lcd.print("Quotient:");
lcd.print(h);
  
  d=h*10;
  e=d/10;
f=(d)%10;


digitalWrite(l3[e],HIGH);

digitalWrite(l4[f],HIGH);
break;
  }


}  
  
}

}

state2=digitalRead(reset);
//Serial.println(state2);


if(state2==HIGH)
{
  
 for(i=0;i<10;i++)
 {
  digitalWrite(l3[i],LOW);
  digitalWrite(l4[i],LOW);
  digitalWrite(dot,LOW);
  digitalWrite(neg,LOW);
 }
  x=ch[24];
  
  Serial.write(x);
  

 
     lcd.setCursor(0,1);
  lcd.clear();
lcd.print("Lets Calculate!");
 

}




}
