/*
 * Example module
 *
 */
#include <c_stdlib.h>
#include "module.h"
#include "lauxlib.h"

static int hello_world ( lua_State* L )
{
  c_printf("Hello World!\n");
  return 0;
}

// Module function map
static const LUA_REG_TYPE hello_map[] = {
  { LSTRKEY( "world" ),           LFUNCVAL( hello_world ) },
  { LNILKEY, LNILVAL}
};

NODEMCU_MODULE(HELLO, "hello", hello_map, NULL);
