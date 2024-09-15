void navigation()
{
  // if(ly<Buff1 && ly>Buff2 && lx>BuffP && lx<BuffN||ly>BuffP && ly<BuffN && lx<Buff1 && lx>Buff2||rx<Buff1 && rx>Buff2 && ry<BuffN && ry>BuffP)
  // stopmotor();
//  if(ll1==1)
//  stopmotor();
  if((ly>=-128 && ly<=127||lx>=-128 && lx<=127||rx>=-128 && rx<=127) && (ly>=Buff1||ly<=Buff2||lx<=Buff2||lx>=Buff1||rx>Buff1||rx<Buff2))
  {
//forward
  if( ly>=Buff1 && (lx<=BuffP && lx>=BuffN) )
  {
    
    forward();
   
  }
  //backward
else if(ly<=Buff2 && (lx<=BuffP && lx>=BuffN) )
  {
    
    backward();

  }
  //right
 else if(lx>=Buff1 && (ly<=BuffP && ly>=BuffN))
  {
    
    rightm();
  } 
   //left
 else if(lx<=Buff2 && (ly<=BuffP && ly>=BuffN)  )
  {
    
    leftm();
  } 

  //clockwise
  if(rx>Buff1 && (ry>BuffN && ry<BuffP))
  {
    
    clockwise();
  }
  //anticlockwise
  else if(rx<Buff2 && (ry>BuffN && ry<BuffP))
  {
    
    anticlockwise();
  }
  } 
else{
  stopmotor();
}

}
 

  // if(ll2==0||rr2==0)
  // stopmotor();
  
  // //clockwise
  // if(ll2>0 && ll2<=1)
  // {
  //   map(0,1,0,255,ms);
  //   clockwise();
  // }
  // //anticlockwise
  // else if(rr2>0 && rr2<=1)
  // {
  //   map(0,1,0,255,ms);
  //   anticlockwise();
  // }
  // }

