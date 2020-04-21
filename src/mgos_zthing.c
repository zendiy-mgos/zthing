#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <mgos.h>
#include "mgos_zthing.h"


/* Excecution context instance */
static struct mg_zthing_ctx *s_context = NULL;

bool mgos_zthing_register(struct mgos_zthing *handle) {
  if (handle == NULL) return false;
  SLIST_INSERT_HEAD(&s_context->handles, handle, entry);
  return true;
}

struct mgos_zthing *mgos_zthing_get(const char* id) {
  struct mgos_zthing *handle;
  SLIST_FOREACH(handle, &s_context->handles, entry) {
    if (0 == strcasecmp(id, handle->id)) return handle;
  }
  return NULL;
}

void mgos_zthing_close(struct mgos_zthing *handle) {
  if (handle == NULL) return;
  SLIST_REMOVE(&s_context->handles, handle, mgos_zthing, entry);
  free(handle->id);
  free(handle);
}

struct mg_zthing_ctx *mg_zthing_ctx_get() {
  return s_context;
}


bool mgos_zthing_init() {
  /* Create the context */
  s_context = calloc(1, sizeof(struct mg_zthing_ctx));
  if (!s_context) return false;
  
  /* Initialize the context */
  s_context->version = 1;
  SLIST_INIT(&s_context->handles);

  LOG(LL_INFO, ("MGOS_ZTHING_EVENT_BASE %d",
    MGOS_ZTHING_EVENT_BASE));
    
  return true;
}