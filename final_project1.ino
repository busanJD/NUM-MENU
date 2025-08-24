//START
#include <LiquidCrystal.h>
int ledRED=7;
int ledGREEN=8;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int i =0,choice,esc=1;//,palin,prim,perf;

String inputData = "";
char *msg[] = {"ODD","EVEN","Palindrome","Prime","Perfect Square","Hemchandra Num"};
void setup() {
  pinMode(ledRED,OUTPUT);
  pinMode(ledGREEN,OUTPUT);
  Serial.begin(9600);
  digitalWrite(ledRED,HIGH);
  lcd.clear();
  lcd.begin(16, 2);
  lcd.setCursor(1,0);
  lcd.print("Arduino Project");
  lcd.setCursor(3,1);
  lcd.print("| Namaste |");
  delay(1500);
 
  Serial.println("\n1. Odd Numbers \n2. Even Numbers \n3. Palindrome Numbers \n4. Prime Numbers \n5. Perfect Numbers \n6. Hemachandra Numbers \n-----------------\n*Please Select your option*");
  while(Serial.available()==0)
  {
    
  }
  choice = Serial.parseInt();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(choice);
  lcd.print(".");
  lcd.setCursor(2,0);
  lcd.print(msg[choice-1]);
  digitalWrite(ledRED,LOW);
  delay(500);
  
  //edit
   //while(Serial.available()==0)
  //{
  //}
  //esc=Serial.parseInt();
  //if(esc==0);
    //goto restart;
}

 void(* resetFunc) (void) = 0;  // declare reset fuction at address 0


void loop() {
 
  // Check the serial
    inputData = Serial.readString();
  // check if user input 0
  bool status =false;
  status = (inputData == "0");
  
  // Serial.println("user input is 0 :");
  // Serial.print(inputData);
  // Serial.println();
  
  
  
  
  // if user input 0 then null
  if (inputData == "0"){
    Serial.println("Reset System.");
    //delay(50);
    resetFunc(); //call reset
  }
  // else print number
  else{
    digitalWrite(ledGREEN,HIGH);
    lcd.setCursor(7,1);
  
    switch(choice) {
    case 1 :
    i++;
    lcd.print(i++);
    //delay(500);
    break;
    
    case 2 :
    lcd.print(i);
    i+=2;
    //delay(500);
    break;
    
    case 3:
    palindrome();
    //lcd.print(palin);
    i++;
    break;
    
    case 4:
    prime();
    //lcd.print(prim);
    i++;
    break;
    
    case 5:
    perfsq();
    i++;
    //delay(500);
    break;
    
    case 6:
    fibonacci();
    i++;
    //delay(750);
    break;
    
    default:
    lcd.print("!WRONG!");
    resetFunc(); //call reset
  }
 }

}

//Palindrome
int palindrome() {
  int num1= i;
  int rem=0;
  int sum = 0;

  while(num1>0)
  {
    rem=num1%10;
    sum=sum*10+rem;
    num1=num1/10;
  }
  if(sum==i)
    {
      lcd.print(i);
        //delay(50);
        return 0;
     }
  }

//Prime Numbers
int prime() {
  int k=0,j;
  for(j=1;j<=i;j++)
  {
    if(i%j==0)
      k++;
  }
  if(k==2)
  {
    lcd.print(i);
    //delay(500);
    return 0;
  }
}

//Perfect Square
int perfsq() {  
  lcd.print(i*i);
  return 0;
}

int t1=0,t2=1,nt;
//Fibonacci Series
int fibonacci() {
  lcd.print(nt);
  t1 = t2;
  t2=nt;
  nt=t1+t2;
  return 0;
}
   
