#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <stdbool.h>
#include <stringlist.h>
#include <hash.h>

#define ECL_COM_KW "--"
#define ENKF_COM_KW "--"


/** 
    Types used for validation of config items.
*/
typedef enum {CONFIG_STRING 	   = 0,
	      CONFIG_INT    	   = 1,
	      CONFIG_FLOAT  	   = 2,   
	      CONFIG_EXISTING_FILE = 3,
	      CONFIG_EXISTING_DIR  = 4,
              CONFIG_BOOLEAN       = 5,
	      CONFIG_CONFIG        = 6,
	      CONFIG_BYTESIZE      = 7,
              CONFIG_EXECUTABLE    = 8 } config_item_types;


typedef struct config_struct           config_type;
typedef struct config_item_struct      config_item_type;
typedef struct config_item_node_struct config_item_node_type;


char       ** 	  config_alloc_active_list(const config_type *, int *);
/*
  int           	  config_get_argc(const config_type *  , const char *);
  const char ** 	  config_get_argv(const config_type *  , const char * , int *);
  const char *  	  config_get(const config_type *  , const char *);
  const char *  	  config_iget(const config_type *  , const char *, int);
*/
void          	  config_free(config_type *);
config_type * 	  config_alloc( );
char       ** 	  config_alloc_active_list(const config_type * , int * );
void          	  config_parse(config_type * , const char * , const char * , const char * , bool , bool);
bool          	  config_has_item(const config_type * config , const char * kw);
void    	  config_set_arg(config_type * config , const char * , int , const char **);
/*
  stringlist_type * config_get_stringlist(const config_item_type * );
*/

/*****************************************************************/

bool               config_item_set(const config_type * , const char * );
void               config_item_free__ (void * );
void               config_item_free( config_item_type * );
config_item_type * config_item_alloc(const char * , bool , bool);
config_item_type * config_get_item(const config_type *, const char *);
void               config_add_alias(config_type * , const char * , const char * );
void               config_install_message(config_type * , const char * , const char * );
/*
const char       * config_iget_arg(const config_item_type * , int);
int                config_item_get_argc(const config_item_type *);
const char      ** config_item_get_argv(const config_item_type * , int * );
*/


/*const char * config_item_iget_argv(const config_item_type * , int );*/
bool 	     config_item_is_set(const config_item_type * );
char * 	     config_item_set_arg(config_item_type *  , int , const char **, const char * , const char *);
/*  int          config_item_get_argc(const config_item_type * );*/
void         config_item_set_argc_minmax(config_item_type * , int  , int , const config_item_types * );
void         config_item_set_selection_set(config_item_type * , const stringlist_type *);
void         config_item_add_to_selection(config_item_type *  , const char *);
void         config_item_set_required_children(config_item_type * , stringlist_type * );
void         config_item_set_required_children_on_value(config_item_type * , const char * , stringlist_type * );

config_item_type * config_add_item(config_type *, 
				   const char * ,
				   bool         ,
				   bool);


bool config_has_keys(const config_type *,
                     const char       **,
                     int                ,
                     bool               );


const char            * config_iget(const config_type * , const char * , int );
const char            * config_get(const config_type * , const char * );
stringlist_type       * config_alloc_complete_stringlist(const config_type*  , const char * );
stringlist_type       * config_alloc_stringlist(const config_type * config , const char * );
hash_type             * config_alloc_hash(const config_type *  , const char * );
const stringlist_type * config_get_stringlist_ref(const config_type *  , const char * );
const stringlist_type * config_iget_stringlist_ref(const config_type *  , const char * , int );
bool                    config_has_set_item(const config_type *  , const char * );

int                     config_get_occurences(const config_type * , const char * );
#endif
