/*
 * Copyright (c) 2020 ZenDIY
 * All rights reserved
 *
 * Licensed under the Apache License, Version 2.0 (the ""License"");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an ""AS IS"" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MGOS_ZVARIANT_H_
#define MGOS_ZVARIANT_H_

#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#ifdef MGOS_HAVE_MJS
#include "mjs.h"
#endif /* MGOS_HAVE_MJS */ 

#ifdef __cplusplus
extern "C" {
#endif

#define MGOS_ZVARIANT_PTR_CAST(v, t) (*(t*)&v->value)
#define MGOS_ZVARIANT_CAST(v, t) (*(t*)&v.value)

enum mgos_zvariant_type {
  ZVARIANT_UNKNOWN,
  ZVARIANT_BOOL,
  ZVARIANT_INT,
  ZVARIANT_LONG,
  ZVARIANT_DOUBLE,
  ZVARIANT_FLOAT
};

union mgos_zvariant_value {
   int i;
   long l;
   float f;
   double d;
   bool b;
};

#define MGOS_ZVARIANT_NAV { ZVARIANT_UNKNOWN }
struct mgos_zvariant {
  enum mgos_zvariant_type type;
  union mgos_zvariant_value value;
};
  
#ifdef MGOS_HAVE_MJS
mjs_val_t mjs_zvariant_value_size(struct mjs *mjs, void *ap);

static const struct mjs_c_struct_member mjs_zvariant_descr[] = {
  {"type", offsetof(struct mgos_zvariant, type), MJS_STRUCT_FIELD_TYPE_INT, NULL},
  {"value", offsetof(struct mgos_zvariant, value), MJS_STRUCT_FIELD_TYPE_CUSTOM, mjs_zvariant_value_size},
  {NULL, 0, MJS_STRUCT_FIELD_TYPE_INVALID, NULL},
};
#endif /* MGOS_HAVE_MJS */

const char *mgos_zvariant_type_name(struct mgos_zvariant *v);

bool mgos_zvariant_equals(struct mgos_zvariant *v1, struct mgos_zvariant *v2);

bool mgos_zvariant_copy(struct mgos_zvariant *src, struct mgos_zvariant *dest);
    
bool mgos_zvariant_nav_set(struct mgos_zvariant *v);
bool mgos_zvariant_is_nav(struct mgos_zvariant *v);
                                 
bool mgos_zvariant_integer_set(struct mgos_zvariant *v, int value);
bool mgos_zvariant_long_set(struct mgos_zvariant *v, long value);
bool mgos_zvariant_bool_set(struct mgos_zvariant *v, bool value);
bool mgos_zvariant_double_set(struct mgos_zvariant *v, double value);
bool mgos_zvariant_float_set(struct mgos_zvariant *v, float value);

bool mgos_zvariant_integer_get(struct mgos_zvariant *v, int *value);
bool mgos_zvariant_long_get(struct mgos_zvariant *v, long *value);
bool mgos_zvariant_bool_get(struct mgos_zvariant *v, bool *value);
bool mgos_zvariant_double_get(struct mgos_zvariant *v, double *value);
bool mgos_zvariant_float_get(struct mgos_zvariant *v, float *value);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* MGOS_ZVARIANT_H_ */
