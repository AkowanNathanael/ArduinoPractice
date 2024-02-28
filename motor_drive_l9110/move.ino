void stopnow(){
  digitalWrite(in1,0);
  digitalWrite(in2,0);
  digitalWrite(in3,0);
  digitalWrite(in3,0);
}

void forw(){
  digitalWrite(in1,1);
  digitalWrite(in2,0);
  digitalWrite(in3,1);
  digitalWrite(in4,0);
}

void back(){
  digitalWrite(in1,0);
  digitalWrite(in2,1);
  digitalWrite(in3,0);
  digitalWrite(in4,1);
}


void fleft(){
  digitalWrite(in1,0);
  digitalWrite(in2,0);
  digitalWrite(in3,0);
  digitalWrite(in4,1);
}

void bleft(){
  digitalWrite(in1,0);
  digitalWrite(in2,0);
  digitalWrite(in3,1);
  digitalWrite(in4,0);
}

void fright(){
  digitalWrite(in1,1);
  digitalWrite(in2,0);
  digitalWrite(in3,0);
  digitalWrite(in3,0);
}

void bright(){
  digitalWrite(in1,0);
  digitalWrite(in2,1);
  digitalWrite(in3,0);
  digitalWrite(in3,0);
}


//
void forwardx(){
  digitalWrite(in1,1);
 digitalWrite(in2,0);
}

void backwardx(){
  digitalWrite(in1,0);
 digitalWrite(in2,1);
}

void forward(int x,int in1,int in2){
  analogWrite(in1,x);
  analogWrite(in2,0);
}
void backward(int x,int in1,int in2){
  analogWrite(in1,0);
  analogWrite(in2,x);
}
