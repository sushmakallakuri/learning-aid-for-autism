
int x=25 ,i;
int l[24];










void setup() {
l[0]=13;
l[1]=13;
l[2]=13;
l[3]=13;
l[4]=13;
l[5]=13;
l[6]=13;
l[7]=13;
l[8]=13;
l[9]=13;
l[10]=13;
l[11]=13;
l[12]=13;
l[13]=13;
l[14]=13;
l[15]=13;
l[16]=13;
l[17]=13;
l[18]=13;
l[19]=13;
l[20]=13;
l[21]=13;
l[22]=13;
l[23]=13;


  
  for(i=0;i<24;i++)
  {
pinMode(l[i],OUTPUT);

  }
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

if (Serial.available() > 0) {
                // read the incoming byte:
             x = Serial.read();
}
  
for(i=0;i<24;i++)
if(x==i)
digitalWrite(l[i],HIGH);

if(x==25)
for(i=0;i<24;i++)
digitalWrite(l[i],LOW);

}
