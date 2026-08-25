/*
 * SPDX-FileCopyrightText: 2026 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include "lvgl.h"
#include "esp_brookesia.hpp"
#ifdef ESP_UTILS_LOG_TAG
#   undef ESP_UTILS_LOG_TAG
#endif
#define ESP_UTILS_LOG_TAG "BS:VoiceAssistant"
#include "esp_lib_utils.h"
#include "voice_assistant.hpp"

#define APP_NAME "voice_assistant"

using namespace std;
using namespace esp_brookesia::gui;
using namespace esp_brookesia::systems;

namespace {

static lv_obj_t *create_center_label(lv_obj_t *parent, const char *text)
{
    lv_obj_t *label = lv_label_create(parent);
    lv_label_set_text(label, text);
    lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_set_width(label, LV_PCT(100));
    lv_obj_center(label);
    return label;
}

} // namespace

namespace esp_brookesia::apps {

LV_IMG_DECLARE(esp_brookesia_image_middle_app_launcher_default_112_112);

VoiceAssistant *VoiceAssistant::_instance = nullptr;

VoiceAssistant *VoiceAssistant::requestInstance(bool use_status_bar, bool use_navigation_bar)
{
    if (_instance == nullptr) {
        _instance = new VoiceAssistant(use_status_bar, use_navigation_bar);
    }
    return _instance;
}

VoiceAssistant::VoiceAssistant(bool use_status_bar, bool use_navigation_bar):
    App(APP_NAME, &esp_brookesia_image_middle_app_launcher_default_112_112, false, use_status_bar, use_navigation_bar)
{
}

VoiceAssistant::~VoiceAssistant()
{
}

bool VoiceAssistant::run(void)
{
    ESP_UTILS_LOGD("Run");

    lv_obj_t *screen = lv_scr_act();
    lv_obj_set_style_bg_color(screen, lv_color_hex(0x0B1020), 0);
    lv_obj_set_style_bg_opa(screen, LV_OPA_COVER, 0);

    lv_obj_t *panel = lv_obj_create(screen);
    lv_obj_set_size(panel, LV_PCT(100), LV_PCT(100));
    lv_obj_center(panel);
    lv_obj_set_style_bg_color(panel, lv_color_hex(0x111A33), 0);
    lv_obj_set_style_border_width(panel, 0, 0);
    lv_obj_set_style_radius(panel, 0, 0);
    lv_obj_set_style_pad_all(panel, 24, 0);
    lv_obj_set_style_bg_opa(panel, LV_OPA_COVER, 0);

    lv_obj_t *title = lv_label_create(panel);
    lv_label_set_text(title, "Voice Assistant");
    lv_obj_set_style_text_color(title, lv_color_hex(0xFFFFFF), 0);
    lv_obj_set_style_text_font(title, &lv_font_montserrat_28, 0);
    lv_obj_align(title, LV_ALIGN_TOP_MID, 0, 24);

    lv_obj_t *subtitle = lv_label_create(panel);
    lv_label_set_text(subtitle, "Your custom app entry is ready.");
    lv_obj_set_style_text_color(subtitle, lv_color_hex(0xB9C2E3), 0);
    lv_obj_set_style_text_font(subtitle, &lv_font_montserrat_16, 0);
    lv_obj_align(subtitle, LV_ALIGN_TOP_MID, 0, 64);

    lv_obj_t *mic = lv_obj_create(panel);
    lv_obj_set_size(mic, 140, 140);
    lv_obj_align(mic, LV_ALIGN_CENTER, 0, -10);
    lv_obj_set_style_radius(mic, LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_bg_color(mic, lv_color_hex(0x22305E), 0);
    lv_obj_set_style_border_width(mic, 0, 0);
    lv_obj_set_style_shadow_width(mic, 24, 0);
    lv_obj_set_style_shadow_color(mic, lv_color_hex(0x6D7DFF), 0);
    lv_obj_set_style_shadow_opa(mic, LV_OPA_30, 0);

    lv_obj_t *mic_label = lv_label_create(mic);
    lv_label_set_text(mic_label, LV_SYMBOL_MICROPHONE);
    lv_obj_set_style_text_color(mic_label, lv_color_hex(0xFFFFFF), 0);
    lv_obj_set_style_text_font(mic_label, &lv_font_montserrat_48, 0);
    lv_obj_center(mic_label);

    lv_obj_t *hint = lv_label_create(panel);
    lv_label_set_text(hint, "Tap the icon in launcher to open this app.");
    lv_obj_set_style_text_color(hint, lv_color_hex(0x97A5D9), 0);
    lv_obj_set_style_text_font(hint, &lv_font_montserrat_14, 0);
    lv_obj_align(hint, LV_ALIGN_BOTTOM_MID, 0, -28);

    return true;
}

bool VoiceAssistant::back(void)
{
    ESP_UTILS_LOGD("Back");
    ESP_UTILS_CHECK_FALSE_RETURN(notifyCoreClosed(), false, "Notify core closed failed");
    return true;
}

ESP_UTILS_REGISTER_PLUGIN_WITH_CONSTRUCTOR(systems::base::App, VoiceAssistant, APP_NAME, []()
{
    return std::shared_ptr<VoiceAssistant>(VoiceAssistant::requestInstance(), [](VoiceAssistant *p) {});
})

} // namespace esp_brookesia::apps
