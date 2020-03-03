
#procedure DefineTopologies

CF FFLink,TTLink,TTaLink(symmetric),FTLink;
CF FNode,TNode;
CF myep;
auto s x,f,t;

#endprocedure


#procedure TFToChain(nLegs)
.sort

*id cOlf(cOla1?,cOla2?,cOla3?)*cOlf(cOla1?,cOla2?,cOla4?) = NA*d_(cOla3,cOla4);
*id cOlT(cOli1?,cOli2?,cOla1?)*cOlT(cOli2?,cOli1?,cOla2?) = (1/2)*d_(cOla1,cOla2);

#do i=1,`nLegs'
id once cOlf(?args) = FNode(?args,f`i'); 
id once cOlT(?args) = TNode(?args,t`i');
#enddo;

repeat;
id FNode(cOla1?!{cOla0},cOla2?,cOla3?,x1?)*FNode(cOla1?,cOla4?,cOla5?,x2?) = FFLink(x1,x2,1,1)*FNode(cOla0,cOla2,cOla3,x1)*FNode(cOla0,cOla4,cOla5,x2);
id FNode(cOla1?!{cOla0},cOla2?,cOla3?,x1?)*FNode(cOla4?,cOla1?,cOla5?,x2?) = FFLink(x1,x2,1,2)*FNode(cOla0,cOla2,cOla3,x1)*FNode(cOla4,cOla0,cOla5,x2);
id FNode(cOla1?!{cOla0},cOla2?,cOla3?,x1?)*FNode(cOla4?,cOla5?,cOla1?,x2?) = FFLink(x1,x2,1,3)*FNode(cOla0,cOla2,cOla3,x1)*FNode(cOla4,cOla5,cOla0,x2);

id FNode(cOla2?,cOla1?!{cOla0},cOla3?,x1?)*FNode(cOla4?,cOla1?,cOla5?,x2?) = FFLink(x1,x2,2,2)*FNode(cOla2,cOla0,cOla3,x1)*FNode(cOla4,cOla0,cOla5,x2);
id FNode(cOla2?,cOla1?!{cOla0},cOla3?,x1?)*FNode(cOla4?,cOla5?,cOla1?,x2?) = FFLink(x1,x2,2,3)*FNode(cOla2,cOla0,cOla3,x1)*FNode(cOla4,cOla5,cOla0,x2);

id FNode(cOla2?,cOla3?,cOla1?!{cOla0},x1?)*FNode(cOla4?,cOla5?,cOla1?,x2?) = FFLink(x1,x2,3,3)*FNode(cOla2,cOla3,cOla0,x1)*FNode(cOla4,cOla5,cOla0,x2);

id TNode(cOli1?,cOli2?!{cOli0},cOla1?,x1?)*TNode(cOli2?!{cOli0},cOli3?,cOla2?,x2?) = TTLink(x1,x2)*TNode(cOli1,cOli0,cOla1,x1)*TNode(cOli0,cOli3,cOla2,x2);

id TNode(cOli1?,cOli2?,cOla1?!{cOla0},x1?)*FNode(cOla1?!{cOla0},cOla2?,cOla3?,x2?) = FTLink(x2,x1,1)*TNode(cOli1,cOli2,cOla0,x1)*FNode(cOla0,cOla2,cOla3,x2);
id TNode(cOli1?,cOli2?,cOla2?!{cOla0},x1?)*FNode(cOla1?,cOla2?!{cOla0},cOla3?,x2?) = FTLink(x2,x1,2)*TNode(cOli1,cOli2,cOla0,x1)*FNode(cOla1,cOla0,cOla3,x2);
id TNode(cOli1?,cOli2?,cOla3?!{cOla0},x1?)*FNode(cOla1?,cOla2?,cOla3?!{cOla0},x2?) = FTLink(x2,x1,3)*TNode(cOli1,cOli2,cOla0,x1)*FNode(cOla1,cOla2,cOla0,x2);

id TNode(cOli1?,cOli2?,cOla1?!{cOla0},x1?)*TNode(cOli3?,cOli4?,cOla1?!{cOla0},x2?) = TTaLink(x1,x2)*TNode(cOli1,cOli2,cOla0,x1)*TNode(cOli3,cOli4,cOla0,x2);

id TTLink(t1?,t2?)*TTLink(t2?,t1?)*FTLink(f1?,t1?,x1?)*FTLink(f2?,t2?,x2?) = (1/2)*FFLink(f1,f2,x1,x2);

id FFLink(x1?,x2?,x3?,x4?)*FFLink(x1?,x2?,x5?,x6?)*FFLink(x1?,x2?,x7?,x8?) = myep(x3,x5,x7)*myep(x4,x6,x8)*NA*NC;

id FFLink(x1?,x2?,x11?,x12?)*FFLink(x1?,x2?,x13?,x14?)*FFLink(x1?,x3?,x15?,x16?)*FFLink(x2?,x4?,x17?,x18?) = myep(x15,x13,x11)*myep(x17,x14,x12)*NC*FFLink(x3,x4,x16,x18);
id FFLink(x1?,x2?,x11?,x12?)*FFLink(x1?,x2?,x13?,x14?)*FFLink(x1?,x3?,x15?,x16?)*FFLink(x4?,x2?,x18?,x17?) = myep(x15,x13,x11)*myep(x17,x14,x12)*NC*FFLink(x3,x4,x16,x18);
id FFLink(x1?,x2?,x11?,x12?)*FFLink(x1?,x2?,x13?,x14?)*FFLink(x3?,x1?,x16?,x15?)*FFLink(x2?,x4?,x17?,x18?) = myep(x15,x13,x11)*myep(x17,x14,x12)*NC*FFLink(x3,x4,x16,x18);
id FFLink(x1?,x2?,x11?,x12?)*FFLink(x1?,x2?,x13?,x14?)*FFLink(x3?,x1?,x16?,x15?)*FFLink(x4?,x2?,x18?,x17?) = myep(x15,x13,x11)*myep(x17,x14,x12)*NC*FFLink(x3,x4,x16,x18);

id FFLink(x1?,x2?,x11?,x12?)*FFLink(x1?,x2?,x13?,x14?)*FTLink(x1?,x3?,x15?)*FTLink(x2?,x4?,x17?) = myep(x15,x13,x11)*myep(x17,x14,x12)*NC*TTLink(x3,x4);

id FFLink(x1?,x2?,x11?,x12?)*FFLink(x1?,x2?,x13?,x14?)*FTLink(x1?,x3?,x15?)*FFLink(x2?,x4?,x17?,x18?) = myep(x15,x13,x11)*myep(x17,x14,x12)*NC*FTLink(x4,x3,x18);
id FFLink(x1?,x2?,x11?,x12?)*FFLink(x1?,x2?,x13?,x14?)*FTLink(x1?,x3?,x15?)*FFLink(x4?,x2?,x18?,x17?) = myep(x15,x13,x11)*myep(x17,x14,x12)*NC*FTLink(x4,x3,x18);
id FFLink(x1?,x2?,x11?,x12?)*FFLink(x1?,x2?,x13?,x14?)*FTLink(x3?,x1?,x15?)*FFLink(x2?,x4?,x17?,x18?) = myep(x15,x13,x11)*myep(x17,x14,x12)*NC*FTLink(x4,x3,x18);
id FFLink(x1?,x2?,x11?,x12?)*FFLink(x1?,x2?,x13?,x14?)*FTLink(x3?,x1?,x15?)*FFLink(x4?,x2?,x18?,x17?) = myep(x15,x13,x11)*myep(x17,x14,x12)*NC*FTLink(x4,x3,x18);

id FFLink(x1?,x2?,x11?,x12?)*FFLink(x1?,x2?,x13?,x14?)*FFLink(x1?,x3?,x15?,x16?)*FTLink(x2?,x4?,x17?) = myep(x15,x13,x11)*myep(x17,x14,x12)*NC*FTLink(x3,x4,x16);
id FFLink(x1?,x2?,x11?,x12?)*FFLink(x1?,x2?,x13?,x14?)*FFLink(x1?,x3?,x15?,x16?)*FTLink(x4?,x2?,x17?) = myep(x15,x13,x11)*myep(x17,x14,x12)*NC*FTLink(x3,x4,x16);
id FFLink(x1?,x2?,x11?,x12?)*FFLink(x1?,x2?,x13?,x14?)*FFLink(x3?,x1?,x16?,x15?)*FTLink(x2?,x4?,x17?) = myep(x15,x13,x11)*myep(x17,x14,x12)*NC*FTLink(x3,x4,x16);
id FFLink(x1?,x2?,x11?,x12?)*FFLink(x1?,x2?,x13?,x14?)*FFLink(x3?,x1?,x16?,x15?)*FTLink(x4?,x2?,x17?) = myep(x15,x13,x11)*myep(x17,x14,x12)*NC*FTLink(x3,x4,x16);

#do i=1,`nLegs'
    #do j=`i'+1,`nLegs'
        id FFLink(f`j',f`i',x1?,x2?) = FFLink(f`i',f`j',x2,x1);
    #enddo
#enddo

endrepeat;
        
id myep(?args1) = e_(?args1);
id e_(1,2,3)=1;

id FNode(cOla0,cOla0,cOla0,x1?) = 1;
id TNode(cOli0,cOli0,cOla0,x1?) = 1;

#message >> Translation completed 
#call LexicographicalLabel("1","1")
#message >> Reorder completed
#call CannonicalOrientation
#message >> Reorientation completed

#endprocedure


#procedure LexicographicalLabel(OrderF,OrderT)
.sort
#if (`OrderF'==1)
argument;
#do i=1,`nLegs'
    id f`i' = N`i'_?;
#enddo
endargument;
   
renumber 0;

argument;
#do i=1,`nLegs'
    id N`i'_? = `i';
#enddo
endargument;

#do i=1,`nLegs'
    #do j=`i'+1,`nLegs'
        id FFLink(`j',`i',x1?,x2?) = FFLink(`i',`j',x2,x1);
    #enddo
#enddo
#endif

#if (`OrderT'==1)
argument;
#do i=1,`nLegs'
    id t`i' = N`i'_?;
#enddo
endargument;
   
renumber 0;

argument;
#do i=1,`nLegs'
    id N`i'_? = `i';
#enddo
endargument;
#endif

#endprocedure


        
#procedure CannonicalOrientation
.sort
#do i=1,`nLegs'
    #do j=1,`nLegs'
        #do k=1,`nLegs'

            

           

            #if (`j'>`i')
            #if (`k'>`j')
            
            id FFLink(x1?,`i',x11?!{x0},x21?)*FFLink(x1?,`j',x12?!{x0},x32?)*FFLink(x1?,`k',x13?!{x0},x43?) = myep(x11,x12,x13)*FFLink(x1,`i',x0,x21)*FFLink(x1,`j',x0,x32)*FFLink(x1,`k',x0,x43);
            id FFLink(x1?,`i',x11?!{x0},x21?)*FFLink(x1?,`j',x12?!{x0},x32?)*FFLink(`k',x1?,x43?,x13?!{x0}) = myep(x11,x12,x13)*FFLink(x1,`i',x0,x21)*FFLink(x1,`j',x0,x32)*FFLink(`k',x1,x43,x0);
           
            id FFLink(x1?,`i',x11?!{x0},x21?)*FFLink(`j',x1?,x32?,x12?!{x0})*FFLink(x1?,`k',x13?!{x0},x43?) = myep(x11,x12,x13)*FFLink(x1,`i',x0,x21)*FFLink(`j',x1,x32,x0)*FFLink(x1,`k',x0,x43);
            id FFLink(x1?,`i',x11?!{x0},x21?)*FFLink(`j',x1?,x32?,x12?!{x0})*FFLink(`k',x1?,x43?,x13?!{x0}) = myep(x11,x12,x13)*FFLink(x1,`i',x0,x21)*FFLink(`j',x1,x32,x0)*FFLink(`k',x1,x43,x0);
            
            id FFLink(`i',x1?,x21?,x11?!{x0})*FFLink(x1?,`j',x12?!{x0},x32?)*FFLink(x1?,`k',x13?!{x0},x43?) = myep(x11,x12,x13)*FFLink(`i',x1,x21,x0)*FFLink(x1,`j',x0,x32)*FFLink(x1,`k',x0,x43);
            id FFLink(`i',x1?,x21?,x11?!{x0})*FFLink(x1?,`j',x12?!{x0},x32?)*FFLink(`k',x1?,x43?,x13?!{x0}) = myep(x11,x12,x13)*FFLink(`i',x1,x21,x0)*FFLink(x1,`j',x0,x32)*FFLink(`k',x1,x43,x0);
            
            id FFLink(`i',x1?,x21?,x11?!{x0})*FFLink(`j',x1?,x32?,x12?!{x0})*FFLink(x1?,`k',x13?!{x0},x43?) = myep(x11,x12,x13)*FFLink(`i',x1,x21,x0)*FFLink(`j',x1,x32,x0)*FFLink(x1,`k',x0,x43);
            id FFLink(`i',x1?,x21?,x11?!{x0})*FFLink(`j',x1?,x32?,x12?!{x0})*FFLink(`k',x1?,x43?,x13?!{x0}) = myep(x11,x12,x13)*FFLink(`i',x1,x21,x0)*FFLink(`j',x1,x32,x0)*FFLink(`k',x1,x43,x0);
            
            id FTLink(x1?,`i',x11?!{x0})*FTLink(x1?,`j',x12?!{x0})*FTLink(x1?,`k',x13?!{x0}) = myep(x11,x12,x13)*FTLink(x1,`i',x0)*FTLink(x1,`j',x0)*FTLink(x1,`k',x0);
            
            #endif
            
            id FFLink(x1?,`i',x11?!{x0},x21?)*FFLink(x1?,`j',x12?!{x0},x32?)*FTLink(x1?,`k',x13?!{x0}) = myep(x11,x12,x13)*FFLink(x1,`i',x0,x21)*FFLink(x1,`j',x0,x32)*FTLink(x1,`k',x0);
            id FFLink(x1?,`i',x11?!{x0},x21?)*FFLink(`j',x1?,x32?,x12?!{x0})*FTLink(x1?,`k',x13?!{x0}) = myep(x11,x12,x13)*FFLink(x1,`i',x0,x21)*FFLink(`j',x1,x32,x0)*FTLink(x1,`k',x0);
            id FFLink(`i',x1?,x21?,x11?!{x0})*FFLink(x1?,`j',x12?!{x0},x32?)*FTLink(x1?,`k',x13?!{x0}) = myep(x11,x12,x13)*FFLink(`i',x1,x21,x0)*FFLink(x1,`j',x0,x32)*FTLink(x1,`k',x0);
            id FFLink(`i',x1?,x21?,x11?!{x0})*FFLink(`j',x1?,x32?,x12?!{x0})*FTLink(x1?,`k',x13?!{x0}) = myep(x11,x12,x13)*FFLink(`i',x1,x21,x0)*FFLink(`j',x1,x32,x0)*FTLink(x1,`k',x0);
            
            id FTLink(x1?,`i',x11?!{x0})*FTLink(x1?,`j',x12?!{x0})*FFLink(x1?,`k',x13?!{x0},x43?) = myep(x11,x12,x13)*FTLink(x1,`i',x0)*FTLink(x1,`j',x0)*FFLink(x1,`k',x0,x43);
            id FTLink(x1?,`i',x11?!{x0})*FTLink(x1?,`j',x12?!{x0})*FFLink(`k',x1?,x43?,x13?!{x0}) = myep(x11,x12,x13)*FTLink(x1,`i',x0)*FTLink(x1,`j',x0)*FFLink(`k',x1,x43,x0);
                        
            #endif
            
            
            
        #enddo
    #enddo
#enddo

id FFLink(?args1,x0,x0) = FFLink(?args1);
id FTLink(?args1,x0) = FTLink(?args1);
id myep(?args1) = e_(?args1);
id e_(1,2,3)=1;

        
#endprocedure
