static void abInit(struct abuf *ab) {
    ab->b = NULL;/* LN_SP4 */
    ab->len = 0;/* LN_SP4 */
static void abAppend(struct abuf *ab, const char *s, int len) {
    char *new = realloc(ab->b,ab->len+len);/* LN_SP4 */
    if (new == NULL) return;/* LN_SP4 */
    memcpy(new+ab->len,s,len);/* LN_SP4 */
    ab->b = new;/* LN_SP4 */
    ab->len += len;
void refreshMultiLine(struct linenoiseState *l, int flags) {
    char seq[64];
    int plen;
    int rows; /* rows used by current buf. */
    int rpos; /* cursor relative row. *//* LN_SP4 */
    int rpos2; /* rpos after refresh. */
    int col; /* colum position, zero-based. */
    int old_rows;
    int fd;
    int j;
    struct abuf ab;
    plen = strlen(l->prompt);/* LN_SP4 */
    rows = (plen+l->len+l->cols-1)/l->cols;
    rpos = (plen+l->oldpos+l->cols)/l->cols;/* LN_SP4 */
    old_rows = l->oldrows;/* LN_SP4 */
    fd = l->ofd;
    l->oldrows = rows;
    abInit(&ab);/* LN_SP4 */
    if (flags & REFRESH_CLEAN) {/* LN_SP4 */
        if (old_rows-rpos > 0) {/* LN_SP4 */
            snprintf(seq,64,"\x1b[%dB", old_rows-rpos);
            abAppend(&ab,seq,strlen(seq));/* LN_SP4 */
        for (j = 0; j < old_rows-1; j++) {/* LN_SP4 */
            snprintf(seq,64,"\r\x1b[0K\x1b[1A");/* LN_SP4 */
            abAppend(&ab,seq,strlen(seq));/* LN_SP4 */
        }
    if (flags & REFRESH_ALL) {/* LN_SP4 */
        snprintf(seq,64,"\r\x1b[0K");/* LN_SP4 */
        abAppend(&ab,seq,strlen(seq)); /* LN_SP4 */
    if (flags & REFRESH_WRITE) { /* LN_SP4 */
        abAppend(&ab,l->prompt,strlen(l->prompt)); /* LN_SP4 */
        if (maskmode == 1) {
            abAppend(&ab,l->buf,l->len); /* LN_SP4 */
