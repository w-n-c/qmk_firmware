#pragma once

// With this option enabled and theres’s USB communication,
// then that half assumes it is the primary, otherwise it assumes it
// is the dependent. Helps with some finicky pro micros.
#define SPLIT_USB_DETECT
// turn off effects when suspended
#define RGB_MATRIX_SLEEP
// If LED_MATRIX_KEYPRESSES or LED_MATRIX_KEYRELEASES is enabled, you also will want to enable SPLIT_TRANSPORT_MIRROR
#define SPLIT_TRANSPORT_MIRROR
// limits maximum brightness of LEDs (max 255). Higher may cause the controller to crash.
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 100
// How long till mod tap triggers
#define TAPPING_TERM 300
// pressing another key while holding mod key within tapping term does same as if tapping term were held
#define PERMISSIVE_HOLD
