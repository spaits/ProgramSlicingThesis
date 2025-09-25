 void add( json_t* obj, json_t* property ) {
    property->sibling = 0;
    if ( !obj->u.c.child ){
	    obj->u.c.child = property;
	    obj->u.c.last_child = property;
char* objValue( char* ptr, json_t* obj, jsonPool_t* pool ) {
    char endchar;
    char c;
    json_t* parentObj;
    json_t* property;
    endchar = ( obj->type == JSON_OBJ )? '}': ']'; /*TJS_SP1*/
    obj->type    = *ptr == '{' ? JSON_OBJ : JSON_ARRAY;
    obj->u.c.child = 0;
    obj->sibling = 0;
    ptr++; /*TJS_SP1*/
    for(;;) { /*TJS_SP1*/
        ptr = goBlank( ptr );  /*TJS_SP1*/
        if ( !ptr ) return 0;
        if ( *ptr == ',' ) { /*TJS_SP1*/
            ++ptr; /*TJS_SP1*/
            continue; /*TJS_SP1*/
        if ( *ptr == endchar ) { /*TJS_SP1*/
            *ptr = '\0'; /*TJS_SP1*/
            parentObj = obj->sibling;
            if ( !parentObj ) return ++ptr;
            obj->sibling = 0;
            obj = parentObj; 
            ++ptr; /*TJS_SP1*/
        property = pool->alloc( pool );
        if ( !property ) return 0;
        if( obj->type != JSON_ARRAY ) {
        else property->name = 0;
        add( obj, property );
        property->u.value = ptr;
        switch( *ptr ) { // At this point we are sure, that the ptr is not zero. It cannot be: If it was zero at loop beginning, then line 461 would have taken care of it! Branch in line 462 only increments the pointer. Won't be zero. Same goes for branch 466. In branch 480 line 482 assignment may set the ptr to zero, but immediately in line 483 we return in the nullptr case. Thus at this point prt could never be a null pointer.
            case '{':
                property->type    = JSON_OBJ;
                property->u.c.child = 0;
                property->sibling = obj;
                obj = property;
                ++ptr;
                break;
            case '[':
                property->type    = JSON_ARRAY;
                property->u.c.child = 0;
                property->sibling = obj;
                obj = property;
                ++ptr;
                break;
        if ( !ptr ) return 0;
    }
 int isOneOfThem( char ch, char const* set ) {
    while( *set != '\0' )
        if ( ch == *set++ )
            return 1;
 char* goWhile( char* str, char const* set ) {
    for(; *str != '\0'; ++str ) { /*TJS_SP4 */
        if ( !isOneOfThem( *str, set ) ) /*TJS_SP4 */
            return str; /*TJS_SP4 */
    }
char* goBlank( char* str ) {
    return goWhile( str, blank ); /*TJS_SP4 */
