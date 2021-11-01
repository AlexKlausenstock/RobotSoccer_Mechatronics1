
// move motors
// takes velo in and moves motors
// can't run as function since need pwm write to work all the time

// robot control
int velo[3]={0,0,0};
double motor[4]= {0,0,0,0};
double norm = 0;

double robot[3]={0,0,dtor(45)};
double enemy[2]={0,0};
double ball[2]={0,0};
double ballVelo[2]={0,0};

double destination[3]={0,0,0};
double dtranslation[3]={0,0,0};

// left wall bottom wall right wall, top wall
//xy, xy
int walls[4]={0,0,100,100};
