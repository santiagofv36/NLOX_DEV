


#include config.inc
#include `leftDiagDefFile' # global

#message >> Spacetime Handler loaded


#procedure ApplyGluonOnShellConditions

******************************************************************************************
***
***  This set of identities applies:
***               1) Momemtum conservation
***               2) Reduction to minimal set of invariants
***               3) Ep_i.p_i = EpS_i.p_i = 0              
***
*****************************************************************************************

    id `ELIMMOM';
    .sort
    #if (`leftNLoops' == 0) 
    id d = 4;
    #endif
    #include processSpecific.inc
    id VB(fEpsG,PVEC?,PVEC?) = 0;
    id VB(fEpsGStar,PVEC?,PVEC?) = 0;
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
***  If the number of gluons is odd the its polarization gets replaced by -g_(mu,nu).
***  
*************************************************************************************************

auto v PVEC;
auto i grm;
T GRM;

#do i=1,6
    #do j=`i'+1,6

***************************************************************************
***
***    Here we attempt to pair the ith and jth particle iff both are gluons 
***    we do so and mark the replaced pair with GRM(grmi,grmj). We then 
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
***     polarization sum by -g_(mu,nu) (???) this is a bit mysterious
***     since there is no gauge fixing q_mu that will produce this, in general
***     one must replace:
***     
***     (Ep_i(mu)*EpS_i(nu)) -> -g_(mu,nu) + 1/(p_i.q)*(p_i(mu)q(nu)+p_i(nu)q(mu)) 
*** 
***      So I do not know why/if this is acceptable to do. However it is done 
***      in the main branch so I kept it.
***      
***
*******************************************************************************
    
    id VB(fEpsG,v1?,PVEC?)*VB(fEpsGStar,v2?,PVEC?)
      =(-d_(v1,v2));
      
    #call ApplyGluonOnShellConditions

*******************************************************************************
***
***    Re-expresing 1/(pi.pj) by DS. At the moment this might produce DS's which
***    are not simplified (they are acted on but the result is actually larger) 
***    by the ELIMMOM, this only happens if there is a single initial state gluon.
***
*******************************************************************************
     
      id PVEC1?.PVEC2?^-1 = 2*DS(PVEC1+PVEC2,0,1);
      
      argument;
        id `ELIMMOM';
      endargument;
      
      splitarg;
      id DS(PVEC1?,PVEC2?,0,1) = 1/(2*(PVEC1.PVEC2));
      #do i=1,10
      id PVEC1?.PVEC2?^{`i'-11} = (2^{11-`i'})*DS(PVEC1+PVEC2,0,{11-`i'});
      #enddo
      
#endprocedure
      
            
