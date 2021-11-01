// Normalization stuff for driver code
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>      /* printf */
#include <math.h>

using namespace std;
int main(){
    // velo[1] (all in 1 direction)
    // velo [2] (front and rear wheels towards and away from eachother)
    // velo[3] (left weels + right wheels -)

    //super position but need to normalize values so max is 255
    //input value by vectors max 255 normalize them
    //Control layer (decide where want to go and controls to achieve this) (Needs feed back from sensors?)
    //1 take desired direction in x y and rotation
    //2 normalize to limit max motor vectors
    //3 Order motors
    // Psudo code
    // try  to figure out part 2
    // [255,0,0] forward all 255
    // [255,255,0] right and forward; back wheels -255 + front +255; all +255
    // motor control motors[4] Index: (clockwise top left order) 
    // motor [ (255+255), (255+255), -255, -255]
    // how to normalize this?
    // take max vector and %255 and divide all by that
    //
    // norm=motor(MAX(motor))%255 // nomralization value = motor(inxex of max of motor)
    // motor = motor./norm

    int velo[3]={0,0,0};
    double motor[4]= {0,0,0,0};
    double norm = 0;

    //input forward & right
    velo[0]=-255;
    velo[1]=-255;
    velo[2]=-255;
    // find motor values
    // try  to figure out part 2
    // [255,0,0] forward all 255
    // [255,255,0] right and forward; back wheels -255 + front +255; all +255
    // motor control motors[4] Index: (clockwise top left order) 
    // motor [ (255+255), (255+255), -255, -255]
    // how to normalize this?
    // take max vector and %255 and divide all by that

    //front left
    motor[0]=velo[0]+velo[1]+velo[2];
    //front right
    motor[1]=velo[0]-velo[1]-velo[2];
    //back right
    motor[2]=velo[0]+velo[1]-velo[2];
    //back left
    motor[3]=velo[0]-velo[1]+velo[2];

    for(int i=0; i<=3;i++){
        cout << "motor[" << i << "] " << motor[i]<< endl;
    }

    // normm = max element of motor
    for(int i=0; i<=3;i++){
        if(abs(motor[i])>norm){
            norm=abs(motor[i]);
        }
    }
    cout<<"norm: " << norm << endl;
    //cout<<"motor mod: " << motor[0]%norm<<endl;
    if(norm!=0&& norm>255){
        for(int i=0; i<=3;i++){
            motor[i]=motor[i]/norm;
            motor[i]=motor[i]*255;
        }
    }
    
    for(int i=0; i<=3;i++){
        motor[i]=floor(motor[i]);
        cout << "motorfloor[" << i << "] " << motor[i]<< endl;
    }
}
