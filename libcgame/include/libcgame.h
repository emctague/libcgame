// libcgame: A simple, abstracted rendering library for C games, based on SDL.
// Copyright (C) 2019 Ethan McTague
// 
#pragma once

// Used internally for 'cgmem.h' itemizable objects
#define CG_ITEMIZABLE int cg_index;

// CG_IMG_FORMATS is the image format data supplied to SDL's IMG_Init.
#ifndef CG_IMG_FORMATS
#define CG_IMG_FORMATS (IMG_INIT_PNG)
#endif

// CG_SCALE is used to scale up all sprites onscreen for a pixel-art effect.
#ifndef CG_SCALE
#define CG_SCALE 3
#endif

// Keycodes/scancodes for any keyboard-related input.
// CG_KEY_<name> is identical to SDL2's SDL_SCANCODE_<name> for any given name.
typedef enum cg_key {
	CG_KEY_A = 4,
	CG_KEY_B = 5,
	CG_KEY_C = 6,
	CG_KEY_D = 7,
	CG_KEY_E = 8,
	CG_KEY_F = 9,
	CG_KEY_G = 10,
	CG_KEY_H = 11,
	CG_KEY_I = 12,
	CG_KEY_J = 13,
	CG_KEY_K = 14,
	CG_KEY_L = 15,
	CG_KEY_M = 16,
	CG_KEY_N = 17,
	CG_KEY_O = 18,
	CG_KEY_P = 19,
	CG_KEY_Q = 20,
	CG_KEY_R = 21,
	CG_KEY_S = 22,
	CG_KEY_T = 23,
	CG_KEY_U = 24,
	CG_KEY_V = 25,
	CG_KEY_W = 26,
	CG_KEY_X = 27,
	CG_KEY_Y = 28,
	CG_KEY_Z = 29,
	CG_KEY_1 = 30,
	CG_KEY_2 = 31,
	CG_KEY_3 = 32,
	CG_KEY_4 = 33,
	CG_KEY_5 = 34,
	CG_KEY_6 = 35,
	CG_KEY_7 = 36,
	CG_KEY_8 = 37,
	CG_KEY_9 = 38,
	CG_KEY_0 = 39,
	CG_KEY_RETURN = 40,
	CG_KEY_ESCAPE = 41,
	CG_KEY_BACKSPACE = 42,
	CG_KEY_TAB = 43,
	CG_KEY_SPACE = 44,
	CG_KEY_MINUS = 45,
	CG_KEY_EQUALS = 46,
	CG_KEY_LEFTBRACKET = 47,
	CG_KEY_RIGHTBRACKET = 48,
	CG_KEY_BACKSLASH = 49,
	CG_KEY_NONUSHASH = 50,
	CG_KEY_SEMICOLON = 51,
	CG_KEY_APOSTROPHE = 52,
	CG_KEY_GRAVE = 53,
	CG_KEY_COMMA = 54,
	CG_KEY_PERIOD = 55,
	CG_KEY_SLASH = 56,
	CG_KEY_CAPSLOCK = 57,
	CG_KEY_F1 = 58,
	CG_KEY_F2 = 59,
	CG_KEY_F3 = 60,
	CG_KEY_F4 = 61,
	CG_KEY_F5 = 62,
	CG_KEY_F6 = 63,
	CG_KEY_F7 = 64,
	CG_KEY_F8 = 65,
	CG_KEY_F9 = 66,
	CG_KEY_F10 = 67,
	CG_KEY_F11 = 68,
	CG_KEY_F12 = 69,
	CG_KEY_PRINTSCREEN = 70,
	CG_KEY_SCROLLLOCK = 71,
	CG_KEY_PAUSE = 72,
	CG_KEY_INSERT = 73,
	CG_KEY_HOME = 74,
	CG_KEY_PAGEUP = 75,
	CG_KEY_DELETE = 76,
	CG_KEY_END = 77,
	CG_KEY_PAGEDOWN = 78,
	CG_KEY_RIGHT = 79,
	CG_KEY_LEFT = 80,
	CG_KEY_DOWN = 81,
	CG_KEY_UP = 82,
	CG_KEY_NUMLOCKCLEAR = 83,
	CG_KEY_KP_DIVIDE = 84,
	CG_KEY_KP_MULTIPLY = 85,
	CG_KEY_KP_MINUS = 86,
	CG_KEY_KP_PLUS = 87,
	CG_KEY_KP_ENTER = 88,
	CG_KEY_KP_1 = 89,
	CG_KEY_KP_2 = 90,
	CG_KEY_KP_3 = 91,
	CG_KEY_KP_4 = 92,
	CG_KEY_KP_5 = 93,
	CG_KEY_KP_6 = 94,
	CG_KEY_KP_7 = 95,
	CG_KEY_KP_8 = 96,
	CG_KEY_KP_9 = 97,
	CG_KEY_KP_0 = 98,
	CG_KEY_KP_PERIOD = 99,
	CG_KEY_NONUSBACKSLASH = 100,
	CG_KEY_APPLICATION = 101,
	CG_KEY_POWER = 102,
	CG_KEY_KP_EQUALS = 103,
	CG_KEY_F13 = 104,
	CG_KEY_F14 = 105,
	CG_KEY_F15 = 106,
	CG_KEY_F16 = 107,
	CG_KEY_F17 = 108,
	CG_KEY_F18 = 109,
	CG_KEY_F19 = 110,
	CG_KEY_F20 = 111,
	CG_KEY_F21 = 112,
	CG_KEY_F22 = 113,
	CG_KEY_F23 = 114,
	CG_KEY_F24 = 115,
	CG_KEY_EXECUTE = 116,
	CG_KEY_HELP = 117,
	CG_KEY_MENU = 118,
	CG_KEY_SELECT = 119,
	CG_KEY_STOP = 120,
	CG_KEY_AGAIN = 121,
	CG_KEY_UNDO = 122,
	CG_KEY_CUT = 123,
	CG_KEY_COPY = 124,
	CG_KEY_PASTE = 125,
	CG_KEY_FIND = 126,
	CG_KEY_MUTE = 127,
	CG_KEY_VOLUMEUP = 128,
	CG_KEY_VOLUMEDOWN = 129,
	CG_KEY_KP_COMMA = 133,
	CG_KEY_KP_EQUALSAS400 = 134,
	CG_KEY_INTERNATIONAL1 = 135,
	CG_KEY_INTERNATIONAL2 = 136,
	CG_KEY_INTERNATIONAL3 = 137,
	CG_KEY_INTERNATIONAL4 = 138,
	CG_KEY_INTERNATIONAL5 = 139,
	CG_KEY_INTERNATIONAL6 = 140,
	CG_KEY_INTERNATIONAL7 = 141,
	CG_KEY_INTERNATIONAL8 = 142,
	CG_KEY_INTERNATIONAL9 = 143,
	CG_KEY_LANG1 = 144,
	CG_KEY_LANG2 = 145,
	CG_KEY_LANG3 = 146,
	CG_KEY_LANG4 = 147,
	CG_KEY_LANG5 = 148,
	CG_KEY_LANG6 = 149,
	CG_KEY_LANG7 = 150,
	CG_KEY_LANG8 = 151,
	CG_KEY_LANG9 = 152,
	CG_KEY_ALTERASE = 153,
	CG_KEY_SYSREQ = 154,
	CG_KEY_CANCEL = 155,
	CG_KEY_CLEAR = 156,
	CG_KEY_PRIOR = 157,
	CG_KEY_RETURN2 = 158,
	CG_KEY_SEPARATOR = 159,
	CG_KEY_OUT = 160,
	CG_KEY_OPER = 161,
	CG_KEY_CLEARAGAIN = 162,
	CG_KEY_CRSEL = 163,
	CG_KEY_EXSEL = 164,
	CG_KEY_KP_00 = 176,
	CG_KEY_KP_000 = 177,
	CG_KEY_THOUSANDSSEPARATOR = 178,
	CG_KEY_DECIMALSEPARATOR = 179,
	CG_KEY_CURRENCYUNIT = 180,
	CG_KEY_CURRENCYSUBUNIT = 181,
	CG_KEY_KP_LEFTPAREN = 182,
	CG_KEY_KP_RIGHTPAREN = 183,
	CG_KEY_KP_LEFTBRACE = 184,
	CG_KEY_KP_RIGHTBRACE = 185,
	CG_KEY_KP_TAB = 186,
	CG_KEY_KP_BACKSPACE = 187,
	CG_KEY_KP_A = 188,
	CG_KEY_KP_B = 189,
	CG_KEY_KP_C = 190,
	CG_KEY_KP_D = 191,
	CG_KEY_KP_E = 192,
	CG_KEY_KP_F = 193,
	CG_KEY_KP_XOR = 194,
	CG_KEY_KP_POWER = 195,
	CG_KEY_KP_PERCENT = 196,
	CG_KEY_KP_LESS = 197,
	CG_KEY_KP_GREATER = 198,
	CG_KEY_KP_AMPERSAND = 199,
	CG_KEY_KP_DBLAMPERSAND = 200,
	CG_KEY_KP_VERTICALBAR = 201,
	CG_KEY_KP_DBLVERTICALBAR = 202,
	CG_KEY_KP_COLON = 203,
	CG_KEY_KP_HASH = 204,
	CG_KEY_KP_SPACE = 205,
	CG_KEY_KP_AT = 206,
	CG_KEY_KP_EXCLAM = 207,
	CG_KEY_KP_MEMSTORE = 208,
	CG_KEY_KP_MEMRECALL = 209,
	CG_KEY_KP_MEMCLEAR = 210,
	CG_KEY_KP_MEMADD = 211,
	CG_KEY_KP_MEMSUBTRACT = 212,
	CG_KEY_KP_MEMMULTIPLY = 213,
	CG_KEY_KP_MEMDIVIDE = 214,
	CG_KEY_KP_PLUSMINUS = 215,
	CG_KEY_KP_CLEAR = 216,
	CG_KEY_KP_CLEARENTRY = 217,
	CG_KEY_KP_BINARY = 218,
	CG_KEY_KP_OCTAL = 219,
	CG_KEY_KP_DECIMAL = 220,
	CG_KEY_KP_HEXADECIMAL = 221,
	CG_KEY_LCTRL = 224,
	CG_KEY_LSHIFT = 225,
	CG_KEY_LALT = 226,
	CG_KEY_LGUI = 227,
	CG_KEY_RCTRL = 228,
	CG_KEY_RSHIFT = 229,
	CG_KEY_RALT = 230,
	CG_KEY_RGUI = 231,
	CG_KEY_MODE = 257,
	CG_KEY_AUDIONEXT = 258,
	CG_KEY_AUDIOPREV = 259,
	CG_KEY_AUDIOSTOP = 260,
	CG_KEY_AUDIOPLAY = 261,
	CG_KEY_AUDIOMUTE = 262,
	CG_KEY_MEDIASELECT = 263,
	CG_KEY_WWW = 264,
	CG_KEY_MAIL = 265,
	CG_KEY_CALCULATOR = 266,
	CG_KEY_COMPUTER = 267,
	CG_KEY_AC_SEARCH = 268,
	CG_KEY_AC_HOME = 269,
	CG_KEY_AC_BACK = 270,
	CG_KEY_AC_FORWARD = 271,
	CG_KEY_AC_STOP = 272,
	CG_KEY_AC_REFRESH = 273,
	CG_KEY_AC_BOOKMARKS = 274,
	CG_KEY_BRIGHTNESSDOWN = 275,
	CG_KEY_BRIGHTNESSUP = 276,
	CG_KEY_DISPLAYSWITCH = 277,
	CG_KEY_KBDILLUMTOGGLE = 278,
	CG_KEY_KBDILLUMDOWN = 279,
	CG_KEY_KBDILLUMUP = 280,
	CG_KEY_EJECT = 281,
	CG_KEY_SLEEP = 282,
	CG_KEY_APP1 = 283,
	CG_KEY_APP2 = 284,
	CG_KEY_AUDIOREWIND = 285,
	CG_KEY_AUDIOFASTFORWARD = 286,
} cg_key;


