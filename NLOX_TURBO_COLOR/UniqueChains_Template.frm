
#-
off statistics;
#include TopologicalColor.h
#include NLOXSimplifyColor.h

#call NLOXSimplifyColorHeader
#call DefineTopologies

l [UC[1]] = Link(1,2)*Link(1,3)*Link(1,4)*Link(2,5)*Link(2,6)*Link(3,5)*Link(3,6)*Link(4,5)*Link(4,6);
l [UC[2]] = Link(1,2)*Link(1,3)*Link(1,4)*Link(2,3)*Link(2,5)*Link(3,6)*Link(4,5)*Link(4,6)*Link(5,6);
l [UC[3]] = Link(1,2)*Link(1,3)*Link(1,4)*Link(2,5)*Link(2,6)*Link(3,5)*Link(3,7)*Link(4,6)*Link(4,8)*Link(5,8)*Link(6,7)*Link(7,8);
l [UC[4]] = Link(1,2)*Link(1,3)*Link(1,4)*Link(2,5)*Link(2,6)*Link(3,5)*Link(3,6)*Link(4,7)*Link(4,8)*Link(5,7)*Link(6,8)*Link(7,8);
l [UC[5]] = Link(1,2)*Link(1,3)*Link(1,4)*Link(2,5)*Link(2,6)*Link(3,5)*Link(3,7)*Link(4,7)*Link(4,8)*Link(5,8)*Link(6,7)*Link(6,8);
l [UC[6]] = Link(1,2)*Link(1,3)*Link(1,4)*Link(2,5)*Link(2,6)*Link(3,5)*Link(3,7)*Link(4,6)*Link(4,7)*Link(5,8)*Link(6,8)*Link(7,8);
l [UC[7]] = Link(1,2)*Link(1,3)*Link(1,4)*Link(2,3)*Link(2,5)*Link(3,6)*Link(4,5)*Link(4,7)*Link(5,8)*Link(6,7)*Link(6,8)*Link(7,8);
l [UC[8]] = Link(1,2)*Link(1,3)*Link(1,4)*Link(2,3)*Link(2,5)*Link(3,6)*Link(4,7)*Link(4,8)*Link(5,6)*Link(5,7)*Link(6,8)*Link(7,8);
l [UC[9]] = Link(1,2)*Link(1,3)*Link(1,4)*Link(2,3)*Link(2,5)*Link(3,6)*Link(4,7)*Link(4,8)*Link(5,7)*Link(5,8)*Link(6,7)*Link(6,8);
l [UC[10]] = Link(1,2)*Link(1,3)*Link(1,4)*Link(2,5)*Link(2,6)*Link(3,5)*Link(3,7)*Link(4,5)*Link(4,8)*Link(6,7)*Link(6,8)*Link(7,8);
l [UC[11]] = Link(1,2)*Link(1,3)*Link(1,4)*Link(2,5)*Link(2,6)*Link(3,5)*Link(3,7)*Link(4,6)*Link(4,8)*Link(5,7)*Link(6,8)*Link(7,8);
l [UC[12]] = Link(1,2)*Link(1,3)*Link(1,4)*Link(2,5)*Link(2,6)*Link(3,7)*Link(3,8)*Link(4,7)*Link(4,8)*Link(5,6)*Link(5,7)*Link(6,8);
l [UC[13]] = Link(1,2)*Link(1,3)*Link(1,4)*Link(2,3)*Link(2,5)*Link(3,6)*Link(4,6)*Link(4,7)*Link(5,7)*Link(5,8)*Link(6,8)*Link(7,8);
l [UC[14]] = Link(1,2)*Link(1,3)*Link(1,4)*Link(2,5)*Link(2,6)*Link(3,5)*Link(3,7)*Link(4,7)*Link(4,8)*Link(5,6)*Link(6,8)*Link(7,8);
l [UC[15]] = Link(1,2)*Link(1,3)*Link(1,4)*Link(2,3)*Link(2,4)*Link(3,4);
l [UC[16]] = Link(1,2)*Link(1,3)*Link(1,4)*Link(2,3)*Link(2,4)*Link(3,5)*Link(4,6)*Link(5,7)*Link(5,8)*Link(6,7)*Link(6,8)*Link(7,8);
l [UC[17]] = Link(1,2)*Link(1,3)*Link(1,4)*Link(2,3)*Link(2,5)*Link(3,5)*Link(4,6)*Link(4,7)*Link(5,8)*Link(6,7)*Link(6,8)*Link(7,8);


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
#call NLOXSimplifyColorPrintEnd



