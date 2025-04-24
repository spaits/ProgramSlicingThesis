#!/bin/bash

/home/spaits/repo/llvm-project/build/bin/clang --analyze -Xclang -analyzer-checker=core,alpha.core.SlicingCriterion -Xclang -analyzer-output=html -Xclang -analyzer-config -Xclang alpha.core.SlicingCriterion:LineNumber=8 -Xclang -analyzer-config -Xclang alpha.core.SlicingCriterion:ExpressionName=i LoopBreak.c  -o outp

/home/spaits/repo/llvm-project/build/bin/clang --analyze -Xclang -analyzer-checker=core,alpha.core.SlicingCriterion -Xclang -analyzer-output=html -Xclang -analyzer-config -Xclang alpha.core.SlicingCriterion:LineNumber=13 -Xclang -analyzer-config -Xclang alpha.core.SlicingCriterion:ExpressionName=value UnfeasiblePathImplied.c  -o outp

/home/spaits/repo/llvm-project/build/bin/clang --analyze -Xclang -analyzer-checker=core,alpha.core.SlicingCriterion -Xclang -analyzer-output=html -Xclang -analyzer-config -Xclang alpha.core.SlicingCriterion:LineNumber=9 -Xclang -analyzer-config -Xclang alpha.core.SlicingCriterion:ExpressionName=value UnfeasiblePath.c  -o outp

/home/spaits/repo/llvm-project/build/bin/clang --analyze -Xclang -analyzer-checker=core,alpha.core.SlicingCriterion -Xclang -analyzer-output=html -Xclang -analyzer-config -Xclang alpha.core.SlicingCriterion:LineNumber=10 -Xclang -analyzer-config -Xclang alpha.core.SlicingCriterion:ExpressionName=value ConcreteValuePropagation.c  -o outp

/home/spaits/repo/llvm-project/build/bin/clang --analyze -Xclang -analyzer-checker=core,alpha.core.SlicingCriterion -Xclang -analyzer-output=html -Xclang -analyzer-config -Xclang alpha.core.SlicingCriterion:LineNumber=8 -Xclang -analyzer-config -Xclang alpha.core.SlicingCriterion:ExpressionName=i LoopBreakContinue.c  -o outp