// A cg_window represents a window onscreen.
typedef struct cg_window cg_window;

// A cg_sprite represents a sprite image that can be drawn onscreen.
typedef struct cg_sprite cg_sprite;

// A cg_instance is a handle for an item being drawn onscreen. 
typedef struct cg_instance {
	CG_ITEMIZABLE
	int x, y;
	cg_sprite* sprite;

	int index; // Internal index tracker, DO NOT TOUCH
} cg_instance;

// Must be called before any cg_ operations - initializes the library.
int
cg_init ();

// Should be called at the end of the program to clean up. This will automatically
// destroy all items initialized using cg_new_<> functions that have not yet been destroyed
// properly.
void
cg_quit ();

// Creates a new window.
cg_window*
cg_new_window (const char* title, int width, int height);

// Creates a new sprite.
cg_sprite*
cg_new_sprite (cg_window* window, const char* path);

// Creates a new instance that will be drawn onscreen.
cg_instance*
cg_new_instance (cg_sprite* sprite);

// Destroys the given sprite.
void
cg_destroy_sprite (cg_sprite* sprite);

// Destroys an instance, causing it to no longer be drawn onscreen.
void
cg_destroy_instance (cg_instance* instance);

// Destroys a window and all its associated objects (sprites, instances, etc.)
void
cg_destroy_window (cg_window* window);

// Processes any events and then renders the frame, returning '1' unless the
// window has been requested to close.
int
cg_update (cg_window* window);

// Check if the given key is pressed.
// Pass NULL for window to get the global (non-focus-dependent) key state.
// Note that non-focus-dependent key state is unreliable.
int
cg_get_key (cg_window* window, cg_key scancode);

// Hides unnecessary CG_ITEMIZABLE from external use
#ifndef CG_INTERNAL
#undef CG_ITEMIZABLE
#endif // ndef CG_INTERNAL