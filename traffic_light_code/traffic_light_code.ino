int red1 = 4;
int yellow1 = 3;
int green1 = 2;
int red2 = 7;
int yellow2 = 6;
int green2 = 5;
int red3 = 10;
int green3 = 9;
const int buzzer =1;
const int input1 = 13;
int input1s = 0;
int num1= 6;


const int STcp = 12;//Pin connected to ST_CP of 74HC595
const int SHcp = 8;//Pin connected to SH_CP of 74HC595 
const int DS = 11; //Pin connected to DS of 74HC595 
//display 0,1,2,3,4,5,6,7,8
int datArray[16] = {
  0,96, 218, 242, 102, 182, 190, 224, 254};


void setup() {                                           
   pinMode(red1, OUTPUT);
   pinMode(yellow1, OUTPUT);
   pinMode(green1, OUTPUT);
   pinMode(red2, OUTPUT);
   pinMode(yellow2, OUTPUT);
   pinMode(green2, OUTPUT);
   pinMode(red3, OUTPUT);
   pinMode(green3, OUTPUT);
   pinMode(input1, INPUT);  
   pinMode(buzzer, OUTPUT); 
   pinMode(STcp,OUTPUT);
   pinMode(SHcp,OUTPUT);
   pinMode(DS,OUTPUT);
 
}  
void loop()
{
  
  State1();
  State2(); 
}
void State1()
{
  input1s=digitalRead(input1);
     if (input1s == HIGH)
     { 
  for(int num = 8; num >=0; num--)   //display 6-1 and turn on a green led
  {

    digitalWrite(green1,HIGH);  
    digitalWrite(red2,HIGH); 
    digitalWrite(green3,HIGH);
    digitalWrite(STcp,LOW); //ground ST_CP and hold low for transmitting
    shiftOut(DS,SHcp,MSBFIRST,datArray[num]);
    digitalWrite(STcp,HIGH); //pull the ST_CPST_CP to save the data
    tone(buzzer, 500); // Send 500Hz sound signal...
    delay(500);        // ...for 0.5 sec
    noTone(buzzer);     // Stop sound...
    delay(500); 
    
  }
  digitalWrite(green1,LOW);
  digitalWrite(red2,LOW); 
  digitalWrite(green3,LOW);
  
  }   
       else 
       {
          
  for(int num = 6; num >=0; num--)   //display 6-1 and turn on a green led
  {
    digitalWrite(green1,HIGH);
    digitalWrite(red2,HIGH); 
    digitalWrite(green3,HIGH);
    digitalWrite(STcp,LOW); //ground ST_CP and hold low for transmitting
    shiftOut(DS,SHcp,MSBFIRST,datArray[num]);
    digitalWrite(STcp,HIGH); //pull the ST_CPST_CP to save the data
     //wait for a second 
    tone(buzzer, 500); // Send 500Hz sound signal...
    delay(500);        // ...for 0.5 sec
    noTone(buzzer);     // Stop sound...
    delay(500); 
    
  }
  
  digitalWrite(green1,LOW);
  digitalWrite(red2,LOW); 
  digitalWrite(green3,LOW);
       }
  for(int num = 3 ;num >=0; num--)   //diaplay 3 to 1 and turn on the yellow led 
  {
    digitalWrite(yellow1,HIGH);
    digitalWrite(red2,HIGH);
    digitalWrite(red3,HIGH);
    tone(buzzer, 250); // Send 250Hz sound signal...
  delay(500);        // ...for 0.5 sec
  noTone(buzzer);     // Stop sound...
  delay(500); 
    
  }
  digitalWrite(yellow1,LOW);  //turn off the yellow led
  digitalWrite(red2,LOW);  //the red led finally turn off
}


void State2()
{
  digitalWrite(red1,HIGH);
  for(int num = 6; num >=0; num--)
  {
    digitalWrite(green2,HIGH);
    tone(buzzer, 250); // Send 250Hz sound signal...
  delay(500);        // ...for 0.5 sec
  noTone(buzzer);     // Stop sound...
  delay(500); 
  }
  digitalWrite(green2,LOW);
  digitalWrite(red1,LOW);
  
  
  for(int num = 3 ;num >=0; num--)
  {
    digitalWrite(yellow2,HIGH);
    digitalWrite(red1,HIGH);
    tone(buzzer, 250); // Send 250Hz sound signal...
  delay(500);        // ...for 0.5 sec
  noTone(buzzer);     // Stop sound...
  delay(500); 
  }
  digitalWrite(yellow2,LOW);
  digitalWrite(red1,LOW);
  digitalWrite(red3,LOW);

}
