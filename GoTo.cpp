// Navigation

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>      /* printf */
#include <math.h>
using namespace std;

// radian to degree
double rtod(double rad){
    double deg = 0;
    deg = rad * 57.2958;
return deg;
}
// degree to radian
double dtor(double deg){
    double rad = 0;
    rad = deg / 57.2958;
return rad;
}

// over all psudo
// check if at destination
// figure out where going to
// call GoTo
// if stand still GoTo=robot // no because will normalize to max need way to make it set velo to ==0,0,0



// go to function
void GoTo(double destination[3]){
    const double error = 1; // units? // get this close before return (at destination)
    // should we even stop fussing as long as we keep calling this

    if(destination[0]-robot[0]+destination[1])
}




// robot x y theta (0 = pointing +y) clock wise is +
//enemy robot xy
//ball xy
//destination xytheta(make just xy version?) how get theta that will never happen?

double robot[3]={0,0,dtor(45)};
double enemy[2]={0,0};
double ball[2]={0,0};
double ballVelo[2]={0,0};

double destination[3]={0,0,0};
double dtranslation[3]={0,0,0};
// left wall bottom wall right wall, top wall
//xy, xy
int walls[4]={0,0,100,100};

// from the robot control
    double velo[3]={0,0,0};
    double motor[4]= {0,0,0,0};
    double norm = 0;


int main(){
    cout<<"Input direction x y theta"<<endl;
cin>>destination[0];
cin>>destination[1];
cin>>destination[2];

//----------------------------------------------------------------------------------------------------
//Go to xy
// translate and strafe to xy
// y coordinate(forward+ back) velocity x  cordinate (right+, left) rotation degrees (colckiwise+)
// max 255 min -255

// find dx and dy
for (int i=0; i<2;i++){
    dtranslation[i]=destination[i]-robot[i];
    cout<<"dtranlation: " << dtranslation[i] << endl;
}
// find dtheta
    dtranslation[2]=destination[2] - rtod(robot[2]);
    cout<<"dtranlation: " << dtranslation[2] << endl;

// convert to x and y to x,y prime 
//NOTE (-) is added to to bot angle relative to court because the sourced equations use a counter clock wise is (+) sense, I use clock wise is (+) sense
//https://en.wikipedia.org/wiki/Rotation_of_axes

//y
velo[0]=-(dtranslation[0]*sin(-robot[2]))+(dtranslation[1]*cos(-robot[2]));
//x
velo[1]=((dtranslation[0]*cos(-robot[2]))+(dtranslation[1]*sin((-robot[2]))));
//theta
velo[2]=dtranslation[2];


cout << "velo_x: " << velo[1]<<endl;
cout << "velo_y: " << velo[0]<<endl;
cout << "vel_theta: " << velo[2] << endl;
cout<< "robot angle: " << rtod(robot[2])<<endl;
// normalize translation?


}

// The drive function will normalize this
// how will it normalize rotation
// when input roation set it simmilar scale to max component?
// self normalize before storing? where max velues are 255?






/*
// example normalizing code **************************************
// make sure all motor values are under 255 (max input value) by scaling by max value of motor
    // normm = max element of motor
    for(int i=0; i<=3;i++){
        if(abs(motor[i])>norm){
            norm=abs(motor[i]);
        }
    }
    //divide all elements by norm to make motor array into unit vector then multiply by max value 255 to assure
    if(norm!=0 && norm>255){
        for(int i=0; i<=3;i++){
            motor[i]=motor[i]/norm;
            motor[i]=motor[i]*255;
        }
    }
    //round motor values to be an integer(floor=round down)
    for(int i=0; i<=3;i++){
        motor[i]=floor(motor[i]);
    }
// END normalizing code**************************************
*/