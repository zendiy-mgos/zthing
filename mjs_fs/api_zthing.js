let ZenThing = {
  _free: ffi('void free(void *)'),

  _getSafe: function(obj, val) {
  	return ((obj === null || obj === undefined) ? val : obj);
  },

  TYPE_SENSOR: 1,
  TYPE_ACTUATOR: 3,

  NO_TICKS: 0,
  
  STATE_UPD_NOTIFY: {
    NONE: 0,
    IF_CHANGED: 1,
    ALWAYS: 2
  },

  _onCreate: [],
  // register on-create handler
  _onCreateSub: function(f) {
    this._onCreate.push(f);
  },
  // raise on-create event
  _onCreatePub: function(t) {
    for (let i = 0; i < this._onCreate.length; ++i) {
    	this._onCreate[i](t);
    }
  },

  _things: [],
  // register a Zen Thingh
  _regT: function(t) {
    if (t === null || t === undefined) return false;
    this._things.push(t);
    return true;
  },
  getFromHandle: function(h) {
    for (let i = 0; i < this._things.length; ++i) {
      if (h === this._things[i].handle) {
        return this._things[i];
      }
    }
  },
  getHandle: function(t) {
    if (t && t.handle) {
      return t.handle;
    }
    return null;
  },

  RESULT_ERROR: -1,
 
  // enum mgos_zthing_state_act
  ACT_STATE_SET: 0,
  ACT_STATE_GET: 1,

  // Event codes.  
  EV_CREATED: 1515474432, 
  EV_STATE_UPDATED: 1515474433,
  EV_UPDATE_STATE: 1515474434,

  _proto: {
  },
};

ZenThing._onCreateSub(function(t) {
  ZenThing._regT(t);
});
