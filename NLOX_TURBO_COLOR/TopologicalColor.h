#define Legacy "2"
#define N "0"

#procedure DefineTopologies

#if (`Legacy'==0)||(`Legacy'==1)
CF FFLink(symmetric);
#else
CF FFLink;
#endif
CF FNode;
auto s x;

#endprocedure


#procedure TFToChain


#do i=1,10
id once cOlf(?args) = FNode(?args,`i');
#enddo;
#if `Legacy' == 0
#message >> Using Legacy Color
repeat;
id once FNode(cOla1?!{cOla0},cOla2?,cOla3?,x1?)*FNode(cOla1?,cOla4?,cOla5?,x2?) =  FFLink(x1,x2)*FNode(cOla0,cOla2,cOla3,x1)*FNode(cOla4,cOla5,cOla0,x2);
id once FNode(cOla1?!{cOla0},cOla2?,cOla3?,x1?)*FNode(cOla4?,cOla1?,cOla5?,x2?) = -FFLink(x1,x2)*FNode(cOla0,cOla2,cOla3,x1)*FNode(cOla4,cOla5,cOla0,x2);
id once FNode(cOla1?!{cOla0},cOla2?,cOla3?,x1?)*FNode(cOla4?,cOla5?,cOla1?,x2?) =  FFLink(x1,x2)*FNode(cOla0,cOla2,cOla3,x1)*FNode(cOla4,cOla5,cOla0,x2);

id once FNode(cOla2?,cOla1?!{cOla0},cOla3?,x1?)*FNode(cOla4?,cOla1?,cOla5?,x2?) =  FFLink(x1,x2)*FNode(cOla0,cOla2,cOla3,x1)*FNode(cOla4,cOla5,cOla0,x2);
id once FNode(cOla2?,cOla1?!{cOla0},cOla3?,x1?)*FNode(cOla4?,cOla5?,cOla1?,x2?) = -FFLink(x1,x2)*FNode(cOla0,cOla2,cOla3,x1)*FNode(cOla4,cOla5,cOla0,x2);

id once FNode(cOla2?,cOla3?,cOla1?!{cOla0},x1?)*FNode(cOla4?,cOla5?,cOla1?,x2?) =  FFLink(x1,x2)*FNode(cOla0,cOla2,cOla3,x1)*FNode(cOla4,cOla5,cOla0,x2);

id FFLink(x1?,x2?)^3 = NA*NC;
id FFLink(x1?,x2?)^2*FFLink(x1?,x3?)*FFLink(x2?,x4?) = NC*FFLink(x3,x4);
endrepeat;
#else if `Legacy' == 1
#message >> Using New Color
repeat;
id once FNode(cOla1?!{cOla0},cOla2?,cOla3?,x1?)*FNode(cOla1?,cOla4?,cOla5?,x2?) =  FFLink(x1,x2)*FNode(cOla2,cOla3,cOla0,x1)*FNode(cOla4,cOla5,cOla0,x2);
id FFLink(x1?,x2?)^3 = NA*NC;
id FFLink(x1?,x2?)^2*FFLink(x1?,x3?)*FFLink(x2?,x4?) = NC*FFLink(x3,x4);
endrepeat;
#else
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

*#do i=1,20
*
*id FFLink(x1?,x2?,x11?,x12?)*FFLink(x1?,x3?,x13?,x12?)*FFLink(x4?,x2?,x11?,x14?) = FFLink(x1,x2,x13,x14)*FFLink(x1,x3,x11,x12)*FFLink(x4,x2,x11,x12);
*id FFLink(x1?,x2?,x11?,x12?)*FFLink(x3?,x1?,x12?,x13?)*FFLink(x4?,x2?,x11?,x14?) = FFLink(x1,x2,x13,x14)*FFLink(x3,x1,x12,x11)*FFLink(x4,x2,x11,x12);
*id FFLink(x1?,x2?,x11?,x12?)*FFLink(x1?,x3?,x13?,x12?)*FFLink(x2?,x4?,x14?,x11?) = FFLink(x1,x2,x13,x14)*FFLink(x1,x3,x11,x12)*FFLink(x2,x4,x12,x11);
*id FFLink(x1?,x2?,x11?,x12?)*FFLink(x3?,x1?,x12?,x13?)*FFLink(x2?,x4?,x14?,x11?) = FFLink(x1,x2,x13,x14)*FFLink(x3,x1,x12,x11)*FFLink(x2,x4,x12,x11);
*
*id FFLink(?args,x1?,x1?) = x0*FFLink(?args,x1,x1);
*if(count(x0,1)==count(FFLink,1)) id FFLink(?args,x1?,x1?) = FFLink(?args);
*id x0 = 1;
*
*id FFLink(x1?,x2?,x11?,x12?)*FFLink(x1?,x3?,x12?,x13?) = -FFLink(x1,x2,x12,x12)*FFLink(x1,x3,x11,x13); 
*id FFLink(x1?,x2?,x11?,x12?)*FFLink(x3?,x1?,x13?,x12?) = -FFLink(x1,x2,x12,x12)*FFLink(x3,x1,x13,x11);
*id FFLink(x2?,x1?,x12?,x11?)*FFLink(x3?,x1?,x13?,x12?) = -FFLink(x2,x1,x12,x12)*FFLink(x3,x1,x13,x11);
*
*#enddo
#endif

*#do i=1,12
*    #do j=1,12
*        id FFLink(`i',`j')=FFLink(N`i'_?,N`j'_?);
*    #enddo;
*#enddo;

*renumber 0;
*
*#do i=1,12
*    #do j=1,12
*        id FFLink(N`i'_?,N`j'_?)=FFLink(`i',`j');
*    #enddo;
*#enddo;
*
id FNode(cOla0,cOla0,cOla0,x1?) = 1;


****
****   This is a while loop
****

.sort 
CF FrozenFFLink;
CF Consistency(symmetric);
id FFLink(1,?args) = FrozenFFLink(1,?args);
#$Done = 0;

#endprocedure




#procedure RecurseClassify
    
   #do i=1,1
    $Break = 0;
    #if `$Done' == 1
        #breakdo
    #endif

****
****   No choice branch: here we freeze singly-open FNodes if we can do so consistently, if not we break at this level to force on a recall with different choice.
**** 

    id FrozenFFLink(x1?,x2?,x11?,x21?)*FrozenFFLink(x1?,x3?,x12?,x32?)*FFLink(x1?,x4?,x13?,x43?) = Consistency(x11,x12,x13)*FrozenFFLink(x1,x2,x11,x21)*FrozenFFLink(x1,x3,x12,x32)*FrozenFFLink(x1,x4,x13,x43); 
    id FrozenFFLink(x1?,x2?,x11?,x21?)*FrozenFFLink(x1?,x3?,x12?,x32?)*FFLink(x4?,x1?,x43?,x13?) = Consistency(x11,x12,x13)*FrozenFFLink(x1,x2,x11,x21)*FrozenFFLink(x1,x3,x12,x32)*FrozenFFLink(x4,x1,x43,x13);
                                                                                                                                                                            
    id FrozenFFLink(x2?,x1?,x21?,x11?)*FrozenFFLink(x1?,x3?,x12?,x32?)*FFLink(x1?,x4?,x13?,x43?) = Consistency(x11,x12,x13)*FrozenFFLink(x2,x1,x21,x11)*FrozenFFLink(x1,x3,x12,x32)*FrozenFFLink(x1,x4,x13,x43); 
    id FrozenFFLink(x2?,x1?,x21?,x11?)*FrozenFFLink(x1?,x3?,x12?,x32?)*FFLink(x4?,x1?,x43?,x13?) = Consistency(x11,x12,x13)*FrozenFFLink(x2,x1,x21,x11)*FrozenFFLink(x1,x3,x12,x32)*FrozenFFLink(x4,x1,x43,x13);
                                                                                                                                                                         
    id FrozenFFLink(x1?,x2?,x11?,x21?)*FrozenFFLink(x3?,x1?,x32?,x12?)*FFLink(x1?,x4?,x13?,x43?) = Consistency(x11,x12,x13)*FrozenFFLink(x1,x2,x11,x21)*FrozenFFLink(x3,x1,x32,x12)*FrozenFFLink(x1,x4,x13,x43); 
    id FrozenFFLink(x1?,x2?,x11?,x21?)*FrozenFFLink(x3?,x1?,x32?,x12?)*FFLink(x4?,x1?,x43?,x13?) = Consistency(x11,x12,x13)*FrozenFFLink(x1,x2,x11,x21)*FrozenFFLink(x3,x1,x32,x12)*FrozenFFLink(x4,x1,x43,x13);
                                                                                                                                                                          
    id FrozenFFLink(x2?,x1?,x21?,x11?)*FrozenFFLink(x3?,x1?,x32?,x12?)*FFLink(x1?,x4?,x13?,x43?) = Consistency(x11,x12,x13)*FrozenFFLink(x2,x1,x21,x11)*FrozenFFLink(x3,x1,x32,x12)*FrozenFFLink(x1,x4,x13,x43); 
    id FrozenFFLink(x2?,x1?,x21?,x11?)*FrozenFFLink(x3?,x1?,x32?,x12?)*FFLink(x4?,x1?,x43?,x13?) = Consistency(x11,x12,x13)*FrozenFFLink(x2,x1,x21,x11)*FrozenFFLink(x3,x1,x32,x12)*FrozenFFLink(x4,x1,x43,x13);
    
    if (count(Consistency(1,2,3),1)<count(Consistency,1)) $Break = 1;
    .sort 
    #if `$Break'==1
        #breakdo
    #endif
    
    if (count(FFLink,1)==0) $Done =1;
    
****
****  Choice 1: 
****
    
    id once FrozenFFLink(x1?,x2?,?args1)*FFLink(x1?,x3?,x11?.x13?)*FFLink(x1?,x4?,?args3) = 
    
    
    $Done=1;




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

