
#procedure DefineTopologies

CF FFLink;
CF FNode;
auto s x,y;

#endprocedure


#procedure TFToChain

.sort 
CF myep;
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

id FFLink(x1?,x2?,x3?,x4?)*FFLink(x1?,x2?,x5?,x6?)*FFLink(x1?,x2?,x7?,x8?) = myep(x3,x5,x7)*myep(x4,x6,x8)*NA*NC;

id FFLink(x1?,x2?,x11?,x12?)*FFLink(x1?,x2?,x13?,x14?)*FFLink(x1?,x3?,x15?,x16?)*FFLink(x2?,x4?,x17?,x18?) = myep(x15,x13,x11)*myep(x17,x14,x12)*NC*FFLink(x3,x4,x16,x18);
id FFLink(x1?,x2?,x11?,x12?)*FFLink(x1?,x2?,x13?,x14?)*FFLink(x1?,x3?,x15?,x16?)*FFLink(x4?,x2?,x18?,x17?) = myep(x15,x13,x11)*myep(x17,x14,x12)*NC*FFLink(x3,x4,x16,x18);
id FFLink(x1?,x2?,x11?,x12?)*FFLink(x1?,x2?,x13?,x14?)*FFLink(x3?,x1?,x16?,x15?)*FFLink(x2?,x4?,x17?,x18?) = myep(x15,x13,x11)*myep(x17,x14,x12)*NC*FFLink(x3,x4,x16,x18);
id FFLink(x1?,x2?,x11?,x12?)*FFLink(x1?,x2?,x13?,x14?)*FFLink(x3?,x1?,x16?,x15?)*FFLink(x4?,x2?,x18?,x17?) = myep(x15,x13,x11)*myep(x17,x14,x12)*NC*FFLink(x3,x4,x16,x18);


#do i=1,10
    #do j=`i'+1,10
        id FFLink(`j',`i',x1?,x2?) = FFLink(`i',`j',x2,x1);
    #enddo
#enddo

endrepeat;
        
id myep(?args1) = e_(?args1);
id e_(1,2,3)=1;

id FNode(cOla0,cOla0,cOla0,x1?) = 1;


#call LexicographicalLabel

#call CannonicalOrientation

#endprocedure

        

#procedure LexicographicalLabel

.sort
#do i=1,10
    #do j=`i'+1,10
        id FFLink(`i',`j',x1?,x2?) = FFLink(N`i'_?,N`j'_?,x1,x2);
    #enddo
#enddo
        
renumber 0;

#do i=1,10
    #do j=`i'+1,10
        id FFLink(N`j'_?,N`i'_?,x1?,x2?) = FFLink(N`i'_?,N`j'_?,x2,x1);
    #enddo
#enddo

#do i=1,4
argument;
id N`i'_? = `i';
endargument;
#enddo

renumber 0;

#do i=1,10
    #do j=`i'+1,10
        id FFLink(N`j'_?,N`i'_?,x1?,x2?) = FFLink(N`i'_?,N`j'_?,x2,x1);
    #enddo
#enddo

#do i=1,4
argument;
id N`i'_? = {`i'+4};
endargument;
#enddo






#endprocedure
        
#procedure CannonicalOrientation

.sort
CF myep;
#do i=1,10
    #do j=`i'+1,10
        #do k=`j'+1,10
            
            id FFLink(x1?,`i',x11?!{x0},x21?)*FFLink(x1?,`j',x12?!{x0},x32?)*FFLink(x1?,`k',x13?!{x0},x43?) = myep(x11,x12,x13)*FFLink(x1,`i',x0,x21)*FFLink(x1,`j',x0,x32)*FFLink(x1,`k',x0,x43);
            id FFLink(x1?,`i',x11?!{x0},x21?)*FFLink(x1?,`j',x12?!{x0},x32?)*FFLink(`k',x1?,x43?,x13?!{x0}) = myep(x11,x12,x13)*FFLink(x1,`i',x0,x21)*FFLink(x1,`j',x0,x32)*FFLink(`k',x1,x43,x0);
           
            id FFLink(x1?,`i',x11?!{x0},x21?)*FFLink(`j',x1?,x32?,x12?!{x0})*FFLink(x1?,`k',x13?!{x0},x43?) = myep(x11,x12,x13)*FFLink(x1,`i',x0,x21)*FFLink(`j',x1,x32,x0)*FFLink(x1,`k',x0,x43);
            id FFLink(x1?,`i',x11?!{x0},x21?)*FFLink(`j',x1?,x32?,x12?!{x0})*FFLink(`k',x1?,x43?,x13?!{x0}) = myep(x11,x12,x13)*FFLink(x1,`i',x0,x21)*FFLink(`j',x1,x32,x0)*FFLink(`k',x1,x43,x0);
            
            id FFLink(`i',x1?,x21?,x11?!{x0})*FFLink(x1?,`j',x12?!{x0},x32?)*FFLink(x1?,`k',x13?!{x0},x43?) = myep(x11,x12,x13)*FFLink(`i',x1,x21,x0)*FFLink(x1,`j',x0,x32)*FFLink(x1,`k',x0,x43);
            id FFLink(`i',x1?,x21?,x11?!{x0})*FFLink(x1?,`j',x12?!{x0},x32?)*FFLink(`k',x1?,x43?,x13?!{x0}) = myep(x11,x12,x13)*FFLink(`i',x1,x21,x0)*FFLink(x1,`j',x0,x32)*FFLink(`k',x1,x43,x0);
            
            id FFLink(`i',x1?,x21?,x11?!{x0})*FFLink(`j',x1?,x32?,x12?!{x0})*FFLink(x1?,`k',x13?!{x0},x43?) = myep(x11,x12,x13)*FFLink(`i',x1,x21,x0)*FFLink(`j',x1,x32,x0)*FFLink(x1,`k',x0,x43);
            id FFLink(`i',x1?,x21?,x11?!{x0})*FFLink(`j',x1?,x32?,x12?!{x0})*FFLink(`k',x1?,x43?,x13?!{x0}) = myep(x11,x12,x13)*FFLink(`i',x1,x21,x0)*FFLink(`j',x1,x32,x0)*FFLink(`k',x1,x43,x0);

        #enddo
    #enddo
#enddo

id FFLink(?args1,x0,x0) = FFLink(?args1);
id myep(?args1) = e_(?args1);
id e_(1,2,3)=1;

        
#endprocedure
