[kernel] Parsing linenoiseNoStdDef.c (with preprocessing)
[variadic:libc:frama-c] Warning: 
  Unable to locate ACSL predicate valid_read_string which should be in the Frama-C LibC. Correct specifications can't be generated.
[variadic:libc:frama-c] Warning: 
  Unable to locate ACSL predicate format_length which should be in the Frama-C LibC. Correct specifications can't be generated.
[variadic] Warning: Unable to locate __fc_FILE field __fc_FILE_data.
[variadic:libc:frama-c] Warning: 
  Unable to locate global __fc_stdout which should be in the Frama-C LibC. Correct specifications can't be generated.
[variadic:typing] linenoiseNoStdDef.c:1159: Warning: 
  Incorrect type for argument 3. The argument will be cast from int to unsigned int.
[eva:builtins:missing-spec] linenoiseNoStdDef.c:40: Warning: 
  The builtin for function memmove will not be used, as its frama-c libc specification is not available.
[eva:builtins:missing-spec] linenoiseNoStdDef.c:37: Warning: 
  The builtin for function realloc will not be used, as its frama-c libc specification is not available.
[eva:builtins:missing-spec] linenoiseNoStdDef.c:47: Warning: 
  The builtin for function strchr will not be used, as its frama-c libc specification is not available.
[eva:builtins:missing-spec] linenoiseNoStdDef.c:35: Warning: 
  The builtin for function malloc will not be used, as its frama-c libc specification is not available.
[eva:builtins:missing-spec] linenoiseNoStdDef.c:36: Warning: 
  The builtin for function memcpy will not be used, as its frama-c libc specification is not available.
[eva:builtins:missing-spec] linenoiseNoStdDef.c:24: Warning: 
  The builtin for function free will not be used, as its frama-c libc specification is not available.
[eva:builtins:missing-spec] linenoiseNoStdDef.c:34: Warning: 
  The builtin for function strlen will not be used, as its frama-c libc specification is not available.
[eva:builtins:missing-spec] linenoiseNoStdDef.c:38: Warning: 
  The builtin for function memset will not be used, as its frama-c libc specification is not available.
[eva] Analyzing a complete application starting at refreshMultiLine
[eva:initial-state] Values of globals at initialization
  errno ∈ {42}
  linenoiseEditMore ∈
                   {{ "If you see this, you are misusing the API: when linenoiseEditFeed() is called, if it returns linenoiseEditMore the user is yet editing the line. See the README file for more information." }}
  unsupported_term[0] ∈ {{ "dumb" }}
                  [1] ∈ {{ "cons25" }}
                  [2] ∈ {{ "emacs" }}
                  [3] ∈ {0}
  completionCallback ∈ {0}
  hintsCallback ∈ {0}
  freeHintsCallback ∈ {0}
  orig_termios ∈ {0}
  maskmode ∈ {0}
  rawmode ∈ {0}
  mlmode ∈ {0}
  atexit_registered ∈ {0}
  history_max_len ∈ {100}
  history_len ∈ {0}
  history ∈ {0}
[eva:alarm] linenoiseNoStdDef.c:616: Warning: 
  out of bounds read. assert \valid_read(&l->prompt);
[kernel:annot:missing-spec] linenoiseNoStdDef.c:616: Warning: 
  Neither code nor specification for function strlen,
   generating default assigns. See -generated-spec-* options for more info
[eva] using specification for function strlen
[eva:alarm] linenoiseNoStdDef.c:617: Warning: 
  division by zero. assert l->cols ≢ 0;
[eva:alarm] linenoiseNoStdDef.c:629: Warning: 
  signed overflow. assert -2147483648 ≤ old_rows - rpos;
[eva:alarm] linenoiseNoStdDef.c:629: Warning: 
  signed overflow. assert old_rows - rpos ≤ 2147483647;
[eva:alarm] linenoiseNoStdDef.c:631: Warning: 
  signed overflow. assert -2147483648 ≤ old_rows - rpos;
[eva:alarm] linenoiseNoStdDef.c:631: Warning: 
  signed overflow. assert old_rows - rpos ≤ 2147483647;
