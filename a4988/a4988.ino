const int SW_R = 4;
const int SW_L = 5;

const int DIR  = 8;
const int STEP = 9;

int i = 0;
int val_R = 0;
int val_L = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(SW_R, INPUT);
  pinMode(SW_L, INPUT);
  
  pinMode(DIR, OUTPUT);
  pinMode(STEP, OUTPUT);
  
  digitalWrite(DIR, LOW);
  digitalWrite(STEP, LOW);
}

void step(){
  for(i = 0; i <= 400; i++){
    digitalWrite(STEP, HIGH);
    delayMicroseconds(2000);
    digitalWrite(STEP, LOW);
    delayMicroseconds(2000);
  }
}

void loop() {
  val_R = digitalRead(SW_R);
  val_L = digitalRead(SW_L);
   
  if(val_R == HIGH && val_L == HIGH){
    Serial.print("STOP \n");
  }
  else if(val_R == HIGH){
    digitalWrite(DIR, LOW);
    Serial.print("R \n");

    step();
  }
  else if(val_L == HIGH){
    digitalWrite(DIR, HIGH);
    Serial.print("L \n");
    
    step();
  }
}