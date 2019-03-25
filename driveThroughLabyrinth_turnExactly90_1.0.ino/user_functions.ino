void recognizeBlack(){

  isBlack == false;
  
  int lr = readLight(lightRight);
  int ll = readLight(lightLeft);

  if (lr > blackValue or ll > blackValue){
    isBlack == true;
  }

}

//======================================================================================================================================================

void stopFor(int timeForStop){
  stoppedTime = 0;
  
  while(stoppedTime <= timeForStop){
    timer.update();
  }
}

 void prStr(String text){
  lcd.backlight();
  lcd.setCursor(0, line);
  lcd.print(text);
  
  line++;

  if (line == 4) newDis();
  
}

 void prInt(double text){

  lcd.backlight();
  lcd.setCursor(0, line);
  lcd.print(text);
  
  line++;

  //if (line == 4) newDis();

}

void newDis(){
  lcd.clear();
  line = 0;
}
