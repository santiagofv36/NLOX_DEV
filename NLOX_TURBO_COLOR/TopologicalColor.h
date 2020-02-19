

#procedure DefineTopologies

CF FNode;
CF FFLink(symmetric);
auto s x;

#endprocedure


#procedure TFToChain


#do i=1,10
id once cOlf(?args) = FNode(?args,`i');
#enddo;

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

*id FNode(?args) = 1;

#do i=1,12
    #do j=1,12
        id FFLink(`i',`j')=FFLink(N`i'_?,N`j'_?);
    #enddo;
#enddo;

renumber 0;

#do i=1,12
    #do j=`i'+1,12
        id FFLink(N`i'_?,N`j'_?)=FFLink(`i',`j');
    #enddo;
#enddo;

id FNode(cOla0,cOla0,cOla0,x1?) = 1;

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

id FFLink(x1?,x2?)*FNode(cOla0,cOla1?,cOla2?,x1?)*FNode(cOla0,cOla3?,cOla4?,x2?)=  FNode(x1,cOla3,cOla4,x2)*FNode(x2,cOla1,cOla2,x1);
id FFLink(x1?,x2?)*FNode(cOla0,cOla1?,cOla2?,x1?)*FNode(cOla3?,cOla0,cOla4?,x2?)= -FNode(cOla3,x1,cOla4,x2)*FNode(x2,cOla1,cOla2,x1);
id FFLink(x1?,x2?)*FNode(cOla0,cOla1?,cOla2?,x1?)*FNode(cOla3?,cOla4?,cOla0,x2?)=  FNode(cOla3,cOla4,x1,x2)*FNode(x2,cOla1,cOla2,x1);

id FFLink(x1?,x2?)*FNode(cOla1?,cOla0,cOla2?,x1?)*FNode(cOla3?,cOla0,cOla4?,x2?)=  FNode(cOla3,x1,cOla4,x2)*FNode(cOla1,x2,cOla2,x1);
id FFLink(x1?,x2?)*FNode(cOla1?,cOla0,cOla2?,x1?)*FNode(cOla3?,cOla4?,cOla0,x2?)= -FNode(cOla3,cOla4,x1,x2)*FNode(cOla1,x2,cOla2,x1);

id FFLink(x1?,x2?)*FNode(cOla1?,cOla2?,cOla0,x1?)*FNode(cOla3?,cOla4?,cOla0,x2?)=  FNode(cOla3,cOla4,x1,x2)*FNode(cOla1,cOla2,x2,x1);
    
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
