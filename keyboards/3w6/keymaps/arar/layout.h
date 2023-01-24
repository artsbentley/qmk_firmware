// left hand combinations.
const uint16_t PROGMEM q_w_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM w_f_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM a_r_combo[] = {KC_A, KC_R, COMBO_END};
const uint16_t PROGMEM r_s_combo[] = {KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM s_t_combo[] = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM p_b_combo[] = {KC_P, KC_B, COMBO_END};
const uint16_t PROGMEM f_p_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM f_b_combo[] = {KC_F, KC_B, COMBO_END};
const uint16_t PROGMEM w_p_combo[] = {KC_W, KC_P, COMBO_END};
const uint16_t PROGMEM z_x_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM x_d_combo[] = {KC_X, KC_D, COMBO_END};
const uint16_t PROGMEM x_c_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM c_d_combo[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM c_v_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM z_b_combo[] = {KC_Z, KC_B, COMBO_END};

// right hand combinations.
const uint16_t PROGMEM y_en_combo[] = {KC_Y, KC_ENTER, COMBO_END};
const uint16_t PROGMEM l_u_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM j_l_combo[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM k_h_combo[] = {KC_K, KC_H, COMBO_END};
const uint16_t PROGMEM j_slash_combo[] = {KC_J, KC_SLASH, COMBO_END};


#define NXTTAB LCTL(KC_PGDN)
#define PRVTAB LCTL(KC_PGUP)
#define UPTAB  LCTL(LSFT(KC_PGUP))
#define DNTAB  LCTL(LSFT(KC_PGDN))
#define NXTWIN LALT(KC_TAB)
#define PRVWIN LALT(LSFT(KC_TAB))
#define CALDL  LCTL(LALT(KC_DELT))
#define TSKMGR LCTL(LSFT(KC_ESC))
#define EXPLR  LGUI(KC_E)
#define LCKGUI LGUI(KC_L)
#define CONPST LSFT(KC_INS)
#define CLSGUI LALT(KC_F4)

combo_t key_combos[COMBO_COUNT] = {
    // left hand combinations.
  COMBO(q_w_combo, KC_ESCAPE),
  COMBO(p_b_combo, KC_TAB),
  COMBO(w_p_combo, KC_LGUI),
  
  COMBO(w_f_combo, KC_LCTL),
  COMBO(f_p_combo, KC_LSFT),
  COMBO(f_b_combo, KC_LALT),
  /*
  COMBO(c_v_combo, KC_END),
  COMBO(z_x_combo, KC_INSERT),
  COMBO(x_d_combo, KC_HOME),
  COMBO(f_p_combo, KC_UP),
  COMBO(x_c_combo, KC_LEFT),
  COMBO(c_d_combo, KC_DOWN),
  COMBO(d_v_combo, KC_RIGHT),
  */
  COMBO(y_en_combo, KC_ENTER),
  COMBO(j_l_combo, KC_DELT)
};