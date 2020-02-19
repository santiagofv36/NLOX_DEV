**********************************************************************
*
* Process specific
*
**********************************************************************

* input files
#define leftDiagDefFile "/home/diogenes1991/Pole_Checks/gg_ggg_born/gg_ggg/diags/tree/tree_g3e0.dia"
#define rightDiagDefFile "/home/diogenes1991/Pole_Checks/gg_ggg_born/gg_ggg/diags/tree_star/tree_star_g3e0.dia"
#define leftNLoops "0"
#define rightNLoops "0"
#define renorm "0"

* process kinematics
#define kinematicsFile "processSpecific.inc"

* number of external quarks and gluons, for color average/sum
#define nInGluons "2"
#define nInQuarks "0"

* total number of incoming fermions and vector bosons
#define nInFermions "0"
#define nInMassiveVBs "0"
#define nInMasslessVBs "2"

* final-state symmetry factor
#define symmetryFactor "6"

* gauge to use for *all* internal bosons
#define GAUGE "0"
#define nfl "1"
#define dimScheme "HV"

* enables/disables complex mass scheme
#define complexMass "0"

* boson specific
#define transversePhotons "1"
#define transverseGluons "1"
#define transverseZW "0"
#define gluGaugeConditions "1"

* spinor chain simplifications
#define applyDiracEquation "1"

* debugging settings
#define disableEpsTensor "0"
#define oldDiagColor "1"
#define colorCorr "0"
#define oldTensorDec "1"

#define colorIDNew "1"
* compute only a subset?
#define numPieces "4"
#define subsetNLODiagrams "0"
#define subsetfirst "0"
#define subsetlast "0"
#define xsectNorm "1"

**********************************************************************
*
* Global
*
**********************************************************************

#define savDir "sav"
#define mathDir "math"
#define idDir "ids"
#define logDir "logs"
#define diagResPrefix "diag"
#define simpDiagResPrefix "simpdiag"
#define xsectionResPrefix "xsection"
#define leftMarker "l"
#define rightMarker "r"
