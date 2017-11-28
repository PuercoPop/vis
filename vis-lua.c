/***
 * Lua Extension API for the [Vis Editor](https://github.com/martanne/vis).
 *
 * *WARNING:* there is no stability guarantee at this time, the API might
 * change without notice!
 *
 * This document might be out of date, run `make luadoc` to regenerate it.
 *
 * @module vis
 * @author Marc André Tanner
 * @license ISC
 * @release RELEASE
 */
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <libgen.h>
#include <sys/types.h>
#include <pwd.h>

#include "vis-lua.h"
#include "vis-core.h"
#include "text-motions.h"
#include "util.h"

#ifndef VIS_PATH
#define VIS_PATH "/usr/local/share/vis"
#endif

#define VIS_LUA_TYPE_VIS "vis"
#define VIS_LUA_TYPE_FILE "file"
#define VIS_LUA_TYPE_TEXT "text"
#define VIS_LUA_TYPE_MARK "mark"
#define VIS_LUA_TYPE_MARKS "marks"
#define VIS_LUA_TYPE_WINDOW "window"
#define VIS_LUA_TYPE_SELECTION "selection"
#define VIS_LUA_TYPE_SELECTIONS "selections"
#define VIS_LUA_TYPE_UI "ui"
#define VIS_LUA_TYPE_REGISTERS "registers"
#define VIS_LUA_TYPE_KEYACTION "keyaction"

static void window_status_update(Vis *vis, Win *win) {
  return;
}

bool vis_lua_path_add(Vis *vis, const char *path) { return true; }
bool vis_lua_paths_get(Vis *vis, char **lpath, char **cpath) { return false; }
void vis_lua_init(Vis *vis) { }
void vis_lua_start(Vis *vis) { }
void vis_lua_quit(Vis *vis) { }
void vis_lua_file_open(Vis *vis, File *file) { }
bool vis_lua_file_save_pre(Vis *vis, File *file, const char *path) { return true; }
void vis_lua_file_save_post(Vis *vis, File *file, const char *path) { }
void vis_lua_file_close(Vis *vis, File *file) { }
void vis_lua_win_open(Vis *vis, Win *win) { }
void vis_lua_win_close(Vis *vis, Win *win) { }
void vis_lua_win_highlight(Vis *vis, Win *win) { }
void vis_lua_win_status(Vis *vis, Win *win) { window_status_update(vis, win); }
