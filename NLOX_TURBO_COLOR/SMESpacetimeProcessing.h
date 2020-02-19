

#procedure ApplyGluonOnShellConditions

******************************************************************************************
***
***  This set of identities applies:
***               1) Momemtum conservation
***               2) Reduction to minimal set of invariants
***               3) Ep_i.p_i = EpS_i.p_i = 0              
***
*****************************************************************************************

    .sort
    #if (`leftNLoops' == 0) 
    id d = 4;
    #endif
    #include processSpecific.inc
    id VB(fEpsG,p1?,p1?) = 0;
    id VB(fEpsGStar,p1?,p1?) = 0;
    .sort
    
#endprocedure



#procedure ProcessGluons
    

.sort

   
#message >> processing gluon lines

********************************************************************************************
***
***  Procedure to handle gluon polarizations
***
***  The main idea is to pair gluons, we do so by trying to pair the ith-particle with the 
***  jth-particle and do so iff both are gluons. If the replacement is possible we place a marker 
***  called GRM to signal that two gluons have been paired. We replace the gluon 
***  polarization sums one at the time and apply on-shell rules as often as possible. 
***  We also keep the 1/(pi.pj) as is in hopes that it might cancel against a numerator and 
***  simplify further, at the end we go back to DS to be able to pass the C code generator.
***  If the number of gluons is odd the last polarization sum gets replaced by -g_(mu,nu).
***  
*************************************************************************************************

auto i grm;
T GRM;

#do i=1,6
    #do j=`i'+1,6

***************************************************************************
***
***    Here we attempt to pair the ith and jth particle, if both are gluons 
***    we do so, we mark the replaced pair with GRM(grmi,grmj). We then 
***    apply all on-shell realtions for gluons (see its comment)   
***
**************************************************************************
        
        id VB(fEpsG,v1?,p`i')*VB(fEpsGStar,v2?,p`i')*VB(fEpsG,v3?,p`j')*VB(fEpsGStar,v4?,p`j') 
        =  GRM(grm`i',grm`j')*VB(fEpsG,v3,p`j')*VB(fEpsGStar,v4,p`j') 
          *(-d_(v1,v2)+(1/(p`i'.p`j'))*(p`i'(v1)*p`j'(v2)+p`i'(v2)*p`j'(v1)));
              
        #call ApplyGluonOnShellConditions

***************************************************************************
***
***    This second piece of code is active only if the first piece went through
***    the GRM marker makes sure this is the case. Then we again reduce the 
***    expressions by applying on-shell equations.
***
****************************************************************************
          
        id GRM(grm`i',grm`j')*VB(fEpsG,v1?,p`j')*VB(fEpsGStar,v2?,p`j')
        =(-d_(v1,v2)+(1/(p`i'.p`j'))*(p`i'(v1)*p`j'(v2)+p`i'(v2)*p`j'(v1)));
        
        #call ApplyGluonOnShellConditions

    #enddo
#enddo
   
*****************************************************************************
***
***     Last Gluon contraction, at this late stage we repalce the last gluon 
***     polarization sum by -g_(mu,nu). Fernando provided a proof of why this 
***     is aceptable, the reasoning revolves around the fact that there 
***     cannot be ghost diagrams associated to this final single gluon line.
***
*******************************************************************************
    
    id VB(fEpsG,v1?,p1?)*VB(fEpsGStar,v2?,p1?)
      =(-d_(v1,v2));
      
    #call ApplyGluonOnShellConditions


      
#endprocedure



      
#procedure ConvertToDS
      
*******************************************************************************
***
***    Procedure to translate 1/(pi.pj) into DS terms that the C 
***    code generator can handle
***
*******************************************************************************

#do i=1,6
    #do j=`i'+1,6
        #if (`i'>2&&`j'<=2)||(`i'<=2&&`j'>2)
            id (p`i'.p`j')^-1 = -2*DS(p`i'-p`j',0,1);
        #else 
            id (p`i'.p`j')^-1 =  2*DS(p`i'+p`j',0,1);
        #endif
    #enddo
#enddo

repeat id DS(?args,n1?)*DS(?args,n2?) = DS(?args,n1+n2);

argument;
    id `ELIMMOM';
endargument;
      
#endprocedure
