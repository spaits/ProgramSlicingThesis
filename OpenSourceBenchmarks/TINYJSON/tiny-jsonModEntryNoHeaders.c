
/*

<https://github.com/rafagafe/tiny-json>

  Licensed under the MIT License <http://opensource.org/licenses/MIT>.
  SPDX-License-Identifier: MIT
  Copyright (c) 2016-2018 Rafa Garcia <rafagarcia77@gmail.com>.

  Permission is hereby  granted, free of charge, to any  person obtaining a copy
  of this software and associated  documentation files (the "Software"), to deal
  in the Software  without restriction, including without  limitation the rights
  to  use, copy,  modify, merge,  publish, distribute,  sublicense, and/or  sell
  copies  of  the Software,  and  to  permit persons  to  whom  the Software  is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE  IS PROVIDED "AS  IS", WITHOUT WARRANTY  OF ANY KIND,  EXPRESS OR
  IMPLIED,  INCLUDING BUT  NOT  LIMITED TO  THE  WARRANTIES OF  MERCHANTABILITY,
  FITNESS FOR  A PARTICULAR PURPOSE AND  NONINFRINGEMENT. IN NO EVENT  SHALL THE
  AUTHORS  OR COPYRIGHT  HOLDERS  BE  LIABLE FOR  ANY  CLAIM,  DAMAGES OR  OTHER
  LIABILITY, WHETHER IN AN ACTION OF  CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE  OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.

*/

/*HEADERS*/
#define NULL 0
char *getenv (const char *a)                                                      ;
int strcasecmp (const char *a, const char *ab)                                    ;
int isatty (int a)                                                                ;
typedef unsigned char cc_t;
typedef unsigned int speed_t;
typedef unsigned int tcflag_t;
typedef unsigned int mode_t;
struct termios
  {
    tcflag_t c_iflag;
    tcflag_t c_oflag;
    tcflag_t c_cflag;
    tcflag_t c_lflag;
    cc_t c_line;
    cc_t c_cc[32];
    speed_t c_ispeed;
    speed_t c_ospeed;
  };
int atexit (void (*a) (void))                                                    ;
int tcgetattr (int a, struct termios *__termios_p)                               ;
int tcsetattr (int a, int __optional_actions, const struct termios *__termios_p) ;
void free (void *a)                                                              ;
int ioctl (int a, unsigned long int __request, void *aa)                         ;
struct winsize
  {
    unsigned short int ws_row;
    unsigned short int ws_col;
    unsigned short int ws_xpixel;
    unsigned short int ws_ypixel;
  };
  int errno = 42;
unsigned long strlen (const char *a)                                              ;
void *malloc (unsigned long a)                                                    ;
void *memcpy (void * a, const void * __src, unsigned long __n)                    ;
void *realloc (void *a, unsigned long __size)                                     ;
void *memset (void *a, int __c, unsigned long __n)                                ;
char *strdup (const char *a)                                                      ;
void *memmove (void *a, const void *__src, unsigned long __n)                  ;
char *strncpy (char * a, const char * __src, unsigned long __n)                ;
#define FILE int
int fflush (FILE *a)                                                         ;
int fgetc (FILE *a)                                                          ;
FILE *fopen (const char *a, const char * modes)                              ;
char *fgets (char *a, int n, FILE *stream)                                          ;
char *strchr (const char *a, int __c)                                             ;
int fclose (FILE *a)                                             ;            
mode_t umask (mode_t a)                                                        ;
int chmod (const char *a, mode_t __mode)                                       ;
typedef long unsigned int size_t;
typedef long int ssize_t;
ssize_t write (int a, const void *__buf, size_t __n)                             ;
int sscanf (const char *a, const char * __format, ...)                           ;
ssize_t read (int a, void *__buf, size_t __nbytes)                               ;
int snprintf (char * a, size_t __maxlen, const char * __format, ...)              ;
int fprintf (FILE * a, const char * __format, ...)                           ;
int printf (const char * a, ...)                                             ;
int memcmp (const void *a, const void *__s2, size_t __n)                         ;
int isprint (int a)                                                               ;
int strcmp (const char *a, const char *__s2)                                     ;
int isxdigit (int a) ;
long long int strtoll (const char * a,
         char ** b, int c) ;
int isdigit (int a) ;
double strtod (const char * a,
        char ** __endptr) ;
/*HEADERS*/


