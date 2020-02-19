

import amplitudeTools as aTools


def UniqueChains(seq):
    seen = [] 
    for item in seq:
        chain = item['value'][0][0]
        NewChain = ''
        record = 0
        for i in chain:
            if i == 'C' or i== 'c': record = 1
            if(record==1): NewChain += i
        if NewChain in seen: continue
        if (len(NewChain)): seen.append(NewChain)
    return seen

def UniqueChainsReplaced(filename):
    
    UniqueChainsFile = "UniqueChains.frm"
    UCF = open(UniqueChainsFile,"w")
    
    UniqueChainsReplacedFile = "UniqueChains"+filename
    UCRF = open(UniqueChainsReplacedFile,"w")
    
    ### Global Header 
    Header  = '#-\n'+'off statistics;\n'
    Header += '#include TopologicalColor.h\n'
    Header += '#include NLOXSimplifyColor.h\n'
    Header += '#call NLOXSimplifyColorHeader\n'
    Header += '#call DefineTopologies\n'
    UCF.write(Header)
    UCRF.write(Header)
    ###
    
    
    Expressions = aTools.splitExpressions(filename)
    seen = {}
    ChainCount = 0
    for Term in Expressions:
        UCRFLine = 'l '+Term['name'] + ' = '
        Chain = Term['value'][0][0]
        NewChain = ''
        Prefactor = ''
        record = 0
        for i in Chain:
            if i == 'F': 
                record = 1
            if(record==1): 
                NewChain += i
            else:
                Prefactor += i
        UCRFLine += Prefactor 
        UCRF.write(UCRFLine)
        if NewChain in seen.keys():
            UCRFLine = seen[NewChain] + ';\n'
            UCRF.write(UCRFLine)
            continue
        if (len(NewChain)):
            ChainCount +=1
            UCFLine = "l [UC["+str(ChainCount)+"]] = "+NewChain+";\n"
            UCF.write(UCFLine)
            seen[NewChain] = 'UC['+str(ChainCount)+']'
            
            UCRFLine = seen[NewChain]
            UCRF.write(UCRFLine)
        UCRF.write(';\n')
    
    UCRFLine  = '#include FillUniqueChains.id\n'
    UCRFLine += '#call NLOXSimplifyColorPrintEnd\n'
    
    
    
    UCFLine = ''
    UCFLine += '#call ChainToTF\n'
    UCFLine += '.sort             \n'
    UCFLine += '#call NLOXSimplifyColorTranslateIndices \n'
    UCFLine += 'argument;                     \n'
    UCFLine += 'id cOli1e = cOlaie1;          \n'
    UCFLine += 'id cOlj1e = cOlaje1;          \n'
    UCFLine += 'id cOli2e = cOlaie2;          \n'
    UCFLine += 'id cOlj2e = cOlaje2;          \n'
    UCFLine += 'id cOli3e = cOlaie3;          \n'
    UCFLine += 'id cOlj3e = cOlaje3;          \n'
    UCFLine += 'id cOli4e = cOlaie4;          \n'
    UCFLine += 'id cOlj4e = cOlaje4;          \n'
    UCFLine += 'id cOli5e = cOlaie5;          \n'
    UCFLine += 'id cOlj5e = cOlaje5;          \n'
    UCFLine += 'endargument;                  \n'
    UCFLine += '#call NLOXSimplifyColorFooter \n'
    UCFLine += '#call NLOXSimplifyColorPrintEnd\n'
    UCF.write(UCFLine)

aTools.runForm("ColorProducts.id.frm", "COLOR.out",False,'form')
UniqueChainsReplaced('COLOR.out')
aTools.runForm("UniqueChains.frm","UniqueChains.frm.out",False,'form')
aTools.FormExprsToTable("UniqueChains.frm.out","FillUniqueChains.id")

