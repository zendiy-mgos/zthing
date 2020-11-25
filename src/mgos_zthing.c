#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <mgos.h>
#include "mgos_zthing.h"


/* Excecution context instance */
static struct mg_zthing_ctx *s_context = NULL;

/* Handler's attachments context entry */
struct mg_zthing_att_ctx_e {
  struct mgos_zthing *handle;
  void *att;
  SLIST_ENTRY(mg_zthing_att_ctx_e) entry;
};

/* Handler's attachments context */
struct mg_zthing_atts_ctx {
  int version;
  SLIST_HEAD(entries, mg_zthing_att_ctx_e) entries;
};

/* Handler's attachments context instance */
static struct mg_zthing_atts_ctx *s_atts_context = NULL;

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

bool mgos_zthing_attach_ext(struct mgos_zthing *handle, void *ext) {
  if (handle == NULL || ext == NULL) return false;
  struct mg_zthing_att_ctx_e *e = calloc(1, sizeof(struct mg_zthing_att_ctx_e));
  if (e) {
    SLIST_INSERT_HEAD(&s_context->entries, e, entry);
  }
  return (e != NULL);
}


bool mgos_zthing_init() {
  if (!mgos_event_register_base(MGOS_ZTHING_EVENT_BASE, "ZenThing events")) {
    return false;
  }

  /* Create execution context */
  s_context = calloc(1, sizeof(struct mg_zthing_ctx));
  if (!s_context) return false;
  
  /* Initialize execution context */
  s_context->version = 1;
  SLIST_INIT(&s_context->handles);
  
  /* Create handler's attachments context */
  s_atts_context = calloc(1, sizeof(struct mg_zthing_atts_ctx));
  if (!s_atts_context) return false;
  
  /* Initialize handler's attachments context */
  s_atts_context->version = 1;
  SLIST_INIT(&s_atts_context->entries);

  /* LOG(LL_INFO, ("MGOS_ZTHING_EVENT_BASE %d",
    MGOS_ZTHING_EVENT_BASE)); */
    
  return true;
}
