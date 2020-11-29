#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <mgos.h>
#include "mgos_zthing.h"


/* Excecution context instance */
static struct mg_zthing_ctx *s_context = NULL;

/* Handler's extensions context entry */
struct mg_zthing_ext_ctx_e {
  struct mgos_zthing *handle;
  const char* name;
  void *ext;
  SLIST_ENTRY(mg_zthing_ext_ctx_e) entry;
};

/* Handler's extensions context */
struct mg_zthing_exts_ctx {
  int version;
  SLIST_HEAD(entries, mg_zthing_ext_ctx_e) entries;
};

/* Handler's extensions context instance */
static struct mg_zthing_exts_ctx *s_exts_context = NULL;

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

bool mgos_zthing_ext_attach(struct mgos_zthing *handle, const char* ext_name, void *ext) {
  if (!handle || !ext || !ext_name) return false;
  struct mg_zthing_ext_ctx_e *e = calloc(1, sizeof(struct mg_zthing_ext_ctx_e));
  if (e) {
    e->handle = handle;
    e->ext = ext;
    e->name = ext_name;
    SLIST_INSERT_HEAD(&s_exts_context->entries, e, entry);
  }
  return (e != NULL);
}

void *mgos_zthing_ext_get(struct mgos_zthing *handle, const char* ext_name) {
  if (!handle || !ext_name) return NULL;
  struct mg_zthing_ext_ctx_e *e;
  SLIST_FOREACH(e, &s_exts_context->entries, entry) {
    if ((((void *)e->handle) == ((void *)handle)) && (0 == strcasecmp(e->name, ext_name))) return e;
  }
  return NULL;
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
  
  /* Create handler's extensions context */
  s_exts_context = calloc(1, sizeof(struct mg_zthing_exts_ctx));
  if (!s_exts_context) return false;
  
  /* Initialize handler's extensions context */
  s_exts_context->version = 1;
  SLIST_INIT(&s_exts_context->entries);

  /* LOG(LL_INFO, ("MGOS_ZTHING_EVENT_BASE %d",
    MGOS_ZTHING_EVENT_BASE)); */
    
  return true;
}
