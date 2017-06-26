#include <stdio.h>
#include <sys/time.h>
#include <time.h>

// if LUA_VERSION_NUM >= 502
#include <lua5.2/lua.h>
#include <lua5.2/lauxlib.h>
// else
/*
#include <lua.h>
#include <lauxlib.h>
*/

//微秒
static int getmicrosecond(lua_State *L) {
    struct timeval tv;
    gettimeofday(&tv,NULL);
    long microsecond = tv.tv_sec*1000000+tv.tv_usec;
    lua_pushnumber(L, microsecond);
    return 1;
}

//毫秒
static int getmillisecond(lua_State *L) {
    struct timeval tv;
    gettimeofday(&tv,NULL);
    long millisecond = (tv.tv_sec*1000000+tv.tv_usec)/1000;
    lua_pushnumber(L, millisecond);

    return 1;
}


int luaopen_ktime(lua_State *L) {

  luaL_Reg l[] = {
    {"getmillisecond", getmillisecond},
    {"getmicrosecond", getmicrosecond},
    { NULL, NULL },
  };

  luaL_newlib(L, l);
	#if LUA_VERSION_NUM >= 502
		luaL_newlib(L, l);
		
		// Or second way
		/*
		lua_newtable(L);
		luaL_setfuncs(L, heyfuncs, 0);
		*/
	#else
    	luaL_register(L, "ktime", l);
	#endif
  return 1;
}
