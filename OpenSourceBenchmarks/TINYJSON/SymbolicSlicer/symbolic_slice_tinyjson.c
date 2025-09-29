430  void add( json_t* obj, json_t* property ) {
431     property->sibling = 0;
432     if ( !obj->u.c.child ){
433 	    obj->u.c.child = property;
434 	    obj->u.c.last_child = property;
447 char* objValue( char* ptr, json_t* obj, jsonPool_t* pool ) {
448     char endchar;
449     char c;
450     json_t* parentObj;
451     json_t* property;
452     endchar = ( obj->type == JSON_OBJ )? '}': ']'; /*TJS_SP1*/
453     obj->type    = *ptr == '{' ? JSON_OBJ : JSON_ARRAY;
455     obj->u.c.child = 0;
456     obj->sibling = 0;
458     ptr++; /*TJS_SP1*/
459     for(;;) { /*TJS_SP1*/
460         ptr = goBlank( ptr );  /*TJS_SP1*/
461         if ( !ptr ) return 0;
462         if ( *ptr == ',' ) { /*TJS_SP1*/
463             ++ptr; /*TJS_SP1*/
464             continue; /*TJS_SP1*/
466         if ( *ptr == endchar ) { /*TJS_SP1*/
467             *ptr = '\0'; /*TJS_SP1*/
468             parentObj = obj->sibling;
469             if ( !parentObj ) return ++ptr;
470             obj->sibling = 0;
471             obj = parentObj; 
473             ++ptr; /*TJS_SP1*/
476         property = pool->alloc( pool ); /*TJS_SP1*/
477         if ( !property ) return 0;
478         if( obj->type != JSON_ARRAY ) { /*TJS_SP1*/
483         else property->name = 0;
484         add( obj, property );
485         property->u.value = ptr;
486         switch( *ptr ) { /*TJS_SP1*/
487             case '{': /*TJS_SP1*/
488                 property->type    = JSON_OBJ; /*TJS_SP1*/
489                 property->u.c.child = 0;
490                 property->sibling = obj;
491                 obj = property;
492                 ++ptr; /*TJS_SP1*/
493                 break;
494             case '[': /*TJS_SP1*/
495                 property->type    = JSON_ARRAY; /*TJS_SP1*/
496                 property->u.c.child = 0;
497                 property->sibling = obj;
498                 obj = property;
499                 ++ptr; /*TJS_SP1*/
500                 break;
507         if ( !ptr ) return 0; /*TJS_SP1*/
508     }
534  int isOneOfThem( char ch, char const* set ) {
535     while( *set != '\0' )
536         if ( ch == *set++ )
537             return 1;
545  char* goWhile( char* str, char const* set ) {
546     for(; *str != '\0'; ++str ) { /*TJS_SP1 */
547         if ( !isOneOfThem( *str, set ) ) /*TJS_SP1 */
548             return str; /*TJS_SP1 */
549     }
559 char* goBlank( char* str ) {
560     return goWhile( str, blank ); /*TJS_SP1 */
