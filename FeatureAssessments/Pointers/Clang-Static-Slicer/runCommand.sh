
/home/spaits/repo/llvm-project/build/bin/clang --analyze     -Xclang -analyzer-checker=core,alpha.core.SlicingCriterion     -Xclang -analyzer-output=html     -Xclang -analyzer-config -Xclang alpha.core.SlicingCriterion:LineNumber=14     -Xclang -analyzer-config -Xclang alpha.core.SlicingCriterion:ExpressionName=element   PointerArithmetic.c  -o outp

/home/spaits/repo/llvm-project/build/bin/clang --analyze     -Xclang -analyzer-checker=core,alpha.core.SlicingCriterion     -Xclang -analyzer-output=html     -Xclang -analyzer-config -Xclang alpha.core.SlicingCriterion:LineNumber=19     -Xclang -analyzer-config -Xclang alpha.core.SlicingCriterion:ExpressionName=valueToTrack   Aliasing.c     -o outp


