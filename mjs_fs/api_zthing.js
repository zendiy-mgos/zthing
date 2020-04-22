let ZenThing = {
  _free: ffi('void free(void *)'),

  RESULT_ERROR: -1,
 
  // enum mgos_zthing_state_act
  ACT_STATE_SET: 0,
  ACT_STATE_GET: 1,

  // Event codes.  
  EV_CREATED: 1515474432, 
  EV_STATE_UPDATED: 1515474433,

  _proto: {
  },
};