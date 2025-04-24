typedef unsigned char cc_t;
typedef unsigned int speed_t;
typedef unsigned int tcflag_t;
struct termios
    tcflag_t c_iflag;
    tcflag_t c_oflag;
    tcflag_t c_cflag;
    tcflag_t c_lflag;
    cc_t c_line;
    cc_t c_cc[32];
    speed_t c_ispeed;
    speed_t c_ospeed;
  int errno = 42;
unsigned long strlen (const char *a)                                              {return a == 0?1:0;}
void *realloc (void *a, unsigned long __size)                                   {return a++;}
typedef long unsigned int size_t;
struct linenoiseState {
    int in_completion;  /* The user pressed TAB and we are now in completion
    size_t completion_idx; /* Index of next completion to propose. */
    int ifd;            /* Terminal stdin file descriptor. */
    int ofd;            /* Terminal stdout file descriptor. */
    char *buf;          /* Edited line buffer. */
    size_t buflen;      /* Edited line buffer size. */
    const char *prompt; /* Prompt to display. */
    size_t plen;        /* Prompt length. */
    size_t pos;         /* Current cursor position. */
    size_t oldpos;      /* Previous refresh cursor position. */
    size_t len;         /* Current edited line length. */
    size_t cols;        /* Number of columns in terminal. */
    size_t oldrows;     /* Rows used by last refrehsed line (multiline mode) */
    int history_index;  /* The history index we are currently editing. */
typedef struct linenoiseCompletions {
  size_t len;
  char **cvec;
} linenoiseCompletions;
typedef void(linenoiseCompletionCallback)(const char *, linenoiseCompletions *);
typedef char*(linenoiseHintsCallback)(const char *, int *color, int *bold);
typedef void(linenoiseFreeHintsCallback)(void *);
static char *unsupported_term[] = {"dumb","cons25","emacs",NULL};
static linenoiseCompletionCallback *completionCallback = NULL;
static linenoiseHintsCallback *hintsCallback = NULL;
static linenoiseFreeHintsCallback *freeHintsCallback = NULL;
static struct termios orig_termios; /* In order to restore at exit.*/
static int maskmode = 0; /* Show "***" instead of input. For passwords. */
static int rawmode = 0; /* For atexit() function to check if restore is needed*/
static int mlmode = 0;  /* Multi line mode. Default is single line. */
static int atexit_registered = 0; /* Register atexit just 1 time. */
static int history_max_len = LINENOISE_DEFAULT_HISTORY_MAX_LEN;
static int history_len = 0;
static char **history = NULL;
enum KEY_ACTION{
struct abuf {
    char *b;
    int len;
static void abInit(struct abuf *ab) {
    ab->b = NULL;
    ab->len = 0;
static void abAppend(struct abuf *ab, const char *s, int len) {
    char *new = realloc(ab->b,ab->len+len);
    if (new == NULL) return;
    ab->b = new;
    ab->len += len;
void refreshMultiLine(struct linenoiseState *l, int flags) {
    plen = strlen(l->prompt);
    rows = (plen+l->len+l->cols-1)/l->cols;
    rpos = (plen+l->oldpos+l->cols)/l->cols;
    old_rows = l->oldrows;
    fd = l->ofd;
    l->oldrows = rows;
    abInit(&ab);
    if (flags & REFRESH_CLEAN) {
        if (old_rows-rpos > 0) {
            abAppend(&ab,seq,strlen(seq));
        for (j = 0; j < old_rows-1; j++) {
            abAppend(&ab,seq,strlen(seq));
    if (flags & REFRESH_ALL) {
        abAppend(&ab,seq,strlen(seq));
    if (flags & REFRESH_WRITE) {
        abAppend(&ab,l->prompt,strlen(l->prompt));
        if (maskmode == 1) {
            for (i = 0; i < l->len; i++) abAppend(&ab,"*",1);
        } else {
            abAppend(&ab,l->buf,l->len); /* LN_SP4 */
char *linenoiseEditMore = "If you see this, you are misusing the API: when linenoiseEditFeed() is called, if it returns linenoiseEditMore the user is yet editing the line. See the README file for more information.";
