int joy_x = 0; 
int joy_y = 1; 
int xval; 
int yval; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
}

void loop() {
  // put your main code here, to run repeatedly:

  xval = analogRead(joy_x); 
  yval = analogRead(joy_y);

  if(yval < 200) //for moving fwd
  {
    Serial.write('0');
  }

  else if(yval > 900) //for moving bckwd
  {
    Serial.write('1'); 
  }

  else if(xval > 900) //for moving right
  {
    Serial.write('2'); 
  }

  else if(xval < 200) //for moving left
  {
    Serial.write('3'); 
  }

  else //for all other cases, don't move. 
  {
    Serial.write('4'); 
  }

  
}
