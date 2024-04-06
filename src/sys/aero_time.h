#include <esp_sntp.h>
#include <WiFi.h>
#include <M5Dial.h>
#include <aero_preferences.h>

#define NTP_SERVER "pool.ntp.org"

static void sync_time_cb(timeval *tv)
{
    time_t t = time(nullptr) + 1; // Advance one second.
    while (t > time(nullptr))
        ; // Wait until time has advanced by at least one second
    M5Dial.Rtc.setDateTime(gmtime(&t));
}
inline void setupTime()
{
    sntp_set_sync_mode(SNTP_SYNC_MODE_IMMED);
    sntp_set_time_sync_notification_cb(sync_time_cb);
    sntp_set_sync_interval(12 * 60 * 60 * 1000UL);
    String timezone = settings.getString("ntp_timezone");
    String tz = settings.getString("ntp_tz_str");
    configTzTime(tz.c_str(), NTP_SERVER);
}