497 static void abInit(struct abuf *ab) {
498     ab->b = NULL;/* LN_SP4 */
499     ab->len = 0;/* LN_SP4 */
502 static void abAppend(struct abuf *ab, const char *s, int len) {
503     char *new = realloc(ab->b,ab->len+len);/* LN_SP4 */
505     if (new == NULL) return;/* LN_SP4 */
506     memcpy(new+ab->len,s,len);/* LN_SP4 */
507     ab->b = new;/* LN_SP4 */
508     ab->len += len;
604 void refreshMultiLine(struct linenoiseState *l, int flags) {
605     char seq[64];
606     int plen;
607     int rows; /* rows used by current buf. */
608     int rpos; /* cursor relative row. *//* LN_SP4 */
609     int rpos2; /* rpos after refresh. */
610     int col; /* colum position, zero-based. */
611     int old_rows;
612     int fd;
613     int j;
614     struct abuf ab;
616     plen = strlen(l->prompt);/* LN_SP4 */
617     rows = (plen+l->len+l->cols-1)/l->cols;
618     rpos = (plen+l->oldpos+l->cols)/l->cols;/* LN_SP4 */
619     old_rows = l->oldrows;/* LN_SP4 */
620     fd = l->ofd;
622     l->oldrows = rows;
626     abInit(&ab);/* LN_SP4 */
628     if (flags & REFRESH_CLEAN) {/* LN_SP4 */
629         if (old_rows-rpos > 0) {/* LN_SP4 */
631             snprintf(seq,64,"\x1b[%dB", old_rows-rpos);
632             abAppend(&ab,seq,strlen(seq));/* LN_SP4 */
636         for (j = 0; j < old_rows-1; j++) {/* LN_SP4 */
638             snprintf(seq,64,"\r\x1b[0K\x1b[1A");/* LN_SP4 */
639             abAppend(&ab,seq,strlen(seq));/* LN_SP4 */
640         }
643     if (flags & REFRESH_ALL) {/* LN_SP4 */
646         snprintf(seq,64,"\r\x1b[0K");/* LN_SP4 */
647         abAppend(&ab,seq,strlen(seq)); /* LN_SP4 */
650     if (flags & REFRESH_WRITE) { /* LN_SP4 */
652         abAppend(&ab,l->prompt,strlen(l->prompt)); /* LN_SP4 */
653         if (maskmode == 1) {
658             abAppend(&ab,l->buf,l->len); /* LN_SP4 */
