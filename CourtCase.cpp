//Alex Klausenstock
//Determine court condition

//cases:
//A
//Have Ball
//Don't have ball
//B
//Blocked
//Un Blocked
//C enemy hass ball???

// code to determine this:
// A Have ball?
// if delta xy ball vs robot && (is robot pointing at ball?)
// fringe case, competing with enemy for ball Deal witht these cases later***

//B 
// Check A
// make vecotr of all xy between robot and (goal or ball depending on A)
// if enemy in that vector
// maybe to avoid issues with rounding and making array maybe make line eq and see if criteria satisfy it
// like if  y=mx+b but point form and both ball and  enemy satisfy same slope?
// check if behind ball as opposed to infront of?


//If Don't have ball && Un blocked
//go to ball
//(go to location that would push towards goal)



//If have ball && unblocked
//push ball to goal
//avoid enemy?

// If 

