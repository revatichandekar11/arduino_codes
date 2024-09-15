
void navigation()
{
  if(ly<Buff1 && ly>Buff2 && lx>BuffP && lx<BuffN && ll2==0 && rr2==0 && ly>BuffP && ly<BuffN && lx<Buff1 && lx>Buff2)
  stopmotor();
  else
  {
//forward
  if(lx>=0 && lx<=BuffP && lx>=BuffN && ly<=127 && ly>=Buff1)
  {
    map(Buff1,127,0,255,ms);
    forward();
   
  }
  //backward
else if(lx>=0 && lx<=BuffP && lx>=BuffN && ly>=-128 && ly<=Buff2)
  {
    map(-128,Buff2,0,255,ms);
    backward();

  }
  //right
 else if(ly>=0 && ly<=BuffP && ly>=BuffN && lx<=127 && lx>=Buff1)
  {
    map(Buff1,127,0,255,ms);
    rightm();
  } 
   //left
 else if(ly>=0 && ly<=BuffP && ly>=BuffN && lx>=-128 && lx<=Buff2)
  {
    map(-128,Buff2,0,255,ms);
    leftm();
  } 

  //clockwise
  if(ll2>0 && ll2<=1)
  {
    map(0,1,0,255,ms);
    clockwise();
  }
  //anticlockwise
  else if(rr2>0 && rr2<=1)
  {
    map(0,1,0,255,ms);
    anticlockwise();
  }
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

