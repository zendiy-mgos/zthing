#include "mgos_zvariant.h"

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
    *value = v->i;
    return true;
  }
  return false;
}

bool mgos_zvariant_long_get(struct mgos_zvariant *v, long *value) {
  if (v && (v->type == ZVARIANT_LONG) && value) {
    *value = v->l;
    return true;
  }
  return false;
}

bool mgos_zvariant_bool_get(struct mgos_zvariant *v, bool *value) {
  if (v && (v->type == ZVARIANT_BOOL) && value) {
    *value = v->b;
    return true;
  }
  return false;
}

bool mgos_zvariant_double_get(struct mgos_zvariant *v, double *value) {
  if (v && (v->type == ZVARIANT_DOUBLE) && value) {
    *value = v->d;
    return true;
  }
  return false;
}

bool mgos_zvariant_float_get(struct mgos_zvariant *v, float *value) {
  if (v && (v->type == ZVARIANT_FLOAT) && value) {
    *value = v->f;
    return true;
  }
  return false;
}