const int M11 = 10;
const int M12 = 5;
const int M21 = 6;
const int M22 = 9;

const int AE1 = 3;
const int AE2 = 7;
const int BE1 = 4;
const int BE2 = 2;

volatile long distance = 0;

const float wheel_d = 66;
const float t = 408;
const float base_d = 162;

float wheel_c = wheel_d * 3.14;
float tpm= 408/wheel_c;

float base_c = base_d * 3.14;
float one_degree_arc = 509/360;
float ticks_per_degree = tpm * one_degree_arc;


void setup() {
  pinMode(M11, OUTPUT);
  pinMode(M12, OUTPUT);
  pinMode(M21, OUTPUT);
  pinMode(M22, OUTPUT);
  pinMode(AE1, INPUT);
  pinMode(BE1, INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(AE1), left, RISING); 
  attachInterrupt(digitalPinToInterrupt(BE2), right, RISING); 



}
void loop(){};

  void left(){
   distance++;
   Serial.print("Distance in mm: ");   
   float mili = distance / 6.18;
   Serial.println(mili);
   if (mili < 25){
     analogWrite(M12, 105);    
     }
   else
     analogWrite(M12, 0); 
  }
  
  void right(){
   distance++;
   Serial.print("Distance in mm2: ");
   float mili2 = distance / 6.18;
   Serial.println(mili2);
   if (mili2 < 25){
     analogWrite(M21, 103);    
     }
   else
     analogWrite(M21, 0); }

 
 
