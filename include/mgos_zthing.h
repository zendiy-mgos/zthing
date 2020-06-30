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

#ifndef MGOS_ZTHING_H_
#define MGOS_ZTHING_H_

#include <stdbool.h>
#include "mgos_event.h"
#include "common/queue.h"
#include "mgos_zthing_utils.h"

#ifdef __cplusplus
extern "C" {
#endif

struct mgos_zthing;

#define MGOS_ZTHING_SENSOR 1
#define MGOS_ZTHING_ACTUATOR 3

#define MGOS_ZTHING_RESULT_ERROR -1

#define MGOS_ZTHING_ENV_DEVICEID "${device_id}"
#define MGOS_ZTHING_ENV_THINGID "${zthing_id}"

#define MGOS_ZTHING_STR_ON "ON"
#define MGOS_ZTHING_STR_OFF "OFF"

#define MGOS_ZTHING_NO_TICKS 0

#define MGOS_ZTHING_EVENT_BASE MGOS_EVENT_BASE('Z', 'T', 'N')
enum mgos_zthing_event {
  MGOS_EV_ZTHING_CREATED = MGOS_ZTHING_EVENT_BASE, 
  MGOS_EV_ZTHING_STATE_UPDATED
};

enum mgos_zthing_state_act {
  MGOS_ZTHING_STATE_SET,
  MGOS_ZTHING_STATE_GET
};

#define MGOS_ZTHING_BASE            \
  char *id;                         \
  int type;                         \
  SLIST_ENTRY(mgos_zthing) entry;

#define MGOS_ZTHING(id, type) {id, type}

/* Generic and semi-opaque ZenThing handle */
struct mgos_zthing {
  MGOS_ZTHING_BASE
};

#define MGOS_ZTHING_CAST(h) ((struct mgos_zthing *)h)

extern struct mg_zthing_ctx *mg_zthing_ctx_get();
#define MGOS_ZTHING_FOREACH(i)                                 \
  struct mgos_zthing *i;                                        \
  SLIST_FOREACH(i, &mg_zthing_ctx_get()->handles, entry)

/* Execution context */
struct mg_zthing_ctx {
  int version;
  SLIST_HEAD(handles, mgos_zthing) handles;
};

/* Register the ZenThing handle */
bool mgos_zthing_register(struct mgos_zthing *handle);

/* Return the handle having the given ID or NULL */
struct mgos_zthing *mgos_zthing_get(const char* id);

/* Close the ZenThing handle */
void mgos_zthing_close(struct mgos_zthing *handle);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* MGOS_ZTHING_H_ */