typedef enum {
    JSON_OBJ, JSON_ARRAY, JSON_TEXT, JSON_BOOLEAN,
    JSON_INTEGER, JSON_REAL, JSON_NULL
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


char const* json_getName( json_t const* json ) {
    return json->name;
}

char const* json_getValue( json_t const* property ) {
    return property->u.value;
}

jsonType_t json_getType( json_t const* json ) {
    return json->type;
}

json_t const* json_getSibling( json_t const* json ) {
    return json->sibling;
}

json_t const* json_getProperty( json_t const* obj, char const* property );


char const* json_getPropertyValue( json_t const* obj, char const* property );

json_t const* json_getChild( json_t const* json ) {
    return json->u.c.child;
}

int json_getBoolean( json_t const* property ) {
    return *property->u.value == 't';
}

int json_getInteger( json_t const* property ) {
  return strtoll( property->u.value,(char**)NULL, 10);
}

double json_getReal( json_t const* property ) {
  return strtod( property->u.value,(char**)NULL );
}




typedef struct jsonPool_s jsonPool_t;
struct jsonPool_s {
    json_t* (*init)( jsonPool_t* pool );
    json_t* (*alloc)( jsonPool_t* pool );
};



/** Structure to handle a heap of JSON properties. */
typedef struct jsonStaticPool_s {
    json_t* mem;      /**< Pointer to array of json properties.      */
    unsigned int qty; /**< Length of the array of json properties.   */
    unsigned int nextFree;  /**< The index of the next free json property. */
    jsonPool_t pool;
} jsonStaticPool_t;

/* Search a property by its name in a JSON object. */
json_t const* json_getProperty( json_t const* obj, char const* property ) {
    json_t const* sibling;
    for( sibling = obj->u.c.child; sibling; sibling = sibling->sibling )
        if ( sibling->name && !strcmp( sibling->name, property ) )
            return sibling;
    return 0;
}

/* Search a property by its name in a JSON object and return its value. */
char const* json_getPropertyValue( json_t const* obj, char const* property ) {
	json_t const* field = json_getProperty( obj, property );
    jsonType_t type;
	if ( !field ) return 0;
        type = json_getType( field );
        if ( JSON_ARRAY >= type ) return 0;
	return json_getValue( field );
}

/* Internal prototypes: */
 char* goBlank( char* str );
 char* goNum( char* str );
 json_t* poolInit( jsonPool_t* pool );
 json_t* poolAlloc( jsonPool_t* pool );
 char* objValue( char* ptr, json_t* obj, jsonPool_t* pool );
 char* setToNull( char* ch );
 int isEndOfPrimitive( char ch );




/** Get a special character with its escape character. Examples:
  * 'b' -> '\\b', 'n' -> '\\n', 't' -> '\\t'
  * @param ch The escape character.
  * @retval  The character code. */
 char getEscape( char ch ) {
     struct { char ch; char code; } const pair[] = {
        { '\"', '\"' }, { '\\', '\\' },
        { '/',  '/'  }, { 'b',  '\b' },
        { 'f',  '\f' }, { 'n',  '\n' },
        { 'r',  '\r' }, { 't',  '\t' },
    };
    unsigned int i;
    for( i = 0; i < sizeof pair / sizeof *pair; ++i )
        if ( pair[i].ch == ch )
            return pair[i].code;
    return '\0';
}

/** Parse 4 characters.
  * @param str Pointer to  first digit.
  * @retval '?' If the four characters are hexadecimal digits.
  * @retval '\0' In other cases. */
 unsigned char getCharFromUnicode( unsigned char const* str ) {
    unsigned int i;
    for( i = 0; i < 4; ++i )
        if ( !isxdigit( str[i] ) )
            return '\0';
    return '?';
}

/** Parse a string and replace the scape characters by their meaning characters.
  * This parser stops when finds the character '\"'. Then replaces '\"' by '\0'.
  * @param str Pointer to first character.
  * @retval Pointer to first non white space after the string. If success.
  * @retval Null pointer if any error occur. */
 char* parseString( char* str ) {
    unsigned char* head;
    unsigned char* tail;
    head = (unsigned char*)str;
    tail = (unsigned char*)str;

    for( ; *head; ++head, ++tail ) {
        if ( *head == '\"' ) {
            *tail = '\0';
            return (char*)++head;
        }
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
        }
        else *tail = *head;
    }
    return 0;
}

/** Parse a string to get the name of a property.
  * @param ptr Pointer to first character.
  * @param property The property to assign the name.
  * @retval Pointer to first of property value. If success.
  * @retval Null pointer if any error occur. */
 char* propertyName( char* ptr, json_t* property ) {
    property->name = ++ptr;
    ptr = parseString( ptr );
    if ( !ptr ) return 0;
    ptr = goBlank( ptr );
    if ( !ptr ) return 0;
    if ( *ptr++ != ':' ) return 0;
    return goBlank( ptr );
}

/** Parse a string to get the value of a property when its type is JSON_TEXT.
  * @param ptr Pointer to first character ('\"').
  * @param property The property to assign the name.
  * @retval Pointer to first non white space after the string. If success.
  * @retval Null pointer if any error occur. */
 char* textValue( char* ptr, json_t* property ) {
    ++property->u.value;
    ptr = parseString( ++ptr ); /*TJS_SP1*/
    if ( !ptr ) return 0; /*TJS_SP1*/
    property->type = JSON_TEXT;
    return ptr;
}

