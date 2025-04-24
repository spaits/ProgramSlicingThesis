  int errno = 42;
int strcmp (const char *a, const char *__s2)                                     {return a == NULL;}
int isxdigit (int a) {return a == 42;}
int isdigit (int a) { return a == 42; }
typedef enum {
} jsonType_t;
typedef struct json_s {
    struct json_s* sibling;
    char const* name;
    union {
        char const* value;
        struct {
            struct json_s* child;
            struct json_s* last_child;
        } c;
    } u;
    jsonType_t type;
} json_t;
typedef struct jsonPool_s jsonPool_t;
struct jsonPool_s {
    json_t* (*init)( jsonPool_t* pool );
    json_t* (*alloc)( jsonPool_t* pool );
 char getEscape( char ch ) {
     struct { char ch; char code; } const pair[] = {
    unsigned int i;
    for( i = 0; i < sizeof pair / sizeof *pair; ++i )
        if ( pair[i].ch == ch )
            return pair[i].code;
    return '\0';
}
 unsigned char getCharFromUnicode( unsigned char const* str ) {
    unsigned int i;
    for( i = 0; i < 4; ++i )
        if ( !isxdigit( str[i] ) )
            return '\0';
    return '?';
}
 char* parseString( char* str ) {
    unsigned char* head;
    unsigned char* tail;
    head = (unsigned char*)str;
    tail = (unsigned char*)str;
    for( ; *head; ++head, ++tail ) {
        if ( *head == '\"' ) {
            *tail = '\0';
            return (char*)++head;
        if ( *head == '\\' ) {
            if ( *++head == 'u' ) {
                unsigned char ch;
                ch = getCharFromUnicode( ++head );
                if ( ch == '\0' ) return 0;
                *tail = ch;
                head += 3;
            }
            else {
                unsigned char esc;
                esc = getEscape( *head );
                if ( esc == '\0' ) return 0;
                *tail = esc;
        }
        else *tail = *head;
    }
    return 0;
}
 char* propertyName( char* ptr, json_t* property ) {
    property->name = ++ptr;
    ptr = parseString( ptr );
    if ( !ptr ) return 0;
    ptr = goBlank( ptr );
    if ( !ptr ) return 0;
    if ( *ptr++ != ':' ) return 0;
    return goBlank( ptr );
}
 char* textValue( char* ptr, json_t* property ) {
    ++property->u.value;
    ptr = parseString( ++ptr );
    if ( !ptr ) return 0;
    property->type = JSON_TEXT;
    return ptr;
}
 char* checkStr( char* ptr, char const* str ) {
    while( *str )
        if ( *ptr++ != *str++ )
            return 0;
    return ptr;
}
 char* primitiveValue( char* ptr, json_t* property, char const* value, jsonType_t type ) {
    ptr = checkStr( ptr, value );
    if ( !ptr || !isEndOfPrimitive( *ptr ) ) return 0;
    ptr = setToNull( ptr );
    property->type = type;
    return ptr;
}
 char* trueValue( char* ptr, json_t* property ) {
    return primitiveValue( ptr, property, "1", JSON_BOOLEAN );
 char* falseValue( char* ptr, json_t* property ) {
    return primitiveValue( ptr, property, "0", JSON_BOOLEAN );
 char* nullValue( char* ptr, json_t* property ) {
    return primitiveValue( ptr, property, "null", JSON_NULL );
 char* expValue( char* ptr ) {
    if ( *ptr == '-' || *ptr == '+' ) ++ptr;
    if ( !isdigit( (int)(*ptr) ) ) return 0;
    ptr = goNum( ++ptr );
    return ptr;
}
 char* fraqValue( char* ptr ) {
    if ( !isdigit( (int)(*ptr) ) ) return 0;
    ptr = goNum( ++ptr );
    if ( !ptr ) return 0;
    return ptr;
}
 char* numValue( char* ptr, json_t* property ) {
    if ( *ptr == '-' ) ++ptr;
    if ( !isdigit( (int)(*ptr) ) ) return 0;
    if ( *ptr != '0' ) {
        ptr = goNum( ptr );
        if ( !ptr ) return 0;
    }
    else if ( isdigit( (int)(*++ptr) ) ) return 0;
    property->type = JSON_INTEGER;
    if ( *ptr == '.' ) {
        ptr = fraqValue( ++ptr );
        if ( !ptr ) return 0;
        property->type = JSON_REAL;
    }
    if ( *ptr == 'e' || *ptr == 'E' ) {
        ptr = expValue( ++ptr );
        if ( !ptr ) return 0;
        property->type = JSON_REAL;
    }
    if ( !isEndOfPrimitive( *ptr ) ) return 0;
    if ( JSON_INTEGER == property->type ) {
        char const* value = property->u.value;
        int negative = *value == '-';
         char min[] = "-9223372036854775808";
         char max[] = "9223372036854775807";
        unsigned int const maxdigits = ( negative? sizeof min: sizeof max ) - 1;
        char const* threshold = negative ? min: max;
        unsigned int  len = ( unsigned int const ) ( ptr - value );
        if ( len > maxdigits ) return 0;
        if ( len == maxdigits ) {
            char tmp = *ptr;
            *ptr = '\0';
            if ( 0 > strcmp( threshold, value ) ) return 0;
            *ptr = tmp;
        }
    }
    ptr = setToNull( ptr );
    return ptr;
}
 void add( json_t* obj, json_t* property ) {
    property->sibling = 0;
    if ( !obj->u.c.child ){
	    obj->u.c.child = property;
	    obj->u.c.last_child = property;
    } else {
	    obj->u.c.last_child->sibling = property;
	    obj->u.c.last_child = property;
}
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
            continue; /*TJS_SP1*/
        property = pool->alloc( pool );
        if ( !property ) return 0;
        if( obj->type != JSON_ARRAY ) {
            if ( *ptr != '\"' ) return 0;
            ptr = propertyName( ptr, property ); // This should be unreachable for the slice: if ptr is zero we are returning. Else we are continuing and we will certainly run onto a break in the case.
            if ( !ptr ) return 0;
        }
        else property->name = 0;
        add( obj, property );
        property->u.value = ptr;
        switch( *ptr ) { // At this point we are sure, that the ptr is not zero. It cannot be: If it was zero at loop beginning, then line 461 would have taken care of it! Branch in line 462 only increments the pointer. Won't be zero. Same goes for branch 466. In branch 480 line 482 assignment may set the ptr to zero, but immediately in line 483 we return in the nullptr case. Thus at this point prt could never be a null pointer.
                property->type    = JSON_OBJ;
                property->u.c.child = 0;
                property->sibling = obj;
                obj = property;
                ++ptr;
                break;
                property->type    = JSON_ARRAY;
                property->u.c.child = 0;
                property->sibling = obj;
                obj = property;
                ++ptr;
                break;
            case '\"': ptr = textValue( ptr, property );  break;
            case 't':  ptr = trueValue( ptr, property );  break;
            case 'f':  ptr = falseValue( ptr, property ); break;
            case 'n':  ptr = nullValue( ptr, property );  break;
            default:   ptr = numValue( ptr, property );   break;
        if ( !ptr ) return 0;
    }
}
 int isOneOfThem( char ch, char const* set ) {
    while( *set != '\0' )
        if ( ch == *set++ )
            return 1;
    return 0;
}
 char* goWhile( char* str, char const* set ) {
    for(; *str != '\0'; ++str ) { /*TJS_SP4 */
        if ( !isOneOfThem( *str, set ) ) /*TJS_SP4 */
            return str; /*TJS_SP4 */
    }
    return 0; /*TJS_SP4 */
}
 char const* const blank = " \n\r\t\f";
char* goBlank( char* str ) {
    return goWhile( str, blank ); /*TJS_SP4 */
char* goNum( char* str ) {
    for( ; *str != '\0'; ++str ) {
        if ( !isdigit( (int)(*str) ) )
            return str;
    }
    return 0;
}
 char const* const endofblock = "}]";
 char* setToNull( char* ch ) {
    if ( !isOneOfThem( *ch, endofblock ) ) *ch++ = '\0';
    return ch;
 int isEndOfPrimitive( char ch ) {
    return ch == ',' || isOneOfThem( ch, blank ) || isOneOfThem( ch, endofblock );
