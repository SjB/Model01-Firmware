// -*- mode: c++ -*-

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "SjB Keymap built"
#endif


/**
 * These #include directives pull in the Kaleidoscope firmware core,
 * as well as the Kaleidoscope plugins we use in the Model 01's firmware
 */


// The Kaleidoscope core
#include "Kaleidoscope.h"

#include "kaleidoscope/hid.h"

// Support for keys that move the mouse
#include "Kaleidoscope-MouseKeys.h"

// Support for macros
#include "Kaleidoscope-Macros.h"

// Support for controlling the keyboard's LEDs
#include "Kaleidoscope-LEDControl.h"

// Support DualUse features
#include "Kaleidoscope-DualUse.h"

// Support One-Shot features
#include "Kaleidoscope-OneShot.h"
//#include "Kaleidoscope-Escape-OneShot.h"

// Support TapDance features
#include "Kaleidoscope-TapDance.h"

// SpaceCadet :tap shift keys to insert parens
//#include "Kaleidoscope-SpaceCadet.h"

#include "Kaleidoscope-LED-ActiveModColor.h"

#include "Kaleidoscope-LEDEffect-DigitalRain.h"
#include "Kaleidoscope-LED-Wavepool.h"

// Support for an "LED off mode"
#include "LED-Off.h"

// Support for the "Boot greeting" effect, which pulses the 'LED' button for 10s
// when the keyboard is connected to a computer (or that computer is powered on)
//#include "Kaleidoscope-LEDEffect-BootGreeting.h"

// Support for LED modes that set all LEDs to a single color
#include "Kaleidoscope-LEDEffect-SolidColor.h"

// Support for an LED mode that makes all the LEDs 'breathe'
#include "Kaleidoscope-LEDEffect-Breathe.h"

// Support for an LED mode that makes a red pixel chase a blue pixel across the keyboard
#include "Kaleidoscope-LEDEffect-Chase.h"

// Support for LED modes that pulse the keyboard's LED in a rainbow pattern
#include "Kaleidoscope-LEDEffect-Rainbow.h"

// Support for an LED mode that lights up the keys as you press them
#include "Kaleidoscope-LED-Stalker.h"

// Support for an LED mode that prints the keys you press in letters 4px high
#include "Kaleidoscope-LED-AlphaSquare.h"

// Support for Keyboardio's internal keyboard testing mode
//#include "Kaleidoscope-Model01-TestMode.h"


enum {
	MACRO_VERSION_INFO,
	MACRO_FILES,
	MACRO_CALC,
	MACRO_SEARCH,
	MACRO_EMAIL,
	MACRO_BROWSER,
	MACRO_TSKSWCH,
	MACRO_VIM_CMD
};

enum {
	TAPDANCE_TERM
};



#define L(k) (LSHIFT(Key_ ## k))

#define LCA(k) ((Key) { k.keyCode, k.flags | CTRL_HELD | LALT_HELD })
#define LSS(k) ((Key) { k.keyCode, k.flags | SHIFT_HELD | GUI_HELD })
#define F_LOCK LGUI(Key_L)
#define F_TERM LCA(Key_T)
#define F_MAX LALT(Key_F10)
#define F_TSKSWCH M(MACRO_TSKSWCH)

#define MT_Escape MT(RightAlt, Escape)
#define MT_LeftBracket MT(RightAlt, LeftBracket)
#define MT_RightBracket MT(RightAlt, RightBracket)

#define TD_TERM TD(TAPDANCE_TERM)

// #define SJB_HOME ((Key) { .raw = HID_CONSUMER_AL_LOCAL_MACHINE_BROWSER }) // | ((Key) {0, KEY_FLAGS | SYNTHETIC|IS_CONSUMER  | HID_TYPE_RTC }).raw})
#define SJB_HOME Consumer_AL_Local_MachineBrowser
#define SJB_CALC Consumer_AL_Calculator
#define SJB_SEARCH Consumer_AC_Search 
#define SJB_EMAIL Consumer_AL_Email_Reader
#define SJB_BROWSER Consumer_AL_InternetBrowser
#define Key_NumLock LockLayer(NUMPAD)

enum { QWERTY, FUNCTION, NUMPAD }; // layers

