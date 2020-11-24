# ZenThing
## Overview
A Mongoose OS library for ZenThings ecosystem.
## C/C++ API Reference
### enum mgos_zthing_event
```c
enum mgos_zthing_event {
  MGOS_EV_ZTHING_CREATED, 
  MGOS_EV_ZTHING_STATE_UPDATED,
  MGOS_EV_ZTHING_UPDATE_STATE
};
```
ZenThing listening events and publishing events. Use `mgos_event_add_handler()` to subscribe to a publishing event or use `mgos_event_add_group_handler(MGOS_ZTHING_EVENT_BASE)` to subscribe to all publishing events. Use `mgos_event_trigger()` instead to raise a listening event.

|Value|Type||
|--|--|--|
|MGOS_EV_ZTHING_CREATED|Publishing|Raised Raised when a new ZenThing instance is created.|
|MGOS_EV_ZTHING_STATE_UPDATED|Publishing|Raised when the state of a ZenThing instance has been updated. This event is raised according the instance configuration (see the `mgos_zthing_notify_update_state_mode` enum).|
|MGOS_EV_ZTHING_UPDATE_STATE|Listening|Send this message to a Zenthing instance to force it updating its state.|
### enum mgos_zthing_state_updated_notify_mode
```c
enum mgos_zthing_upd_notify_mode {
  ZTHING_UPD_NOTIFY_NONE,
  ZTHING_UPD_NOTIFY_IF_CHANGED,
  ZTHING_UPD_NOTIFY_ALWAIS,
};
```
State-updated notify modes. A ZenThing instance notify that its state is changed raising the `MGOS_EV_ZTHING_STATE_UPDATED` event. The event is raised according one of these values.

|Value||
|--|--|
|ZTHING_UPD_NOTIFY_NONE|The ZenThing doesn't raise the event.|
|ZTHING_UPD_NOTIFY_IF_CHANGED|The ZenThing raises the event only if the its new state is not equals to the previous one.|
|ZTHING_UPD_NOTIFY_ALWAIS|The ZenThing alwais raises the event, even if its new state is equals to the previous one.|
## JS API Reference
*Under construction...*
