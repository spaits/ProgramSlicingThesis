// frama-c -eva -kernel-warn-key CERT:MSC:38=inactive -main main Aliasing.c -slice-pragma main -slicing-level=2 -then-on 'Slicing export' -print > tmp.c
[kernel] Parsing Aliasing.c (with preprocessing)
[eva] Analyzing a complete application starting at main
[eva:initial-state] Values of globals at initialization
  
[eva] ====== VALUES COMPUTED ======
[eva:final-states] Values at end of function main:
  data ∈ {71}
  mp ∈ {{ &data }}
  p1 ∈ {{ &data }}
  p2 ∈ {{ &data }}
  valueToTrack ∈ {{ &data }}
  anotherOne ∈ {92}
  __retres ∈ {0}
[eva:summary] ====== ANALYSIS SUMMARY ======
  ----------------------------------------------------------------------------
  1 function analyzed (out of 1): 100% coverage.
  In this function, 13 statements reached (out of 13): 100% coverage.
  ----------------------------------------------------------------------------
  No errors or warnings raised during the analysis.
  ----------------------------------------------------------------------------
  0 alarms generated by the analysis.
  ----------------------------------------------------------------------------
  No logical properties have been reached by the analysis.
  ----------------------------------------------------------------------------
[slicing] slicing requests in progress...
[slicing] initializing slicing ...
[slicing] interpreting slicing requests from the command line...
[pdg] computing for function main
[pdg] done for function main
[slicing] applying all slicing requests...
[slicing] applying 0 actions...
[slicing] applying all slicing requests...
[slicing] applying 1 actions...
[slicing] applying actions: 1/1...
[slicing] exporting project to 'Slicing export'...
[slicing] applying all slicing requests...
[slicing] applying 0 actions...
[sparecode] remove unused global declarations from project 'Slicing export tmp'
[sparecode] removed unused global declarations in new project 'Slicing export'
/* Generated by Frama-C */
void main(void)
{
  int data;
  int *mp;
  int *valueToTrack;
  mp = & data;
  valueToTrack = mp;
  /*@ slice pragma expr valueToTrack; */ ;
  return;
}


