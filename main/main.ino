#include <cstdlib>
#include <ctime>
//#include <Servo.h>

int chessboard[64] = {11,12,13,14,15,16,17,18,
                       21,22,23,24,25,26,27,28,
                       0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,
                       31,32,33,34,35,36,37,38,
                       41,42,43,44,45,46,47,48};
/*Servo servo1;
Servo servo2;*/
int stepsFromBeginning;

class move{
  public:
    int startSquare;
    int endSquare;
    int endValue=chessboard[endSquare];
    int startValue=chessboard[startSquare];
    void makeMove(){
      chessboard[endSquare]=chessboard[startSquare];
      chessboard[startSquare]=0;
    }
    void unmakeMove(){
      chessboard[startSquare]=startValue;
      chessboard[endSquare]=endValue;
    }
};
void playFirst(){
  int pieceLocation;
  for(int i=0; i==1; i){
    srand(time(0));
    pieceLocation = rand()%64;
    int piece = chessboard[pieceLocation];
    if(piece > 30){
        i=1;
    }
  }
  move movetoPlay = generateMoves(pieceLocation);


  /*int piece = chessboard[pieceId];
  if(piece == 41 || piece == 48) {
    for (int i =0; i==1;i){
      int xPosition = random
    }
  }*/
}
int checkSquare(int square){
  if(chessboard[square]<30 && chessboard[square]!=0){
    return 1;
  }
  else if(chessboard[square]>30){
    return 2;
  }
  else{
    return 0;
  }
}
move generateMoves(int pieceLocation){
  int moves[40][2];
  int piece=chessboard[pieceLocation];
  int xCoordinate=(pieceLocation % 8);
  int yCoordinate=(pieceLocation / 8);
  int tempX;
  int tempY;
  int tempLocation;
  int numberofMoves=0;
  int squareValue=checkSquare(pieceLocation);
  if(piece==41||piece==48||piece==11||piece==18){
    for(int x=xCoordinate+1; x<8; x++){
      tempLocation=(yCoordinate*8+x);
      if(squareValue==checkSquare(tempLocation)){
        break;
      }
      moves[numberofMoves][0]=tempLocation;
      numberofMoves+=1;
      if(checkSquare(tempLocation) != 0){
        break;
      }
    }
    for(int x=xCoordinate-1; x >= 0; x--){
      tempLocation=(yCoordinate*8+x);
      if(squareValue==checkSquare(tempLocation)){
        break;
      }
      moves[numberofMoves][0]=tempLocation;
      numberofMoves+=1;
      if(checkSquare(tempLocation) != 0){
        break;
      }
    }
    for(int y=yCoordinate+1; y<8; y++){
      tempLocation=(y*8+xCoordinate);
      if(squareValue==checkSquare(tempLocation)){
        break;
      }
      moves[numberofMoves][0]=tempLocation;
      numberofMoves+=1;
      if(checkSquare(tempLocation) != 0){
        break;
      }
    }
    for(int y=yCoordinate-1; y >= 0; y--){
      tempLocation=(y*8+xCoordinate);
      if(squareValue==checkSquare(tempLocation)){
        break;
      }
      moves[numberofMoves][0]=tempLocation;
      numberofMoves+=1;
      if(checkSquare(tempLocation) != 0){
        break;
      }
    }
  }
  if(piece==43||piece==46||piece==13||piece==16){
    for(int x=xCoordinate+1, y=yCoordinate+1; x<8 && y<8; x++, y++){
      tempLocation=(y*8+x);
      if(squareValue==checkSquare(tempLocation)){
        break;
      }
      moves[numberofMoves][0]=tempLocation;
      numberofMoves+=1;
      if(checkSquare(tempLocation) != 0){
        break;
      }
    }
    for(int x=xCoordinate+1, y=yCoordinate-1; x<8 && y >= 0; x++, y--){
      tempLocation=(y*8+x);
      if(squareValue==checkSquare(tempLocation)){
        break;
      }
      moves[numberofMoves][0]=tempLocation;
      numberofMoves+=1;
      if(checkSquare(tempLocation) != 0){
        break;
      }
    }
    for(int x=xCoordinate-1, y=yCoordinate+1; x >= 0 && y<8; x--, y++){
      tempLocation=(y*8+x);
      if(squareValue==checkSquare(tempLocation)){
        break;
      }
      moves[numberofMoves][0]=tempLocation;
      numberofMoves+=1;
      if(checkSquare(tempLocation) != 0){
        break;
      }
    }
    for(int x=xCoordinate-1, y=yCoordinate-1; x >= 0 && y >= 0; x--, y--){
      tempLocation=(y*8+x);
      if(squareValue==checkSquare(tempLocation)){
        break;
      }
      moves[numberofMoves][0]=tempLocation;
      numberofMoves+=1;
      if(checkSquare(tempLocation) != 0){
        break;
      }
    }
  }
  if(piece==42||piece==47||piece==12||piece==17){
    int x = xCoordinate + 2;
    int y = yCoordinate + 1;
    tempLocation = y*8+x;
    if(xCoordinate < 6 && yCoordinate < 7){
      if(squareValue != checkSquare(tempLocation)){
        moves[numberofMoves][0]=tempLocation;
        numberofMoves += 1;
      }
    }
    x = xCoordinate + 2;
    y = yCoordinate - 1;
    tempLocation = y*8+x;
    if(xCoordinate < 6 && yCoordinate > 0){
      if(squareValue != checkSquare(tempLocation)){
        moves[numberofMoves][0]=tempLocation;
        numberofMoves += 1;
      }
    }
    x = xCoordinate - 2;
    y = yCoordinate + 1;
    tempLocation = y*8+x;
    if(xCoordinate > 1 && yCoordinate < 7){
      if(squareValue != checkSquare(tempLocation)){
        moves[numberofMoves][0]=tempLocation;
        numberofMoves += 1;
      }
    }
    x = xCoordinate - 2;
    y = yCoordinate - 1;
    tempLocation = y*8+x;
    if(xCoordinate > 1 && yCoordinate > 0){
      if(squareValue != checkSquare(tempLocation)){
        moves[numberofMoves][0]=tempLocation;
        numberofMoves += 1;
      }
    }
    x = xCoordinate + 1;
    y = yCoordinate + 2;
    tempLocation = y*8+x;
    if(xCoordinate < 7 && yCoordinate < 6){
      if(squareValue != checkSquare(tempLocation)){
        moves[numberofMoves][0]=tempLocation;
        numberofMoves += 1;
      }
    }
    x = xCoordinate - 1;
    y = yCoordinate + 2;
    tempLocation = y*8+x;
    if(xCoordinate > 0 && yCoordinate < 6){
      if(squareValue != checkSquare(tempLocation)){
        moves[numberofMoves][0]=tempLocation;
        numberofMoves += 1;
      }
    }
    x = xCoordinate + 1;
    y = yCoordinate - 2;
    tempLocation = y*8+x;
    if(xCoordinate < 7 && yCoordinate > 1){
      if(squareValue != checkSquare(tempLocation)){
        moves[numberofMoves][0]=tempLocation;
        numberofMoves += 1;
      }
    }
    x = xCoordinate - 1;
    y = yCoordinate - 2;
    tempLocation = y*8+x;
    if(xCoordinate > 0 && yCoordinate > 1){
      if(squareValue != checkSquare(tempLocation)){
        moves[numberofMoves][0]=tempLocation;
        numberofMoves += 1;
      }
    }
  }
  if(piece==14||piece==44){
    for(int x=xCoordinate+1; x<8; x++){
      tempLocation=(yCoordinate*8+x);
      if(squareValue==checkSquare(tempLocation)){
        break;
      }
      moves[numberofMoves][0]=tempLocation;
      numberofMoves+=1;
      if(checkSquare(tempLocation) != 0){
        break;
      }
    }
    for(int x=xCoordinate-1; x >= 0; x--){
      tempLocation=(yCoordinate*8+x);
      if(squareValue==checkSquare(tempLocation)){
        break;
      }
      moves[numberofMoves][0]=tempLocation;
      numberofMoves+=1;
      if(checkSquare(tempLocation) != 0){
        break;
      }
    }
    for(int y=yCoordinate+1; y<8; y++){
      tempLocation=(y*8+xCoordinate);
      if(squareValue==checkSquare(tempLocation)){
        break;
      }
      moves[numberofMoves][0]=tempLocation;
      numberofMoves+=1;
      if(checkSquare(tempLocation) != 0){
        break;
      }
    }
    for(int y=yCoordinate-1; y >= 0; y--){
      tempLocation=(y*8+xCoordinate);
      if(squareValue==checkSquare(tempLocation)){
        break;
      }
      moves[numberofMoves][0]=tempLocation;
      numberofMoves+=1;
      if(checkSquare(tempLocation) != 0){
        break;
      }
    }
    for(int x=xCoordinate+1, y=yCoordinate+1; x<8 && y<8; x++, y++){
      tempLocation=(y*8+x);
      if(squareValue==checkSquare(tempLocation)){
        break;
      }
      moves[numberofMoves][0]=tempLocation;
      numberofMoves+=1;
      if(checkSquare(tempLocation) != 0){
        break;
      }
    }
    for(int x=xCoordinate+1, y=yCoordinate-1; x<8 && y >= 0; x++, y--){
      tempLocation=(y*8+x);
      if(squareValue==checkSquare(tempLocation)){
        break;
      }
      moves[numberofMoves][0]=tempLocation;
      numberofMoves+=1;
      if(checkSquare(tempLocation) != 0){
        break;
      }
    }
    for(int x=xCoordinate-1, y=yCoordinate+1; x >= 0 && y<8; x--, y++){
      tempLocation=(y*8+x);
      if(squareValue==checkSquare(tempLocation)){
        break;
      }
      moves[numberofMoves][0]=tempLocation;
      numberofMoves+=1;
      if(checkSquare(tempLocation) != 0){
        break;
      }
    }
    for(int x=xCoordinate-1, y=yCoordinate-1; x >= 0 && y >= 0; x--, y--){
      tempLocation=(y*8+x);
      if(squareValue==checkSquare(tempLocation)){
        break;
      }
      moves[numberofMoves][0]=tempLocation;
      numberofMoves+=1;
      if(checkSquare(tempLocation) != 0){
        break;
      }
    }
  }
  if(piece == 45||piece == 15){
    for(int x=xCoordinate+1; x<8; x++){
      if(xCoordinate == x + 2){
        break;
      }
      tempLocation=(yCoordinate*8+x);
      if(squareValue==checkSquare(tempLocation)){
        break;
      }
      moves[numberofMoves][0]=tempLocation;
      numberofMoves+=1;
      if(checkSquare(tempLocation) != 0){
        break;
      }
      if(xCoordinate == x + 2){
        break;
      }
    }
    for(int x=xCoordinate-1; x >= 0; x--){
      if(xCoordinate == x - 2){
        break;
      }
      tempLocation=(yCoordinate*8+x);
      if(squareValue==checkSquare(tempLocation)){
        break;
      }
      moves[numberofMoves][0]=tempLocation;
      numberofMoves+=1;
      if(checkSquare(tempLocation) != 0){
        break;
      }
    }
    for(int y=yCoordinate + 1; y<8; y++){
      if(yCoordinate == y + 2){
        break;
      }
      tempLocation=(y*8+xCoordinate);
      if(squareValue==checkSquare(tempLocation)){
        break;
      }
      moves[numberofMoves][0]=tempLocation;
      numberofMoves+=1;
      if(checkSquare(tempLocation) != 0){
        break;
      }
    }
    for(int y=yCoordinate-1; y >= 0; y--){
      if(yCoordinate == y - 2){
        break;
      }
      tempLocation=(y*8+xCoordinate);
      if(squareValue==checkSquare(tempLocation)){
        break;
      }
      moves[numberofMoves][0]=tempLocation;
      numberofMoves+=1;
      if(checkSquare(tempLocation) != 0){
        break;
      }
    }
    for(int x=xCoordinate+1, y=yCoordinate+1; x<8 && y<8; x++, y++){
      if(xCoordinate == x + 2){
        break;
      }
      if(yCoordinate == x + 2){
        break;
      }
      tempLocation=(y*8+x);
      if(squareValue==checkSquare(tempLocation)){
        break;
      }
      moves[numberofMoves][0]=tempLocation;
      numberofMoves+=1;
      if(checkSquare(tempLocation) != 0){
        break;
      }
    }
    for(int x=xCoordinate+1, y=yCoordinate-1; x<8 && y >= 0; x++, y--){
      if(xCoordinate == x + 2){
        break;
      }
      if(yCoordinate == x - 2){
        break;
      }
      tempLocation=(y*8+x);
      if(squareValue==checkSquare(tempLocation)){
        break;
      }
      moves[numberofMoves][0]=tempLocation;
      numberofMoves+=1;
      if(checkSquare(tempLocation) != 0){
        break;
      }
    }
    for(int x=xCoordinate-1, y=yCoordinate+1; x >= 0 && y<8; x--, y++){
      if(xCoordinate == x - 2){
        break;
      }
      if(yCoordinate == x + 2){
        break;
      }
      tempLocation=(y*8+x);
      if(squareValue==checkSquare(tempLocation)){
        break;
      }
      moves[numberofMoves][0]=tempLocation;
      numberofMoves+=1;
      if(checkSquare(tempLocation) != 0){
        break;
      }
    }
    for(int x=xCoordinate-1, y=yCoordinate-1; x >= 0 && y >= 0; x--, y--){
      if(xCoordinate == x - 2){
        break;
      }
      if(yCoordinate == x - 2){
        break;
      }
      tempLocation=(y*8+x);
      if(squareValue==checkSquare(tempLocation)){
        break;
      }
      moves[numberofMoves][0]=tempLocation;
      numberofMoves+=1;
      if(checkSquare(tempLocation) != 0){
        break;
      }
    }
  }
  if(piece > 20 && piece < 39){
    for(int x = 0; x < 1; x++){
      if(yCoordinate == 1){
        tempLocation = (yCoordinate+1)*8+xCoordinate;
        if(checkSquare(tempLocation) != 0){
          break;
        }
        else{
          moves[numberofMoves][0] = tempLocation;
          numberofMoves += 1;
          break;
        }
      }
      if(yCoordinate == 6){
        tempLocation = (yCoordinate-1)*8+xCoordinate;
        if(checkSquare(tempLocation) != 0){
          break;
        }
        else{
          moves[numberofMoves][0] = tempLocation;
          numberofMoves += 1;
          break;
        }
      }
    }
  }
  srand(time(0));
  move movetoPlay;
  movetoPlay.startSquare = pieceLocation;
  movetoPlay.endSquare = moves[rand() % (sizeof(moves) + 1)][0];
  return movetoPlay;
}
float evaluatePosition(int board[64]){
  //piece evaluation
  int evaluationScore = 0;
  int whiteScore;
  int blackScore;
  int rookStat[64] = {0,10,20,20,20,10,10,0,
                       15,20,20,20,20,20,20,15,
                       20,20,20,20,20,20,20,20,
                       20,20,20,20,20,20,20,20,
                       25,25,25,25,25,25,25,25,
                       25,25,25,25,25,25,25,25,
                       40,40,40,40,40,40,40,40,
                       45,45,45,45,45,45,45,45};
    int bishopStat[64] = {30,20,10,0,0,10,20,30,
                       20,30,20,10,10,20,30,20,
                       0,20,30,20,20,30,20,0,
                       0,10,20,30,30,20,10,0,
                       0,10,20,30,30,20,10,0,
                       0,20,30,20,20,30,20,0,
                       20,30,20,10,10,20,30,20,
                       30,20,10,0,0,10,20,30};
    int knightStat[64] = {0,0,0,0,0,0,0,0,
                       0,5,5,10,10,5,5,0,
                       0,10,20,15,15,20,10,0,
                       0,10,20,25,25,20,10,0,
                       0,10,20,25,25,20,10,0,
                       0,10,20,20,20,20,10,0,
                       0,5,5,10,10,5,5,0,
                       0,0,0,0,0,0,0,0};
    int pawnStat[64] = {0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,
                       5,5,5,5,5,5,5,5,
                       10,10,10,10,10,10,10,10,
                       30,30,30,30,30,30,30,30,
                       40,40,40,40,40,40,40,40,
                       200,200,200,200,200,200,200,200};
    int kingStat[64] = {10,10,10,10,10,10,10,10,
                       15,15,15,15,15,15,15,15,
                       10,10,10,10,10,10,10,10,
                       5,5,5,5,5,5,5,5,
                       0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0};
    int queenStat[64] = {0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,
                       15,15,15,15,15,15,15,15,
                       20,20,20,20,20,20,20,20,
                       30,30,30,30,30,30,30,30,
                       40,40,40,40,40,40,40,40};
  for (int i=0; i<64;i++){
    if (chessboard[i] == 11){
      whiteScore += 500;
      whiteScore += rookStat[i];
    }
    if (chessboard[i] == 12){
      whiteScore += 300;
      whiteScore += knightStat[i];
    }
    if (chessboard[i] == 13){
      whiteScore += 300;
      whiteScore += bishopStat[i];
    }
    if (chessboard[i] == 14){
      whiteScore += 10000;
      whiteScore += kingStat[i];
    }
    if (chessboard[i] == 15){
      whiteScore += 900;
      whiteScore += queenStat[i];
    }
    if (chessboard[i] == 16){
      whiteScore += 300;
      whiteScore += bishopStat[i];
    }
    if (chessboard[i] == 17){
      whiteScore += 300;
      whiteScore += knightStat[i];
    }
    if (chessboard[i] == 18){
      whiteScore += 500;
      whiteScore += rookStat[i];
    }
    if (chessboard[i] == 21){
      whiteScore += 100;
      whiteScore += pawnStat[i];
    }
    if (chessboard[i] == 22){
      whiteScore += 100;
      whiteScore += pawnStat[i];
    }
    if (chessboard[i] == 23){
      whiteScore += 100;
      whiteScore += pawnStat[i];
    }
    if (chessboard[i] == 24){
      whiteScore += 100;
      whiteScore += pawnStat[i];
    }
    if (chessboard[i] == 25){
      whiteScore += 100;
      whiteScore += pawnStat[i];
    }
    if (chessboard[i] == 26){
      whiteScore += 100;
      whiteScore += pawnStat[i];
    }
    if (chessboard[i] == 27){
      whiteScore += 100;
      whiteScore += pawnStat[i];
    }
    if (chessboard[i] == 28){
      whiteScore += 100;
      whiteScore += pawnStat[i];
    }
    if (chessboard[i] == 41){
      blackScore += 500;
      blackScore += rookStat[(63-i)];
    }
    if (chessboard[i] == 42){
      blackScore += 300;
      blackScore += knightStat[(63-i)];
    }
    if (chessboard[i] == 43){
      blackScore += 300;
      blackScore += bishopStat[(63-i)];
    }
    if (chessboard[i] == 44){
      blackScore += 10000;
      blackScore += kingStat[(63-i)];
    }
    if (chessboard[i] == 45){
      blackScore += 900;
      blackScore += queenStat[(63-i)];
    }
    if (chessboard[i] == 46){
      blackScore += 300;
      blackScore += bishopStat[(63-i)];
    }
    if (chessboard[i] == 47){
      blackScore += 300;
      blackScore += knightStat[(63-i)];
    }
    if (chessboard[i] == 48){
      blackScore += 500;
      blackScore += rookStat[(63-i)];
    }
    if (chessboard[i] == 31){
      blackScore += 100;
      blackScore += pawnStat[(63-i)];
    }
    if (chessboard[i] == 32){
      blackScore += 100;
      blackScore += pawnStat[(63-i)];
    }
    if (chessboard[i] == 33){
      blackScore += 100;
      blackScore += pawnStat[(63-i)];
    }
    if (chessboard[i] == 34){
      blackScore += 100;
      blackScore += pawnStat[(63-i)];
    }
    if (chessboard[i] == 35){
      blackScore += 100;
      blackScore += pawnStat[(63-i)];
    }
    if (chessboard[i] == 36){
      blackScore += 100;
      blackScore += pawnStat[(63-i)];
    }
    if (chessboard[i] == 37){
      blackScore += 100;
      blackScore += pawnStat[(63-i)];
    }
    if (chessboard[i] == 38){
      blackScore += 100;
      blackScore += pawnStat[(63-i)];
    }
    }
    evaluationScore=(whiteScore - blackScore)/100;
    return evaluationScore;
}
void playMechanically(move movetoPlay){
  float servoAngle[64][2] = {};
  int stepsFromDefault[64][2] = {};

  /*servo1.write(servoAngle[movetoPlay.startSquare][0]);
  servo2.write(servoAngle[movetoPlay.startSquare][1]);*/
}

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
