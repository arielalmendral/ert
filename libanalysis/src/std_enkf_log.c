/*
   Copyright (C) 2016  Statoil ASA, Norway.

   The file 'std_enkf_log.c' is part of ERT - Ensemble based Reservoir Tool.

   ERT is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   ERT is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or
   FITNESS FOR A PARTICULAR PURPOSE.

   See the GNU General Public License at <http://www.gnu.org/licenses/gpl.html>
   for more details.
*/


#include <stdio.h>
#include <stdlib.h>

#include <ert/util/util.h>

#include <ert/analysis/std_enkf_log.h>

#define DEFAULT_LOG_FILE               "std_enkf.out"
#define DEFAULT_CLEAR_LOG              false

struct std_enkf_log_struct {
  bool      clear_log;
  char    * log_file;
  FILE    * log_stream;
};


std_enkf_log_type * std_enkf_log_alloc() {
  std_enkf_log_type * std_enkf_log = util_malloc( sizeof * std_enkf_log );
  std_enkf_log->log_file = NULL;
  std_enkf_log->log_stream = NULL;
  std_enkf_log_set_log_file( std_enkf_log , DEFAULT_LOG_FILE);
  std_enkf_log_set_clear_log( std_enkf_log , DEFAULT_CLEAR_LOG );
  return std_enkf_log;
}

bool std_enkf_log_get_clear_log( const std_enkf_log_type * data ) {
  return data->clear_log;
}

void std_enkf_log_set_clear_log( std_enkf_log_type * data , bool clear_log) {
  data->clear_log = clear_log;
}

void std_enkf_log_set_log_file( std_enkf_log_type * data , const char * log_file ) {
  data->log_file = util_realloc_string_copy( data->log_file , log_file );
}

const char * std_enkf_log_get_log_file( const std_enkf_log_type * data) {
  return data->log_file;
}


void std_enkf_log_free(std_enkf_log_type * std_enkf_log) {
  std_enkf_log_close( std_enkf_log );
  util_safe_free( std_enkf_log->log_file );
  free( std_enkf_log );
}


void std_enkf_log_open( std_enkf_log_type * std_enkf_log ) {
  if (std_enkf_log->log_file) {
    if (std_enkf_log->clear_log)
      std_enkf_log->log_stream = util_mkdir_fopen( std_enkf_log->log_file , "w");
    else
      std_enkf_log->log_stream = util_mkdir_fopen( std_enkf_log->log_file , "a");
  }
}


bool std_enkf_log_is_open( const std_enkf_log_type * std_enkf_log ) {
  if (std_enkf_log->log_stream)
    return true;
  else
    return false;
}


void std_enkf_log_close( std_enkf_log_type * std_enkf_log ) {
  if (std_enkf_log->log_stream)
    fclose( std_enkf_log->log_stream );

  std_enkf_log->log_stream = NULL;
}


void std_enkf_log_line( std_enkf_log_type * std_enkf_log , const char * fmt , ...) {
  if (std_enkf_log->log_stream) {
    va_list ap;
    va_start(ap , fmt);
    vfprintf( std_enkf_log->log_stream , fmt , ap );
    va_end( ap );
  }
}


