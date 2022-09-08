# QMK Keymap for ANSI with shortcuts for the German language

This keymap provides an easy way to type German umlauts and eszett on the US-International keyboard layout while also resurrecting its dead keys.
It was made for the Melody96/YMD96 keyboards. This branch is to be used for Keychron Q1 V2 Knob keyboards.


```
-----------------------------------------------------------------------------------------------------
 Esc | F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10| F11| F12|Print| Del | Home| End | PgU | PgD 
-----------------------------------------------------------------------------------------------------
  ~` |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |   0|  - |  = |    BkSpc  | NLk |  /  |  *  |  -   
-----------------------------------------------------------------------------------------------------
 Tab  |  Q |  W | E/€|  R |  T |  Y | U/Ü|  I | O/Ö|  P |  { |  } |   \      |  7  |  8  |  9  |  +   
------------------------------------------------------------------------------------------------
 _LOC  | A/Ä| S/ß|  D |  F |  G |  H |  J |  K |  L |  ; | '  |      Return  |  4  |  5  |  6  |      
-----------------------------------------------------------------------------------------------------
 LShft  |  Z |  X |  C |  V |  B |  N |  M |  , |  . |  / |   RShft     | Up |  1  |  2  |  3  | En   
------------------------------------------------------------------------------------------------
 Ctrl | LGUI | Alt |            Space               |RAlt|_OPT|Ctrl|Left|Down|Rght |  0  |  .  | ter 
-----------------------------------------------------------------------------------------------------
```


## Usage

To type umlauts, use the `CAPS LOCK` key and `a`, `o`, `u` or `s`. Upper-case works with shift on top. Dead keys (`` ` `` and ` ' `) will now immediately produce that character, without requiring hitting space.

Additionally, `CAPS LOCK` + `'`, `;`, `{` and `-` produce the chars corresponding to their original position on the QWERTZ keyboard. This is meant to avoid mistakes while re-wiring your brain to use this layout.

## Why?

I wanted to have an ANSI keyboard that would be comfortable to type on in German while also being universally compatible with every operating system.

Hence I settled on US-International as it ships with all operating systems I can think of. Here I encountered two downsides:

- Unintuitive positions of umlauts (Q, P, Y)
- Important characters for programming behind dead keys

One layout that mitigates this is [EurKEY](https://eurkey.steffen.bruentjen.eu/). It places the umlauts at an intuitive position (A, O, U). I used this layout for quite a while, but after a while two things stood out to me:

- Installing an external layout is often not possible, especially when handling work computers
- Bending the thumb repeatedly to reach for Alt-Gr on longer German texts was putting stress on the thumb joint

This QMK layout is still a work in process. I have yet to reach >100 WPM on it like I did on ISO QWERTZ with dedicated umlauts, but I'm already much faster on it than on EurKEY or stock US-INTL.

## Caveats
- CAPS LOCK is gone for good
- Not suited to type accented characters as the dead keys would be used for that
- Dead keys cannot be held to repeat, they will only produce one char at a time


## Installation
```
cd qmk_firmware/keyboards/keychron/q1/rev_0101/keymaps
git clone https://github.com/davidramiro/km96-usintl-de.git
git checkout keychron-q1v2-knob
cd ~/qmk_firmware
make keychron/q1/rev_0101:km96-usintl-de:flash
```
