#include <esp_sntp.h>
#include <WiFi.h>
#include <M5Dial.h>
#include "../secrets.h"

static void sync_time_cb(timeval *tv)
{
    time_t t = time(nullptr) + 1; // Advance one second.
    while (t > time(nullptr))
        ; // Wait until time has advanced by at least one second
    M5Dial.Rtc.setDateTime(gmtime(&t));
}
inline void setupTime()
{
    #if NETWORK_ENABLED==1
    sntp_set_sync_mode(SNTP_SYNC_MODE_IMMED);
    sntp_set_time_sync_notification_cb(sync_time_cb);
    sntp_set_sync_interval(12 * 60 * 60 * 1000UL);
    configTzTime(NTP_TIMEZONE, NTP_SERVER1, NTP_SERVER2, NTP_SERVER3);
    #endif
}