const Key keymaps[][ROWS][COLS] PROGMEM = {

  [QWERTY] = KEYMAP_STACKED
  (XXX,               Key_1,            Key_2,         Key_3,      Key_4, Key_5, TD_TERM,
   Key_Backtick,      Key_Q,            Key_W,         Key_E,      Key_R, Key_T, M(MACRO_VIM_CMD),
   Key_Backslash,     Key_A,            Key_S,         Key_D,      Key_F, Key_G,
   Key_LeftBracket,   Key_Z,            Key_X,         Key_C,      Key_V, Key_B, Key_Escape,
   OSM(LeftShift),    OSM(LeftControl), Key_Backspace, Key_LeftGui, 
   OSL(FUNCTION),

   OSM(RightAlt),     Key_6,        Key_7,        Key_8,       Key_9,      Key_0,         Key_Minus,
   XXX,               Key_Y,        Key_U,        Key_I,       Key_O,      Key_P,         Key_Equals,
                      Key_H,        Key_J,        Key_K,       Key_L,      Key_Semicolon, Key_Quote,
   Key_Tab,           Key_N,        Key_M,        Key_Comma,   Key_Period, Key_Slash,     Key_RightBracket,
   OSM(LeftAlt),      Key_Enter,    Key_Spacebar, OSM(RightShift),
   OSL(FUNCTION)),

  [FUNCTION] =  KEYMAP_STACKED
  (Key_NumLock,   Key_F1,         Key_F2,        Key_F3,        Key_F4,           Key_F5,             Key_LEDEffectNext,
   ___,           Key_mouseBtnL,  Key_mouseUp,   Key_mouseBtnR, Key_mouseBtnM,    XXX,                F_MAX,
   ___,           Key_mouseL,     Key_mouseDn,   Key_mouseR,    Key_mouseScrollL, Key_mouseScrollUp,
   ___,           Key_VolumeDown, Key_VolumeUp,  Key_Mute,      Key_mouseScrollR, Key_mouseScrollDn,  ___,
   ___,           ___,            Key_Delete,    ___,
   ___,
   XXX,           Key_F6,         Key_F7,        Key_F8,      Key_F9,         Key_F10,          Key_F11,
   SJB_HOME,      Key_Home,       Key_PageDown,  Key_PageUp,  Key_End,        Key_PrintScreen,  Key_F12,
                  Key_LeftArrow,  Key_DownArrow, Key_UpArrow, Key_RightArrow, Key_Insert,       ___,
   ___,           SJB_CALC,       SJB_SEARCH,    SJB_EMAIL,   SJB_BROWSER,    F_TSKSWCH,        Consumer_Sleep,
   ___,           Key_Enter,      ___,     ___,
   ___),


  [NUMPAD] =  KEYMAP_STACKED
  (Key_NumLock, XXX,       XXX,            XXX,             XXX,             XXX,              XXX,
   XXX,         L(1),      L(2),           L(3),            L(4),            L(5),             ___,
   XXX,         L(6),      L(7),           L(8),            L(9),            L(0), 
   XXX,         Key_Slash, L(LeftBracket), L(RightBracket), Key_LeftBracket, Key_RightBracket, Key_Escape,
   ___, ___, ___, ___,
   ___,

   M(MACRO_VERSION_INFO),  L(Backtick),   Key_Keypad7, Key_Keypad8,   Key_Keypad9,        Key_KeypadSubtract, XXX,
   ___,                    Key_Backtick,  Key_Keypad4, Key_Keypad5,   Key_Keypad6,        Key_KeypadAdd,      XXX,
                           Key_Pipe,      Key_Keypad1, Key_Keypad2,   Key_Keypad3,        Key_Equals,         Key_Quote,
   XXX,                    Key_Backslash, Key_Keypad0, Key_KeypadDot, Key_KeypadMultiply, Key_KeypadDivide,   Key_Enter,
   ___, ___, ___, ___,
   ___)
};

static void versionInfoMacro(uint8_t keyState) {
  if (keyToggledOn(keyState)) {
    Macros.type(PSTR("Keyboardio Model 01 - Kaleidoscope "));
    Macros.type(PSTR(BUILD_INFORMATION));
  }
}

