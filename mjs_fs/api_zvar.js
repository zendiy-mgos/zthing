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
  
  typeOf: function(x) {
    return ZenVar._tof(x);
  },
  
  isNaV(x) {
    return ZenVar._isnav(x);
  },
  
  bool: function(x, val) {
    let t = ZenVar.typeOf(x);
    if (val === undefined) {
      // get
      return (t === ZenVar.TYPE_BOOL ? ZenVar._bg(x) : null);
    } else {
      // set
      return (t === ZenVar.TYPE_BOOL ? ZenVar._bs(x, val) : false);
    }
  },
  
  int: function(x, val) {
    let t = ZenVar.typeOf(x);
    if (val === undefined) {
      // get
      return (t === ZenVar.TYPE_INT ? ZenVar._ig(x) : null);
    } else {
      // set
      return (t === ZenVar.TYPE_INT ? ZenVar._is(x, val) : false);
    }
  },
  
  double: function(x, val) {
    let t = ZenVar.typeOf(x);
    if (val === undefined) {
      // get
      return (t === ZenVar.TYPE_DOUBLE ? ZenVar._dg(x) : NaN);
    } else {
      // set
      return (t === ZenVar.TYPE_DOUBLE ? ZenVar._ds(x, val) : false);
    }
  },
  
  float: function(x, val) {
    let t = ZenVar.typeOf(x);
    if (val === undefined) {
      // get
      return (t === ZenVar.TYPE_FLOAT ? ZenVar._fg(x) : NaN);
    } else {
      // set
      return (t === ZenVar.TYPE_FLOAT ? ZenVar._fs(x, val) : false);
    }
  },
};
