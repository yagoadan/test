 #include <Stepper.h> 
 
const int stepsPerRevolution = 32;  
const int GearedStepsPerRev = 2038;  

int Lswitch=2; //limitswitch is connected to digital pin 2
int flag=0;   //flag indicates that limitswitch was pressed when value is 1
int countr=0; //counts the steps until wall reached

Stepper myStepper1(stepsPerRevolution, 6, 8, 7, 9); //stepper 1: respecively IN1, IN2, IN3, IN4
Stepper myStepper2(stepsPerRevolution, 10, 12, 11, 13); //STEPPER 2: IN1. IN2, IN3, IN4

void setup() {
  pinMode(Lswitch, INPUT); 
  myStepper1.setSpeed(800);  
  myStepper2.setSpeed(800);
  Serial.begin(9600);
} 
void loop() {
  if (digitalRead(Lswitch) == HIGH){    //when limitswitch pressed do this:
    Serial.println("pressed");          //print pressed
    Serial.print("distance done:"); Serial.println(countr); //also print out the number of steps done until switch was pressed
    flag=1;    
  }  
  if (flag==0){   //when flag is 0 it means that the rollerswitch hasnt been pressed yet so crry on moving forward
    countr+=1;    //add one to the counter this way keeping track of steps 
    myStepper1.step(1);
    myStepper2.step(-1);
  } 
  if (flag==1){   //when flag is 1, it means the switch was pressed and the vehicle will change direction
    for (int i = 0; i < countr; i++) {    //
      myStepper1.step(-1);
      myStepper2.step(1);
          
  }
  delay(1000); // wait 10 seconds when back at starting point
  }
  
}