[eva] using specification for function snprintf_va_8
[kernel:annot:missing-spec] linenoiseNoStdDef.c:503: Warning: 
  Neither code nor specification for function realloc,
   generating default assigns. See -generated-spec-* options for more info
[eva] using specification for function realloc
[eva:invalid-assigns] linenoiseNoStdDef.c:503: 
  Completely invalid destination for assigns clause *((char *)a + (0 ..)).
  Ignoring.
[kernel:annot:missing-spec] linenoiseNoStdDef.c:506: Warning: 
  Neither code nor specification for function memcpy,
   generating default assigns. See -generated-spec-* options for more info
[eva] using specification for function memcpy
[eva:invalid-assigns] linenoiseNoStdDef.c:506: 
  Completely invalid destination for assigns clause *((char *)a + (0 ..)).
  Ignoring.
[eva:alarm] linenoiseNoStdDef.c:636: Warning: 
  signed overflow. assert -2147483648 ≤ old_rows - 1;
[eva] using specification for function snprintf_va_9
[eva:alarm] linenoiseNoStdDef.c:503: Warning: 
  signed overflow. assert -2147483648 ≤ ab->len + len;
[eva:alarm] linenoiseNoStdDef.c:503: Warning: 
  signed overflow. assert ab->len + len ≤ 2147483647;
[eva:alarm] linenoiseNoStdDef.c:508: Warning: 
  signed overflow. assert -2147483648 ≤ ab->len + len;
[eva:alarm] linenoiseNoStdDef.c:508: Warning: 
  signed overflow. assert ab->len + len ≤ 2147483647;
[eva] linenoiseNoStdDef.c:636: starting to merge loop iterations
[eva] using specification for function snprintf_va_10
[eva] using specification for function snprintf_va_11
[eva:alarm] linenoiseNoStdDef.c:674: Warning: 
  signed overflow. assert rows + 1 ≤ 2147483647;
[eva:alarm] linenoiseNoStdDef.c:683: Warning: 
  signed overflow. assert -2147483648 ≤ rows - rpos2;
[eva:alarm] linenoiseNoStdDef.c:683: Warning: 
  signed overflow. assert rows - rpos2 ≤ 2147483647;
[eva:alarm] linenoiseNoStdDef.c:685: Warning: 
  signed overflow. assert -2147483648 ≤ rows - rpos2;
[eva:alarm] linenoiseNoStdDef.c:685: Warning: 
  signed overflow. assert rows - rpos2 ≤ 2147483647;
[eva] using specification for function snprintf_va_12
[eva:alarm] linenoiseNoStdDef.c:690: Warning: 
  division by zero. assert (int)l->cols ≢ 0;
[eva:alarm] linenoiseNoStdDef.c:690: Warning: 
  signed overflow. assert -2147483648 ≤ plen + (int)l->pos;
[eva:alarm] linenoiseNoStdDef.c:690: Warning: 
  signed overflow. assert plen + (int)l->pos ≤ 2147483647;
[eva] using specification for function snprintf_va_13
[eva] using specification for function snprintf_va_14
[kernel:annot:missing-spec] linenoiseNoStdDef.c:702: Warning: 
  Neither code nor specification for function write,
   generating default assigns. See -generated-spec-* options for more info
[eva] using specification for function write
[kernel:annot:missing-spec] linenoiseNoStdDef.c:512: Warning: 
  Neither code nor specification for function free,
   generating default assigns. See -generated-spec-* options for more info
[eva] using specification for function free
[eva:invalid-assigns] linenoiseNoStdDef.c:512: 
  Completely invalid destination for assigns clause *((char *)a + (0 ..)).
  Ignoring.
[scope:rm_asserts] removing 6 assertion(s)
[eva] ====== VALUES COMPUTED ======
[eva:final-states] Values at end of function abInit:
  ab{.b; .len} ∈ {0}
    .[bits 96 to 127] ∈ UNINITIALIZED
[eva:final-states] Values at end of function abFree:
  
[eva:final-states] Values at end of function abAppend:
  new ∈ [--..--]
  ab{.b; .len} ∈ [--..--]
    .[bits 96 to 127] ∈ UNINITIALIZED
[eva:final-states] Values at end of function refreshShowHints:
  
