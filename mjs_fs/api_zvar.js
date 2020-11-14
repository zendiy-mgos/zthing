let ZenVar = {
  _tof: ffi(''),
  _bs: ffi('bool mgos_zvariant_bool_set(void *, bool)'),
  _bg: ffi('bool mjs_zvariant_bool_get(void *)'),
  _is: ffi('bool mgos_zvariant_long_set(void *, bool)'),
  _ig: ffi('bool mjs_zvariant_long_get(void *)'),
  _fs: ffi('bool mgos_zvariant_double_set(void *, bool)'),
  _fg: ffi('bool mjs_zvariant_double_get(void *)'),
  
  TYPE_UNKNOWN: 0,
  TYPE_BOOL: 1,
  TYPE_INT: 2,
  TYPE_LONG: 3,
  TYPE_DOUBLE: 4,
  TYPE_FLOA: 5,
  
  typeOf: function(var) {
    return ZenVar._tof(var);
  },
  
  bool: function(var, val) {
    if (val === undefined) {
      // get
      return ZenVar._bg(var);
    } else {
      // set
      return ZenVar._bs(var, val);
    }
  },
  
  number: function(var, val) {
    let t = ZenVar.typeOf(var);
    if (val === undefined) {
      // get
      if (t === ZenVar.TYPE_INT || t === ZenVar.TYPE_LONG) {
        return ZenVar._ig(var);
      } else if (t === ZenVar.TYPE_FLOAT || t === ZenVar.TYPE_DOUBLE) {
      }
      return null;
    } else {
      // set
      return ZenVar._is(var, val);
    }
  },
};
