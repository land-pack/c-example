#include <lua5.2/lua.h>
#include <lua5.2/lauxlib.h>
#include <stdio.h>


int hey(lua_State * L){
	size_t msg_len = 0;
	unsigned int arguments;

	char * s;
	int i;

	arguments = lua_gettop(L);
	for(i=2; i<= arguments; i++){
		s = (char*)lua_tolstring(L, i, &msg_len);
		printf("Welcome | %s\n", s);
	}
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
		
		// Or second way
		
		/*
		lua_newtable(L);
		luaL_setfuncs(L, heyfuncs, 0);
		*/
	#else
    	luaL_register(L, "hey", heyfuncs);
	#endif
    return 1;
}
