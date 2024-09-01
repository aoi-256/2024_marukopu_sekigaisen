double sekigaisen_value;

void setup() {

  Serial.begin(115200);

  pinMode(2,INPUT); 
  pinMode(4,OUTPUT);
  delay(500);//初期化待ち（一応）

}

void loop() {
   
  sekigaisen_value = analogRead(A12);//ADC12のアナログ変換値を取得

  //Serial.println(sekigaisen_value); //アナログ変換値を出力(デバッグ用）

  
  if(sekigaisen_value >= 3500.0){

    digitalWrite(4, HIGH);  

    //赤外線を検知した場合、すぐに消えてしまうとLEDが光っているかを見れないので、ちょっとだけつけっぱなしにする
    delay(1000)

  }
  else{

    digitalWrite(4, LOW);

  }
}
