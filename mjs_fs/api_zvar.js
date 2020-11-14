let ZenVar = {
  _tof: ffi('int mjs_zvariant_type_get(void *)'),
  _bs: ffi('bool mgos_zvariant_bool_set(void *, bool)'),
  _bg: ffi('bool mjs_zvariant_bool_get(void *)'),
  _is: ffi('bool mgos_zvariant_integer_set(void *, int)'),
  _ig: ffi('int mjs_zvariant_integer_get(void *)'),
  _fs: ffi('bool mgos_zvariant_float_set(void *, float)'),
  _fg: ffi('float mjs_zvariant_float_get(void *)'),
  _ds: ffi('bool mgos_zvariant_double_set(void *, double)'),
  _dg: ffi('double mjs_zvariant_double_get(void *)'),
  _isnav: ffi('bool mgos_zvariant_is_nav(void *)'),
  
  TYPE_UNKNOWN: 0,
  TYPE_BOOL: 1,
  TYPE_INT: 2,
  TYPE_LONG: 3,
  TYPE_DOUBLE: 4,
  TYPE_FLOAT: 5,
  
  typeOf: function(var) {
    return ZenVar._tof(var);
  },
  
  isNaV(var) {
    return ZenVar._isnav(var);
  },
  
  bool: function(var, val) {
    let t = ZenVar.typeOf(var);
    if (val === undefined) {
      // get
      return (t === ZenVar.TYPE_BOOL ? ZenVar._bg(var) : null);
    } else {
      // set
      return (t === ZenVar.TYPE_BOOL ? ZenVar._bs(var, val) : false);
    }
  },
  
  int: function(var, val) {
    let t = ZenVar.typeOf(var);
    if (val === undefined) {
      // get
      return (t === ZenVar.TYPE_INT ? ZenVar._ig(var) : null);
    } else {
      // set
      return (t === ZenVar.TYPE_INT ? ZenVar._is(var, val) : false);
    }
  },
  
  double: function(var, val) {
    let t = ZenVar.typeOf(var);
    if (val === undefined) {
      // get
      return (t === ZenVar.TYPE_DOUBLE ? ZenVar._dg(var) : NaN);
    } else {
      // set
      return (t === ZenVar.TYPE_DOUBLE ? ZenVar._ds(var, val) : false);
    }
  },
  
  float: function(var, val) {
    let t = ZenVar.typeOf(var);
    if (val === undefined) {
      // get
      return (t === ZenVar.TYPE_FLOAT ? ZenVar._fg(var) : NaN);
    } else {
      // set
      return (t === ZenVar.TYPE_FLOAT ? ZenVar._fs(var, val) : false);
    }
  },
};