[eva:final-states] Values at end of function refreshMultiLine:
  seq[0..63] ∈ [--..--] or UNINITIALIZED
  plen ∈ [--..--]
  rows ∈ [--..--]
  rpos ∈ [--..--]
  rpos2 ∈ [--..--] or UNINITIALIZED
  col ∈ [-2147483647..2147483647] or UNINITIALIZED
  old_rows ∈ [--..--]
  fd ∈ [--..--]
  j ∈ [0..2147483647] or UNINITIALIZED
  ab{.b; .len} ∈ [--..--]
    .[bits 96 to 127] ∈ UNINITIALIZED
  S_l[0].in_completion ∈ [--..--]
     [0].[bits 32 to 63] ∈ UNINITIALIZED
     [0]{.completion_idx; .ifd; .ofd} ∈ [--..--]
     [0].buf ∈ {{ NULL ; &S_buf_0_S_l[0] }}
     [0].buflen ∈ [--..--]
     [0].prompt ∈ {{ NULL ; &S_prompt_0_S_l[0] }}
     [0]{.plen; .pos; .oldpos; .len} ∈ [--..--]
     [0].cols ∈ [1..18446744073709551615]
     [0]{.oldrows; .history_index} ∈ [--..--]
     [0].[bits 800 to 831] ∈ UNINITIALIZED
     [1].in_completion ∈ [--..--]
     [1].[bits 32 to 63] ∈ UNINITIALIZED
     [1]{.completion_idx; .ifd; .ofd} ∈ [--..--]
     [1].buf ∈ {{ NULL ; &S_buf_1_S_l[0] }}
     [1].buflen ∈ [--..--]
     [1].prompt ∈ {{ NULL ; &S_prompt_1_S_l[0] }}
     [1]{.plen; .pos; .oldpos; .len; .cols; .oldrows; .history_index} ∈
     [--..--]
     [1].[bits 800 to 831] ∈ UNINITIALIZED
[eva:summary] ====== ANALYSIS SUMMARY ======
  ----------------------------------------------------------------------------
  5 functions analyzed (out of 51): 9% coverage.
  In these functions, 77 statements reached (out of 113): 68% coverage.
  ----------------------------------------------------------------------------
  Some errors and warnings have been raised during the analysis:
    by the Eva analyzer:      0 errors    8 warnings
    by the Frama-C kernel:    0 errors    5 warnings
  ----------------------------------------------------------------------------
  19 alarms generated by the analysis:
      16 integer overflows
       2 divisions by zero
       1 invalid memory access
  ----------------------------------------------------------------------------
  Evaluation of the logical properties reached by the analysis:
    Assertions        0 valid     0 unknown     0 invalid      0 total
    Preconditions     7 valid     0 unknown     0 invalid      7 total
  100% of the logical properties reached have been proven.
  ----------------------------------------------------------------------------
