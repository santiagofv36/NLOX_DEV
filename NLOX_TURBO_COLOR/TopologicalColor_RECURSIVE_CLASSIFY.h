#define Legacy "2"
#define N "0"

#procedure DefineTopologies

#if (`Legacy'==0)||(`Legacy'==1)
CF FFLink(symmetric);
#else
CF FFLink;
#endif
CF FNode;
auto s x,y;

#endprocedure


#procedure TFToChain


#do i=1,10
id once cOlf(?args) = FNode(?args,`i');
#enddo;

repeat;
id FNode(cOla1?!{cOla0},cOla2?,cOla3?,x1?)*FNode(cOla1?,cOla4?,cOla5?,x2?) = FFLink(x1,x2,1,1)*FNode(cOla0,cOla2,cOla3,x1)*FNode(cOla0,cOla4,cOla5,x2);
id FNode(cOla1?!{cOla0},cOla2?,cOla3?,x1?)*FNode(cOla4?,cOla1?,cOla5?,x2?) = FFLink(x1,x2,1,2)*FNode(cOla0,cOla2,cOla3,x1)*FNode(cOla4,cOla0,cOla5,x2);
id FNode(cOla1?!{cOla0},cOla2?,cOla3?,x1?)*FNode(cOla4?,cOla5?,cOla1?,x2?) = FFLink(x1,x2,1,3)*FNode(cOla0,cOla2,cOla3,x1)*FNode(cOla4,cOla5,cOla0,x2);

id FNode(cOla2?,cOla1?!{cOla0},cOla3?,x1?)*FNode(cOla4?,cOla1?,cOla5?,x2?) = FFLink(x1,x2,2,2)*FNode(cOla2,cOla0,cOla3,x1)*FNode(cOla4,cOla0,cOla5,x2);
id FNode(cOla2?,cOla1?!{cOla0},cOla3?,x1?)*FNode(cOla4?,cOla5?,cOla1?,x2?) = FFLink(x1,x2,2,3)*FNode(cOla2,cOla0,cOla3,x1)*FNode(cOla4,cOla5,cOla0,x2);

id FNode(cOla2?,cOla3?,cOla1?!{cOla0},x1?)*FNode(cOla4?,cOla5?,cOla1?,x2?) = FFLink(x1,x2,3,3)*FNode(cOla2,cOla3,cOla0,x1)*FNode(cOla4,cOla5,cOla0,x2);

id FFLink(x1?,x2?,x3?,x4?)*FFLink(x1?,x2?,x5?,x6?)*FFLink(x1?,x2?,x7?,x8?) = NA*NC;
id FFLink(x1?,x2?,x11?,x12?)*FFLink(x1?,x2?,x13?,x14?)*FFLink(x1?,x3?,x15?,x16?)*FFLink(x2?,x4?,x17?,x18?) = NC*FFLink(x3,x4,x16,x18);
id FFLink(x1?,x2?,x11?,x12?)*FFLink(x1?,x2?,x13?,x14?)*FFLink(x1?,x3?,x15?,x16?)*FFLink(x4?,x2?,x18?,x17?) = NC*FFLink(x3,x4,x16,x18);
id FFLink(x1?,x2?,x11?,x12?)*FFLink(x1?,x2?,x13?,x14?)*FFLink(x3?,x1?,x16?,x15?)*FFLink(x4?,x2?,x18?,x17?) = NC*FFLink(x3,x4,x16,x18);
endrepeat;



#do i=1,10
    #do j=`i'+1,10
        id FFLink(`j',`i',x1?,x2?) = FFLink(`i',`j',x2,x1);
    #enddo
#enddo

id FNode(cOla0,cOla0,cOla0,x1?) = 1;





.sort 
CF FrozenFFLink;
S Inconsistent,Left,Replaced;
CF Who,Consistency;
*id once FFLink(1,?args) = FrozenFFLink(1,?args);
*id FFLink(?args) = FFLink(?args)*Left;
.sort
#$Done = 0;
#$Start = 1;
*#call RecurseClassify(`$Start')
#call LexicographicalOrder2

#endprocedure


#procedure LexicographicalOrder

.sort
s dummy,torep;
#do i=1,10
    #do j=`i'+1,10
        id FFLink(`i',`j',x1?,x2?) = FFLink(y`i',y`j',x2,x1);
    #enddo
#enddo

id once FFLink(y1,x1?,?args1)*FFLink(y1,x2?,?args2)*FFLink(y1,x3?,?args3) = replace_(x1,y2)*replace_(x2,y3)*replace_(x3,y4)*FFLink(y1,x1,?args1)*FFLink(y1,x2,?args2)*FFLink(y1,x3,?args3);

id once FFLink(y2,y4,?args1) = torep*replace_(y3,dummy)*FFLink(y2,y4,?args1); 
id once torep = torep*replace_(y4,y3);
id once torep = replace_(dummy,y4);

id once FFLink(y2,x1?!{y3,y4},?args1) = replace_(x1,y5)*FFLink(y2,x1,?args1);
id once FFLink(y2,x1?!{y3,y4,y5},?args1) = replace_(x1,y6)*FFLink(y2,x1,?args1);


#endprocedure 


#procedure LexicographicalOrder2

.sort
CF myep;
#do i=1,10
    #do j=`i'+1,10
        id FFLink(`i',`j',x1?,x2?) = FFLink(N`i'_?,N`j'_?,x2,x1);
    #enddo
#enddo
        
renumber 0;

#do i=1,10
    #do j=`i'+1,10
        id FFLink(N`j'_?,N`i'_?,x1?,x2?) = FFLink(N`i'_?,N`j'_?,x2,x1);
    #enddo
#enddo

#do i=1,10
    #do j=`i'+1,10
        id FFLink(N`i'_?,N`j'_?,x1?,x2?) = FFLink(`i',`j',x2,x1);
    #enddo
#enddo


#do i=1,10
    #do j=`i'+1,10
        #do k=`j'+1,10
        
id once FFLink(x1?,`i',x11?!{x0},x21?)*FFLink(x1?,`j',x12?!{x0},x32?)*FFLink(x1?,`k',x13?!{x0},x43?) = myep(x11,x12,x13)*FFLink(x1,`i',x0,x21)*FFLink(x1,`j',x0,x32)*FFLink(x1,`k',x0,x43);
id once FFLink(x1?,`i',x11?!{x0},x21?)*FFLink(x1?,`j',x12?!{x0},x32?)*FFLink(`k',x1?,x43?,x13?!{x0}) = myep(x11,x12,x13)*FFLink(x1,`i',x0,x21)*FFLink(x1,`j',x0,x32)*FFLink(`k',x1,x43,x0);

id once FFLink(x1?,`i',x11?!{x0},x21?)*FFLink(`j',x1?,x32?,x12?!{x0})*FFLink(x1?,`k',x13?!{x0},x43?) = myep(x11,x12,x13)*FFLink(x1,`i',x0,x21)*FFLink(`j',x1,x32,x0)*FFLink(x1,`k',x0,x43);
id once FFLink(x1?,`i',x11?!{x0},x21?)*FFLink(`j',x1?,x32?,x12?!{x0})*FFLink(`k',x1?,x43?,x13?!{x0}) = myep(x11,x12,x13)*FFLink(x1,`i',x0,x21)*FFLink(`j',x1,x32,x0)*FFLink(`k',x1,x43,x0);

id once FFLink(`i',x1?,x21?,x11?!{x0})*FFLink(x1?,`j',x12?!{x0},x32?)*FFLink(x1?,`k',x13?!{x0},x43?) = myep(x11,x12,x13)*FFLink(`i',x1,x21,x0)*FFLink(x1,`j',x0,x32)*FFLink(x1,`k',x0,x43);
id once FFLink(`i',x1?,x21?,x11?!{x0})*FFLink(x1?,`j',x12?!{x0},x32?)*FFLink(`k',x1?,x43?,x13?!{x0}) = myep(x11,x12,x13)*FFLink(`i',x1,x21,x0)*FFLink(x1,`j',x0,x32)*FFLink(`k',x1,x43,x0);

id once FFLink(`i',x1?,x21?,x11?!{x0})*FFLink(`j',x1?,x32?,x12?!{x0})*FFLink(x1?,`k',x13?!{x0},x43?) = myep(x11,x12,x13)*FFLink(`i',x1,x21,x0)*FFLink(`j',x1,x32,x0)*FFLink(x1,`k',x0,x43);
id once FFLink(`i',x1?,x21?,x11?!{x0})*FFLink(`j',x1?,x32?,x12?!{x0})*FFLink(`k',x1?,x43?,x13?!{x0}) = myep(x11,x12,x13)*FFLink(`i',x1,x21,x0)*FFLink(`j',x1,x32,x0)*FFLink(`k',x1,x43,x0);

        #enddo
    #enddo
#enddo

id myep(?args1) = e_(?args1);
id e_(1,2,3)=1;
id FFLink(?args1,x0,x0) = FFLink(?args1);
        
#endprocedure 




#procedure RecurseClassify(Last)
    #message >> RecurseClassify has been called!
    $Consistent=1;
    $Which = `Last';
    .sort
   #do i=1,1
    #if (`$Done' == 1)
        #breakdo
    #endif

****
****   No choice branch: here we freeze singly-open FNodes if we can do so consistently, 
****   if not we break at this level to force on a recall with different choice.
**** 
    
    id FrozenFFLink(x1?,x2?,x11?,x21?)*FrozenFFLink(x1?,x3?,x12?,x32?)*FFLink(x1?,x4?,x13?,x43?) = Consistency(x21,x32)*FrozenFFLink(x1,x2,x11,x21)*FrozenFFLink(x1,x3,x12,x32)*FFLink(x1,x4,x13,x43); 
    id FrozenFFLink(x1?,x2?,x11?,x21?)*FrozenFFLink(x1?,x3?,x12?,x32?)*FFLink(x4?,x1?,x43?,x13?) = Consistency(x21,x32)*FrozenFFLink(x1,x2,x11,x21)*FrozenFFLink(x1,x3,x12,x32)*FFLink(x4,x1,x43,x13);
                                                                                                                                                                            
    id FrozenFFLink(x2?,x1?,x21?,x11?)*FrozenFFLink(x1?,x3?,x12?,x32?)*FFLink(x1?,x4?,x13?,x43?) = Consistency(x21,x32)*FrozenFFLink(x2,x1,x21,x11)*FrozenFFLink(x1,x3,x12,x32)*FFLink(x1,x4,x13,x43); 
    id FrozenFFLink(x2?,x1?,x21?,x11?)*FrozenFFLink(x1?,x3?,x12?,x32?)*FFLink(x4?,x1?,x43?,x13?) = Consistency(x21,x32)*FrozenFFLink(x2,x1,x21,x11)*FrozenFFLink(x1,x3,x12,x32)*FFLink(x4,x1,x43,x13);
                                                                                                                                                                         
    id FrozenFFLink(x1?,x2?,x11?,x21?)*FrozenFFLink(x3?,x1?,x32?,x12?)*FFLink(x1?,x4?,x13?,x43?) = Consistency(x21,x32)*FrozenFFLink(x1,x2,x11,x21)*FrozenFFLink(x3,x1,x32,x12)*FFLink(x1,x4,x13,x43); 
    id FrozenFFLink(x1?,x2?,x11?,x21?)*FrozenFFLink(x3?,x1?,x32?,x12?)*FFLink(x4?,x1?,x43?,x13?) = Consistency(x21,x32)*FrozenFFLink(x1,x2,x11,x21)*FrozenFFLink(x3,x1,x32,x12)*FFLink(x4,x1,x43,x13);
                                                                                                                                                                          
    id FrozenFFLink(x2?,x1?,x21?,x11?)*FrozenFFLink(x3?,x1?,x32?,x12?)*FFLink(x1?,x4?,x13?,x43?) = Consistency(x21,x32)*FrozenFFLink(x2,x1,x21,x11)*FrozenFFLink(x3,x1,x32,x12)*FFLink(x1,x4,x13,x43); 
    id FrozenFFLink(x2?,x1?,x21?,x11?)*FrozenFFLink(x3?,x1?,x32?,x12?)*FFLink(x4?,x1?,x43?,x13?) = Consistency(x21,x32)*FrozenFFLink(x2,x1,x21,x11)*FrozenFFLink(x3,x1,x32,x12)*FFLink(x4,x1,x43,x13);
    
    id Consistency(x1?,x1?) = Inconsistent;
    id Consistency(x1?,x2?) = 1;
    
    if (count(Inconsistent,1)) $Consistent=0;
    .sort
    #if `$Consistent'==0
        id Inconsistent = 1;
        $Which = `Last';
        #message >> Inconsistent, we are submitting a swap of node `$Which'
        .sort
        #breakdo
    #else
        #message >> At this stage everything is consistent, continuing!
    #endif
    
    id FrozenFFLink(x1?,x2?,x11?,x21?)*FrozenFFLink(x1?,x3?,x12?,x32?)*FFLink(x1?,x4?,x13?,x43?) = (Left^-1)*FrozenFFLink(x1,x2,x11,x21)*FrozenFFLink(x1,x3,x12,x32)*FrozenFFLink(x1,x4,x13,x43); 
    id FrozenFFLink(x1?,x2?,x11?,x21?)*FrozenFFLink(x1?,x3?,x12?,x32?)*FFLink(x4?,x1?,x43?,x13?) = (Left^-1)*FrozenFFLink(x1,x2,x11,x21)*FrozenFFLink(x1,x3,x12,x32)*FrozenFFLink(x4,x1,x43,x13);

    id FrozenFFLink(x2?,x1?,x21?,x11?)*FrozenFFLink(x1?,x3?,x12?,x32?)*FFLink(x1?,x4?,x13?,x43?) = (Left^-1)*FrozenFFLink(x2,x1,x21,x11)*FrozenFFLink(x1,x3,x12,x32)*FrozenFFLink(x1,x4,x13,x43); 
    id FrozenFFLink(x2?,x1?,x21?,x11?)*FrozenFFLink(x1?,x3?,x12?,x32?)*FFLink(x4?,x1?,x43?,x13?) = (Left^-1)*FrozenFFLink(x2,x1,x21,x11)*FrozenFFLink(x1,x3,x12,x32)*FrozenFFLink(x4,x1,x43,x13);

    id FrozenFFLink(x1?,x2?,x11?,x21?)*FrozenFFLink(x3?,x1?,x32?,x12?)*FFLink(x1?,x4?,x13?,x43?) = (Left^-1)*FrozenFFLink(x1,x2,x11,x21)*FrozenFFLink(x3,x1,x32,x12)*FrozenFFLink(x1,x4,x13,x43); 
    id FrozenFFLink(x1?,x2?,x11?,x21?)*FrozenFFLink(x3?,x1?,x32?,x12?)*FFLink(x4?,x1?,x43?,x13?) = (Left^-1)*FrozenFFLink(x1,x2,x11,x21)*FrozenFFLink(x3,x1,x32,x12)*FrozenFFLink(x4,x1,x43,x13);

    id FrozenFFLink(x2?,x1?,x21?,x11?)*FrozenFFLink(x3?,x1?,x32?,x12?)*FFLink(x1?,x4?,x13?,x43?) = (Left^-1)*FrozenFFLink(x2,x1,x21,x11)*FrozenFFLink(x3,x1,x32,x12)*FrozenFFLink(x1,x4,x13,x43); 
    id FrozenFFLink(x2?,x1?,x21?,x11?)*FrozenFFLink(x3?,x1?,x32?,x12?)*FFLink(x4?,x1?,x43?,x13?) = (Left^-1)*FrozenFFLink(x2,x1,x21,x11)*FrozenFFLink(x3,x1,x32,x12)*FrozenFFLink(x4,x1,x43,x13);

    if (count(Left,1)==0) $Done = 1;
    .sort
    #if `$Done'==1
    #message >> We recieved a signal indicating we are done, exiting now...
    #else
    #message >> Still not done
    #endif
                            
****
****  Now we make the target nodes be consistent.
****
    
    id FrozenFFLink(x1?,x2?,x11?,x21?)*FFLink(x1?,x3?,x21?,x32?)*FFLink(x1?,x4?,x13?,x43?) = -FrozenFFLink(x1,x2,x21,x21)*FFLink(x1,x3,x11,x32)*FFLink(x1,x4,x13,x43);
    id FrozenFFLink(x1?,x2?,x11?,x21?)*FFLink(x1?,x3?,x21?,x32?)*FFLink(x4?,x1?,x43?,x13?) = -FrozenFFLink(x1,x2,x21,x21)*FFLink(x1,x3,x11,x32)*FFLink(x4,x1,x43,x13);

    id FrozenFFLink(x1?,x2?,x11?,x21?)*FFLink(x3?,x1?,x32?,x21?)*FFLink(x1?,x4?,x13?,x43?) = -FrozenFFLink(x1,x2,x21,x21)*FFLink(x3,x1,x32,x11)*FFLink(x1,x4,x13,x43); 
    id FrozenFFLink(x1?,x2?,x11?,x21?)*FFLink(x3?,x1?,x32?,x21?)*FFLink(x4?,x1?,x43?,x13?) = -FrozenFFLink(x1,x2,x21,x21)*FFLink(x3,x1,x32,x11)*FFLink(x4,x1,x43,x13);

    id FrozenFFLink(x2?,x1?,x21?,x11?)*FFLink(x1?,x3?,x12?,x32?)*FFLink(x1?,x4?,x21?,x43?) = -FrozenFFLink(x2,x1,x21,x21)*FFLink(x1,x3,x12,x32)*FFLink(x1,x4,x11,x43); 
    id FrozenFFLink(x2?,x1?,x21?,x11?)*FFLink(x1?,x3?,x12?,x32?)*FFLink(x4?,x1?,x43?,x21?) = -FrozenFFLink(x2,x1,x21,x21)*FFLink(x1,x3,x12,x32)*FFLink(x4,x1,x43,x11);

    id FrozenFFLink(x2?,x1?,x21?,x11?)*FFLink(x3?,x1?,x32?,x12?)*FFLink(x1?,x4?,x21?,x43?) = -FrozenFFLink(x2,x1,x21,x21)*FFLink(x3,x1,x32,x12)*FFLink(x1,x4,x11,x43); 
    id FrozenFFLink(x2?,x1?,x21?,x11?)*FFLink(x3?,x1?,x32?,x12?)*FFLink(x4?,x1?,x43?,x21?) = -FrozenFFLink(x2,x1,x21,x21)*FFLink(x3,x1,x32,x12)*FFLink(x4,x1,x43,x11); 
    
    
****
****  Next we pick the following node to be frozen           
****

    $BreakHere = 0;
    #do i=1,8
    #message >> Attempting to freeze node `i'
    id FrozenFFLink(`i',x2?,x11?,x11?)*FFLink(`i',x3?,x21?,x32?)*FFLink(`i',x4?,x13?,x43?) = -Replaced*FrozenFFLink(`i',x2,x21,x21)*FFLink(`i',x3,x11,x32)*FFLink(`i',x4,x13,x43);
    id FrozenFFLink(`i',x2?,x11?,x11?)*FFLink(`i',x3?,x21?,x32?)*FFLink(x4?,`i',x43?,x13?) = -Replaced*FrozenFFLink(`i',x2,x21,x21)*FFLink(`i',x3,x11,x32)*FFLink(x4,`i',x43,x13);

    id FrozenFFLink(`i',x2?,x11?,x11?)*FFLink(x3?,`i',x32?,x21?)*FFLink(`i',x4?,x13?,x43?) = -Replaced*FrozenFFLink(`i',x2,x21,x21)*FFLink(x3,`i',x32,x11)*FFLink(`i',x4,x13,x43); 
    id FrozenFFLink(`i',x2?,x11?,x11?)*FFLink(x3?,`i',x32?,x21?)*FFLink(x4?,`i',x43?,x13?) = -Replaced*FrozenFFLink(`i',x2,x21,x21)*FFLink(x3,`i',x32,x11)*FFLink(x4,`i',x43,x13);

    id FrozenFFLink(x2?,`i',x11?,x11?)*FFLink(`i',x3?,x12?,x32?)*FFLink(`i',x4?,x21?,x43?) = -Replaced*FrozenFFLink(x2,`i',x21,x21)*FFLink(`i',x3,x12,x32)*FFLink(`i',x4,x11,x43); 
    id FrozenFFLink(x2?,`i',x11?,x11?)*FFLink(`i',x3?,x12?,x32?)*FFLink(x4?,`i',x43?,x21?) = -Replaced*FrozenFFLink(x2,`i',x21,x21)*FFLink(`i',x3,x12,x32)*FFLink(x4,`i',x43,x11);

    id FrozenFFLink(x2?,`i',x11?,x11?)*FFLink(x3?,`i',x32?,x12?)*FFLink(`i',x4?,x21?,x43?) = -Replaced*FrozenFFLink(x2,`i',x21,x21)*FFLink(x3,`i',x32,x12)*FFLink(`i',x4,x11,x43); 
    id FrozenFFLink(x2?,`i',x11?,x11?)*FFLink(x3?,`i',x32?,x12?)*FFLink(x4?,`i',x43?,x21?) = -Replaced*FrozenFFLink(x2,`i',x21,x21)*FFLink(x3,`i',x32,x12)*FFLink(x4,`i',x43,x11);

    if(count(Replaced,1)) $Which = `i';
    if(count(Replaced,1)) $BreakHere = 1;
    .sort
    #if (`$BreakHere'==1)
        id Replaced = 1;
        #breakdo
    #endif
    #enddo
    #message >> Node `$Which' has been frozen
                                                                                                                                                                  
****
****  Choice 1:
****
    
    #message >> Submtting node `$Which' as written
                                       
   id FrozenFFLink($Which,x2?,x11?,x11?)*FFLink($Which,x3?,x12?,x32?)*FFLink($Which,x4?,x13?,x43?) = (Left^-2)*FrozenFFLink($Which,x2,x11,x11)*FrozenFFLink($Which,x3,x12,x32)*FrozenFFLink($Which,x4,x13,x43);
   id FrozenFFLink($Which,x2?,x11?,x11?)*FFLink($Which,x3?,x12?,x32?)*FFLink(x4?,$Which,x43?,x13?) = (Left^-2)*FrozenFFLink($Which,x2,x11,x11)*FrozenFFLink($Which,x3,x12,x32)*FrozenFFLink(x4,$Which,x43,x13);

   id FrozenFFLink($Which,x2?,x11?,x11?)*FFLink(x3?,$Which,x32?,x12?)*FFLink($Which,x4?,x13?,x43?) = (Left^-2)*FrozenFFLink($Which,x2,x11,x11)*FrozenFFLink(x3,$Which,x32,x12)*FrozenFFLink($Which,x4,x13,x43);
   id FrozenFFLink($Which,x2?,x11?,x11?)*FFLink(x3?,$Which,x32?,x12?)*FFLink(x4?,$Which,x43?,x13?) = (Left^-2)*FrozenFFLink($Which,x2,x11,x11)*FrozenFFLink(x3,$Which,x32,x12)*FrozenFFLink(x4,$Which,x43,x13);

   id FrozenFFLink(x2?,$Which,x11?,x11?)*FFLink($Which,x3?,x12?,x32?)*FFLink($Which,x4?,x13?,x43?) = (Left^-2)*FrozenFFLink(x2,$Which,x11,x11)*FrozenFFLink($Which,x3,x12,x32)*FrozenFFLink($Which,x4,x13,x43);
   id FrozenFFLink(x2?,$Which,x11?,x11?)*FFLink($Which,x3?,x12?,x32?)*FFLink(x4?,$Which,x43?,x13?) = (Left^-2)*FrozenFFLink(x2,$Which,x11,x11)*FrozenFFLink($Which,x3,x12,x32)*FrozenFFLink(x4,$Which,x43,x13);

   id FrozenFFLink(x2?,$Which,x11?,x11?)*FFLink(x3?,$Which,x32?,x12?)*FFLink($Which,x4?,x13?,x43?) = (Left^-2)*FrozenFFLink(x2,$Which,x11,x11)*FrozenFFLink(x3,$Which,x32,x12)*FrozenFFLink($Which,x4,x21,x43);
   id FrozenFFLink(x2?,$Which,x11?,x11?)*FFLink(x3?,$Which,x32?,x12?)*FFLink(x4?,$Which,x43?,x13?) = (Left^-2)*FrozenFFLink(x2,$Which,x11,x11)*FrozenFFLink(x3,$Which,x32,x12)*FrozenFFLink(x4,$Which,x43,x21);
    
    #call RecurseClassify(`$Which')
    
****
****  Choice 2:
****
   
   #if `$Which'==1
        #breakdo
   #endif
   
    #message >> Swapping the endpoints of node `$Which'
    
    if(count(Replaced,1)==0) id FrozenFFLink($Which,x2?,x11?,x11?)*FrozenFFLink($Which,x3?,x12?,x32?)*FrozenFFLink($Which,x4?,x13?,x43?) = -(Left^-2)*Replaced*FrozenFFLink($Which,x2,x11,x11)*FrozenFFLink($Which,x3,x13,x32)*FrozenFFLink($Which,x4,x12,x43);
    if(count(Replaced,1)==0) id FrozenFFLink($Which,x2?,x11?,x11?)*FrozenFFLink($Which,x3?,x12?,x32?)*FrozenFFLink(x4?,$Which,x43?,x13?) = -(Left^-2)*Replaced*FrozenFFLink($Which,x2,x11,x11)*FrozenFFLink($Which,x3,x13,x32)*FrozenFFLink(x4,$Which,x43,x12);

    if(count(Replaced,1)==0) id FrozenFFLink($Which,x2?,x11?,x11?)*FrozenFFLink(x3?,$Which,x32?,x12?)*FrozenFFLink($Which,x4?,x13?,x43?) = -(Left^-2)*Replaced*FrozenFFLink($Which,x2,x11,x11)*FrozenFFLink(x3,$Which,x32,x13)*FrozenFFLink($Which,x4,x12,x43);
    if(count(Replaced,1)==0) id FrozenFFLink($Which,x2?,x11?,x11?)*FrozenFFLink(x3?,$Which,x32?,x12?)*FrozenFFLink(x4?,$Which,x43?,x13?) = -(Left^-2)*Replaced*FrozenFFLink($Which,x2,x11,x11)*FrozenFFLink(x3,$Which,x32,x13)*FrozenFFLink(x4,$Which,x43,x12);
                             
    if(count(Replaced,1)==0) id FrozenFFLink(x2?,$Which,x11?,x11?)*FrozenFFLink($Which,x3?,x12?,x32?)*FrozenFFLink($Which,x4?,x13?,x43?) = -(Left^-2)*Replaced*FrozenFFLink(x2,$Which,x11,x11)*FrozenFFLink($Which,x3,x13,x32)*FrozenFFLink($Which,x4,x12,x43);
    if(count(Replaced,1)==0) id FrozenFFLink(x2?,$Which,x11?,x11?)*FrozenFFLink($Which,x3?,x12?,x32?)*FrozenFFLink(x4?,$Which,x43?,x13?) = -(Left^-2)*Replaced*FrozenFFLink(x2,$Which,x11,x11)*FrozenFFLink($Which,x3,x13,x32)*FrozenFFLink(x4,$Which,x43,x12);
                             
    if(count(Replaced,1)==0) id FrozenFFLink(x2?,$Which,x11?,x11?)*FrozenFFLink(x3?,$Which,x32?,x12?)*FrozenFFLink($Which,x4?,x13?,x43?) = -(Left^-2)*Replaced*FrozenFFLink(x2,$Which,x11,x11)*FrozenFFLink(x3,$Which,x32,x13)*FrozenFFLink($Which,x4,x12,x43);
    if(count(Replaced,1)==0) id FrozenFFLink(x2?,$Which,x11?,x11?)*FrozenFFLink(x3?,$Which,x32?,x12?)*FrozenFFLink(x4?,$Which,x43?,x13?) = -(Left^-2)*Replaced*FrozenFFLink(x2,$Which,x11,x11)*FrozenFFLink(x3,$Which,x32,x13)*FrozenFFLink(x4,$Which,x43,x12);
    
    id Replaced = 1;
                            
    #call RecurseClassify(`$Which')
    
    #message >> No more options for node `$Which', exiting this level
    #message >> Submitting a swap of node `Last'
    $Which = `Last';
    .sort 


#enddo
    
#endprocedure


#procedure ChainToTF

************************************************************
***
***  First we reintroduce Nodes by adding 2 FNodes per FFLink 
***  This will overcount every node three times, hence we 
***  correct for it next.
***
***********************************************************

id FFLink(x1?,x2?) = FFLink(x1,x2)*FNode(cOla0,cOla0,cOla0,x1)*FNode(cOla0,cOla0,cOla0,x2);
id FNode(cOla0,cOla0,cOla0,x1?)^3 = FNode(cOla0,cOla0,cOla0,x1); 

**************************************************************************
***
***  These rules make sure that any two nodes that are Linked have the 
***  other node on the same relative position, if not we must pay a sign 
***  coming from the full anti-symmetry of the FNodes.
***
***************************************************************************


#if `Legacy' == 0
#message >> Using Legacy Inverse
id FFLink(x1?,x2?)*FNode(cOla0,cOla1?,cOla2?,x1?)*FNode(cOla0,cOla3?,cOla4?,x2?)=  FNode(x1,cOla3,cOla4,x2)*FNode(x2,cOla1,cOla2,x1);
id FFLink(x1?,x2?)*FNode(cOla0,cOla1?,cOla2?,x1?)*FNode(cOla3?,cOla0,cOla4?,x2?)= -FNode(cOla3,x1,cOla4,x2)*FNode(x2,cOla1,cOla2,x1);
id FFLink(x1?,x2?)*FNode(cOla0,cOla1?,cOla2?,x1?)*FNode(cOla3?,cOla4?,cOla0,x2?)=  FNode(cOla3,cOla4,x1,x2)*FNode(x2,cOla1,cOla2,x1);

id FFLink(x1?,x2?)*FNode(cOla1?,cOla0,cOla2?,x1?)*FNode(cOla3?,cOla0,cOla4?,x2?)=  FNode(cOla3,x1,cOla4,x2)*FNode(cOla1,x2,cOla2,x1);
id FFLink(x1?,x2?)*FNode(cOla1?,cOla0,cOla2?,x1?)*FNode(cOla3?,cOla4?,cOla0,x2?)= -FNode(cOla3,cOla4,x1,x2)*FNode(cOla1,x2,cOla2,x1);

id FFLink(x1?,x2?)*FNode(cOla1?,cOla2?,cOla0,x1?)*FNode(cOla3?,cOla4?,cOla0,x2?)=  FNode(cOla3,cOla4,x1,x2)*FNode(cOla1,cOla2,x2,x1);
#else if `Legacy'==1
#message >> Using New Inverse

repeat;
id once FFLink(x1?,x2?)*FNode(cOla0,cOla1?,cOla2?,x1?)*FNode(cOla0,cOla3?,cOla4?,x2?) =  FNode(cOla3,cOla4,x1,x2)*FNode(cOla1,cOla2,x2,x1);
endrepeat;

#else 
#message >> Inverse Debug

#do i=1,10
repeat;
id once FFLink(x1?,x2?)*FNode(cOla0,cOla1?,cOla2?,x1?)*FNode(cOla0,cOla3?,cOla4?,x2?) =  FNode(cOla3,cOla4,x1,x2)*FNode(cOla1,cOla2,x2,x1);
endrepeat;
#enddo

#endif
    
*****************************************************************************
***
***  We convert from Node indices to cOlf or cOlT indices
***
*****************************************************************************

#do i=1,10
    #do j=1,10
        #if (`i' < `j')
            id FNode(`j',x1?,x2?,`i') = FNode(cOla`i'`j',x1,x2,`i');
            id FNode(`j',cOla1?,cOla2?,`i') = FNode(cOla`i'`j',cOla1,cOla2,`i');
            
            id FNode(x1?,`j',x2?,`i') = FNode(x1,cOla`i'`j',x2,`i');
            id FNode(cOla1?,`j',cOla2?,`i') = FNode(cOla1,cOla`i'`j',cOla2,`i');
            
            id FNode(x1?,x2?,`j',`i') = FNode(x1,x2,cOla`i'`j',`i');
            id FNode(cOla1?,cOla2?,`j',`i') = FNode(cOla1,cOla2,cOla`i'`j',`i');
        #else
            id FNode(`j',x1?,x2?,`i') = FNode(cOla`j'`i',x1,x2,`i');
            id FNode(`j',cOla1?,cOla2?,`i') = FNode(cOla`j'`i',cOla1,cOla2,`i');
            
            id FNode(x1?,`j',x2?,`i') = FNode(x1,cOla`j'`i',x2,`i');
            id FNode(cOla1?,`j',cOla2?,`i') = FNode(cOla1,cOla`j'`i',cOla2,`i');
            
            id FNode(x1?,x2?,`j',`i') = FNode(x1,x2,cOla`j'`i',`i');
            id FNode(cOla1?,cOla2?,`j',`i') = FNode(cOla1,cOla2,cOla`j'`i',`i');
        #endif
    #enddo
#enddo
       
***************************************************************************
***
***  Back to cOlf and cOlT fully 
***
***************************************************************************

id FNode(cOla1?,cOla2?,cOla3?,x4?) = cOlf(cOla1,cOla2,cOla3);


#endprocedure


#procedure NLOXSimplifyChainColor
    
    #do i=1,10
        #do j=1,10
        id once FFLink(`i',`j') = -2*i_;
        #enddo
    #enddo

#endprocedure

