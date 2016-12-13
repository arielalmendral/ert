/*
   Copyright (C) 2016  Statoil ASA, Norway.

   The file 'std_enkf_log.h' is part of ERT - Ensemble based Reservoir Tool.

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

#ifndef STD_ENKF_LOG_H
#define STD_ENKF_LOG_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

  typedef struct std_enkf_log_struct std_enkf_log_type;

  std_enkf_log_type * std_enkf_log_alloc();
  void std_enkf_log_free(std_enkf_log_type * std_enkf_log);
  bool std_enkf_log_get_clear_log( const std_enkf_log_type * data );
  void std_enkf_log_set_clear_log( std_enkf_log_type * data , bool clear_log);
  void std_enkf_log_set_log_file( std_enkf_log_type * data , const char * log_file );
  const char * std_enkf_log_get_log_file( const std_enkf_log_type * data);
  void std_enkf_log_open( std_enkf_log_type * std_enkf_log );
  void std_enkf_log_close( std_enkf_log_type * std_enkf_log );
  void std_enkf_log_line( std_enkf_log_type * std_enkf_log , const char * fmt , ...);
  bool std_enkf_log_is_open( const std_enkf_log_type * std_enkf_log );

#ifdef __cplusplus
}
#endif
#endif