[slicing] slicing requests in progress...
[slicing] initializing slicing ...
[slicing] interpreting slicing requests from the command line...
[pdg] computing for function refreshMultiLine
[from] Computing for function strlen
[from] Done for function strlen
[from] Computing for function abInit
[from] Done for function abInit
[from] Computing for function snprintf_va_8
[from] Done for function snprintf_va_8
[from] Computing for function abAppend
[from] Computing for function realloc <-abAppend
[from] Done for function realloc
[from] Computing for function memcpy <-abAppend
[from] Done for function memcpy
[from] Done for function abAppend
[from] Computing for function snprintf_va_9
[from] Done for function snprintf_va_9
[from] Computing for function snprintf_va_10
[from] Done for function snprintf_va_10
[from] Computing for function refreshShowHints
[from] Done for function refreshShowHints
[from] Computing for function snprintf_va_11
[from] Done for function snprintf_va_11
[from] Computing for function snprintf_va_12
[from] Done for function snprintf_va_12
[from] Computing for function snprintf_va_13
[from] Done for function snprintf_va_13
[from] Computing for function snprintf_va_14
[from] Done for function snprintf_va_14
[from] Computing for function write
[from] Done for function write
[from] Computing for function abFree
[from] Computing for function free <-abFree
[from] Done for function free
[from] Done for function abFree
[pdg] done for function refreshMultiLine
[slicing] applying all slicing requests...
[slicing] applying 0 actions...
[slicing] applying all slicing requests...
[slicing] applying 1 actions...
[slicing] applying actions: 1/1...
[pdg] computing for function abAppend
[pdg] done for function abAppend
[pdg] computing for function abInit
[pdg] done for function abInit
[slicing] exporting project to 'Slicing export'...
[slicing] applying all slicing requests...
[slicing] applying 0 actions...
[sparecode] remove unused global declarations from project 'Slicing export tmp'
[sparecode] removed unused global declarations in new project 'Slicing export'
/* Generated by Frama-C */
typedef unsigned long size_t;
struct linenoiseState {
   int in_completion ;
   size_t completion_idx ;
   int ifd ;
   int ofd ;
   char *buf ;
   size_t buflen ;
   char const *prompt ;
   size_t plen ;
   size_t pos ;
   size_t oldpos ;
   size_t len ;
   size_t cols ;
   size_t oldrows ;
   int history_index ;
};
enum KEY_ACTION {
    KEY_NULL = 0,
    CTRL_A = 1,
    CTRL_B = 2,
    CTRL_C = 3,
    CTRL_D = 4,
    CTRL_E = 5,
    CTRL_F = 6,
    CTRL_H = 8,
    TAB = 9,
    CTRL_K = 11,
    CTRL_L = 12,
    ENTER = 13,
    CTRL_N = 14,
    CTRL_P = 16,
    CTRL_T = 20,
    CTRL_U = 21,
    CTRL_W = 23,
    ESC = 27,
    BACKSPACE = 127
};
struct abuf {
   char *b ;
   int len ;
};
unsigned long strlen(char const *a);

void *realloc(void *a, unsigned long __size);

static void abInit_slice_1(struct abuf *ab)
{
  ab->b = (char *)0;
  ab->len = 0;
  return;
}

static void abAppend_slice_1(struct abuf *ab, int len)
{
  char *new = realloc((void *)ab->b,(unsigned long)(ab->len + len));
  if (new == (char *)0) goto return_label;
  ab->b = new;
  ab->len += len;
  return_label: return;
}

/*@ requires \valid(a + (0 .. __maxlen - 1)); */
int snprintf_va_8(char *a, size_t __maxlen, char const *__format, int param0);

/*@ requires \valid(a + (0 .. __maxlen - 1)); */
int snprintf_va_9(char *a, size_t __maxlen, char const *__format);

/*@ requires \valid(a + (0 .. __maxlen - 1)); */
int snprintf_va_10(char *a, size_t __maxlen, char const *__format);

static void refreshMultiLine(struct linenoiseState *l, int flags)
{
  char seq[64];
  int plen;
  int rpos;
  int old_rows;
  int j;
  struct abuf ab;
  unsigned long tmp;
  tmp = strlen(l->prompt);
  plen = (int)tmp;
  rpos = (int)((((size_t)plen + l->oldpos) + l->cols) / l->cols);
  old_rows = (int)l->oldrows;
  abInit_slice_1(& ab);
  if (flags & (1 << 0)) {
    if (old_rows - rpos > 0) {
      unsigned long tmp_0;
      snprintf_va_8(seq,(size_t)64,"\033[%dB",old_rows - rpos);
      tmp_0 = strlen((char const *)(seq));
      abAppend_slice_1(& ab,(int)tmp_0);
    }
    j = 0;
    while (j < old_rows - 1) {
      {
        unsigned long tmp_1;
        snprintf_va_9(seq,(size_t)64,"\r\033[0K\033[1A");
        tmp_1 = strlen((char const *)(seq));
        abAppend_slice_1(& ab,(int)tmp_1);
      }
      j ++;
    }
  }
  if (flags & ((1 << 0) | (1 << 1))) {
    unsigned long tmp_2;
    snprintf_va_10(seq,(size_t)64,"\r\033[0K");
    tmp_2 = strlen((char const *)(seq));
    abAppend_slice_1(& ab,(int)tmp_2);
  }
  if (flags & (1 << 1)) {
    unsigned long tmp_3;
    tmp_3 = strlen(l->prompt);
    abAppend_slice_1(& ab,(int)tmp_3);
    /*@ slice pragma expr ab; */ ;
  }
  return;
}


