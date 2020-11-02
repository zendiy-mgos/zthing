#include "mgos_zvariant.h"

bool mgos_zvariant_is_nav(struct mgos_zvariant *v) {
  return (v ? v->type == ZVARIANT_UNKNOWN : true);
}

bool mgos_zvariant_nav_set(struct mgos_zvariant *v) {
  if (!v) return false;
  v->type = ZVARIANT_UNKNOWN;
  return true;
}

bool mgos_zvariant_equals(struct mgos_zvariant *v1, struct mgos_zvariant *v2) {
  if (v1 && v2) {
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

bool mgos_zvariant_copy(struct mgos_zvariant *src, struct mgos_zvariant *dest) {
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
        return false;
    };
  }
  return false;
}

bool mgos_zvariant_integer_set(struct mgos_zvariant *v, int value) {
  if (!v) return false;
  v->type = ZVARIANT_INT;
  v->value.i = value;
  return true;
}

bool mgos_zvariant_long_set(struct mgos_zvariant *v, long value) {
  if (!v) return false;
  v->type = ZVARIANT_LONG;
  v->value.l = value;
  return true;
}

bool mgos_zvariant_bool_set(struct mgos_zvariant *v, bool value) {
  if (!v) return false;
  v->type = ZVARIANT_BOOL;
  v->value.b = value;
  return true;
}

bool mgos_zvariant_double_set(struct mgos_zvariant *v, double value) {
  if (!v) return false;
  v->type = ZVARIANT_DOUBLE;
  v->value.d = value;
  return true;
}

bool mgos_zvariant_float_set(struct mgos_zvariant *v, float value) {
  if (!v) return false;
  v->type = ZVARIANT_FLOAT;
  v->value.f = value;
  return true;
}

bool mgos_zvariant_integer_get(struct mgos_zvariant *v, int *value) {
  if (v && (v->type == ZVARIANT_INT) && value) {
    *value = v->value.i;
    return true;
  }
  return false;
}

bool mgos_zvariant_long_get(struct mgos_zvariant *v, long *value) {
  if (v && (v->type == ZVARIANT_LONG) && value) {
    *value = v->value.l;
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
  if (v && (v->type == ZVARIANT_DOUBLE) && value) {
    *value = v->value.d;
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
