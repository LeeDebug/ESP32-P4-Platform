/*
 * SPDX-FileCopyrightText: 2026 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

#include "systems/phone/esp_brookesia_phone_app.hpp"

namespace esp_brookesia::apps {

class VoiceAssistant: public systems::phone::App {
public:
    static VoiceAssistant *requestInstance(bool use_status_bar = true, bool use_navigation_bar = true);

    ~VoiceAssistant() override;

    using systems::phone::App::startRecordResource;
    using systems::phone::App::endRecordResource;

protected:
    VoiceAssistant(bool use_status_bar, bool use_navigation_bar);

    bool run(void) override;
    bool back(void) override;

private:
    static VoiceAssistant *_instance;
};

} // namespace esp_brookesia::apps
