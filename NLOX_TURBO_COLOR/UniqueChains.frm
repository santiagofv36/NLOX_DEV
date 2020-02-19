#-
off statistics;
#include TopologicalColor.h
#include NLOXSimplifyColor.h
#call NLOXSimplifyColorHeader
#call DefineTopologies
l [UC[1]] = FFLink(1,2)*FFLink(1,3)*FFLink(1,4)*FFLink(2,5)*FFLink(2,6)*FFLink(3,5)*FFLink(3,6)*FFLink(4,5)*FFLink(4,6);
l [UC[2]] = FFLink(1,2)*FFLink(1,3)*FFLink(1,4)*FFLink(2,3)*FFLink(2,5)*FFLink(3,6)*FFLink(4,5)*FFLink(4,6)*FFLink(5,6);
l [UC[3]] = FFLink(1,2)*FFLink(1,3)*FFLink(1,4)*FFLink(2,5)*FFLink(2,6)*FFLink(3,5)*FFLink(3,7)*FFLink(4,6)*FFLink(4,8)*FFLink(5,8)*FFLink(6,7)*FFLink(7,8);
l [UC[4]] = FFLink(1,2)*FFLink(1,3)*FFLink(1,4)*FFLink(2,5)*FFLink(2,6)*FFLink(3,5)*FFLink(3,6)*FFLink(4,7)*FFLink(4,8)*FFLink(5,7)*FFLink(6,8)*FFLink(7,8);
l [UC[5]] = FFLink(1,2)*FFLink(1,3)*FFLink(1,4)*FFLink(2,5)*FFLink(2,6)*FFLink(3,5)*FFLink(3,7)*FFLink(4,7)*FFLink(4,8)*FFLink(5,8)*FFLink(6,7)*FFLink(6,8);
l [UC[6]] = FFLink(1,2)*FFLink(1,3)*FFLink(1,4)*FFLink(2,5)*FFLink(2,6)*FFLink(3,5)*FFLink(3,7)*FFLink(4,6)*FFLink(4,7)*FFLink(5,8)*FFLink(6,8)*FFLink(7,8);
l [UC[7]] = FFLink(1,2)*FFLink(1,3)*FFLink(1,4)*FFLink(2,3)*FFLink(2,5)*FFLink(3,6)*FFLink(4,5)*FFLink(4,7)*FFLink(5,8)*FFLink(6,7)*FFLink(6,8)*FFLink(7,8);
l [UC[8]] = FFLink(1,2)*FFLink(1,3)*FFLink(1,4)*FFLink(2,3)*FFLink(2,5)*FFLink(3,6)*FFLink(4,7)*FFLink(4,8)*FFLink(5,6)*FFLink(5,7)*FFLink(6,8)*FFLink(7,8);
l [UC[9]] = FFLink(1,2)*FFLink(1,3)*FFLink(1,4)*FFLink(2,3)*FFLink(2,5)*FFLink(3,6)*FFLink(4,7)*FFLink(4,8)*FFLink(5,7)*FFLink(5,8)*FFLink(6,7)*FFLink(6,8);
l [UC[10]] = FFLink(1,2)*FFLink(1,3)*FFLink(1,4)*FFLink(2,5)*FFLink(2,6)*FFLink(3,5)*FFLink(3,7)*FFLink(4,5)*FFLink(4,8)*FFLink(6,7)*FFLink(6,8)*FFLink(7,8);
l [UC[11]] = FFLink(1,2)*FFLink(1,3)*FFLink(1,4)*FFLink(2,5)*FFLink(2,6)*FFLink(3,5)*FFLink(3,7)*FFLink(4,6)*FFLink(4,8)*FFLink(5,7)*FFLink(6,8)*FFLink(7,8);
l [UC[12]] = FFLink(1,2)*FFLink(1,3)*FFLink(1,4)*FFLink(2,5)*FFLink(2,6)*FFLink(3,7)*FFLink(3,8)*FFLink(4,7)*FFLink(4,8)*FFLink(5,6)*FFLink(5,7)*FFLink(6,8);
l [UC[13]] = FFLink(1,2)*FFLink(1,3)*FFLink(1,4)*FFLink(2,3)*FFLink(2,5)*FFLink(3,6)*FFLink(4,6)*FFLink(4,7)*FFLink(5,7)*FFLink(5,8)*FFLink(6,8)*FFLink(7,8);
l [UC[14]] = FFLink(1,2)*FFLink(1,3)*FFLink(1,4)*FFLink(2,5)*FFLink(2,6)*FFLink(3,5)*FFLink(3,7)*FFLink(4,7)*FFLink(4,8)*FFLink(5,6)*FFLink(6,8)*FFLink(7,8);
l [UC[15]] = FFLink(1,2)*FFLink(1,3)*FFLink(1,4)*FFLink(2,3)*FFLink(2,4)*FFLink(3,4);
l [UC[16]] = FFLink(1,2)*FFLink(1,3)*FFLink(1,4)*FFLink(2,3)*FFLink(2,4)*FFLink(3,5)*FFLink(4,6)*FFLink(5,7)*FFLink(5,8)*FFLink(6,7)*FFLink(6,8)*FFLink(7,8);
l [UC[17]] = FFLink(1,2)*FFLink(1,3)*FFLink(1,4)*FFLink(2,3)*FFLink(2,5)*FFLink(3,5)*FFLink(4,6)*FFLink(4,7)*FFLink(5,8)*FFLink(6,7)*FFLink(6,8)*FFLink(7,8);
#call ChainToTF
.sort             
#call NLOXSimplifyColorTranslateIndices 
argument;                     
id cOli1e = cOlaie1;          
id cOlj1e = cOlaje1;          
id cOli2e = cOlaie2;          
id cOlj2e = cOlaje2;          
id cOli3e = cOlaie3;          
id cOlj3e = cOlaje3;          
id cOli4e = cOlaie4;          
id cOlj4e = cOlaje4;          
id cOli5e = cOlaie5;          
id cOlj5e = cOlaje5;          
endargument;                  
#call NLOXSimplifyColorFooter 
#call NLOXSimplifyColorPrintEn