/** Compare two strings until get the null character in the second one.
  * @param ptr sub string
  * @param str main string
  * @retval Pointer to next character.
  * @retval Null pointer if any error occur. */
 char* checkStr( char* ptr, char const* str ) {
    while( *str )
        if ( *ptr++ != *str++ )
            return 0;
    return ptr;
}

/** Parser a string to get a primitive value.
  * If the first character after the value is different of '}' or ']' is set to '\0'.
  * @param ptr Pointer to first character.
  * @param property Property handler to set the value and the type, (1, 0 or null).
  * @param value String with the primitive literal.
  * @param type The code of the type. ( JSON_intEAN or JSON_NULL )
  * @retval Pointer to first non white space after the string. If success.
  * @retval Null pointer if any error occur. */
 char* primitiveValue( char* ptr, json_t* property, char const* value, jsonType_t type ) {
    ptr = checkStr( ptr, value );
    if ( !ptr || !isEndOfPrimitive( *ptr ) ) return 0;
    ptr = setToNull( ptr );
    property->type = type;
    return ptr;
}

/** Parser a string to get a 1 value.
  * If the first character after the value is different of '}' or ']' is set to '\0'.
  * @param ptr Pointer to first character.
  * @param property Property handler to set the value and the type, (1, 0 or null).
  * @retval Pointer to first non white space after the string. If success.
  * @retval Null pointer if any error occur. */
 char* trueValue( char* ptr, json_t* property ) {
    return primitiveValue( ptr, property, "1", JSON_BOOLEAN );
}

/** Parser a string to get a 0 value.
  * If the first character after the value is different of '}' or ']' is set to '\0'.
  * @param ptr Pointer to first character.
  * @param property Property handler to set the value and the type, (1, 0 or null).
  * @retval Pointer to first non white space after the string. If success.
  * @retval Null pointer if any error occur. */
 char* falseValue( char* ptr, json_t* property ) {
    return primitiveValue( ptr, property, "0", JSON_BOOLEAN );
}

/** Parser a string to get a null value.
  * If the first character after the value is different of '}' or ']' is set to '\0'.
  * @param ptr Pointer to first character.
  * @param property Property handler to set the value and the type, (1, 0 or null).
  * @retval Pointer to first non white space after the string. If success.
  * @retval Null pointer if any error occur. */
 char* nullValue( char* ptr, json_t* property ) {
    return primitiveValue( ptr, property, "null", JSON_NULL );
}

/** Analyze the exponential part of a real number.
  * @param ptr Pointer to first character.
  * @retval Pointer to first non numerical after the string. If success.
  * @retval Null pointer if any error occur. */
 char* expValue( char* ptr ) {
    if ( *ptr == '-' || *ptr == '+' ) ++ptr;
    if ( !isdigit( (int)(*ptr) ) ) return 0;
    ptr = goNum( ++ptr );
    return ptr;
}

/** Analyze the decimal part of a real number.
  * @param ptr Pointer to first character.
  * @retval Pointer to first non numerical after the string. If success.
  * @retval Null pointer if any error occur. */
 char* fraqValue( char* ptr ) {
    if ( !isdigit( (int)(*ptr) ) ) return 0;
    ptr = goNum( ++ptr );
    if ( !ptr ) return 0;
    return ptr;
}

/** Parser a string to get a numerical value.
  * If the first character after the value is different of '}' or ']' is set to '\0'.
  * @param ptr Pointer to first character.
  * @param property Property handler to set the value and the type: JSON_REAL or JSON_INTEGER.
  * @retval Pointer to first non white space after the string. If success.
  * @retval Null pointer if any error occur. */
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
        int const negative = *value == '-';
         char const min[] = "-9223372036854775808";
         char const max[] = "9223372036854775807";
        unsigned int const maxdigits = ( negative? sizeof min: sizeof max ) - 1;
        char const* threshold = negative ? min: max;

        unsigned int const len = ( unsigned int const ) ( ptr - value );
        if ( len > maxdigits ) return 0;
        if ( len == maxdigits ) {
            char const tmp = *ptr;
            *ptr = '\0';
            if ( 0 > strcmp( threshold, value ) ) return 0;
            *ptr = tmp;
        }
    }
    ptr = setToNull( ptr );
    return ptr;
}

/** Add a property to a JSON object or array.
  * @param obj The handler of the JSON object or array.
  * @param property The handler of the property to be added. */
 void add( json_t* obj, json_t* property ) {
    property->sibling = 0;
    if ( !obj->u.c.child ){
	    obj->u.c.child = property;
	    obj->u.c.last_child = property;
    } else {
	    obj->u.c.last_child->sibling = property;
	    obj->u.c.last_child = property;
    }
}

