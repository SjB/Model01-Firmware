// -*- mode: c++ -*-

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "SjB Keymap built"
#endif

// The Kaleidoscope core
#include "Kaleidoscope.h"
#include "Kaleidoscope-MouseKeys.h"
#include "Kaleidoscope-Macros.h"
#include "Kaleidoscope-LEDControl.h"
//#include "Kaleidoscope-NumPad.h"
#include "LED-Off.h"
//#include "Kaleidoscope-DualUse.h"
#include "Kaleidoscope-OneShot.h"
#include "Kaleidoscope-TapDance.h"
#include "Kaleidoscope-HostPowerManagement.h"
#include "Kaleidoscope-MagicCombo.h"
#include "Kaleidoscope-USB-Quirks.h"

#include "Kaleidoscope-LED-ActiveModColor.h"
#include "Kaleidoscope-LEDEffect-DigitalRain.h"
//#include "Kaleidoscope-LED-Wavepool.h"
#include "LED-Off.h"
#include "Kaleidoscope-LEDEffect-SolidColor.h"
#include "Kaleidoscope-LEDEffect-Breathe.h"
#include "Kaleidoscope-LEDEffect-Chase.h"
#include "Kaleidoscope-LEDEffect-Rainbow.h"
#include "Kaleidoscope-LEDEffect-BootGreeting.h"
#include "Kaleidoscope-LED-Stalker.h"
#include "Kaleidoscope-LED-AlphaSquare.h"

enum {
	MACRO_VERSION_INFO,
	MACRO_TSKSWCH,
	MACRO_VIM_CMD
};

enum {
	TAPDANCE_TERM
};


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

KEYMAPS(
  [QWERTY] = KEYMAP_STACKED
  (XXX,               Key_1,            Key_2,         Key_3,      Key_4, Key_5, TD_TERM,
   Key_Backtick,      Key_Q,            Key_W,         Key_E,      Key_R, Key_T, LCTRL(Key_Spacebar),
   Key_Backslash,     Key_A,            Key_S,         Key_D,      Key_F, Key_G,
   Key_LeftBracket,   Key_Z,            Key_X,         Key_C,      Key_V, Key_B, Key_Escape,
   OSM(LeftShift),    OSM(LeftControl), Key_Backspace, OSM(LeftAlt), 
   OSL(FUNCTION),

   OSM(RightAlt),     Key_6,        Key_7,        Key_8,       Key_9,      Key_0,         Key_Minus,
   Key_Enter,         Key_Y,        Key_U,        Key_I,       Key_O,      Key_P,         Key_Equals,
                      Key_H,        Key_J,        Key_K,       Key_L,      Key_Semicolon, Key_Quote,
   Key_Tab,           Key_N,        Key_M,        Key_Comma,   Key_Period, Key_Slash,     Key_RightBracket,
   OSM(LeftAlt),      Key_Spacebar, Key_LeftGui,  OSM(RightShift),
   OSL(FUNCTION)),

  [FUNCTION] =  KEYMAP_STACKED
  (Key_NumLock,   Key_F1,         Key_F2,        Key_F3,        Key_F4,           Key_F5,             Key_LEDEffectNext,
   ___,           Key_mouseBtnL,  Key_mouseUp,   Key_mouseBtnR, Key_mouseBtnM,    XXX,                F_MAX,
   ___,           Key_mouseL,     Key_mouseDn,   Key_mouseR,    Key_mouseScrollL, Key_mouseScrollUp,
   ___,           Consumer_VolumeDecrement, Consumer_VolumeDecrement, Consumer_Mute, Key_mouseScrollR, Key_mouseScrollDn,  ___,
   ___,           ___,            Key_Delete,    ___,
   ___,
   XXX,           Key_F6,         Key_F7,        Key_F8,      Key_F9,         Key_F10,          Key_F11,
   ___,           Key_Home,       Key_PageDown,  Key_PageUp,  Key_End,        Key_PrintScreen,  Key_F12,
                  Key_LeftArrow,  Key_DownArrow, Key_UpArrow, Key_RightArrow, Key_Insert,       ___,
   ___,           SJB_CALC,       SJB_SEARCH,    SJB_EMAIL,   SJB_BROWSER,    F_TSKSWCH,        SJB_HOME,
   ___,           ___,            Key_Enter,     ___,
   ___),


  [NUMPAD] =  KEYMAP_STACKED
  (Key_NumLock, XXX,       XXX,            XXX,             XXX,             XXX,              XXX,
   XXX,         LSHIFT(Key_1),  LSHIFT(Key_2),       LSHIFT(Key_3),        LSHIFT(Key_4),        LSHIFT(Key_5),         ___,
   XXX,         LSHIFT(Key_6),  LSHIFT(Key_7),       LSHIFT(Key_8),        LSHIFT(Key_9),        LSHIFT(Key_0), 
   XXX,         Key_Slash, LSHIFT(Key_LeftBracket), LSHIFT(Key_RightBracket), Key_LeftBracket, Key_RightBracket, Key_Escape,
   ___, ___, ___, ___,
   ___,

   M(MACRO_VERSION_INFO),  L(Backtick),   Key_Keypad7, Key_Keypad8,   Key_Keypad9,        Key_KeypadSubtract, XXX,
   ___,                    Key_Backtick,  Key_Keypad4, Key_Keypad5,   Key_Keypad6,        Key_KeypadAdd,      XXX,
                           Key_Pipe,      Key_Keypad1, Key_Keypad2,   Key_Keypad3,        Key_Equals,         Key_Quote,
   XXX,                    Key_Backslash, Key_Keypad0, Key_KeypadDot, Key_KeypadMultiply, Key_KeypadDivide,   Key_Enter,
   ___, ___, ___, ___,
   ___)
)

