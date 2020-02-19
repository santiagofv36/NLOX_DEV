


#include config.inc
#include `leftDiagDefFile' # global

#message >> Spacetime Handler loaded


#procedure ApplyGluonOnShellConditions

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

***********************************************************************************
***
***   It semms like 4 rules are needed because the VB might have been contracted 
***   with some vectors and thus the 4 possible cases. Might be easier than this.
***
************************************************************************************
        

        #message FORM is now trying to pair Gluons `i' and `j' in 
        print;
        
        id VB(fEpsG,v1?,p`i')*VB(fEpsGStar,v2?,p`i')*VB(fEpsG,v3?,p`j')*VB(fEpsGStar,v4?,p`j') 
        =  GRM(grm`i',grm`j')*VB(fEpsG,v3,p`j')*VB(fEpsGStar,v4,p`j') 
          *(-d_(v1,v2)+(1/(p`i'.p`j'))*(p`i'(v1)*p`j'(v2)+p`i'(v2)*p`j'(v1)));
              
*        id VB(fEpsG,PVEC?,p`i')*VB(fEpsGStar,v2?,p`i')*VB(fEpsG,v3?,p`j')*VB(fEpsGStar,v4?,p`j') 
*        =  GRM(grm`i',grm`j')*VB(fEpsG,v3,p`j')*VB(fEpsGStar,v4,p`j') 
*          *(-PVEC(v2)+(1/(p`i'.p`j'))*((p`i'.PVEC)*p`j'(v2)+p`i'(v2)*(p`j'.PVEC)));
*        
*        id VB(fEpsGStar,PVEC?,p`i')*VB(fEpsG,v2?,p`i')*VB(fEpsG,v3?,p`j')*VB(fEpsGStar,v4?,p`j') 
*        =  GRM(grm`i',grm`j')*VB(fEpsG,v3,p`j')*VB(fEpsGStar,v4,p`j') 
*          *(-PVEC(v2)+(1/(p`i'.p`j'))*((p`i'.PVEC)*p`j'(v2)+p`i'(v2)*(p`j'.PVEC)));
*          
*        id VB(fEpsG,PVEC1?,p`i')*VB(fEpsGStar,PVEC2?,p`i')*VB(fEpsG,v3?,p`j')*VB(fEpsGStar,v4?,p`j') 
*        =  GRM(grm`i',grm`j')*VB(fEpsG,v3,p`j')*VB(fEpsGStar,v4,p`j') 
*          *(-(PVEC1.PVEC2)+(1/(p`i'.p`j'))*((p`i'.PVEC1)*(p`j'.PVEC2)+(p`i'.PVEC2)*(p`j'.PVEC1)));
*        
        #call ApplyGluonOnShellConditions
          
        
        id GRM(grm`i',grm`j')*VB(fEpsG,v1?,p`j')*VB(fEpsGStar,v2?,p`j')
        =(-d_(v1,v2)+(1/(p`i'.p`j'))*(p`i'(v1)*p`j'(v2)+p`i'(v2)*p`j'(v1)));
        
*       id GRM(grm`i',grm`j')*VB(fEpsG,PVEC?,p`j')*VB(fEpsGStar,v2?,p`j')
*       =(-PVEC(v2)+(1/(p`i'.p`j'))*((p`i'.PVEC)*p`j'(v2)+p`i'(v2)*(p`j'.PVEC)));
*       
*       id GRM(grm`i',grm`j')*VB(fEpsGStar,PVEC?,p`j')*VB(fEpsG,v2?,p`j')
*       =(-PVEC(v2)+(1/(p`i'.p`j'))*((p`i'.PVEC)*p`j'(v2)+p`i'(v2)*(p`j'.PVEC)));
*       
*       id GRM(grm`i',grm`j')*VB(fEpsG,PVEC1?,p`j')*VB(fEpsGStar,PVEC2?,p`j')
*       =(-(PVEC1.PVEC2)+(1/(p`i'.p`j'))*((p`i'.PVEC1)*(p`j'.PVEC2)+(p`i'.PVEC2)*(p`j'.PVEC1)));
*       
        #call ApplyGluonOnShellConditions


        #message The resulting expression is:
        print;

    #enddo
#enddo
    
***     Last Gluon contraction
    
    id VB(fEpsG,PVEC1?,PVEC?)*VB(fEpsGStar,PVEC2?,PVEC?)
      =(-(PVEC1.PVEC2));
      
    #call ApplyGluonOnShellConditions


*** Re-expresing 1/(pi.pj) by DS's 
     
      id PVEC1?.PVEC2?^-1 = 2*DS(PVEC1+PVEC2,0,1);
      
      argument;
        id `ELIMMOM';
      endargument;
      
      splitarg;
      id DS(PVEC1?,PVEC2?,0,1) = 1/(2*(PVEC1.PVEC2));
      #do i=1,10
      #message id PVEC1?.PVEC2?^{`i'-11} = (2^{11-`i'})*DS(PVEC1+PVEC2,0,{11-`i'});
      id PVEC1?.PVEC2?^{`i'-11} = (2^{11-`i'})*DS(PVEC1+PVEC2,0,{11-`i'});
      #enddo
      
#endprocedure
      
      
#procedure EliminateDS

      
#endprocedure
      
