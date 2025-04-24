#!/bin/bash

/home/spaits/repo/llvm-project/build/bin/clang --analyze -Xclang -analyzer-checker=core,alpha.core.SlicingCriterion -Xclang -analyzer-output=html -Xclang -analyzer-config -Xclang alpha.core.SlicingCriterion:LineNumber=9 -Xclang -analyzer-config -Xclang alpha.core.SlicingCriterion:ExpressionName=i FunctionCall.c  -o outp

/home/spaits/repo/llvm-project/build/bin/clang --analyze -Xclang -analyzer-checker=core,alpha.core.SlicingCriterion -Xclang -analyzer-output=html -Xclang -analyzer-config -Xclang alpha.core.SlicingCriterion:LineNumber=11 -Xclang -analyzer-config -Xclang alpha.core.SlicingCriterion:ExpressionName=i IndirectFunctionCall.c  -o outp