static void ConsumerKeyWrite(uint8_t keyState, uint16_t hid_code) {
  if (keyToggledOn(keyState)) {
	  ConsumerControl.write(hid_code);
	  Keyboard.sendReport();
  }
}


static int tskwsch_count = 0;
const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {

  case MACRO_VERSION_INFO:
	  versionInfoMacro(keyState);
	  break;
  case MACRO_FILES:
	  ConsumerKeyWrite(keyState, HID_CONSUMER_AL_LOCAL_MACHINE_BROWSER);
	  break;
  case MACRO_CALC:
	  ConsumerKeyWrite(keyState, HID_CONSUMER_AL_CALCULATOR);
	  break;
  case MACRO_SEARCH:
	  ConsumerKeyWrite(keyState, HID_CONSUMER_AC_SEARCH);
	  break;
  case MACRO_EMAIL:
	  ConsumerKeyWrite(keyState, HID_CONSUMER_AL_EMAIL_READER);
	  break;
  case MACRO_BROWSER:
	  ConsumerKeyWrite(keyState, HID_CONSUMER_AL_INTERNET_BROWSER);
	  break;
  case MACRO_TSKSWCH:
	  return MACRODOWN(D(LeftGui), T(Tab), U(LeftGui));
  case MACRO_VIM_CMD:
	  return MACRODOWN(T(Escape), D(LeftShift), T(Semicolon), U(LeftShift));
  }
  return MACRO_NONE;
}


static kaleidoscope::LEDSolidColor solidRed(160, 0, 0);
static kaleidoscope::LEDSolidColor solidOrange(140, 70, 0);
static kaleidoscope::LEDSolidColor solidYellow(130, 100, 0);
static kaleidoscope::LEDSolidColor solidGreen(0, 160, 0);
static kaleidoscope::LEDSolidColor solidBlue(0, 70, 130);
static kaleidoscope::LEDSolidColor solidIndigo(0, 0, 170);
static kaleidoscope::LEDSolidColor solidViolet(130, 0, 120);

void tapDanceAction(uint8_t tap_dance_index, byte row, byte col, uint8_t tap_count, kaleidoscope::TapDance::ActionType tap_dance_action) {
	switch(tap_dance_index) {
	case TAPDANCE_TERM: 
		return tapDanceActionKeys(tap_count, tap_dance_action, F_TERM, F_LOCK);
	}
}

void setup() {
  Kaleidoscope.setup();

  ConsumerControl.begin();
  Kaleidoscope.use(
	  //   &BootGreetingEffect,
    &LEDControl,
    &StalkerEffect,
    &LEDDigitalRainEffect,
    &WavepoolEffect,
    &LEDRainbowEffect,
    &LEDRainbowWaveEffect,
    &LEDChaseEffect,
    &solidRed, &solidOrange, &solidYellow, &solidGreen, &solidBlue, &solidIndigo, &solidViolet,
    &LEDBreatheEffect,
    &AlphaSquareEffect,
    &ActiveModColorEffect,
    &LEDOff,
    
    &Macros,
    &MouseKeys,
    &DualUse,
    &OneShot,
//    &EscapeOneShot,
//    &SpaceCadet,
    &TapDance
  );

  ActiveModColorEffect.highlight_color = CRGB(0x00, 0xff, 0xff);
  AlphaSquare.color = { 0, 255, 0 };

  LEDRainbowEffect.brightness(150);
  LEDRainbowWaveEffect.brightness(150);

  LEDDigitalRainEffect.DROP_TICKS = 22;

  WavepoolEffect.idle_timeout = 5000;

  //StalkerEffect.variant = STALKER(BlazingTrail);
  StalkerEffect.variant = STALKER(Haunt);
  StalkerEffect.activate();

  // define SpaceCadet map
  // static kaleidoscope::SpaceCadet::KeyBinding spacecadetmap[] = {
  //   {Key_LeftShift, Key_LeftParen, 250}
  //   , {Key_RightShift, Key_RightParen, 250}
  //   , SPACECADET_MAP_END
  // };
  // SpaceCadet.map = spacecadetmap;
}

void loop() {
  Kaleidoscope.loop();
}