static void versionInfoMacro(uint8_t keyState) {
  if (keyToggledOn(keyState)) {
    Macros.type(PSTR("Keyboardio Model 01 - Kaleidoscope "));
    Macros.type(PSTR(BUILD_INFORMATION));
  }
}

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {
  case MACRO_VERSION_INFO:
	  versionInfoMacro(keyState);
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

void toggleLedsOnSuspendResume(kaleidoscope::HostPowerManagement::Event event) {
  switch (event) {
  case kaleidoscope::HostPowerManagement::Suspend:
    LEDControl.paused = true;
    LEDControl.set_all_leds_to({0, 0, 0});
    LEDControl.syncLeds();
    break;
  case kaleidoscope::HostPowerManagement::Resume:
    LEDControl.paused = false;
    LEDControl.refreshAll();
    break;
  case kaleidoscope::HostPowerManagement::Sleep:
    break;
  }
}

void hostPowerManagementEventHandler(kaleidoscope::HostPowerManagement::Event event) {
  toggleLedsOnSuspendResume(event);
}

enum {
  COMBO_TOGGLE_NKRO_MODE
};

static void toggleKeyboardProtocol(uint8_t combo_index) {
  USBQuirks.toggleKeyboardProtocol();
}

USE_MAGIC_COMBOS({.action = toggleKeyboardProtocol,
                  // Left Fn + Esc + Shift
                  .keys = { R3C6, R2C6, R3C7 }
                 });

KALEIDOSCOPE_INIT_PLUGINS(
			  BootGreetingEffect,
			  LEDControl,
			  LEDOff,
			  StalkerEffect,
			  LEDDigitalRainEffect,
			  //WavepoolEffect,
			  LEDRainbowEffect,
			  LEDRainbowWaveEffect,
			  LEDChaseEffect,
			  solidRed,
			  solidOrange,
			  solidYellow,
			  solidGreen,
			  solidBlue,
			  solidIndigo,
			  solidViolet,
			  LEDBreatheEffect,
			  AlphaSquareEffect,
			  ActiveModColorEffect,
			  LEDOff,
    
			  Macros,
			  MouseKeys,
			  // DualUse,
			  OneShot,
			  TapDance,

			  HostPowerManagement,
			  MagicCombo,

			  USBQuirks
			  );

void setup() {
  Kaleidoscope.setup();

  // ConsumerControl.begin();

  ActiveModColorEffect.highlight_color = CRGB(0x00, 0xff, 0xff);
  AlphaSquare.color = { 0, 255, 0 };

  LEDRainbowEffect.brightness(150);
  LEDRainbowWaveEffect.brightness(150);

  LEDDigitalRainEffect.DROP_TICKS = 22;

  //WavepoolEffect.idle_timeout = 5000;

  StalkerEffect.variant = STALKER(BlazingTrail);
  //StalkerEffect.variant = STALKER(Haunt);
  LEDOff.activate();

}

void loop() {
  Kaleidoscope.loop();
}
