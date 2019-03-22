
int x=27 ,i,j;
char ch[25]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y'};
int ledPin[24];

char str[1],sr[10];








void setup() {
  
ledPin[0]=48;
ledPin[1]=46;
ledPin[2]=44;
ledPin[3]=42;
ledPin[4]=40;
ledPin[5]=38;
ledPin[6]=36;
ledPin[7]=34;
ledPin[8]=32;
ledPin[9]=30;

//operations 
ledPin[10]=52; //+
ledPin[11]=53; // -
ledPin[12]=50;// *
ledPin[13]=51; // /




ledPin[14]=49;
ledPin[15]=47;
ledPin[16]=45;
ledPin[17]=43;
ledPin[18]=41;
ledPin[19]=39;
ledPin[20]=37;
ledPin[21]=35;
ledPin[22]=33;
ledPin[23]=31;


/*
ledPin[0]=26;
ledPin[1]=25;
ledPin[2]=23;
ledPin[3]=22;
ledPin[4]=21;
ledPin[5]=21;
ledPin[6]=21;
ledPin[7]=21;
ledPin[8]=21;
ledPin[9]=21;
ledPin[10]=41;
ledPin[11]=46;
ledPin[12]=39;
ledPin[13]=38;
ledPin[14]=37;
ledPin[15]=36;
ledPin[16]=35;
ledPin[17]=34;
ledPin[18]=33;
ledPin[19]=32;
ledPin[20]=31;
ledPin[21]=30;
ledPin[22]=29;
ledPin[23]=28;
*/
  
  for(i=0;i<24;i++)
  {
pinMode(ledPin[i],OUTPUT);

  }
Serial.begin(9600);
Serial3.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
j=0;
if (Serial3.available()) {
   //allows all serial sent to be received together
    while(Serial3.available() && j<1) {
      str[j++] = Serial3.read();
    }
    str[j++]='\0';
  }


for(i=0;i<24;i++)
if(str[0]==ch[i])
{
digitalWrite(ledPin[i],HIGH);
//delay(50);
//Serial3.print("button pressed");
//delay(50);
itoa(i,sr,10);

Serial.print(sr);
Serial.print("\r");
delay(10);

}
if(str[0]==ch[i])
for(i=0;i<24;i++)
digitalWrite(ledPin[i],LOW);




/*Serial.print("loop running");
Serial3.write("loop running");
Serial3.print("loop running");
*/
}
