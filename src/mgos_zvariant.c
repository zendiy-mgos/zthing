#include "mgos_zvariant.h"

#ifdef MGOS_HAVE_MJS
#include "mjs.h"
#endif /* MGOS_HAVE_MJS */

const char *mgos_zvariant_type_name(struct mgos_zvariant *v) {
  if (v) {
    switch(v->type) {
      case ZVARIANT_INT:
        return "integer";
      case ZVARIANT_LONG:
        return "long";
      case ZVARIANT_FLOAT:
        return "float";
      case ZVARIANT_DOUBLE:
        return "double";
      case ZVARIANT_BOOL:
        return "bool";
      case ZVARIANT_UNKNOWN:
        return "unknown";
      default:
        break;
    };
  }
  return "undefined";
}

bool mgos_zvariant_is_nav(struct mgos_zvariant *v) {
  return (v ? v->type == ZVARIANT_UNKNOWN : true);
}

struct mgos_zvariant *mgos_zvariant_nav_set(struct mgos_zvariant *v) {
  if (v) {
    v->type = ZVARIANT_UNKNOWN;
  }
  return v;
}

bool mgos_zvariant_equals(struct mgos_zvariant *v1, struct mgos_zvariant *v2) {
  if (v1 != NULL && v2 != NULL) {
    if (v1->type != v2->type) return false;
    switch(v1->type) {
      case ZVARIANT_INT:
        return (v1->value.i == v2->value.i);
      case ZVARIANT_LONG:
        return (v1->value.l == v2->value.l);
      case ZVARIANT_FLOAT:
        return (v1->value.f == v2->value.f);
      case ZVARIANT_DOUBLE:
        return (v1->value.d == v2->value.d);
      case ZVARIANT_BOOL:
        return (v1->value.b == v2->value.b);
      case ZVARIANT_UNKNOWN:
        return true;
      default:
        return false;
    };
  }
  return (v1 == NULL && v2 == NULL);
}

struct mgos_zvariant *mgos_zvariant_copy(struct mgos_zvariant *src, struct mgos_zvariant *dest) {
  if (src) {
    switch(src->type) {
      case ZVARIANT_INT:
        return mgos_zvariant_integer_set(dest, src->value.i);
      case ZVARIANT_LONG:
        return mgos_zvariant_long_set(dest, src->value.l);
      case ZVARIANT_FLOAT:
        return mgos_zvariant_float_set(dest, src->value.f);
      case ZVARIANT_DOUBLE:
        return mgos_zvariant_double_set(dest, src->value.d);
      case ZVARIANT_BOOL:
        return mgos_zvariant_bool_set(dest, src->value.b);
      case ZVARIANT_UNKNOWN:
        return mgos_zvariant_nav_set(dest);
      default:
        return NULL;
    };
  }
  return dest;
}

struct mgos_zvariant *mgos_zvariant_integer_set(struct mgos_zvariant *v, int value) {
  if (v) {
    v->type = ZVARIANT_INT;
    v->value.i = value;
  }
  return v;
}

struct mgos_zvariant *mgos_zvariant_long_set(struct mgos_zvariant *v, long value) {
  if (v) {
    v->type = ZVARIANT_LONG;
    v->value.l = value;
  }
  return v;
}

struct mgos_zvariant *mgos_zvariant_bool_set(struct mgos_zvariant *v, bool value) {
  if (v) {
    v->type = ZVARIANT_BOOL;
    v->value.b = value;
  }
  return v;
}

struct mgos_zvariant *mgos_zvariant_double_set(struct mgos_zvariant *v, double value) {
  if (v) {
    v->type = ZVARIANT_DOUBLE;
    v->value.d = value;
  }
  return v;
}

struct mgos_zvariant *mgos_zvariant_float_set(struct mgos_zvariant *v, float value) {
  if (v) {
    v->type = ZVARIANT_FLOAT;
    v->value.f = value;
  }
  return v;
}

bool mgos_zvariant_integer_get(struct mgos_zvariant *v, int *value) {
  if (v && (v->type == ZVARIANT_INT || v->type == ZVARIANT_BOOL) && value) {
    *value = (v->type == ZVARIANT_INT ? v->value.i : v->value.b);
    return true;
  }
  return false;
}

bool mgos_zvariant_long_get(struct mgos_zvariant *v, long *value) {
  if (v && (v->type == ZVARIANT_LONG || v->type == ZVARIANT_INT || v->type == ZVARIANT_BOOL) && value) {
    *value = (v->type == ZVARIANT_LONG ? v->value.l : (v->type == ZVARIANT_INT ? v->value.i : v->value.b));
    return true;
  }
  return false;
}

bool mgos_zvariant_bool_get(struct mgos_zvariant *v, bool *value) {
  if (v && (v->type == ZVARIANT_BOOL) && value) {
    *value = v->value.b;
    return true;
  }
  return false;
}

bool mgos_zvariant_double_get(struct mgos_zvariant *v, double *value) {
  if (v && (v->type == ZVARIANT_DOUBLE || v->type == ZVARIANT_FLOAT) && value) {
    *value = (v->type == ZVARIANT_DOUBLE ? v->value.d : v->value.f);
    return true;
  }
  return false;
}

bool mgos_zvariant_float_get(struct mgos_zvariant *v, float *value) {
  if (v && (v->type == ZVARIANT_FLOAT) && value) {
    *value = v->value.f;
    return true;
  }
  return false;
}

#ifdef MGOS_HAVE_MJS

enum mgos_zvariant_type mjs_zvariant_type_get(struct mgos_zvariant *v) {
  return (v != NULL ? v->type : ZVARIANT_UNKNOWN);
}

bool mjs_zvariant_bool_get(struct mgos_zvariant *v) {
  return MGOS_ZVARIANT_PTR_CAST(v, bool);
}

int mjs_zvariant_integer_get(struct mgos_zvariant *v) {
  return MGOS_ZVARIANT_PTR_CAST(v, int);
}

double mjs_zvariant_double_get(struct mgos_zvariant *v) {
  if (v->type == ZVARIANT_DOUBLE) return MGOS_ZVARIANT_PTR_CAST(v, double);
  return NAN;
}

float mjs_zvariant_float_get(struct mgos_zvariant *v) {
  if (v->type == ZVARIANT_FLOAT) return MGOS_ZVARIANT_PTR_CAST(v, float);
  return NAN;
}

mjs_val_t mjs_zvariant_value_size(struct mjs *mjs, void *ap) {
  return sizeof(union mgos_zvariant_value);
}
const struct mjs_c_struct_member *mjs_zvariant_descr_get(void) {
  return mjs_zvariant_descr;
};

#endif /* MGOS_HAVE_MJS */
