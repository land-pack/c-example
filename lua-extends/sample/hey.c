#include <lua5.2/lua.h>
#include <lua5.2/lauxlib.h>
#include <stdio.h>


int hey(lua_State * L){
    printf("My First Lua Extention in C\n");
    return 0;
}

luaL_Reg heyfuncs[] = {
    {"hey", hey},
    {0,0}
};

int luaopen_hey(lua_State * L){

	//lua_State *L = lua_open();
	#if LUA_VERSION_NUM >= 502
		luaL_newlib(L, heyfuncs);
		//luaL_setfuncs(L, heyfuncs, 0);
		//lua_pushvalue(L, -1);
		//lua_pushcfunction(L, &hey);
		//lua_setglobal(L, "hey");
    	//luaL_register(L, "hey", heyfuncs);
	#else
		//luaL_register(L, "ao", ao); /* 5.1 */
    	luaL_register(L, "hey", heyfuncs);
	#endif
    return 1;
}
