
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
int a,bb,e,f,c,i,neg,dot,d,x;
float h;

int b[10],l[10],b1[10],l1[10],b2[10],l2[10],l3[10],l4[10];



int value2=0;
int value1=1023;

int equal;
int state1=0;
int state2=0;
int reset;


void setup() {
  // put your setup code here, to run once:




b[0]=A0;
b[1]=A0;
b[2]=A1;
b[3]=A1;
b[4]=A2;
b[5]=A2;
b[6]=A3;
b[7]=A3;
b[8]=A4;
b[9]=A4;




b1[0]=A5;
b1[1]=A5;
b1[2]=A6;
b1[3]=A6;








 b2[0]=A7;
b2[1]=A7;
 b2[2]=A8;
b2[3]=A8;
 b2[4]=A9;
b2[5]=A9;
 b2[6]=A10;
b2[7]=A10;
 b2[8]=A11;
b2[9]=A11;

equal=A12;
reset=A12;





 l[0]=9;
l[1]=10;
l[2]=11;
l[3]=12;
l[4]=13;
l[5]=14;
l[6]=15;
l[7]=16;
l[8]=17;
l[9]=18;







l1[0]=19;
l1[1]=20;
l1[2]=21;
l1[3]=22;
l1[4]=23;
l1[5]=24;
l1[6]=25;
l1[7]=26;
l1[8]=27;
l1[8]=28;
l1[9]=29;

l2[0]=50;
l2[1]=51;
l2[3]=52;
l2[4]=53;

l3[0]=30;
l3[1]=31;
l3[2]=32;
l3[3]=33;
l3[4]=34;
l3[5]=35;
l3[6]=36;
l3[7]=37;
l3[8]=38;
l[9]=39;

l4[0]=40;
l4[1]=41;
l4[2]=42;
l4[3]=43;
l4[4]=44;
l4[5]=45;
l4[6]=46;
l4[7]=47;
l4[8]=48;
l4[9]=49;

neg=50;

dot=1;


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
  lcd.begin();
      lcd.print("Lets calculate!");
  // Turn on the blacklight and print a message.
  lcd.backlight();
}

void loop() {
//  flag=0;
 
  // put your main code here, to run repeatedly:
  for( i=0;i<10;i++)
  {
bs[i]=analogRead(b[i]);
//Serial.println(bs[i]);
if(i%2==0)
{

   if(bs[i]==value1)
   {
digitalWrite(l[i],HIGH);

//Serial.println("buton1 presed");
//f1=1;
a=i;
lcd.setCursor(0,0);
lcd.print("First number : ");
lcd.print(a);
Serial.print("first value=");
Serial.println(a);
//Serial.println("   ########################################");
break;
}}
else if(bs[i]==value2)
{

digitalWrite(l[i],HIGH);
lcd.setCursor(0,0);
lcd.print("First number : ");
lcd.print(a);
//Serial.println("buton1 presed");

a=i;

Serial.print("first value=");
Serial.println(a);
//Serial.println(flag);
break;
  

}

  }
  





bs1[0]=analogRead(b1[0]);



if(bs1[0]==value1)
{
digitalWrite(l1[0],HIGH);
c=0;
//Serial.println(c);
//Serial.println("buton2 presed");
Serial.print("operation selected=");
lcd.setCursor(0,1);
lcd.print("Operation : ");
lcd.print("+ ");
Serial.println("+");
//Serial.println(flag);
}


bs1[1]=analogRead(b1[1]);
if(bs1[1]==value2)
{
digitalWrite(l1[1],HIGH);
c=1;
//Serial.println(c);
//Serial.println("buton2 presed");
Serial.print("operation selected=");
lcd.setCursor(0,1);
lcd.print("Operation : ");
lcd.print("-");
Serial.println("-");
//Serial.println(flag);
}


bs1[2]=analogRead(b1[2]);
if(bs1[2]==value1)
{
digitalWrite(l1[2],HIGH);
c=2;
//Serial.println(c);
//Serial.println("buton2 presed");
Serial.print("operation selected=");
lcd.setCursor(0,1);
lcd.print("Operation : ");
lcd.print("* ");
Serial.println("*");
//Serial.println(flag);
}

bs1[3]=analogRead(b1[3]);
if(bs1[3]==value2)
{
digitalWrite(l1[3],HIGH);
c=3;
//Serial.println(c);
//Serial.println("buton2 presed");
Serial.print("operation selected=");
lcd.setCursor(0,1);
lcd.print("Operation : ");
lcd.print("/");
Serial.println("/");
//Serial.println(flag);
}








for( i=0;i<10;i++)
  {
bs2[i]=analogRead(b2[i]);
if(i%2==0)
{

  if(bs2[i]==value1)
  {
digitalWrite(l2[i],HIGH);
bb=i;

//Serial.println(bb);
//Serial.println("buton3 presed");
Serial.print("second value=");
Serial.println(bb);
lcd.setCursor(0,2);
lcd.print("Second number: ");
lcd.print(bb);
break;
//Serial.println(flag);
  }}
  else if(bs2[i]==value2)
  {
    digitalWrite(l2[i],HIGH);
bb=i;
lcd.setCursor(0,2);
lcd.print("Second number: ");
lcd.print(bb);
//Serial.println(bb);
//Serial.println("buton3 presed");
Serial.print("second value=");
Serial.println(bb);
  }
}

  


state1=analogRead(equal);
if(state1==value2)
{
 
switch(c){
 case 0:
  {
    d=a+bb;
  Serial.print("sum=");
  Serial.println(d);
  lcd.setCursor(0,1);
  lcd.clear();
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
  Serial.print("difference=");
  Serial.println(d);
  lcd.setCursor(0,1);
lcd.print("Difference number:");


if(d<0)
{
  d=-d;
  digitalWrite(neg,HIGH);
  lcd.print(d);
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
  Serial.print("product=");
  Serial.println(d);
  lcd.setCursor(0,1);
  lcd.clear();
lcd.print("Product of number:");
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
  Serial.print("quotient=");
  digitalWrite(dot,HIGH);
  Serial.println(h);
    lcd.setCursor(0,1);
  lcd.clear();
lcd.print("Quotient of number:");
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
state2=analogRead(reset);
if(state2==value1)
{
  for(i=0;i<10;i++)
 {
  digitalWrite(l3[i],LOW);
  digitalWrite(l4[i],LOW);
  digitalWrite(dot,LOW);
  digitalWrite(neg,LOW);
 }
  

 
     lcd.setCursor(0,1);
  lcd.clear();
lcd.print("Lets Calculate!");
}





  }


  