/** Parser a string to get a json object value.
  * @param ptr Pointer to first character.
  * @param obj The handler of the JSON root object or array.
  * @param pool The handler of a json pool for creating json instances.
  * @retval Pointer to first character after the value. If success.
  * @retval Null pointer if any error occur. */
char* objValue( char* ptr, json_t* obj, jsonPool_t* pool ) {
    char endchar;
    char c;
    json_t* parentObj;
    json_t* property;
    endchar = ( obj->type == JSON_OBJ )? '}': ']';
    obj->type    = *ptr == '{' ? JSON_OBJ : JSON_ARRAY; /*TJS_SP1*/

    obj->u.c.child = 0; /*TJS_SP1*/
    obj->sibling = 0; /*TJS_SP1*/

    ptr++; /*TJS_SP1*/
    for(;;) { /*TJS_SP1*/
        ptr = goBlank( ptr );  /*TJS_SP1*/
        if ( !ptr ) return 0;
        if ( *ptr == ',' ) { /*TJS_SP1*/
            ++ptr; /*TJS_SP1*/
            continue; /*TJS_SP1*/
        }
        if ( *ptr == endchar ) {
            *ptr = '\0'; /*TJS_SP1*/
            parentObj = obj->sibling;
            if ( !parentObj ) return ++ptr;
            obj->sibling = 0;
            obj = parentObj; 
            /*@ slice pragma expr ptr; */
            ++ptr; /*TJS_SP1*/
            continue; /*TJS_SP1*/
        }
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
            case '\"': ptr = textValue( ptr, property );  break;
            case 't':  ptr = trueValue( ptr, property );  break;
            case 'f':  ptr = falseValue( ptr, property ); break;
            case 'n':  ptr = nullValue( ptr, property );  break;
            default:   ptr = numValue( ptr, property );   break;
        }
        if ( !ptr ) return 0;
    }
}

/** Initialize a json pool.
  * @param pool The handler of the pool.
  * @return a instance of a json. */
 json_t* poolInit( jsonPool_t* pool ) {
    jsonStaticPool_t *spool = 0;
    spool->nextFree = 1;
    return spool->mem;
}

/** Create an instance of a json from a pool.
  * @param pool The handler of the pool.
  * @retval The handler of the new instance if success.
  * @retval Null pointer if the pool was empty. */
/* json_t* poolAlloc( jsonPool_t* pool ) {
    jsonStaticPool_t *spool = json_containerOf( pool, jsonStaticPool_t, pool );
    if ( spool->nextFree >= spool->qty ) return 0;
    return spool->mem + spool->nextFree++;
}*/

/** Checks whether an character belongs to set.
  * @param ch Character value to be checked.
  * @param set Set of characters. It is just a null-terminated string.
  * @return 1 or 0 there is membership or not. */
 int isOneOfThem( char ch, char const* set ) {
    while( *set != '\0' )
        if ( ch == *set++ )
            return 1;
    return 0;
}

/** Increases a pointer while it points to a character that belongs to a set.
  * @param str The initial pointer value.
  * @param set Set of characters. It is just a null-terminated string.
  * @return The final pointer value or null pointer if the null character was found. */
 char* goWhile( char* str, char const* set ) {
    for(; *str != '\0'; ++str ) { /*TJS_SP1*/
        if ( !isOneOfThem( *str, set ) ) /*TJS_SP1*/
            return str; /*TJS_SP1*/
    }
    return 0; /*TJS_SP1*/
}

/** Set of characters that defines a blank. */
 char const* const blank = " \n\r\t\f";

/** Increases a pointer while it points to a white space character.
  * @param str The initial pointer value.
  * @return The final pointer value or null pointer if the null character was found. */
 char* goBlank( char* str ) {
    return goWhile( str, blank ); /*TJS_SP1*/ 
}

/** Increases a pointer while it points to a decimal digit character.
  * @param str The initial pointer value.
  * @return The final pointer value or null pointer if the null character was found. */
 char* goNum( char* str ) {
    for( ; *str != '\0'; ++str ) {
        if ( !isdigit( (int)(*str) ) )
            return str;
    }
    return 0;
}

/** Set of characters that defines the end of an array or a JSON object. */
 char const* const endofblock = "}]";

/** Set a char to '\0' and increase its pointer if the char is different to '}' or ']'.
  * @param ch Pointer to character.
  * @return  Final value pointer. */
 char* setToNull( char* ch ) {
    if ( !isOneOfThem( *ch, endofblock ) ) *ch++ = '\0';
    return ch;
}

/** Indicate if a character is the end of a primitive value. */
 int isEndOfPrimitive( char ch ) {
    return ch == ',' || isOneOfThem( ch, blank ) || isOneOfThem( ch, endofblock );
}

int main() {return 0;}