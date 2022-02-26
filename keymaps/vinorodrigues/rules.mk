VIA_ENABLE = yes
LTO_ENABLE = yes
NKRO_ENABLE = no  # allow mac keys to work

ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
    SRC += rgb_matrix_keymap.c
endif
