int rosso;
int giallo;
int bianco;
int verde;
int durataSpegnimento;

void setup() {
  rosso = 10;
  giallo = 8;
  bianco = 6;
  verde = 4;
  
  pinMode (rosso, OUTPUT);
  pinMode (giallo, OUTPUT);
  pinMode (bianco, OUTPUT);
  pinMode (verde, OUTPUT);

  Serial.begin(9600);
  durataSpegnimento = seriale("Quanto vuoi che stiano spenti i led? (UNITà DI MISURA = MS)", durataSpegnimento);
}

int seriale(String s, int i){
  Serial.println(s);
  while (Serial.available()==0){};
  i = Serial.readString().toInt();
  return i;
  }

void contemporanea(){
  digitalWrite(rosso, HIGH);
  digitalWrite(giallo, HIGH);
  digitalWrite(bianco, LOW);
  digitalWrite(verde, LOW);
  delay(durataSpegnimento);

  digitalWrite(rosso, LOW);
  digitalWrite(giallo, LOW);
  digitalWrite(bianco, HIGH);
  digitalWrite(verde, HIGH);
  delay(durataSpegnimento);
}

  
void loop() {
  contemporanea();
}
